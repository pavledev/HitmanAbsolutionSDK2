#pragma once

#include "ZPF5Location.h"
#include "SVector3.h"

class ZPF5LineHitInfo
{
public:
	ZPF5Location m_PF5Location;
	SVector3 m_vEdgeVertex0;
	SVector3 m_vEdgeVertex1;

	ZPF5LineHitInfo() = default;
	~ZPF5LineHitInfo() = default;
	void SetEdgeVertices(SVector3 vEdgeVertex0, SVector3 vEdgeVertex1);
};
