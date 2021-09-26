#pragma once

#include "IRenderResourceAsyncUpdate.h"
#include "TRenderReferencedCountedImpl.h"

class IRenderPrimitive;

class ZRenderAsyncUpdateRenderPrimitiveProperties : public TRenderReferencedCountedImpl<IRenderResourceAsyncUpdate, 0>
{
public:
	unsigned int m_nNumIndicesToDraw;
	IRenderPrimitive* m_pPrim;
	unsigned char m_nLODMask;
	bool m_bChangedBounds : 1;
	bool m_bChangedNumIndicesToDraw : 1;
	bool m_bChangedLODMask : 1;

	~ZRenderAsyncUpdateRenderPrimitiveProperties() override = default;
	void Apply() override;

	ZRenderAsyncUpdateRenderPrimitiveProperties() = default;
	ZRenderAsyncUpdateRenderPrimitiveProperties(IRenderPrimitive* pPrimitiveInstance);
};
