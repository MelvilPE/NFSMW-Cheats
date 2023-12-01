#pragma once

#include "../../Includes.h"

#include "Vector2.h"

class Matrix2
{
public:
	/* Constructors */
	Matrix2()
	{
		this->x = Vector2();
		this->y = Vector2();
	}

	Matrix2(Vector2 x, Vector2 y)
	{
		this->x = x;
		this->y = y;
	}

	/* Getters */
	Vector2 GetMatrixX();
	Vector2 GetMatrixY();

	/* Setters */
	void SetMatrixX(Vector2 x);
	void SetMatrixY(Vector2 y);
	void SetMatrixXY(Vector2 x, Vector2 y);
	void SetMatrixXY(Matrix2 xy);

	bool HasSameValues(Vector2 x, Vector2 y);
private:
	Vector2 x;
	Vector2 y;
};