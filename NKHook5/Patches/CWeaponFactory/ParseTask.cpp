#include "ParseTask.h"
#include "../../Signatures/Signature.h"
#include "../../Classes/CApplyStatusEffectTask.h"
#include "../../Classes/CWeaponFactory.h"
#include "../../Classes/CProjectile.h"
#include "../../ClassesEx/CProjectileExt.h"
#include "../../Classes/CCollectableTask.h"
#include "../../ClassesEx/CCollectableTaskExt.h"
#include "../../Util/NewFramework.h"
#include <Logging/Logger.h>

using namespace Common;
using namespace Common::Logging;
using namespace Common::Logging::Logger;
using namespace NKHook5;
using namespace NKHook5::Patches;
using namespace NKHook5::Patches::CWeaponFactory;
using namespace NKHook5::Signatures;

struct parseResult_t {
    char pad_0000[16]; //0x0000
    ClassesEx::CProjectileExt* resultTask; //0x0010
};

static uint64_t o_func;
void* __fastcall cb_hook(Classes::CWeaponFactory* self, int pad, const Classes::JsonObject& documentHandle, parseResult_t* parseResults, bool hasSubtasks, int param_4) {
    bool overrideHasSubtasks = hasSubtasks;
    /*if (documentHandle.Get("Type") != nullptr)
    {
        const Classes::JsonPropertyValue* taskType = documentHandle.Get("Type");
        if ((taskType->value.stringValue == "StatusEffect") || (taskType->value.stringValue == "Effect") && documentHandle.Get("Tasks") != nullptr)
        {
            overrideHasSubtasks = true;
        }
    }*/

    //Call the original CWeaponFactory::ParseTask function
    void* result = PLH::FnCast(o_func, &cb_hook)(self, pad, documentHandle, parseResults, overrideHasSubtasks, param_4);
    //Get the resulting tasl
    Classes::CWeaponTask* baseTask = parseResults->resultTask;

    //Find its type name
    std::string typeName = nfw::typeof(baseTask);

    //The typename is mangled, but it'll contain CProjectile. This is effectively if(self instanceof CProjectile) for you java devs
    if (typeName.find("CProjectile") != std::string::npos) {
        ClassesEx::CProjectileExt* projectileTask = (ClassesEx::CProjectileExt*)baseTask;
        //Parse our custom json properties
        projectileTask->NO_CLEANUP = false;
        projectileTask->ALWAYS_UPDATE = false;
        if (!documentHandle.dataMap.empty()) {
            const Classes::JsonPropertyValue* noCleanup = documentHandle.Get("NO_CLEANUP");
            if (noCleanup != nullptr) {
                projectileTask->NO_CLEANUP = noCleanup->value.boolValue;
            }
            const Classes::JsonPropertyValue* alwaysUpdate = documentHandle.Get("ALWAYS_UPDATE");
            if (alwaysUpdate != nullptr) {
                projectileTask->ALWAYS_UPDATE = alwaysUpdate->value.boolValue;
            }
            const Classes::JsonPropertyValue* noOgc = documentHandle.Get("NO_OGC");
            if (noOgc != nullptr) {
                projectileTask->NO_OGC = noOgc->value.boolValue;
            }
        }
    }

    //Cool
    if (typeName.find("CCollectableTask") != std::string::npos) {
        ClassesEx::CCollectableTaskExt* collectableExt = (ClassesEx::CCollectableTaskExt*)baseTask;
        collectableExt->COLLECT_METHOD = ClassesEx::CollectMethod::DEFAULT;
        if (!documentHandle.dataMap.empty()) {
            const Classes::JsonPropertyValue* collectMethod = documentHandle.Get("COLLECT_METHOD");
            if (collectMethod) {
                if (collectMethod->value.stringValue == "DEFAULT") {
                    collectableExt->COLLECT_METHOD = ClassesEx::CollectMethod::DEFAULT;
                }
                if (collectMethod->value.stringValue == "AUTOMATIC") {
                    collectableExt->COLLECT_METHOD = ClassesEx::CollectMethod::AUTOMATIC;
                }
            }
        }
    }

    return result;
}

auto ParseTask::Apply() -> bool
{
    const void* address = Signatures::GetAddressOf(Sigs::CWeaponFactory_ParseTask);
    if (address)
    {
        PLH::x86Detour* detour = new PLH::x86Detour((const uintptr_t)address, (const uintptr_t)&cb_hook, &o_func);
        if (detour->hook())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
