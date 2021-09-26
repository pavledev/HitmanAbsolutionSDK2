#pragma once

#include "IComponentInterface.h"

class IRenderPrimitiveMesh;
struct SVector4;

class __declspec(novtable) IFabricEntity : public IComponentInterface
{
public:
	~IFabricEntity() override = default;
	virtual unsigned int GetNumSubmeshes() const = 0;
	virtual IRenderPrimitiveMesh* GetSubmesh(const unsigned int param1) = 0;
	virtual unsigned int GetNumSubmeshVerticies(const unsigned int param1) const = 0;
	virtual SVector4* GetSubmeshVerticies(const unsigned int param1) = 0;
	virtual bool AssociateWithExternalColliders() const = 0;

	static void RegisterType();
	IFabricEntity() = default;
};
