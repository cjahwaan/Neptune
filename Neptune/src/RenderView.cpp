#include "RenderView.h"

RenderView::RenderView(int Width, int Height)
{
	width = Width;
	height = Height;
	source = { 0, 0, (float)width, (float)height };
	renderTexture = LoadRenderTexture(width, height);
	baseColor = WHITE;
}

RenderView::~RenderView()
{
	UnloadRenderTexture(renderTexture);
}

void RenderView::Begin()
{
	BeginTextureMode(renderTexture);
}

void RenderView::End()
{
	EndTextureMode();
}

void RenderView::Draw(Rectangle rect)
{
	DrawTexturePro(renderTexture.texture, source, rect, { 0, 0 }, 0, baseColor);
}

void RenderView::Draw(int x, int y, int width, int height)
{
	DrawTexturePro(renderTexture.texture, source, 
		{ (float)x, (float)y, (float)width, (float)height }, { 0, 0 }, 0, baseColor);
}
