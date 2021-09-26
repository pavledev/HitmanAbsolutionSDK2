#pragma once

class ZRenderGraphNodeLight;

struct SRenderGraphNodeLight
{
	float m_fPriority;
	ZRenderGraphNodeLight* m_pLight;

	SRenderGraphNodeLight() = default;
	SRenderGraphNodeLight(float fPriority, ZRenderGraphNodeLight* pLight);
	~SRenderGraphNodeLight() = default;
	bool operator<(const SRenderGraphNodeLight& lhs) const;
};
