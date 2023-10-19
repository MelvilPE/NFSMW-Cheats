#include "Vector3.h"

float Vector3::GetAxisX()
{
	return this->x;
}

float Vector3::GetAxisY()
{
	return this->y;
}

float Vector3::GetAxisZ()
{
	return this->z;
}

void Vector3::SetAxisX(float x)
{
	this->x = x;
}

void Vector3::SetAxisY(float y)
{
	this->y = y;
}

void Vector3::SetAxisZ(float z)
{
	this->z = z;
}

void Vector3::SetAxisXYZ(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::SetAxisXYZ(Vector3 xyz)
{
	this->x = xyz.x;
	this->y = xyz.y;
	this->z = xyz.z;
}

bool Vector3::IsSameLocation(float x, float y, float z)
{
	return (this->x == x && this->y == y && this->z == z);
}