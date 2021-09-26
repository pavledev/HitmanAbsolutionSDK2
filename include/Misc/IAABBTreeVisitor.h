#pragma once

#include "float4.h"

class __declspec(novtable) IAABBTreeVisitor
{
public:
	virtual bool ProcessVolume(const float4& param1, const float4& param2) = 0;
	virtual void ProcessObject(void* param1, const float4& param2, const float4& param3) = 0;
	virtual ~IAABBTreeVisitor() = default;

	IAABBTreeVisitor() = default;
};
