#pragma once

#include "SVector3.h"

struct float4;

class ZPF5Location
{
public:
	SVector3 m_vPos;
	int m_iComponent;

	ZPF5Location(const float4& vPos, int iComponent);
	ZPF5Location() = default;
	~ZPF5Location() = default;
	void Reset();
	void SetComponent(int iComponent);
	void Set(const float4& vPos, int iComponent);
	bool IsInside() const;
	int GetComponent() const;
};
