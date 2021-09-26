#pragma once

class ZRenderShaderResourceView;
class ZRenderTexture2D;

struct SRenderPostfilterPreprocessOutput
{
	ZRenderShaderResourceView* m_pGlareAccumulationSRV;
	ZRenderTexture2D* m_pGlareAccumulationTexture;

	SRenderPostfilterPreprocessOutput() = default;
	~SRenderPostfilterPreprocessOutput() = default;
};
