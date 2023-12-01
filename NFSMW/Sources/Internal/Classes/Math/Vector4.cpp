#include "Vector4.h"

float Vector4::GetAxisX()
{
	return this->x;
}

float Vector4::GetAxisY()
{
	return this->y;
}

float Vector4::GetAxisZ()
{
	return this->z;
}

float Vector4::GetAxisW()
{
	return this->w;
}

void Vector4::SetAxisX(float x)
{
	this->x = x;
}

void Vector4::SetAxisY(float y)
{
	this->y = y;
}

void Vector4::SetAxisZ(float z)
{
	this->z = z;
}

void Vector4::SetAxisW(float w)
{
	this->w = w;
}

void Vector4::SetAxisXYZW(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void Vector4::SetAxisXYZW(Vector4 xyzw)
{
	*this = xyzw;
}

bool Vector4::HasSameValues(float x, float y, float z, float w)
{
	return (this->GetAxisX() == x 
		 && this->GetAxisY() == y 
		 && this->GetAxisZ() == z
		 && this->GetAxisW() == w);
}