#pragma once

#include "../Util/NewFramework.h"
#include "Macro.h"

#include "CModifySpeedStatusEffect.h"
#include "CSprite.h"
#include "CTextureManager.h"

namespace NKHook5
{
	namespace Classes
	{
#define CGlueStatusEffect_VFuncCount 9
		class CGlueStatusEffect : public CModifySpeedStatusEffect, public CSprite
		{
		public:
			overload_new;

			CTextureManager* texMgr; //0x0138
			char pad_013C[4]; //0x013C
			float damageRate; //0x0140
			int32_t damageTimer; //0x0144
			char pad_0148[4]; //0x0148

			CGlueStatusEffect(CTextureManager* texMgr, bool detach, float speedScale, float damageRate, float damageTimer = 0.0f) : CSprite(nullptr, false, Vec2F(0, 0), true) {
				ThisCall<CGlueStatusEffect*, CGlueStatusEffect*, CTextureManager*, bool, float, float, float>(Sigs::CGlueStatusEffect_CCTOR, this, texMgr, detach, speedScale, damageRate, damageTimer);
			}
		}; //Size: 0x014C
		static_assert(sizeof(CGlueStatusEffect) == 0x14C);
	}
}