#pragma once
#include <raylib.h>

struct RenderView
{
	RenderTexture2D renderTexture;
	Color baseColor;

	RenderView(int Width, int Height);
	~RenderView();

	void Begin();
	void End();

	void Draw(Rectangle rect);
	void Draw(int x, int y, int width, int height);

private:
	Rectangle source;
	int width;
	int height;
};

