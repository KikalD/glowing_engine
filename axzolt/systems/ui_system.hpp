#pragma once

#include "../src/lve_camera.hpp"
#include "../src/lve_device.hpp"
#include "../src/lve_frame_info.hpp"
#include "../src/lve_game_object.hpp"
#include "../src/lve_pipeline.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
class UiSystem {
 public:
     UiSystem(
      LveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
     ~UiSystem();

  UiSystem(const UiSystem&) = delete;
  UiSystem&operator=(const UiSystem&) = delete;

  void renderGameObjects(FrameInfo &frameInfo);

 private:
  void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
  void createPipeline(VkRenderPass renderPass);

  LveDevice &lveDevice;

  std::unique_ptr<LvePipeline> lvePipeline;
  VkPipelineLayout pipelineLayout;
};
}  // namespace lve
