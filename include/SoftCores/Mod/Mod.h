#pragma once

#include <memory>
#include <vector>
#include "SoftCores/ModContext.h"

namespace SoftCores
{
	class	Feature
	{
	public:
		ModContext	*Context;

		explicit		Feature(ModContext *context);
		virtual			~Feature() = default;
		virtual void	Initialize();
	};

	class	Mod
	{
		std::vector<std::unique_ptr<Feature>>	Features;

	public:
		ModContext	*Context;

		explicit	Mod(ModContext *context);
		template <typename FeatureType>
		void		LoadFeature()
		{
			std::unique_ptr<FeatureType>	feat = std::make_unique<FeatureType>(Context);

			feat->Initialize();
			Features.push_back(std::move(feat));
		}
	};

}
