#pragma once

#include "TArray.h"

class ZRenderGraphNode;
class ZRenderGraphNodeLight;

struct SLightBundle
{
	TArray<ZRenderGraphNode*> nodes;
	ZRenderGraphNodeLight* pLight;
	unsigned int nInsideFlag;
	float m_fPriority;
	float m_fOcclusionPriority;
	unsigned int m_nPixelsTouched;
	unsigned int lights[1];
	unsigned int m_nKey;
	bool bUseStencil : 1;
	bool bCastShadows;
	unsigned char nLightType;

	void ClearKey();
	void SetSortValue1(unsigned char nSort1);
	unsigned short GetSortMask();
	void SetSortMask(unsigned short nMask);
	unsigned int GetKey();
	SLightBundle() = default;
	~SLightBundle() = default;
	SLightBundle& operator=(const SLightBundle& __that);
};
