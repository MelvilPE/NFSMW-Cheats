#pragma once

#include "../../Includes.h"
#include "../../Classes/Math/Vector2.h"
#include "../../Classes/Math/Vector3.h"
#include "../../Classes/Math/Vector4.h"
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
    void* unknown4;
    Vector3 appliedForces;                                         
    float weight;                                                  
    void* unknown5;                                                
    void* unknown6;                                                
    void* unknown7;                                                
    float unknown8;                                                
    float unknown9;                                                
    float unknown10;                                               
    float unknown11;                                               
    void* unknown12;                                               
    Vector3 unknown13;
    void* unknown14;
    Vector3 unknown15;
    float unknown16;
    Vector3 unknown17;
    void* unknown18;
    Vector3 unknown19;
    float unknown20;
    float unknown21;
    Vector2 unknown22;
    void* unknown23;
    void* unknown24;
    void* unknown25;
    void* unknown26;
    float unknown27;
};