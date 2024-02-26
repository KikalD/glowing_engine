#pragma once

#include<vulkan/vulkan.h>
#include<unordered_map>
#include "lve_device.hpp"

namespace lve
{
	class LveTexture
	{		
	private:
		VkImage textureImage;
		VkDeviceMemory textureImageMemory;
		VkImageView textureImageView;
		VkSampler textureSampler;

		VkImageView createImageView(VkImage image, VkFormat format, LveDevice& device);
		void createTextureImageWiew(LveDevice& device);
		void createTextureImage(char const* filename, LveDevice& device);
		void createTextureSampler(LveDevice& device);

	public :
		LveDevice device;
		using id_t = unsigned int;
		using Map = std::unordered_map<id_t, LveTexture>;
		void loadTexture(char const* filename, LveDevice& device);
	};
}

