#include "Matrix2.h"

Vector2 Matrix2::GetMatrixX()
{
	return this->x;
}

Vector2 Matrix2::GetMatrixY()
{
	return this->y;
}

void Matrix2::SetMatrixX(Vector2 x)
{
	this->x = x;
}

void Matrix2::SetMatrixY(Vector2 y)
{
	this->y = y;
}

void Matrix2::SetMatrixXY(Vector2 x, Vector2 y)
{
	this->x = x;
	this->y = y;
}

void Matrix2::SetMatrixXY(Matrix2 xy)
{
	*this = xy;
}

bool Matrix2::HasSameValues(Vector2 x, Vector2 y)
{
	return (this->x.HasSameValues(x.GetAxisX(), x.GetAxisY())
		 && this->y.HasSameValues(y.GetAxisX(), y.GetAxisY()));
}