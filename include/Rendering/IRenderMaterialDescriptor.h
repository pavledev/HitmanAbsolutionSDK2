#pragma once

#include "TEntityRef.h"

class ISoundMaterialDescriptor;

class __declspec(novtable) IRenderMaterialDescriptor
{
public:
	virtual TEntityRef<ISoundMaterialDescriptor> GetSoundMaterialDescriptor() const = 0;
	virtual float GetWetnessFactor() const = 0;
	virtual ~IRenderMaterialDescriptor() = default;

	static void RegisterType();
	IRenderMaterialDescriptor() = default;
};
