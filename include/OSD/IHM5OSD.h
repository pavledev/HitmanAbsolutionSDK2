#pragma once

#include "EHM5OSDSprite.h"
#include "float4.h"
#include "SVector2.h"

class IHM5OSD
{
public:
    virtual ~IHM5OSD();
    virtual void AddSprite(EHM5OSDSprite, float, float, unsigned __int8);
    virtual void AddSpriteBar(EHM5OSDSprite, float, float, float, float, unsigned __int8);
    virtual void AddCircle(float, float, float, float, unsigned __int8);
    virtual void AddBox(float, float, float, float, float, unsigned __int8);
    virtual void AddQuad(const float4*, const float4*, const float4*, const float4*, const float4*, unsigned __int8);
    virtual void AddTriangle(float, float, unsigned __int8);
    virtual void SetScale(float, float);
    virtual void SetRotation(float);
    virtual void SetColor(unsigned int);
    virtual SVector2 GetSize(EHM5OSDSprite);
    virtual float GetAspectRatio();
};
