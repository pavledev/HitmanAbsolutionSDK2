#pragma once
#pragma warning(disable : 4005)

#include "TRenderResourceImpl.h"
#include "SRenderTexture3DDesc.h"
#include "ERenderResourceMapType.h"
#include "d3d11.h"

struct SRenderMappedTexture3D;
struct SRenderSubResourceData;
class ZRenderDevice;
class IRenderResource;

class ZRenderTexture3D : public TRenderResourceImpl<IRenderResource, 2>
{
public:
	SRenderTexture3DDesc m_Description;
	ID3D11Texture3D* m_pTexture3D;
	ID3D11DeviceContext* m_pDeviceContext;

	~ZRenderTexture3D() override = default;

	ZRenderTexture3D() = default;
	ZRenderTexture3D(const SRenderTexture3DDesc* pDescription, const SRenderSubResourceData* pData, ZRenderDevice* pRenderDevice);
	const SRenderTexture3DDesc& GetDesc() const;
	void Map(unsigned int nSubResource, ERenderResourceMapType eMapType, unsigned int nMapFlags, SRenderMappedTexture3D* pMappedTexture);
	void Unmap(unsigned int nSubResource);
	ID3D11Texture3D* GetTexture3D() const;
};
