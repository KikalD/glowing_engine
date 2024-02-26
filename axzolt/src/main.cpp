
#include "first_app.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <windows.h>



int main() {
  lve::FirstApp app{};

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
    Sleep(1000);
  }

  return EXIT_SUCCESS;
}