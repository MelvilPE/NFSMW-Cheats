#pragma once

#include "../../Includes.h"

#include "Vector4.h"

class Matrix4
{
public:
	/* Constructors */
	Matrix4()
	{
		this->x = Vector4();
		this->y = Vector4();
		this->z = Vector4();
		this->w = Vector4();
	}

	Matrix4(Vector4 x, Vector4 y, Vector4 z, Vector4 w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->z = w;
	}

	/* Getters */
	Vector4 GetMatrixX();
	Vector4 GetMatrixY();
	Vector4 GetMatrixZ();
	Vector4 GetMatrixW();

	/* Setters */
	void SetMatrixX(Vector4 x);
	void SetMatrixY(Vector4 y);
	void SetMatrixZ(Vector4 z);
	void SetMatrixW(Vector4 w);

	void SetMatrixXYZW(Vector4 x, Vector4 y, Vector4 z, Vector4 w);
	void SetMatrixXYZW(Matrix4 xyzw);

	bool HasSameValues(Vector4 x, Vector4 y, Vector4 z, Vector4 w);
private:
	Vector4 x;
	Vector4 y;
	Vector4 z;
	Vector4 w;
};