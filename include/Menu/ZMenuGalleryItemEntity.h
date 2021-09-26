#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "EUIText.h"
#include "SComponentMapEntry.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZDynamicFlashMovieResource;
struct STypeID;

class ZMenuGalleryItemEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TResourcePtr<ZDynamicFlashMovieResource> m_pImage;
	EUIText m_eTitle;
	EUIText m_eInfo;
	unsigned int m_nStatus;
	ZEntityRef m_pResource;

	static SComponentMapEntry s_componentMap[0];

	~ZMenuGalleryItemEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZMenuGalleryItemEntity() = default;
	static void RegisterType();
	ZMenuGalleryItemEntity(ZComponentCreateInfo& Info);
	void OnImageChanged();
	void OnTitleChanged();
	void OnInfoChanged();
	void OnStatusChanged();
	void OnResourceChanged();
};
