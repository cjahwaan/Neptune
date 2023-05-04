#include "Resource.h"

int main()
{
	Window window = { 1080, 720, "Neptune" };
	InitWindow(window.width, window.height, window.title.c_str());

	while (!WindowShouldClose())
	{

	}

	CloseWindow();
	return 0;
}