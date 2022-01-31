#pragma once
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <vector>
#include "Camera.h"
#include "Scene.h"




class Window
{
private:
	GLFWwindow* window;

	bool mouse = false;
	bool mouse2 = false;
	bool new_click = true;
public:
	Scene* actual_scene;
	Window();
	float fov = 45.0f;
	void notifyNew(float fov);
	void notifyMouse(double x, double y,bool new_mouse);
	void notifyChangeSize(int width, int height);

	GLFWwindow* getWindow();

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};

