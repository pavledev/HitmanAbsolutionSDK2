#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZDynamicFlashMovieResource;
struct STypeID;

class ZScaleformResourceEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TResourcePtr<ZDynamicFlashMovieResource> m_pFlashMovieResource;

	static SComponentMapEntry s_componentMap[0];

	~ZScaleformResourceEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZScaleformResourceEntity() = default;
	static void RegisterType();
	ZScaleformResourceEntity(ZComponentCreateInfo& info);
	void OnFlashMovieResourceChanged();
};
