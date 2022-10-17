#pragma once

#include "../Utils.h"

#include "AssetType.h"
#include "IBasePointers.h"
#include "IScreenData.h"
#include "Macro.h"

#include <ghstl/string>
#include <ghstl/vector>

#include <stdint.h>
#include <string>

namespace NKHook5
{
	namespace Classes
	{
		using namespace Signatures;

		class CBaseScreen
		{
		public:
			//char vtable[4]; //0x0000
			IBasePointers basePointers; //0x0004
			char pad_0070[12]; //0x0070
			ghstl::vector<CBaseScreen*> children; //0x007C
			char pad_0088[4]; //0x0088
			ghstl::string screenName; //0x008C
			CBaseScreen* parentScreen; //0x00A4
			char pad_00A8[8]; //0x00A8

		public:
			CBaseScreen(ghstl::string* screenName) {
				ThisCall<void, CBaseScreen*, ghstl::string*>(Sigs::CBaseScreen_CCTOR, this, screenName);
			};
			void OpenPopup(class CPopupScreenBase* popupScreen, IScreenData* popupData, uint32_t* param_3);
			void StartUsingAsset(eAssetType type, std::string& assetName);
			virtual ~CBaseScreen() {};
		};

		static_assert(sizeof(CBaseScreen) == 0x00B0);
	} // namespace Classes

} // namespace NKHook5
