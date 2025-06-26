#include "../Neptune.h"

struct Context
{
	struct {
		std::string title;
		SizeInt display;
		SizeInt screen;
		SizeInt size;
		GLFWwindow* handle;
	}Window;

	struct {
		std::vector<Vector3> points;
		std::vector<int> indices;
		unsigned int vbo, vao, ebo;
	}MeshBatch;

	struct {
		glm::mat4 perspective;
	}Matrix;
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

	auto glew_error = glewInit();
	if (GLEW_OK != glew_error) {
		glfwTerminate();
		exit(-1);
	}

	Context.Window.size = { width, height };
	Context.Window.title = title;
	Context.Window.display = {};
	Context.Window.screen = {};

	Context.Matrix.perspective = glm::ortho(0, width, 0, height);
}

void OpenGlUpdate() {
	glfwSwapBuffers(Context.Window.handle);
	glfwPollEvents();
}

void OpenGlCloseWindow() {
	glfwDestroyWindow(Context.Window.handle);
	glfwTerminate();
}

void OpenGlClearColor(Color color) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(color.r, color.g, color.b, color.a);
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

void Neptune::ClearColor(Color color) {
	OpenGlClearColor(color);
}

void Neptune::DrawRect(RectInt rect, Color color) {
	// draw rect
	
}
