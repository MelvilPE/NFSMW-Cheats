#pragma once

#include "../../Includes.h"
#include "../../Classes/Math/Vector2.h"
#include "../../Classes/Math/Vector3.h"
#include "../../Classes/Math/Vector4.h"
#include "../../Classes/Math/Matrix4.h"
#include "../../Classes/Math/Quaternion.h"

class VehicleEntity
{
public:
    /* Getters */
    Quaternion GetRotation();
    Vector3 GetPosition();
    Vector3 GetAppliedForces();
    float GetWeight();

    /* Setters */
    void SetRotation(Quaternion rotation);
    void SetPosition(Vector3 position);
    void SetAppliedForces(Vector3 appliedForces);
    void SetWeight(float weight);

private:
    /* Dumped deduced memory types from ReClass.NET */
    Quaternion rotation;
    Vector3 position;
    void *unknown4;
    Vector3 appliedForces;
    float weight;
    Vector3 stuffRotation;
    float unknown8;
    Vector3 unknownArray;
    void *unknown12;
    Vector3 unknown13;
    BYTE unknown14A;
    bool reinitializeStuff;
    BYTE unknown14B;
    BYTE unknown14C;
    Vector3 unknown15;
    float unknown16;
    Matrix4 rotationMatrix;
};
