#pragma once

#include "float4.h"
#include "TResourcePtr.h"

class ZRenderMaterialInstance;

class ZRayQueryOutputBase
{
public:
	float4 m_vPosition;
	float4 m_vNormal;
	float m_nT;
	TResourcePtr<ZRenderMaterialInstance> m_pBlockingMaterial;
	unsigned char m_nIntersectedBoneMeshId;
	bool m_bHasHit;

	ZRayQueryOutputBase() = default;
	void ClearBase();
	void ClearHitBase();
	~ZRayQueryOutputBase() = default;
	ZRayQueryOutputBase& operator=(const ZRayQueryOutputBase& __that);
};
