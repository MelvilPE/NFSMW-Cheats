#include "VehicleEntity.h"

Quaternion VehicleEntity::GetRotation()
{
	return this->rotation;
}

Vector3 VehicleEntity::GetPosition()
{
	return this->position;
}

Vector3 VehicleEntity::GetAppliedForces()
{
	return this->appliedForces;
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

void VehicleEntity::SetAppliedForces(Vector3 appliedForces)
{
	this->appliedForces = appliedForces;
}

void VehicleEntity::SetWeight(float weight)
{
	this->weight = weight;
}
