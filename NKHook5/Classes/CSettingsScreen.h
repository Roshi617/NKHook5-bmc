#ifndef NKHOOK5_CLASSES_CSETTINGSSCREEN
#define NKHOOK5_CLASSES_CSETTINGSSCREEN

#include "Macro.h"
#include "CPopupScreenBase.h"

namespace NKHook5
{
	namespace Signatures {
		namespace CSettingsScreen {
			static const char* SIG_CCTOR = "55 8B EC 6A ?? 68 ?? ?? ?? ?? 64 ?? ?? ?? ?? ?? 50 83 EC ?? 56 A1 34 ?? ?? ?? 33 C5 50 8D ?? ?? ?? A3 ?? ?? ?? ?? 8B F1 ?? 75 ?? 83 EC ?? 8B CC ?? 65 ?? 6A ?? ?? 41 ?? ?? ?? ?? ?? ?? 41 ?? ?? ?? ?? ?? 68 ?? ?? ?? ?? ?? 01 ?? E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ?? 06 ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? ?? ?? ?? 86 ?? ?? ?? ?? ?? ?? 86";
		}
	};

	namespace Classes
	{
		ghstl::string* settingScreen = new ghstl::string("SettingsScreen");
		class CSettingsScreen : public CPopupScreenBase
		{
		private:
		public:
			CSettingsScreen(CGameSystemPointers* pCGameSystemPointers) : CPopupScreenBase(pCGameSystemPointers, settingScreen) {
				ThisCall<CSettingsScreen*, CSettingsScreen*, CGameSystemPointers*>(Signatures::CSettingsScreen::SIG_CCTOR, this, pCGameSystemPointers);
			}
			virtual ~CSettingsScreen() {};
		};
	} // namespace Classes

} // namespace NKHook5


#endif /* NKHOOK5_CLASSES_CSETTINGSSCREEN */