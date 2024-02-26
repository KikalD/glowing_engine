#pragma once
#include "scene.hpp"

namespace lve {

	class gameLoop
	{
	public:
		lveScene scene;
		void loop();
		void setScene(lveScene scene);
	private:
	};

}
