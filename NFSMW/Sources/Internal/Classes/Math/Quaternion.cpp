#include "Quaternion.h"

float Quaternion::GetAxisX()
{
	return this->x;
}

float Quaternion::GetAxisY()
{
	return this->y;
}

float Quaternion::GetAxisZ()
{
	return this->z;
}

float Quaternion::GetAxisW()
{
	return this->w;
}

void Quaternion::SetAxisX(float x)
{
	this->x = x;
}

void Quaternion::SetAxisY(float y)
{
	this->y = y;
}

void Quaternion::SetAxisZ(float z)
{
	this->z = z;
}

void Quaternion::SetAxisW(float w)
{
	this->w = w;
}

void Quaternion::SetAxisXYZW(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void Quaternion::SetAxisXYZW(Quaternion xyzw)
{
	*this = xyzw;
}

bool Quaternion::HasSameValues(float x, float y, float z, float w)
{
	return (this->GetAxisX() == x 
		 && this->GetAxisY() == y 
		 && this->GetAxisZ() == z
		 && this->GetAxisW() == w);
}

void Quaternion::Normalize()
{
	float normalized = sqrt(this->w * this->w + this->x * this->x + this->y * this->y + this->z * this->z);
    this->w /= normalized;
    this->x /= normalized;
    this->y /= normalized;
    this->z /= normalized;
}

Quaternion Quaternion::MultiplyQuaternions(Quaternion q1, Quaternion q2)
{
    Quaternion result;
    result.SetAxisW(q1.GetAxisW() * q2.GetAxisW() 
		          - q1.GetAxisX() * q2.GetAxisX() 
		          - q1.GetAxisY() * q2.GetAxisY() 
		          - q1.GetAxisZ() * q2.GetAxisZ());

    result.SetAxisX(q1.GetAxisW() * q2.GetAxisX() 
		          + q1.GetAxisX() * q2.GetAxisW() 
		          + q1.GetAxisY() * q2.GetAxisZ() 
		          - q1.GetAxisZ() * q2.GetAxisY());

    result.SetAxisY(q1.GetAxisW() * q2.GetAxisY() 
		          - q1.GetAxisX() * q2.GetAxisZ() 
		          + q1.GetAxisY() * q2.GetAxisW() 
		          + q1.GetAxisZ() * q2.GetAxisX());

    result.SetAxisZ(q1.GetAxisW() * q2.GetAxisZ() 
		          + q1.GetAxisX() * q2.GetAxisY() 
		          - q1.GetAxisY() * q2.GetAxisX() 
		          + q1.GetAxisZ() * q2.GetAxisW());

    result.Normalize();
    return result;
}

Quaternion Quaternion::AxisAngleToQuaternion(float angle, Vector3 xyz)
{
    Quaternion result;
    float halfAngle = static_cast<float>(angle/2.0);
    float sinHalfAngle = sin(halfAngle);

    result.SetAxisW(cos(halfAngle));
    result.SetAxisX(sinHalfAngle * xyz.GetAxisX());
    result.SetAxisY(sinHalfAngle * xyz.GetAxisY());
    result.SetAxisZ(sinHalfAngle * xyz.GetAxisZ());

    result.Normalize();
    return result;
}