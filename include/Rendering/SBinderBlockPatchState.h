#pragma once

#include "ZRenderConstBufferRef.h"
#include "ZRenderShaderResourceView.h"

struct SBinderBlockPatchState
{
	ZRenderConstBufferRef m_ConstBufferV;
	ZRenderConstBufferRef m_ConstBufferF;
	ZRenderShaderResourceView* m_TextureState[16];

	SBinderBlockPatchState() = default;
	~SBinderBlockPatchState() = default;
};
