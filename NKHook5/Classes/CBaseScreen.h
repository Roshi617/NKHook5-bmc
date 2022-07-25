#ifndef NKHOOK5_CLASSES_CBASESCREEN
#define NKHOOK5_CLASSES_CBASESCREEN

#include "../Utils.h"
#include "Macro.h"
#include "IBasePointers.h"
#include "IScreenData.h"
#include <ghstl/string>

namespace NKHook5
{
	namespace Signatures {
		namespace CBaseScreen {
			static const char* SIG_CCTOR = "55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F9 ?? 7D ?? 8D ?? ?? E8 ?? ?? ?? ?? ?? 45";
			static const char* SIG_OPENPOPUP = "55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? ?? 0F ?? ?? ?? 8B F1 ?? 75 ?? 8B";
		};
	};

	namespace Classes
	{
		class CBaseScreen
		{
		public:
			//char vtable[4]; //0x0000
			IBasePointers basePointers; //0x0004
			char pad_0070[24]; //0x0070
			ghstl::string screenName; //0x0088
			char pad_00A0[4]; //0x00A0
			class CScreenManager* pCScreenManager; //0x00A4
			char pad_00A8[8]; //0x00A8

		public:
			CBaseScreen(ghstl::string* screenName) {
				ThisCall<void, CBaseScreen*, ghstl::string*>(Signatures::CBaseScreen::SIG_CCTOR, this, screenName);
			};
			void OpenPopup(class CPopupScreenBase* popupScreen, IScreenData* popupData, uint32_t* param_3);
			virtual ~CBaseScreen() {};
		};

		static_assert(sizeof(CBaseScreen) == 0x00B0);
	} // namespace Classes

} // namespace NKHook5

#endif /* NKHOOK5_CLASSES_CBASESCREEN */
