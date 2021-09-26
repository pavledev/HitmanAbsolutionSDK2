#pragma once

struct SRenderBinderBlock3PatchIndex;
class ZRenderShaderResourceView;

struct SRenderBinderBlock3Patch
{
	unsigned int nBinderVersion;
	unsigned short nSize;
	unsigned short nParamIndexOffset;
	unsigned short nTextureOffset;
	unsigned short nFloatOffset;

	SRenderBinderBlock3Patch() = default;
	~SRenderBinderBlock3Patch() = default;
	void Init(unsigned int nNumTextures, unsigned int nNumParams, unsigned int nNumFloats, unsigned int nBinderVersion);
	SRenderBinderBlock3PatchIndex* TextureIndices();
	SRenderBinderBlock3PatchIndex* ParamIndices();
	ZRenderShaderResourceView** TextureData();
	float* FloatData();
	unsigned int NumTextures();
	unsigned int NumParams();
	static unsigned int PatchSize(unsigned int nNumTextures, unsigned int nNumParams, unsigned int nNumFloats);
};
