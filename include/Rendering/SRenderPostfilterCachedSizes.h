#pragma once

struct SRenderPostfilterCachedSizes
{
	unsigned int m_nWidth;
	unsigned int m_nHeight;
	unsigned int m_nWidth2x;
	unsigned int m_nHeight2x;
	unsigned int m_nWidth4x;
	unsigned int m_nHeight4x;
	unsigned int m_nWidth8x;
	unsigned int m_nHeight8x;
	unsigned int m_nWidth16x;
	unsigned int m_nHeight16x;
	float m_fWidth;
	float m_fHeight;
	float m_fWidth2x;
	float m_fHeight2x;
	float m_fWidth4x;
	float m_fHeight4x;
	float m_fWidth8x;
	float m_fHeight8x;
	float m_fWidth16x;
	float m_fHeight16x;

	SRenderPostfilterCachedSizes() = default;
	~SRenderPostfilterCachedSizes() = default;
	bool Update(unsigned int nWidth, unsigned int nHeight);
};
