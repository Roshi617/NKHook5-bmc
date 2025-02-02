#pragma once

#include "CWeaponTask.h"
#include "Macro.h"

namespace NKHook5 {
	namespace Classes {
		class CCollectableTask : public CWeaponTask {
		public:
			char pad_0124[92]; //0x0124
		public:
			void GiveContentsAndDie() {
				return ThisCall<void, CCollectableTask*>(Sigs::CCollectableTask_GiveContentsAndDie, this);
			}
		};

		static_assert(sizeof(CCollectableTask) == 0x180);
	}
}