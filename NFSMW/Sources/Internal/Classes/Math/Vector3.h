#pragma once

#include "../../Includes.h"

class Vector3
{
public:
	/* Constructors */
	Vector3()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/* Getters */
	float GetAxisX();
	float GetAxisY();
	float GetAxisZ();

	/* Setters */
	void SetAxisX(float x);
	void SetAxisY(float y);
	void SetAxisZ(float z);
	void SetAxisXYZ(float x, float y, float z);
	void SetAxisXYZ(Vector3 xyz);

	bool HasSameValues(float x, float y, float z);
private:
	float x;
	float y;
	float z;
};