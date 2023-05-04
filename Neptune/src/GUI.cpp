#include "GUI.h"

bool GUI::IsButtonClicked(int mouseBtn, Rectangle rect)
{
	if(IsMouseButtonPressed(mouseBtn))
		return CheckCollisionPointRec(GetMousePosition(), rect);

	return false;
}

bool GUI::IsButtonHovered(int mouseBtn, Rectangle rect)
{
	return CheckCollisionPointRec(GetMousePosition(), rect);
}

bool GUI::IsButtonReleased(int mouseBtn, Rectangle rect)
{
	if (IsMouseButtonReleased(mouseBtn))
		return CheckCollisionPointRec(GetMousePosition(), rect);
	return false;
}

void GUI::Label(std::string label, Rectangle rect, int fontSize, Color color)
{
	DrawTextPro(GetFontDefault(), label.c_str(), RectGetPosition(rect), { 0, 0 }, 0, fontSize, 1, color);
}
