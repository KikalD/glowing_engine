#include "scene.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "log.hpp"

namespace lve
{
	void lve::lveScene::clear()
{
		movingObjects.clear();
		fixObjects.clear();
}
	void lveScene::loadScene(std::string path, LveDevice &lveDevice)
	{
		lveScene::clear();
		try
		{
			std::vector<std::string> lines;
			std::ifstream myfile(path);
			if (myfile.is_open()) {
				while (myfile.good()) {
					std::string line;
					myfile >> line;
					lines.push_back(line);
					line.clear();
				}

				for (std::string string : lines)
				{
					std::vector<std::string> vector;
					const char delimiter = '#';
					int i = 0;
					int i2 = 1;
					for(char ch : string)
					{
						if (ch == delimiter)
						{
							i2 += 1;
						}
						else
						{
							if (i == i2)
							{
								vector[i - 1] += ch;
							}
							else
							{
								i = i2;
								std::string ss;
								ss = ch;
								vector.push_back(ss);
							}
						}
					}

					std::vector<float> floats;
					int skip1 = 0;
					for (std::string str : vector)
					{
						if (skip1 != 0)
						{
							floats.push_back(std::stof(str));
							
						}
						skip1 += 1;
					}

					if (vector[0] == "light")
					{
						addLight(floats);
					}
					else
					{
						addObject(vector[0], floats, lveDevice);
					}
				}
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "	" << e.what() << std::endl;
		}
	}
	void lveScene::addObject(std::string path ,std::vector<float> floats, LveDevice &lveDevice)
	{
		std::shared_ptr<LveModel> lveModel =
			LveModel::createModelFromFile(lveDevice, path);
		auto model = LveGameObject::createGameObject();
		model.model = lveModel;
		model.transform.translation = { floats[0], floats[1], floats[2] };
		model.transform.scale = { floats[3], floats[4], floats[5] };
		model.transform.rotation = { floats[6],floats[7], floats[8] };
		if (floats.size() > 9)
		{
			//function to load the textures
		}
		fixObjects.emplace(model.getId(), std::move(model));
	}
	void lveScene::addLight(std::vector<float> floats)
	{
		auto light = LveGameObject::makePointLight(floats[6]);
		light.color = { floats[0],floats[1],floats[2] };
		light.transform.translation = { floats[3], floats[4], floats[5] };
		fixObjects.emplace(light.getId(), std::move(light));
	}
}


