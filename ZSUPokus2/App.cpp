#include "App.h"

App::App()
{
	window = new Window();
	printf("imhere");
}

void App::run()
{
	printf("imhere");
	while (!glfwWindowShouldClose(this->window->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();
		glfwSwapBuffers(this->window->window);

		glfwPollEvents();
	}
	glfwDestroyWindow(this->window->window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
