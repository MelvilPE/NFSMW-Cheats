#include "Matrix3.h"

Vector3 Matrix3::GetMatrixX()
{
	return this->x;
}

Vector3 Matrix3::GetMatrixY()
{
	return this->y;
}

Vector3 Matrix3::GetMatrixZ()
{
	return this->z;
}

void Matrix3::SetMatrixX(Vector3 x)
{
	this->x = x;
}

void Matrix3::SetMatrixY(Vector3 y)
{
	this->y = y;
}

void Matrix3::SetMatrixZ(Vector3 z)
{
	this->z = z;
}

void Matrix3::SetMatrixXYZ(Vector3 x, Vector3 y, Vector3 z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Matrix3::SetMatrixXYZ(Matrix3 xyz)
{
	*this = xyz;
}

bool Matrix3::HasSameValues(Vector3 x, Vector3 y, Vector3 z)
{
	return (this->x.HasSameValues(x.GetAxisX(), x.GetAxisY(), x.GetAxisZ())
		 && this->y.HasSameValues(y.GetAxisX(), y.GetAxisY(), y.GetAxisY())
		 && this->z.HasSameValues(z.GetAxisX(), z.GetAxisY(), z.GetAxisZ()));
}