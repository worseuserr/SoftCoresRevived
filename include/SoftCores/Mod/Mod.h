#pragma once

#include <vector>

#include "SoftCores/ModContext.h"
#include "SoftCores/Util/Logger.h"

namespace SoftCores
{
	class	Feature
	{
	public:
		ModContext	*Context;

		Feature(ModContext *context);
		virtual			~Feature() = default;
		virtual void	Initialize();
	};

	class	Mod
	{
		std::vector<std::unique_ptr<Feature>>	Features;

	public:
		ModContext	*Context;

		Mod(ModContext *context);
		template <typename FeatureType>
		void	LoadFeature()
		{
			std::unique_ptr<FeatureType>	feat = std::make_unique<FeatureType>(Context);

			feat->Initialize();
			Features.push_back(std::move(feat));
		}
	};

}
