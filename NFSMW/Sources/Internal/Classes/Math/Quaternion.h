#pragma once

#include "../../Includes.h"
#include "Vector3.h"

class Quaternion
{
public:
	/* Constructors */
	Quaternion()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Quaternion(float x, float y, float z, float w)
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
	void SetAxisXYZW(Quaternion xyzw);

	bool HasSameValues(float x, float y, float z, float w);

	/* Extra calculations */
	void Normalize();
	
	static Quaternion MultiplyQuaternions(Quaternion q1, Quaternion q2);
	static Quaternion AxisAngleToQuaternion(float angle, Vector3 xyz);
private:
	float x;
	float y;
	float z;
	float w;
};