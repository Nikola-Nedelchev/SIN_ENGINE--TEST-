#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

VkInstance instance;

int main()
{
	InitWindow();
	InitVulkan();
	SceneLoop();
	ExitApp();
}



int InitWindow(){
	register uint16_t WIDTH = 800;
	register uint16_t HEIGHT = 600;

	glfwInit();
	{
		GLFWwindow* window;

		glfwWindowHint(GLFW_CILENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "SIN ENGINE-[TEST]", NULL, NULL);
	}
}

int InitVulkan()
{
	CreateInstanse();//line
}

int CreateInstanse() 
		{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "SIN ENGINE";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "SIN ENGINE";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;

		createInfo.enabledLayerCount = 0;

		#ifdef DEBUG
		if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS) {
			printf("!!!failed to create instance!!!");
			exit(0);
		}
		#endif
	}



int SceneLoop()
{

	while (!glfwWindowShouldClose(window)) 
	{
		glfwPollEvents();
	}

}



void ExitApp() {
	vkDestroyInstance(instance, NULL);

	glfwDestroyWindow(window);

	glfwTerminate();

	exit(0);
}