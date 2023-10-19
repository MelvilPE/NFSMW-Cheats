#pragma once

#include "../../Includes.h"
#include "Vector2.h"

class Vector3 : public Vector2
{
public:
	/* Constructors */
	Vector3() : Vector2()
	{
		this->z = 0.0f;
	}

	Vector3(float x, float y, float z) : Vector2(x, y)
	{
		this->z = z;
	}

	/* Getters */
	float GetAxisZ();

	/* Setters */
	void SetAxisZ(float z);
	void SetAxisXYZ(float x, float y, float z);
	void SetAxisXYZ(Vector3 xyz);

	bool HasSameValues(float x, float y, float z);
private:
	float z;
};