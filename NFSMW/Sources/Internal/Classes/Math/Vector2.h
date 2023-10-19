#pragma once

#include "../../Includes.h"

class Vector2
{
public:
	/* Constructors */
	Vector2()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	/* Getters */
	float GetAxisX();
	float GetAxisY();

	/* Setters */
	void SetAxisX(float x);
	void SetAxisY(float y);
	void SetAxisXY(float x, float y);
	void SetAxisXY(Vector2 xy);

	bool HasSameValues(float x, float y);
private:
	float x;
	float y;
};