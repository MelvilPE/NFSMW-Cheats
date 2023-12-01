#pragma once

#include "../../Includes.h"

#include "Vector3.h"

class Matrix3
{
public:
	/* Constructors */
	Matrix3()
	{
		this->x = Vector3();
		this->y = Vector3();
		this->z = Vector3();
	}

	Matrix3(Vector3 x, Vector3 y, Vector3 z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/* Getters */
	Vector3 GetMatrixX();
	Vector3 GetMatrixY();
	Vector3 GetMatrixZ();

	/* Setters */
	void SetMatrixX(Vector3 x);
	void SetMatrixY(Vector3 y);
	void SetMatrixZ(Vector3 z);

	void SetMatrixXYZ(Vector3 x, Vector3 y, Vector3 z);
	void SetMatrixXYZ(Matrix3 xyz);

	bool HasSameValues(Vector3 x, Vector3 y, Vector3 z);
private:
	Vector3 x;
	Vector3 y;
	Vector3 z;
};