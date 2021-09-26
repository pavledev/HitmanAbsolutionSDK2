#pragma once
#pragma warning(disable : 4005)

#include "TRenderResourceImpl.h"
#include "SRenderTexture2DDesc.h"
#include "ERenderResourceMapType.h"
#include "d3d11.h"

struct SRenderSubResourceData;
struct SRenderMappedTexture2D;
class IRenderResource;
class ZRenderDevice;
class ZRenderShaderResourceView;

class ZRenderTexture2D : public TRenderResourceImpl<IRenderResource, 1>
{
public:
	SRenderTexture2DDesc m_Description;
	ID3D11Texture2D* m_pTexture2D;
	const ZRenderTexture2D* m_pParent;
	const unsigned char* m_pIAData;
	unsigned int m_nIADataSize;
	ID3D11DeviceContext* m_pDeviceContext;
	ZRenderShaderResourceView* m_pSRV;

	~ZRenderTexture2D() override = default;
	virtual void Allocate(unsigned int nLocation);
	virtual void Free();

	ZRenderTexture2D() = default;
	ZRenderTexture2D(const SRenderTexture2DDesc* pDescription, const SRenderSubResourceData* pData, ZRenderDevice* pRenderDevice, ID3D11Texture2D* pTexture2D);
	const SRenderTexture2DDesc& GetDesc() const;
	void Map(unsigned int nSubResource, ERenderResourceMapType eMapType, unsigned int nMapFlags, SRenderMappedTexture2D* pMappedTexture);
	void Unmap(unsigned int nSubResource);
	void Clone(const ZRenderTexture2D* pTexture);
	const ZRenderTexture2D* GetParent();
	unsigned int GetIADataSize() const;
	const unsigned char* GetIAData() const;
	void SetIAData(unsigned int nSize, const unsigned char* pData);
	ID3D11Texture2D* GetTexture2D() const;
	void SetSRV(ZRenderShaderResourceView* pSRV);
	ZRenderShaderResourceView* GetSRV();
};
