#pragma once

#include "float4.h"
#include "ECollidablesType.h"
#include "ERayDetailLevel.h"
#include "ZDelegate.h"

class ZEntityRef;
class ZSpatialEntity;
template <class T> class TEntityRef;

class ZRayQueryInput
{
public:
	float4 m_vFrom;
	float4 m_vTo;
	unsigned int m_nRayFilter;
	ECollidablesType m_eType;
	ERayDetailLevel m_eRayDetailLevel;
	ZDelegate<bool __cdecl(ZEntityRef, TEntityRef<ZSpatialEntity>)> m_FilterCallback;
	bool m_bIgnoreTransparentMaterials;

	static void RegisterType();
	ZRayQueryInput() = default;
	~ZRayQueryInput() = default;
};
