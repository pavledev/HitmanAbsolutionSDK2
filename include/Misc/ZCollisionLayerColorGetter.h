#pragma once

class ICollisionManager;

class ZCollisionLayerColorGetter
{
public:
	ICollisionManager* m_pColMan;
	unsigned int m_nColorOverride;
	bool m_bIsInWorld : 1;
	bool m_bIsSleeping : 1;
	bool m_bIsStatic : 1;
	bool m_bStopMode : 1;

	static const unsigned int DEFALUT_OVERRIDE_COLOR;

	ZCollisionLayerColorGetter() = default;
	ZCollisionLayerColorGetter(const unsigned int nColorOverride);
	~ZCollisionLayerColorGetter() = default;
};
