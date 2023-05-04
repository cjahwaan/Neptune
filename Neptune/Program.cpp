#include "Resource.h"

int main()
{
	Window window = { 1080, 720, "Neptune" };
	InitWindow(window.width, window.height, window.title.c_str());

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		GUI::Label("hello dudes", {0, 0, 12, 12}, 12, BLACK);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}