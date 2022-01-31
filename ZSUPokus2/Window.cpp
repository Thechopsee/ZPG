#include "Window.h"
#include <cstdlib>
#include <stdio.h>
#include "ObjectFactory.h"
Window::Window()
{

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);

	glfwSetCursorPosCallback(window, cursor_callback);

	glfwSetMouseButtonCallback(window, button_callback);

	glfwSetWindowFocusCallback(window, window_focus_callback);

	glfwSetWindowIconifyCallback(window, window_iconify_callback);

	glfwSetWindowSizeCallback(window, window_size_callback);

	glfwSetScrollCallback(window, scroll_callback); 
	glfwSetWindowUserPointer(window, (void*)this);
	


	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
}


void Window::notifyNew(float fov)
{
	this->actual_scene->getCamera()->ProcessMouseScroll(fov);
}
void Window::notifyMouse(double xpos,double ypos,bool new_mouse)
{
	if (this->mouse)
	{
		this->actual_scene->getCamera()->ProcessMouseMovement(xpos, ypos,new_mouse);
		this->new_click = false;
	}
	else if(this->mouse2)
	{
		GLbyte color[4];
		GLfloat depth;
		GLuint index;

		GLint x = (GLint)xpos;
		GLint y = (GLint)ypos;


		int newy = (this->actual_scene->getCamera()->win_height) - y;


		glReadPixels(x, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
		glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
		glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

		printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index % u\n", x, y, color[0], color[1], color[2], color[3], depth, index);

		//Mùžeme nastavit vybrané tìleso scena->setSelect(index-1);

		//Mùžeme vypoèíst pozici v globálním souøadném systému.  
		glm::vec3 screenX = glm::vec3(x, newy, depth);
		glm::mat4 view = this->actual_scene->getCamera()->GetViewMatrix();
		glm::mat4 projection = this->actual_scene->getCamera()->projectionMatrix;
		glm::vec4 viewPort = glm::vec4(0, 0, this->actual_scene->getCamera()->win_width, this->actual_scene->getCamera()->win_height);
		glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);

		printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);

		//this->actual_scene->createNewObject(ObjectFactory::fabricateObjekt(SPHERE, PHONG, glm::vec3(pos.x, pos.y, pos.z)));
		this->actual_scene->actionOnObject(index-1,pos.x,pos.y,pos.z);
	}
}

void Window::notifyChangeSize(int width, int height)
{
	this->actual_scene->getCamera()->win_height = height;
	this->actual_scene->getCamera()->win_width = width;
	this->actual_scene->getCamera()->calculatePerspective();
}

GLFWwindow* Window::getWindow()
{
	return this->window;
}

void Window::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Window::window_focus_callback(GLFWwindow* window, int focused)
{
	printf("window_focus_callback \n");
}

void Window::window_iconify_callback(GLFWwindow* window, int iconified)
{
	printf("window_iconify_callback \n");
}

void Window::window_size_callback(GLFWwindow* window, int width, int height)
{
	printf("resize %d, %d \n", width, height);
	Window* self = (Window*)glfwGetWindowUserPointer(window);
	self->notifyChangeSize(width, height);
	glViewport(0, 0, width, height);
}

void Window::cursor_callback(GLFWwindow* window, double x, double y)
{
	Window* self = (Window*)glfwGetWindowUserPointer(window);
	self->notifyMouse(x, y,self->new_click);
	
}

void Window::button_callback(GLFWwindow* window, int button, int action, int mode)
{
	Window* self = (Window*)glfwGetWindowUserPointer(window);
	if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_2)
	{
		self->mouse = true;
		
	}
	else if(action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_2)
	{
		self->mouse = false;
		self->new_click = true;
	}
	else if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_1)
	{
		self->mouse2 = true;

	}
	else if (action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_1)
	{
		self->mouse2 = false;
	}
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	
	Window* self = (Window*)glfwGetWindowUserPointer(window);
	float* datas=&self->fov;
	*datas -= (float)yoffset;
	if (*datas < 1.0f)
		*datas = 1.0f;
	if (*datas > 45.0f)
		*datas = 45.0f;
	self->notifyNew(self->fov);
}
