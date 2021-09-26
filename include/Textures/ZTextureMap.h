#pragma once

#include "ERenderFormat.h"

class ZTextureMap
{
public:
	enum ETextureFlags
	{
		TEXF_SWIZZLED = 1,
		TEXF_DEFERRED = 2,
		TEXF_MEMORY_READY_XBOX360 = 4,
		TEXF_GAMMA = 8,
		TEXF_EMISSIVE = 16,
		TEXF_DDSC_ENCODED = 32
	};

	enum EInterpretAs
	{
		INTERPRET_AS_COLOR = 0,
		INTERPRET_AS_NORMAL = 1,
		INTERPRET_AS_HEIGHT = 2
	};

	enum EDimensions
	{
		DIMENSIONS_2D = 0,
		DIMENSIONS_CUBE = 1,
		DIMENSIONS_VOLUME = 2
	};

	struct SMipLevel
	{
		unsigned int nWidth;
		unsigned int nHeight;
		unsigned int nSizeInBytes;
		const unsigned char* pData;
	};

	struct STextureMapHeader
	{
		unsigned int nTotalSize;
		unsigned int nFlags;
		unsigned short nWidth;
		unsigned short nHeight;
		unsigned short nFormat;
		unsigned char nNumMipLevels;
		unsigned char nDefaultMipLevel;
		unsigned char nInterpretAs;
		unsigned char nDimensions;
		unsigned char nMipInterpolation;
		unsigned int nIADataSize;
		unsigned int nIADataOffset;
	};

	const unsigned char* m_pData;

	ZTextureMap() = default;
	ZTextureMap(const unsigned char* pData);
	~ZTextureMap() = default;
	unsigned int GetTotalSize() const;
	unsigned int GetWidth() const;
	unsigned int GetHeight() const;
	ERenderFormat GetFormat() const;
	unsigned int GetNumMipLevels() const;
	unsigned int GetDefaultMipLevel() const;
	EInterpretAs GetInterpretAs() const;
	EDimensions GetDimensions() const;
	unsigned int GetFlags() const;
	unsigned char GetMipInterpolation() const;
	void GetMipLevel(SMipLevel* pMipLevel, unsigned int nMipLevel) const;
	const STextureMapHeader* GetHeader() const;
	const void* GetRawTextureData() const;
	const bool HasIAData() const;
	const unsigned int GetIADataSize() const;
	const unsigned char* GetIAData() const;
	void DeleteData();
	void SetData(const unsigned char* pData);
	unsigned int GetDataSize(unsigned int nWidth, unsigned int nHeight, ERenderFormat eFormat) const;
};
