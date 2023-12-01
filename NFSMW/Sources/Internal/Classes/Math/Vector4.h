#pragma once

#include "../../Includes.h"

class Vector4
{
public:
	/* Constructors */
	Vector4()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	/* Getters */
	float GetAxisX();
	float GetAxisY();
	float GetAxisZ();
	float GetAxisW();

	/* Setters */
	void SetAxisX(float x);
	void SetAxisY(float y);
	void SetAxisZ(float z);
	void SetAxisW(float w);
	void SetAxisXYZW(float x, float y, float z, float w);
	void SetAxisXYZW(Vector4 xyzw);

	bool HasSameValues(float x, float y, float z, float w);
private:
	float x;
	float y;
	float z;
	float w;
};