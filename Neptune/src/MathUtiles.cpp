#include "MathUtiles.h"

Vector2 RectGetPosition(Rectangle rect)
{
	return { (float)rect.width, (float)rect.height };
}

Vector2 RectGetSize(Rectangle rect)
{
	return { (float)rect.x, (float)rect.y };
}