#pragma once

#include "TArray.h"
#include "TEnumerator.h"
#include "SVector3.h"
#include "TResourcePtr.h"

class IRenderPrimitive;
class IResourceInstaller;
class ZAnimationBoneData;
class ZUnsafeResourceReader;
template <class T> class TRefCountPtr;

class ZRenderPrimitiveResource
{
public:
	TArray<TRefCountPtr<IRenderPrimitive>> m_Primitives;
	SVector3 m_vMin;
	SVector3 m_vMax;
	ZAnimationBoneData* m_pBoneData;
	bool m_bIsInitialized;
	TResourcePtr<ZAnimationBoneData> m_pBoneDataResourcePtr;

	virtual ~ZRenderPrimitiveResource() = default;

	ZRenderPrimitiveResource(const ZRenderPrimitiveResource& __that);
	ZRenderPrimitiveResource() = default;
	bool Install(const ZUnsafeResourceReader& Prim, IResourceInstaller& installer);
	bool IsInitialized();
	TEnumerator<TRefCountPtr<IRenderPrimitive>> GetPrimitiveEnumerator();
	unsigned int GetPrimitivesCount() const;
	ZAnimationBoneData* GetBoneData() const;
	void GetBounds(SVector3& vMin, SVector3& vMax);
	ZRenderPrimitiveResource& operator=(const ZRenderPrimitiveResource& __that);
};
