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
    float GetWeight();

    /* Setters */
    void SetRotation(Quaternion rotation);
    void SetPosition(Vector3 position);
    void SetWeight(float weight);

private:
    /* Dumped deduced memory types from ReClass.NET */
    Quaternion rotation;                                           //0x0000
    Vector3 position;                                              //0x0010
    void* unknown1;                                                //0x001C
    void* unknown2;                                                //0x0020
    void* unknown3;                                                //0x0024
    void* unknown4;                                                //0x0028
    float weight;                                                  //0x002C
    void* unknown5;                                                //0x0030
    void* unknown6;                                                //0x0034
    void* unknown7;                                                //0x0038
    float unknown8;                                                //0x003C
    float unknown9;                                                //0x0040
    float unknown10;                                               //0x0044
    float unknown11;                                               //0x0048
    void* unknown12;                                               //0x004C
    Vector3 unknown13;                                             //0x0050
    void* unknown14;                                               //0x005C
    Vector3 unknown15;                                             //0x0060
    float unknown16;                                               //0x006C
    Vector3 unknown17;                                             //0x0070
    void* unknown18;                                               //0x007C
    Vector3 unknown19;                                             //0x0080
    float unknown20;                                               //0x008C
    float unknown21;                                               //0x0090
    Vector2 unknown22;                                             //0x0094
    void* unknown23;                                               //0x009C
    void* unknown24;                                               //0x00A0
    void* unknown25;                                               //0x00A4
    void* unknown26;                                               //0x00A8
    float unknown27;                                               //0x00AC
};