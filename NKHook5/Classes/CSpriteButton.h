#pragma once

#include "CBaseButton.h"
#include "CSprite.h"

namespace NKHook5 {
	namespace Classes {
		class CSpriteButton : public CBaseButton, public CSprite {
		public:
		public:
			CSpriteButton() {

			}
		};

		static_assert(sizeof(CSpriteButton) == 0x1D4);
	}
}