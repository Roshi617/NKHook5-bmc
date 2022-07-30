#pragma once

#include <string>
#include <magic_enum.hpp>

namespace NKHook5 {
	namespace Signatures {
		enum class Sigs {
			/* CApp */
			/* CAssetBag */
			/* CBaseFactory */
			/* CBasePositionableObject */
			CBasePositionableObject_AssignParent,
			CBasePositionableObject_SetComplete,
			/* CBaseScreen */
			CBaseScreen_CCTOR,
			CBaseScreen_OpenPopup,
			/* CBaseTower */
			/* CBloonsBaseScreen */
			CBloonsBaseScreen_CCTOR,
			/* CBloonsTD5Game */
			CBloonsTD5Game_CCTOR,
			CBloonsTD5Game_LoadAssets,
			/* CFlagStringConvertor */
			CFlagStringConvertor_FlagToString,
			CFlagStringConvertor_LoadCategory,
			CFlagStringConvertor_StringToFlag,
			/* CFont */
			/* CFontManager */
			CFontManager_GetFont,
			/* CGameSystemPointers */
			/* CLoc */
			CLoc_FindText,
			CLoc_GetText,
			/* Color */
			/* CPopupScreenBase */
			CPopupScreenBase_CCTOR,
			CPopupScreenBase_AddObject,
			/* CReferenceCounted */
			/* CRenderableTextureObject */
			/* CScreenManager */
			/* CSettingsScreen */
			CSettingsScreen_CCTOR,
			CSettingsScreen_InitLayout,
			/* CTextObject */
			CTextObject_CCTOR_A,
			CTextObject_CCTOR_B,
			CTextObject_CCTOR_C,
			/* CTowerFactory */
			CTowerFactory_CCTOR,
			/* CUnzippedFile */
			CUnzippedFile_CCTOR,
			/* CXmlFontImporter */
			/* CZipFile */
			CZipFile_CCTOR,
			CZipFile_Open,
			CZipFile_LoadFrom,
			/* GLRenderLayer */
			/* IBasePointers */
			IBasePointers_CCTOR,
			/* IFontImporter */
			/* IScreenData */
			/* ITextureLoaderListener */
			/* Matrix16F */
			/* Screens */
			Screens_GetScreenForParadigm,
			/* Vec2F */
			/* Vec3F */
			/* ZipCpp */
			SIGNATURE_COUNT
		};

		void* FindFirst(int count, ...);
		void FindAll();
		void* GetAddressOf(Sigs sig);
	}
}