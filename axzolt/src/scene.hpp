#pragma once
#include "lve_game_object.hpp"
#include "lve_Texture.hpp"
#include "lve_object_set.hpp"
#include <string>

namespace lve {
	class lveScene
	{
	public:
		LveGameObject::Map fixObjects;
		LveGameObject::Map movingObjects;
		LveObjectSet::Map FixObjectSets;
		LveObjectSet::Map MovingObjectSets;
		void clear();
		void loadScene(std::string path, LveDevice &lveDevice);
		void addObject(std::string path, std::vector<float> floats, LveDevice &lveDevice);
		void addLight(std::vector<float> floats);
	};
}