#pragma once

#include "Feature.h"

namespace DevKit {
	namespace Features {
		class Setup : public Feature {
		public:
			Setup();
			virtual std::string ActivatorArgs() override;
			virtual bool FlagOnly() override;
			virtual void Run(std::vector<std::string> args) override;
		};
	}
}