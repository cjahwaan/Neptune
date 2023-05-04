#pragma once
#include <iostream>
#include <raylib.h>
#include "MathUtiles.h"

struct GUI
{
	static bool IsButtonHovered(int mouseBtn, Rectangle rect);
	static bool IsButtonClicked(int mouseBtn, Rectangle rect);
	static bool IsButtonReleased(int mouseBtn, Rectangle rect);
	static void Label(std::string label, Rectangle rect, int fontSize, Color color);
};

