#pragma once

class ZRenderGraphNode;
class ZRenderPrimitiveInstance;

struct SRenderDrawFilterEntry
{
	ZRenderGraphNode* m_pNode;
	ZRenderPrimitiveInstance* m_pPrimitiveInstance;
	unsigned char m_nLODFade;
	bool m_bUseFade : 1;
	bool m_bSimpleShader : 1;

	SRenderDrawFilterEntry() = default;
	~SRenderDrawFilterEntry() = default;
};
