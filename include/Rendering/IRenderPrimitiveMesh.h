#pragma once

#include "IRenderPrimitive.h"

class IRenderPrimitiveBuffer;
struct SColiBoxHeader;

class __declspec(novtable) IRenderPrimitiveMesh : public IRenderPrimitive
{
public:
	unsigned char* m_pColiData;

	~IRenderPrimitiveMesh() override = default;
	virtual IRenderPrimitiveBuffer* GetVertexBuffer(unsigned int param1) const = 0;
	virtual IRenderPrimitiveBuffer* GetIndexBuffer() const = 0;
	virtual void SetCopyBones(unsigned int param1, const unsigned int* param2) = 0;
	virtual void GetCopyBones(unsigned int& param1, const unsigned int*& param2) = 0;
	virtual void SetBoneIndices(const unsigned short* param1) = 0;
	virtual bool GetIndicesForBone(unsigned int param1, const unsigned short** param2, unsigned int* param3, IRenderPrimitiveBuffer** renderPrimitiveBuffer, const SColiBoxHeader** coliBoxHeader) = 0;

	IRenderPrimitiveMesh() = default;
};
