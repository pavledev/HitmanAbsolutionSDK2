#pragma once

#include "ZGridNodeRef.h"
#include "float4.h"
#include "SMatrix.h"
#include "TMaxArray.h"

struct SDistanceModifiers
{
	struct SConnector
	{
		ZGridNodeRef m_from;
		ZGridNodeRef m_to;
		float m_fDistance;
		float m_fDistanceToSource;
		bool m_bTwoWay;

		SConnector(const SConnector& __that);
		SConnector() = default;
		SConnector& operator=(const SConnector& __that);
	};

	struct SVolume
	{
		SMatrix m_mOBBTransform;
		float4 m_vHalfSize;
		float m_fMultiplier;

		SVolume() = default;
	};

	TMaxArray<SConnector, 8> m_connectors;
	TMaxArray<SVolume, 8> m_volumes;

	SDistanceModifiers(const SDistanceModifiers& __that);
	SDistanceModifiers() = default;
	~SDistanceModifiers() = default;
	SDistanceModifiers& operator=(const SDistanceModifiers& __that);
};
