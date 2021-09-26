#pragma once

#include "IRenderMaterialDescriptor.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZEntityImpl.h"

class ISoundMaterialDescriptor;
class ZComponentCreateInfo;
class ZEntityRef;
struct STypeID;

class ZMaterialDescriptorEntity : public IRenderMaterialDescriptor, public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fWetnessFactor;
	TResourcePtr<ZEntityRef> m_pSoundMaterialDescriptor;
	TEntityRef<ISoundMaterialDescriptor> m_pSoundMaterialDescriptorEntity;

	static SComponentMapEntry s_componentMap[0];

	TEntityRef<ISoundMaterialDescriptor> GetSoundMaterialDescriptor() const override;
	float GetWetnessFactor() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	void Init() override;

	ZMaterialDescriptorEntity() = default;
	static void RegisterType();
	ZMaterialDescriptorEntity(const ZMaterialDescriptorEntity& __that);
	ZMaterialDescriptorEntity(ZComponentCreateInfo& Info);
	void OnSoundMaterialDescriptorChanged();
	ZMaterialDescriptorEntity& operator=(const ZMaterialDescriptorEntity& __that);
};
