#pragma once

#include <vector>

#include "SoftCores/Config.h"
#include "SoftCores/Util/Logger.h"

namespace SoftCores
{
	class Feature
	{
	public:
		Util::Logger	*Logger;
		Config			*Config;

		Feature(Util::Logger *logger, SoftCores::Config *config);
		virtual			~Feature() = default;
		virtual void	Initialize();
	};

	class Mod
	{
		std::vector<Feature*>	Features;

	public:
		Util::Logger	*Logger;
		Config			*Config;

		Mod(Util::Logger *logger, SoftCores::Config *config);
		~Mod();
		template <typename FeatureType>
		void	LoadFeature()
		{
			Feature	*feat = new FeatureType(Logger, Config);
			feat->Initialize();
			Features.push_back(feat);
		}
	};

}
