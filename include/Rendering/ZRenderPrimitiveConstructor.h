#pragma once

#include "ERenderFormat.h"
#include "ERenderPrimitiveType.h"

struct SPrimObjectHeader;
class ZRenderInputLayout;
class IRenderPrimitive;
class ZUnsafeResourceReader;

class ZRenderPrimitiveConstructor
{
public:
	struct SPrimTypeData
	{
		ZRenderInputLayout* m_pInputLayout;
		unsigned int m_nPrimTypeToVertexTypeMapping;
		ERenderFormat m_ePositionFormat;
		ERenderFormat m_eColorFormat;
	};

	SPrimTypeData m_PrimTypeData[21];

	ZRenderPrimitiveConstructor() = default;
	~ZRenderPrimitiveConstructor() = default;
	IRenderPrimitive* CreateRenderPrimitiveFromResourceStandardMesh(const ZUnsafeResourceReader& Prim, const SPrimObjectHeader* pPrimObjectHeader);
	IRenderPrimitive* CreateRenderPrimitiveFromResourceStandardMeshLinked(const ZUnsafeResourceReader& Prim, const SPrimObjectHeader* pPrimObjectHeader);
	IRenderPrimitive* CreateRenderPrimitiveFromResourceStandardMeshWeighted(const ZUnsafeResourceReader& Prim, const SPrimObjectHeader* pPrimObjectHeader);
	ZRenderInputLayout* GetInputLayout(ERenderPrimitiveType eType) const;
	unsigned int GetPrimitiveToVertexTypeMapping(ERenderPrimitiveType eType) const;
	ERenderFormat GetPositionFormat(ERenderPrimitiveType eType) const;
};
