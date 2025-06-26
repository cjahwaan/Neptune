#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Vector2Int {
	int x, y;
};

struct Vector3 {
	float x, y, z;
};

typedef Vector2Int PointInt;
typedef Vector2Int SizeInt;

struct RectInt
{
	int width, height;
	int x, y;
};

struct Color
{
	float r, g, b, a;
};

namespace Neptune
{
	namespace Colors
	{
		static Color white{ 1, 1, 1, 1 };
		static Color red{ 1, 0, 0, 1 };
		static Color eggshell{ 0.9f, 0.9f, 0.9f, 1.f };
	}

	/* Initialize a window for rendering */
	void InitWindow(int width, int height, std::string title);

	/* Is window running */
	bool IsWindowRunning();

	/* Close window */
	void CloseWindow();

	/* Clear Color */
	void ClearColor(Color color);

	// Draw Rectangle
	void DrawRect(RectInt rect, Color color);
}
