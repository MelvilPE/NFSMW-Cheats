#pragma once

#include "../../Includes.h"
#include "Vector3.h"

class Vector4 : public Vector3
{
public:
	/* Constructors */
	Vector4() : Vector3()
	{
		this->time = 0.0f;
	}

	Vector4(float x, float y, float z, float time) : Vector3(x, y, z)
	{
		this->time = time;
	}

	/* Getters */
	float GetTime();

	/* Setters */
	void SetTime(float time);

private:
	float time;
};