#include "Aplikace.h"
#include "Renderer.h"
#include "Translator.h"

Aplikace::Aplikace()
{
	this->win= new Window();
	
	this->run();
}

void Aplikace::run()
{
	glewExperimental = GL_TRUE;
	glewInit();

	this->printfInfo();
	
	
	this->win->actual_scene = new Scene();
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(this->win->getWindow()))
	{
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(this->win->getWindow());
		this->win->actual_scene->renderAll();
		glfwPollEvents();
		glfwSwapBuffers(this->win->getWindow());
		glfwPollEvents();
	}
	glfwDestroyWindow(this->win->getWindow());
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void Aplikace::printfInfo()
{

	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

void Aplikace::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		this->win->actual_scene->getCamera()->ProcessKeyboard(F, 1);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		this->win->actual_scene->getCamera()->ProcessKeyboard(B, 1);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		this->win->actual_scene->getCamera()->ProcessKeyboard(L, 1);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		this->win->actual_scene->getCamera()->ProcessKeyboard(R, 1);
}
