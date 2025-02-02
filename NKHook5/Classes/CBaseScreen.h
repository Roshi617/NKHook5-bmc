#pragma once

#include "../Utils.h"

#include "boost/shared_ptr"

#include "AssetType.h"
#include "CAssetBag.h"
#include "IBasePointers.h"
#include "IScreenData.h"
#include "SGameTime.h"
#include "Macro.h"

#include <ghstl/string>
#include <ghstl/vector>

#include <list>
#include <stdint.h>
#include <string>
#include <sstream>
#include <vector>

namespace NKHook5
{
	namespace Classes
	{
		using namespace Signatures;

		enum class eScreenState : int32_t {
			UNINITIALIZED,
			INITIALIZED,
			SHOWN,
			UNKNOWN_3,
			HIDDEN,
			DESTROYING,
			DESTROYED
		};
		static_assert(sizeof(eScreenState) == 0x4);

		class CBaseScreen
		{
		public:
			//Commented for vtable char pad_0000[4]; //0x0000
			IBasePointers basePointers; //0x0004
			void* unknown_constructed; //0x0070
			char pad_0074[4]; //0x0074
			std::vector<CBaseScreen*> children; //0x0078
			char pad_0084[4]; //0x0084
			std::string screenName; //0x0088
			CBaseScreen* parentScreen; //0x00A0
			eScreenState screenState; //0x00A4
			char pad_00A8[8]; //0x00A8
			boost::shared_ptr<CAssetBag> pAssetBag; //0x00B0


		public:
			CBaseScreen() {}
			CBaseScreen(std::string screenName) {
				ThisCall<void, CBaseScreen*, std::string&>(Sigs::CBaseScreen_CCTOR, this, screenName);
			};
			void OpenPopup(class CPopupScreenBase* popupScreen, IScreenData* popupData);
			void OpenPopup(class CPopupScreenBase* popupScreen, IScreenData* popupData, uint32_t* param_3);
			void StartUsingAsset(eAssetType type, std::string& assetName);
			CBaseScreen* GetScreen(std::string screenName);

			virtual ~CBaseScreen() {};
			virtual void _PreloadAssets() {};
			virtual void Init(IScreenData* screenData) {};
			virtual void Uninit() {};
			virtual void Show() {};
			virtual void Hide() {};
			virtual void ApplicationWillResignActive() {};
			virtual void ApplicationWillTerminate() {};
			virtual void ApplicationDidBecomeActive() {};
			virtual void SelectButtonPressed() {};
			virtual void BackButtonPressed() {};
			virtual void ScreenResized() {};
			virtual std::string ChildScreenClosed(std::string screenName, bool param_2) { return screenName; };
			virtual void BatteryLevelDidChange() {};
			virtual void ProcessInit() {};
			virtual void ProcessUninit() {};
			virtual void Process() {};
			virtual void Input(SGameTime* pGameTime) {};
			virtual void Draw() {};
			virtual void DrawOverlay() {};
			virtual bool AllAssetsLoaded() { return false; };
			virtual void SetupPointers(CBaseScreen* child) {};
			virtual void RemoveScreen(CBaseScreen* child) {};
			virtual void PrintTree(int param_1, std::stringstream outstream) {};
		};

		static_assert(sizeof(boost::shared_ptr<CAssetBag>) == 0x8);
		static_assert(sizeof(CBaseScreen) == 0x00B8);
	} // namespace Classes

} // namespace NKHook5
