#pragma once

#include "TRefCountPtr.h"
#include "TArray.h"
#include "ZResourcePtr.h"
#include "float4.h"

class IRenderPrimitiveMesh;
struct SVertexGeneric;
struct float1;

class ZRenderDynamicMesh
{
public:
	TRefCountPtr<IRenderPrimitiveMesh> m_pRenderPrimitiveMesh;
	TArray<SVertexGeneric> m_aVertices;
	TArray<unsigned short> m_aIndices;
	float4 vMin;
	float4 vMax;

	~ZRenderDynamicMesh() = default;
	void Create(const ZResourcePtr& pMaterial);
	const TRefCountPtr<IRenderPrimitiveMesh>& GetPrimitiveMesh() const;
	void SetVertexColor(unsigned int nVertexIndex, unsigned int nColor);
	void AddVertex(const float4& vPosition, const float1& vTexU, const float1& vTexV);
	void PackNormal(unsigned char* pDest, const float& x, const float& y, const float& z);
	void AddVertex2DExtrude(const float4& vPosition, const float1& vTexU, const float1& vTexV, const float4& vNormal);
	void SetIndex(unsigned int nIndex, unsigned short nVertexIndex);
	void SetNumIndices(unsigned int nIndexCount);
	void SetNumVertices(unsigned int nVertexCount);
	unsigned int GetNumVertices() const;
	void Reset();
	void Clear();
	void Draw();
	ZRenderDynamicMesh() = default;
};
