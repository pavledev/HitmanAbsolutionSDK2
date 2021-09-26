#pragma once

#include "EHM5OSDSprite.h"
#include "SVector2.h"

struct float4;

class __declspec(novtable) IHM5OSD
{
public:
	virtual ~IHM5OSD() = default;
	virtual void AddSprite(EHM5OSDSprite sprite, float param2, float param3, unsigned char param4) = 0;
	virtual void AddSpriteBar(EHM5OSDSprite sprite, float param2, float param3, float param4, float param5, unsigned char param6) = 0;
	virtual void AddCircle(float param1, float param2, float param3, float param4, unsigned char param5) = 0;
	virtual void AddBox(float param1, float param2, float param3, float param4, float param5, unsigned char param6) = 0;
	virtual void AddQuad(const float4& param1, const float4& param2, const float4& param3, const float4& param4, const float4& param5, unsigned char param6) = 0;
	virtual void AddTriangle(float param1, float param2, unsigned char param3) = 0;
	virtual void SetScale(float param1, float param2) = 0;
	virtual void SetRotation(float param1) = 0;
	virtual void SetColor(unsigned int param1) = 0;
	virtual SVector2 GetSize(EHM5OSDSprite sprite) = 0;
	virtual float GetAspectRatio() const = 0;

	IHM5OSD() = default;
};
