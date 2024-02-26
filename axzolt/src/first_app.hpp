#pragma once

#include "lve_descriptors.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_renderer.hpp"
#include "lve_window.hpp"
#include "scene.hpp"
#include "gameloop.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
class FirstApp {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  FirstApp();
  ~FirstApp();

  FirstApp(const FirstApp &) = delete;
  FirstApp &operator=(const FirstApp &) = delete;

  enum {
	  ENGINEMODE = 0,
	  GAMEMODE = 0,
  };

  void run();
  void addStaticObject(std::vector < std::string> vector);

 private:

  void loadGameObjects();

  LveWindow lveWindow{WIDTH, HEIGHT, "WhoAreYou??"};
  LveDevice lveDevice{lveWindow};
  LveRenderer lveRenderer{lveWindow, lveDevice};

  // note: order of declarations matters
  std::unique_ptr<LveDescriptorPool> globalPool{};
  lveScene scene;
  gameLoop loop;
};
}  // namespace lve
