#pragma once

#include "../../Includes.h"
#include "Vector3.h"

class Quaternion
{
public:
	/* Constructors */
	Quaternion()
	{
		this->rotationAxis = 0.0f;
		this->xyz = Vector3();
	}

	Quaternion(float rotationAxis, float x, float y, float z)
	{
		this->rotationAxis = rotationAxis;
		this->xyz = Vector3(x, y, z);
	}

	Quaternion(float rotationAxis, Vector3 xyz)
	{
		this->rotationAxis = rotationAxis;
		this->xyz = xyz;
	}

	/* Getters */
	float GetRotationAxis();
	Vector3 GetAxisXYZ();

	/* Setters */
	void SetRotationAxis(float rotationAxis);
	void SetAxisXYZ(Vector3 xyz);

private:
	float rotationAxis;
	Vector3 xyz;
};