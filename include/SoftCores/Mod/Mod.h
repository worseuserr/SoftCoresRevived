#pragma once

#include <vector>

#include "SoftCores/Config.h"
#include "SoftCores/Util/Logger.h"

namespace SoftCores
{
	class	Feature
	{
	public:
		Util::Logger	*Logger;
		Config			*Config;

		Feature(Util::Logger *logger, SoftCores::Config *config);
		virtual			~Feature() = default;
		virtual void	Initialize();
	};

	class	Mod
	{
		std::vector<std::unique_ptr<Feature>>	Features;

	public:
		Util::Logger	*Logger;
		Config			*Config;

		Mod(Util::Logger *logger, SoftCores::Config *config);
		template <typename FeatureType>
		void	LoadFeature()
		{
			std::unique_ptr<FeatureType>	feat = std::make_unique<FeatureType>(Logger, Config);

			feat->Initialize();
			Features.push_back(std::move(feat));
		}
	};

}
