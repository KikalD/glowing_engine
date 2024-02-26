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
class PointLightSystem {
 public:
  PointLightSystem(
      LveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
  ~PointLightSystem();

  PointLightSystem(const PointLightSystem &) = delete;
  PointLightSystem &operator=(const PointLightSystem &) = delete;

  void update(FrameInfo &frameInfo, GlobalUbo &ubo);
  void render(FrameInfo &frameInfo);

 private:
  void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
  void createPipeline(VkRenderPass renderPass);

  LveDevice &lveDevice;

  std::unique_ptr<LvePipeline> lvePipeline;
  VkPipelineLayout pipelineLayout;
};
}  // namespace lve
