#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZMenuGalleryItemEntity;
struct STypeID;
template <class T> class TEntityRef;

class ZMenuGalleryEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZMenuGalleryItemEntity>> m_aItems;

	static SComponentMapEntry s_componentMap[0];

	~ZMenuGalleryEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZMenuGalleryEntity() = default;
	static void RegisterType();
	ZMenuGalleryEntity(ZComponentCreateInfo& Info);
	TEntityRef<ZMenuGalleryItemEntity>& GetItemAtIndex(int index);
};
