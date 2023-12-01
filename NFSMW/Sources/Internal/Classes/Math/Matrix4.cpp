#include "Matrix4.h"

Vector4 Matrix4::GetMatrixX()
{
	return this->x;
}

Vector4 Matrix4::GetMatrixY()
{
	return this->y;
}

Vector4 Matrix4::GetMatrixZ()
{
	return this->z;
}

Vector4 Matrix4::GetMatrixW()
{
	return this->w;
}

void Matrix4::SetMatrixX(Vector4 x)
{
	this->x = x;
}

void Matrix4::SetMatrixY(Vector4 y)
{
	this->y = y;
}

void Matrix4::SetMatrixZ(Vector4 z)
{
	this->z = z;
}

void Matrix4::SetMatrixW(Vector4 w)
{
	this->w = w;
}

void Matrix4::SetMatrixXYZW(Vector4 x, Vector4 y, Vector4 z, Vector4 w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void Matrix4::SetMatrixXYZW(Matrix4 xyzw)
{
	*this = xyzw;
}

bool Matrix4::HasSameValues(Vector4 x, Vector4 y, Vector4 z, Vector4 w)
{
	return (this->x.HasSameValues(x.GetAxisX(), x.GetAxisY(), x.GetAxisZ(), x.GetAxisW())
		 && this->y.HasSameValues(y.GetAxisX(), y.GetAxisY(), y.GetAxisY(), y.GetAxisW())
		 && this->z.HasSameValues(z.GetAxisX(), z.GetAxisY(), z.GetAxisZ(), z.GetAxisW())
		 && this->w.HasSameValues(w.GetAxisX(), w.GetAxisY(), w.GetAxisZ(), w.GetAxisW()));
}