#include "VehicleEntity.h"

Quaternion VehicleEntity::GetRotation()
{
	return this->rotation;
}

Vector3 VehicleEntity::GetPosition()
{
	return this->position;
}

float VehicleEntity::GetWeight()
{
	return this->weight;
}

void VehicleEntity::SetRotation(Quaternion rotation)
{
	this->rotation = rotation;
}

void VehicleEntity::SetPosition(Vector3 position)
{
	this->position = position;
}

void VehicleEntity::SetWeight(float weight)
{
	this->weight = weight;
}
