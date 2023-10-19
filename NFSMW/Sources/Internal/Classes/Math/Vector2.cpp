#include "Vector2.h"

float Vector2::GetAxisX()
{
	return this->x;
}

float Vector2::GetAxisY()
{
	return this->y;
}

void Vector2::SetAxisX(float x)
{
	this->x = x;
}

void Vector2::SetAxisY(float y)
{
	this->y = y;
}

void Vector2::SetAxisXY(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::SetAxisXY(Vector2 xy)
{
	this->x = xy.x;
	this->y = xy.y;
}

bool Vector2::HasSameValues(float x, float y)
{
	return (this->x == x && this->y == y);
}