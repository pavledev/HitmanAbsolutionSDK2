#pragma once

#include "SMatrix.h"
#include "float4.h"

struct SCameraUpdate
{
	float m_fFov;
	SMatrix m_mCamera;
	float4 m_fSeperateListenerPos;
	bool m_bSeperateListener;

	SCameraUpdate() = default;
	~SCameraUpdate() = default;
};
