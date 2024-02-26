#pragma once

#include "lve_game_object.hpp"
#include "lve_window.hpp"
#include <glm/fwd.hpp>
#include <Windows.h>

namespace lve {
class KeyboardMovementController {
 public:
  struct KeyMappings {
    int moveLeft = GLFW_KEY_A;
    int moveRight = GLFW_KEY_D;
    int moveForward = GLFW_KEY_W;
    int moveBackward = GLFW_KEY_S;
    int moveUp = GLFW_KEY_E;
    int moveDown = GLFW_KEY_Q;
    int look = GLFW_MOUSE_BUTTON_MIDDLE;
  };

  void moveInPlaneXZ(GLFWwindow* window, float dt, LveGameObject& gameObject);
  KeyMappings keys{};
  float moveSpeed{3.f};
  float lookSpeed{1.5f};
};
}  // namespace lve