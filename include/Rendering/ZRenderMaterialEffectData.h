#pragma once

class ZRenderEffect;

class ZRenderMaterialEffectData
{
public:
	ZRenderEffect* m_pRenderEffect;

	virtual ~ZRenderMaterialEffectData() = default;

	ZRenderMaterialEffectData() = default;
	ZRenderMaterialEffectData(ZRenderEffect* pRenderEffect);
	ZRenderEffect* GetRenderEffect() const;
};
