#pragma once
#include "lve_game_object.hpp"
#include "lve_Texture.hpp"
#include <string>

namespace lve {
	class LveObjectSet
	{
	public:
		using id_t = unsigned int;
		using Map = std::unordered_map<id_t, LveTexture>;

		LveGameObject::Map fixObjects;
		LveGameObject::Map movingObjects;
		void clear();
		void loadSet(std::string path, LveDevice &lveDevice);
		void addObject(std::string path, std::vector<float> floats, LveDevice &lveDevice);
		void addLight(std::vector<float> floats);
	};
}