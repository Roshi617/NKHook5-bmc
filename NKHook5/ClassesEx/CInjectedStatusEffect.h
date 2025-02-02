#pragma once

#include "../Util/NewFramework.h"

#include "../Classes/CCompoundSprite.h"
#include "../Classes/CGlueStatusEffect.h"

namespace NKHook5
{
	using namespace NKHook5::Classes;
	namespace ClassesEx
	{
		class CInjectedStatusEffect : public CGlueStatusEffect
		{
		public:
			overload_new;

			bool adjustedGraphic = false;
			uint64_t injectedId = 0;
			std::string spriteInfo;
			std::string texture;
			bool exceptMoab = false;
			void** pVanillaVTable = nullptr;

			CInjectedStatusEffect(uint64_t injectedId, std::string spriteInfo, std::string texture, bool exceptMoab, CTextureManager* texMgr, bool detach, float speedScale, float damageRate, float damageTimer = 0.0f);
		};
	}
}