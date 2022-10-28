#include "Signature.h"

#include "../Utils.h"

#include <map>
#include <cstdarg>

#include <rttihelper.h>

using namespace NKHook5;
using namespace NKHook5::Signatures;

static std::map<Sigs, void*> pointerMap;

void* Signatures::FindFirst(int count, ...) {
	va_list args;
	va_start(args, count);

	void* result = nullptr;
	for (size_t i = 0; i < count; i++) {
		const char* arg = va_arg(args, const char*);
		if (!result) {
			result = (void*)Utils::FindPattern(arg);
		}
	}

	va_end(args);
	return result;
}

void Signatures::FindAll() {
	/*CBaseFileIO*/
	pointerMap[Sigs::CBaseFileIO_FileExists] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 4D ?? 8B ?? 8B ?? ?? 8B ?? ?? 53 ?? 5D ?? ?? ?? ?? 8B",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D1 ?? 55 ?? 8B ?? ?? 8B ?? 8B"
	);
	pointerMap[Sigs::CBaseFileIO_OpenFile] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 4D ?? 8B ?? 8B ?? ?? 8B ?? ?? 57",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 4D ?? 8B ?? 8B"
	);
	/* CBasePositionableObject */
	pointerMap[Sigs::CBasePositionableObject_AssignParent] = Signatures::FindFirst(1,
		"55 8b ec 56 8b f1 57 8b 7d ?? 8b 46 ?? 3b c7 74 ?? 85 c0 74 ?? e8 ?? ?? ?? ?? 85 ff 74 ?? 56 8b cf e8 ?? ?? ?? ?? 80 7f ?? ?? 75 ?? 8b 06 8b ce 6a ?? ff 90 ?? ?? ?? ?? 8b ce e8 ?? ?? ?? ?? 5f 5e 5d c2 ?? ?? cc cc cc cc cc cc cc cc cc cc cc 80 79"
	);
	pointerMap[Sigs::CBasePositionableObject_SetComplete] = Signatures::FindFirst(1,
		"?? 79 ?? ?? 75 ?? 56 57 8D"
	);
	/* CBaseScreen */
	pointerMap[Sigs::CBaseScreen_CCTOR] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? 8D ?? ?? E8 ?? ?? ?? ?? ?? 45"
	);
	pointerMap[Sigs::CBaseScreen_OpenPopup] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 0F ?? ?? ?? 8B F1 ?? 75 ?? 8B",
		"55 8B EC 83 EC ?? 8B ?? ?? 53 56 57 ?? 00"
	);
	pointerMap[Sigs::CBaseScreen_StartUsingAsset] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? BE ?? ?? ?? ?? ?? 75 ?? A1",
		"55 8B EC 51 56 8B F1 ?? BE ?? ?? ?? ?? ?? 75 ?? 68"
	);
	/* CBloon */
	pointerMap[Sigs::CBloon_Update] = Signatures::FindFirst(1,
		"55 8B EC 83 EC ?? 53 56 8B ?? ?? 8B D9 56 E8 ?? ?? ?? ?? ?? BB"
	);
	/* CBloonsBaseScreen */
	pointerMap[Sigs::CBloonsBaseScreen_CCTOR] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? 8D ?? ?? E8 ?? ?? ?? ?? ?? 45"
	);
	/* CBloonsTD5Game */
	pointerMap[Sigs::CBloonsTD5Game_CCTOR] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 86",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86"
	);
	pointerMap[Sigs::CBloonsTD5Game_LoadAssets] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? B5 ?? ?? ?? ?? 6A ?? ?? 85",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? BD ?? ?? ?? ?? 6A"
	);
	/* CCollectableTask */
	pointerMap[Sigs::CCollectableTask_Clone] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 8B ?? ?? ?? ?? ?? 68"
	);
	pointerMap[Sigs::CCollectableTask_GiveContentsAndDie] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 F3"
	);
	pointerMap[Sigs::CCollectableTask_Update] = Signatures::FindFirst(1,
		"55 8B EC 56 8B F1 ?? BE ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? F3"
	);
	/* CFile */
	pointerMap[Sigs::CFile_ReadBytes] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B ?? ?? 8B ?? ?? 8B ?? 52"
	);
	/* CFlagStringConvertor */
	pointerMap[Sigs::CFlagStringConvertor_FlagToString] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 85",
		"55 8B EC 83 EC ?? 56 57 ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? E8"
	);
	pointerMap[Sigs::CFlagStringConvertor_LoadCategory] = Signatures::FindFirst(2,
		//Kongregate
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8B ?? ?? 85",
		//Steam
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 4D ?? 33"
	);
	pointerMap[Sigs::CFlagStringConvertor_StringToFlag] = Signatures::FindFirst(1,
		"55 8B EC 83 EC ?? 53 56 57 ?? ?? ?? E8"
	);
	/* CFontManager */
	pointerMap[Sigs::CFontManager_GetFont] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8D ?? ?? 8B",
		"55 8B EC 83 EC ?? 53 8B ?? ?? 56 57 8D"
	);
	/* CGameScreen */
	pointerMap[Sigs::CGameScreen_Init] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 9D ?? ?? ?? ?? 8B ?? ?? 56"
	);
	/* CLoc */
	pointerMap[Sigs::CLoc_FindText] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 8B ?? ?? 8B ?? ?? 85 FF",
		"55 8B EC 83 E4 ?? 83 EC ?? A1 34 ?? ?? ?? 33 C4 ?? 44 ?? ?? 53 8B ?? ?? 56 57 8B ?? ?? 8B"
	);
	pointerMap[Sigs::CLoc_GetText] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 8B ?? ?? 8B ?? ?? 8B ?? ?? ?? 75 ?? ?? 45",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 8B ?? ?? 8B ?? ?? 8B ?? ?? ?? 45 ?? ?? ?? ?? ?? 85 C9 75 ?? ?? 4F ?? 75 ?? 50"
	);
	/* CPlayerProfileV1 */
	pointerMap[Sigs::CPlayerProfileV1_InternalLoad] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 65 ?? 8B D9 ?? 9D ?? ?? ?? ?? ?? 9D ?? ?? ?? ?? 8B ?? ?? ?? BD",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 65 ?? 8B F9 ?? BD ?? ?? ?? ?? 8B ?? ?? ?? BD"
	);
	pointerMap[Sigs::CPlayerProfileV1_Save] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 B8 28 ?? ?? ?? E8 ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 B8 D8"
	);
	/* CPopupScreenBase */
	pointerMap[Sigs::CPopupScreenBase_VTable] = h_rtti::get_vtable_pointer("CPopupScreenBase");
	pointerMap[Sigs::CPopupScreenBase_CCTOR] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? ?? 75 ?? ?? 45 ?? ?? ?? ?? ?? 8D ?? ?? ?? ?? ?? 50",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? ?? 75 ?? 8D ?? ?? ?? 45 ?? ?? ?? ?? ?? 50"
	);
	pointerMap[Sigs::CPopupScreenBase_AddObject] = Signatures::FindFirst(1,
		"55 8B EC 53 8B D9 B8 67 ?? ?? ?? 8B"
	);
	pointerMap[Sigs::CPopupScreenBase_AddNavButton] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 45 ?? ?? ?? ?? ?? 33"
	);
	/* CProjectile */
	pointerMap[Sigs::CProjectile_CCTOR_A] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? ?? ?? ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8D ?? ?? ?? ?? ?? ?? 55 ?? ?? 02 ?? ?? ?? ?? ?? 45 ?? ?? ?? 02 ?? ?? ?? ?? ?? 42 ?? ?? ?? ?? ?? ?? 45 ?? ?? 8D ?? ?? ?? ?? ?? ?? 45 ?? ?? 00 ?? ?? ?? ?? ?? 45 ?? ?? ?? 00 ?? ?? ?? ?? ?? 40 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 07 ?? ?? ?? ?? ?? 02 ?? ?? ?? ?? ?? 00 ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? 8D ?? ?? ?? ?? ?? ?? 75 ?? ?? 06 ?? ?? ?? ?? ?? 46 ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? ?? 06 ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? C7 ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? F3 ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? ?? F3 ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? ?? ?? 7F ?? ?? 75 ?? 8D ?? ?? ?? 47 ?? ?? 8B ?? 3B C2 74 ?? 85 C0 74 ?? 8D ?? ?? EB ?? 33 C9 E8 ?? ?? ?? ?? 8B ?? 3B C2 75 ?? 68 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 C4 ?? ?? 45 ?? ?? 45 ?? ?? 8B"
	);
	pointerMap[Sigs::CProjectile_CCTOR_B] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? ?? ?? ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8D ?? ?? ?? ?? ?? ?? 55 ?? ?? 02 ?? ?? ?? ?? ?? 45 ?? ?? ?? 02 ?? ?? ?? ?? ?? 42 ?? ?? ?? ?? ?? ?? 45 ?? ?? 8D ?? ?? ?? ?? ?? ?? 45 ?? ?? 00 ?? ?? ?? ?? ?? 45 ?? ?? ?? 00 ?? ?? ?? ?? ?? 40 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 07 ?? ?? ?? ?? ?? 02 ?? ?? ?? ?? ?? 00 ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? 8D ?? ?? ?? ?? ?? ?? 75 ?? ?? 06 ?? ?? ?? ?? ?? 46 ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? ?? 06 ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? C7 ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? F3 ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? ?? F3 ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? ?? ?? 7F ?? ?? 75 ?? 8D ?? ?? ?? 47 ?? ?? 8B ?? 3B C2 74 ?? 85 C0 74 ?? 8D ?? ?? EB ?? 33 C9 E8 ?? ?? ?? ?? 8B ?? 3B C2 75 ?? 68 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 C4 ?? ?? 45 ?? ?? 45 ?? ?? 8D ?? ?? 6A ?? 6A ?? 51 8B C8 ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B F0 ?? 45 ?? ?? 8B ?? ?? ?? B7 ?? ?? ?? ?? ?? 45 ?? ?? ?? 45 ?? ?? 85 C0 74 ?? 8D ?? ?? ?? 86 ?? ?? ?? ?? 51 8D ?? ?? 51 50 8B CE E8 ?? ?? ?? ?? 8B ?? ?? 3B"
	);
	pointerMap[Sigs::CProjectile_CCTOR_C] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? ?? ?? ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8D ?? ?? ?? ?? ?? ?? 55 ?? ?? 02 ?? ?? ?? ?? ?? 45 ?? ?? ?? 02 ?? ?? ?? ?? ?? 42 ?? ?? ?? ?? ?? ?? 45 ?? ?? 8D ?? ?? ?? ?? ?? ?? 45 ?? ?? 00 ?? ?? ?? ?? ?? 45 ?? ?? ?? 00 ?? ?? ?? ?? ?? 40 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 07 ?? ?? ?? ?? ?? 02 ?? ?? ?? ?? ?? 00 ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? 8D ?? ?? ?? ?? ?? ?? 75 ?? ?? 06 ?? ?? ?? ?? ?? 46 ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? ?? 06 ?? 45 ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? C7 ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 87 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? F3 ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? ?? F3 ?? ?? ?? ?? ?? 0F ?? ?? ?? ?? ?? ?? ?? 7F ?? ?? 75 ?? 8D ?? ?? ?? 47 ?? ?? 8B ?? 3B C2 74 ?? 85 C0 74 ?? 8D ?? ?? EB ?? 33 C9 E8 ?? ?? ?? ?? 8B ?? 3B C2 75 ?? 68 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 C4 ?? ?? 45 ?? ?? 45 ?? ?? 8D ?? ?? 6A ?? 6A ?? 51 8B C8 ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B F0 ?? 45 ?? ?? 8B ?? ?? ?? B7 ?? ?? ?? ?? ?? 45 ?? ?? ?? 45 ?? ?? 85 C0 74 ?? 8D ?? ?? ?? 86 ?? ?? ?? ?? 51 8D ?? ?? 51 50 8B CE E8 ?? ?? ?? ?? 8B ?? ?? 8B"
	);
	pointerMap[Sigs::CProjectile_Clone] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 5D ?? 8B ?? ?? ?? ?? ?? ?? 75 ?? 68"
	);
	pointerMap[Sigs::CProjectile_Update] = Signatures::FindFirst(1,
		"55 8B EC 83 E4 ?? 83 EC ?? 53 56 8B F1 57 8B ?? ?? ?? ?? ?? 8B ?? ?? 8B"
	);
	/* CSettingsScreen */
	pointerMap[Sigs::CSettingsScreen_CCTOR] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? 83 EC ?? 8B CC ?? 65 ?? 6A ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? 68 ?? ?? ?? ?? ?? 01 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 06 ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? 86",
		"55 8B EC 51 56 83 EC ?? 8B F1 8B CC ?? 75 ?? 6A ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? 68 ?? ?? ?? ?? ?? 01 ?? E8 ?? ?? ?? ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? ?? 06 ?? ?? ?? ?? 8B C6 ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? 86"
	);
	pointerMap[Sigs::CSettingsScreen_InitLayout] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 9D ?? ?? ?? ?? ?? ?? ?? ?? 85 ?? ?? ?? ?? ?? ?? ?? ?? ?? 85 ?? ?? ?? ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 6A",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? ?? ?? ?? 85 ?? ?? ?? ?? ?? ?? ?? ?? ?? 85 ?? ?? ?? ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 6A"
	);
	/* CTextObject */
	pointerMap[Sigs::CTextObject_CCTOR_A] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8D"
	);
	pointerMap[Sigs::CTextObject_CCTOR_B] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 5D ?? 8B ?? ?? 8B ?? ?? ?? 5D ?? ?? 45 ?? E8",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? 8B ?? ?? 8B ?? ?? ?? 75 ?? ?? 45"
	);
	pointerMap[Sigs::CTextObject_CCTOR_C] = Signatures::FindFirst(2,
		//Kongregate
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? 8B ?? ?? 8B ?? ?? ?? 7D ?? ?? 45 ?? E8",
		//Steam
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 5D ?? ?? 5D ?? 8B"
	);
	/* CTowerFactory */
	pointerMap[Sigs::CTowerFactory_CCTOR] = Signatures::FindFirst(2,
		//Kongregate
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? BD ?? ?? ?? ?? ?? BD ?? ?? ?? ?? 83",
		//Steam
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? BD ?? ?? ?? ?? ?? BD ?? ?? ?? ?? ?? 45"
	);
	/* CUnzippedFile */
	pointerMap[Sigs::CUnzippedFile_CCTOR] = Signatures::FindFirst(2,
		"56 8B F1 8D ?? ?? ?? 06 ?? ?? ?? ?? E8 ?? ?? ?? ?? ?? 46 ?? ?? ?? ?? ?? 8B",
		"c7 01 ?? ?? ?? ?? 8b c1 c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c6 41 ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c3"
	);
	/* CWeapon */
	pointerMap[Sigs::CWeapon_Fire] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 8B ?? ?? 85"
	);
	/* CWeaponFactory */
	pointerMap[Sigs::CWeaponFactory_ParseTask] = Signatures::FindFirst(2,
		"53 8B DC 83 EC ?? 83 E4 ?? 83 C4 ?? 55 8B ?? ?? ?? 6C ?? ?? 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 53 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 65 ?? 8B F9 ?? BD ?? ?? ?? ?? 8B",
		"53 8B DC 83 EC ?? 83 E4 ?? 83 C4 ?? 55 8B ?? ?? ?? 6C ?? ?? 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 51 53 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 65 ?? 8B F9 8A"
	);
	/* CZipFile */
	pointerMap[Sigs::CZipFile_CCTOR] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 ?? 5D ?? E8 ?? ?? ?? ?? ?? 45",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? ?? 47 ?? ?? ?? ?? ?? ?? 47 ?? ?? ?? ?? ?? ?? 47"
	);
	pointerMap[Sigs::CZipFile_LoadFrom] = Signatures::FindFirst(2,
		//Kartridge
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? 8B ?? ?? 8B",
		//Steam
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B D9 8B ?? ?? 8B ?? ?? ?? 45"
	);
	pointerMap[Sigs::CZipFile_Open] = Signatures::FindFirst(1,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 8B ?? ?? E8"
	);
	/* IBasePointers */
	pointerMap[Sigs::IBasePointers_CCTOR] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 01 ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? ?? 41",
		"c7 01 ?? ?? ?? ?? 8b c1 c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? c3"
	);
	/* IScreenData */
	pointerMap[Sigs::IScreenData_VTable] = h_rtti::get_vtable_pointer("IScreenData");
	/* JsonObject */
	pointerMap[Sigs::JsonObject_ReadBoolProperty] = Signatures::FindFirst(1,
		"55 8b ec 6a ?? 68 ?? ?? ?? ?? 64 a1 ?? ?? ?? ?? 50 83 ec ?? 56 a1 ?? ?? ?? ?? 33 c5 50 8d 45 ?? 64 a3 ?? ?? ?? ?? 8b f1 83 ec ?? c7 45 ?? ?? ?? ?? ?? 8b cc 8d 45 ?? 6a ?? 6a ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? 50 c6 01 ?? e8 ?? ?? ?? ?? ff 75 ?? 8b ce e8 ?? ?? ?? ?? 8b 45 ?? 83 f8 ?? 72 ?? 6a ?? 40 50 ff 75 ?? e8 ?? ?? ?? ?? 83 c4 ?? 8b 4d ?? 64 89 0d ?? ?? ?? ?? 59 5e 8b e5 5d c2 ?? ?? cc cc cc cc cc cc cc cc cc cc cc 55 8b ec 6a ?? 68 ?? ?? ?? ?? 64 a1 ?? ?? ?? ?? 50 83 ec ?? 56 a1 ?? ?? ?? ?? 33 c5 50 8d 45 ?? 64 a3 ?? ?? ?? ?? 8b f1 83 ec ?? c7 45 ?? ?? ?? ?? ?? 8b cc 8d 45 ?? 6a ?? 6a ?? c7 41 ?? ?? ?? ?? ?? c7 41 ?? ?? ?? ?? ?? 50 c6 01 ?? e8 ?? ?? ?? ?? ff 75 ?? 8b ce e8 ?? ?? ?? ?? 8b 45 ?? 83 f8 ?? 72 ?? 6a ?? 40 50 ff 75 ?? e8 ?? ?? ?? ?? 83 c4 ?? 8b 4d ?? 64 89 0d ?? ?? ?? ?? 59 5e 8b e5 5d c2 ?? ?? cc cc cc cc cc cc cc cc cc cc cc 55 8b ec 6a"
	);
	pointerMap[Sigs::JsonObject_ReadIntProperty] = Signatures::FindFirst(1,
		"55 8b ec 6a ?? 68 ?? ?? ?? ?? 64 a1 ?? ?? ?? ?? 50 83 ec ?? 56 57 a1 ?? ?? ?? ?? 33 c5 50 8d 45 ?? 64 a3 ?? ?? ?? ?? 8b f1 8b 7d ?? c7 45 ?? ?? ?? ?? ?? 8d 4d"
	);
	/* Screens */
	pointerMap[Sigs::Screens_GetScreenForParadigm] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 8B ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 45 ?? ?? ?? ?? ?? 83",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 8B ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? 45"
	);
	/* ScriptedScreen */
	pointerMap[Sigs::ScriptedScreen_VTable] = h_rtti::get_vtable_pointer("ScriptedScreen");
	pointerMap[Sigs::ScriptedScreen_CCTOR] = Signatures::FindFirst(1,
		"55 8B EC 51 56 83 EC ?? 8B F1 8B CC ?? 75 ?? 6A ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? 68 ?? ?? ?? ?? ?? 01 ?? E8 ?? ?? ?? ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? ?? 06 ?? ?? ?? ?? 8B C6 ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86"
	);
	/* ScriptedScreenData */
	pointerMap[Sigs::ScriptedScreenData_VTable] = h_rtti::get_vtable_pointer("ScriptedScreenData");
	/* Unknown */
	pointerMap[Sigs::Unknown_WinMain] = Signatures::FindFirst(2,
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 65 ?? 8B ?? ?? 8B",
		"55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? A1 34 ?? ?? ?? 33 C5 ?? 45 ?? 53 56 57 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 65 ?? 8B ?? ?? 8D ?? ?? ?? ?? ?? 8B"
	);
	/* C/C++ Runtime */
	pointerMap[Sigs::CRT_operator_new] = Signatures::FindFirst(1,
		"55 8B EC EB"
	);
	pointerMap[Sigs::CRT_free] = Signatures::FindFirst(1,
		"55 8b ec ff 75 08 e8 f0 ff ff ff 59 5d c3"
	);

	for (int i = 0; i < (int)Sigs::SIGNATURE_COUNT; i++) {
		if (!GetAddressOf((Sigs)i)) {
			std::string_view enumName = magic_enum::enum_name((Sigs)i);
			printf("Failed to find sig '%s'\n", enumName.data());
		}
	}
}

void* Signatures::GetAddressOf(Sigs sig)
{
	if (!pointerMap.count(sig)) {
		printf("Failed to find sig '%d'", sig);
		return nullptr;
	}
	return pointerMap[sig];
}
