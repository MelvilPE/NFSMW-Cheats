#include "Quaternion.h"

float Quaternion::GetRotationAxis()
{
	return this->rotationAxis;
}

Vector3 Quaternion::GetAxisXYZ()
{
	return this->xyz;
}

void Quaternion::SetRotationAxis(float rotationAxis)
{
	this->rotationAxis = rotationAxis;
}

void Quaternion::SetAxisXYZ(Vector3 xyz)
{
	this->xyz = xyz;
}