#include "Vector3.h"

float Vector3::GetAxisZ()
{
	return this->z;
}

void Vector3::SetAxisZ(float z)
{
	this->z = z;
}

void Vector3::SetAxisXYZ(float x, float y, float z)
{
	this->SetAxisXY(x, y);
	this->z = z;
}

void Vector3::SetAxisXYZ(Vector3 xyz)
{
	this->SetAxisXY(xyz);
	this->z = xyz.z;
}

bool Vector3::HasSameValues(float x, float y, float z)
{
	return (this->GetAxisX() == x && this->GetAxisY() == y && this->GetAxisZ() == z);
}