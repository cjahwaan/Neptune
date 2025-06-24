#include "../Neptune.h"

struct Vector2Int {
	int x, y;
};

typedef Vector2Int SizeInt;
typedef Vector2Int PointInt;

struct Context
{
	struct {
		std::string title;
		SizeInt display;
		SizeInt screen;
		SizeInt size;
		GLFWwindow* handle;
	}Window;
}Context;

void OpenGlInitWindow(int width, int height, std::string title) {
	if (!glfwInit())
	{
		exit(-1);
	}
	std::cout << "GLFW initialized\n";

	Context.Window.handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (Context.Window.handle == nullptr) {
		std::cout << "Could not create window\n";
		glfwTerminate();
		exit(-1);
	}
	std::cout << "Window Initialized\n";

	glfwMakeContextCurrent(Context.Window.handle);

	Context.Window.size = { width, height };
	Context.Window.title = title;
	Context.Window.display = {};
	Context.Window.screen = {};
}

void OpenGlUpdate() {
	glfwSwapBuffers(Context.Window.handle);
	glfwPollEvents();
}

void OpenGlCloseWindow() {
	glfwDestroyWindow(Context.Window.handle);
	glfwTerminate();
}

bool Update() {
	OpenGlUpdate();
	return !glfwWindowShouldClose(Context.Window.handle);
}

/* Public API */

void Neptune::InitWindow(int width, int height, std::string title) {
	OpenGlInitWindow(width, height, title);
}

bool Neptune::IsWindowRunning() {
	return Update();
}

void Neptune::CloseWindow() {
	OpenGlCloseWindow();
}

void Neptune::ClearColor(Neptune::Color color) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(color.r, color.g, color.b, color.a);
}
