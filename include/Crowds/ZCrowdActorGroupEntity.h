#pragma once

#include "ZBoxVolumeEntity.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZVariantRef.h"

class ZAnimationClipEntity;
class ZComponentCreateInfo;
class ZCrowdActorEntity;
class ZCrowdActorGroupFocalPointEntity;
struct STypeID;
template <class T> class TEntityRef;

class ZCrowdActorGroupEntity : public ZBoxVolumeEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	unsigned int m_nGroupSize;
	TArray<TEntityRef<ZAnimationClipEntity>> m_idleOverrideClips;
	TArray<TEntityRef<ZCrowdActorGroupFocalPointEntity>> m_aFocalPoints;
	TArray<TEntityRef<ZCrowdActorEntity>> m_aExcludedActorTemplates;
	float m_nPlacementRadius;

	static SComponentMapEntry s_componentMap[0];

	~ZCrowdActorGroupEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZCrowdActorGroupEntity() = default;
	static void RegisterType();
	ZCrowdActorGroupEntity(ZComponentCreateInfo& info);
	const unsigned int GetGroupSize() const;
	const TArray<TEntityRef<ZCrowdActorGroupFocalPointEntity>>& GetFocalPoints() const;
	const bool IsTemplateExcluded(const TEntityRef<ZCrowdActorEntity>& rActorTemplate) const;
	const TArray<TEntityRef<ZCrowdActorEntity>>& GetExcludedActorTemplates() const;
	const float GetPlacementRadius() const;
	TArrayRef<TEntityRef<ZAnimationClipEntity>> GetOverrideClips();
};
