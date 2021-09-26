#pragma once
#include "d3d11.h"

#pragma warning(disable : 4005)

struct BinkDrawData
{
	ID3D11ShaderResourceView* m_Yview;
	ID3D11ShaderResourceView* m_cRview;
	ID3D11ShaderResourceView* m_cBview;
	ID3D11ShaderResourceView* m_Aview;
	unsigned int m_width;
	unsigned int m_height;
	float m_fAlpha_level;
	bool m_bIs_premultiplied_alpha : 1;
	bool m_bHasAlpha : 1;

	BinkDrawData() = default;
	~BinkDrawData() = default;
};
