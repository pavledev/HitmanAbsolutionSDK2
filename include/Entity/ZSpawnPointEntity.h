#pragma once

#include "ZSpatialEntity.h"
#include "TResourcePtr.h"
#include "EActorGroup.h"
#include "SComponentMapEntry.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"

class IEntityFactory;
class IHM5Outfit;
class ZActor;
class ZBoxVolumeEntity;
class ZComponentCreateInfo;
class ZString;
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;

class ZSpawnPointEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TResourcePtr<IEntityFactory> m_actorTemplate0;
	TResourcePtr<IEntityFactory> m_actorTemplate1;
	TResourcePtr<IEntityFactory> m_actorTemplate2;
	TResourcePtr<IEntityFactory> m_actorTemplate3;
	TResourcePtr<IEntityFactory> m_actorTemplate4;
	TEntityRef<IHM5Outfit> m_OutfitEntity;
	TEntityRef<ZBoxVolumeEntity> m_ExcludeBox;
	bool m_bHighPriority;
	ZResourcePtr m_pGizmo;
	ZResourcePtr m_pAlignGizmo;
	EActorGroup m_eActorGroup;
	bool m_bStreamedIn : 1;
	bool m_bNoOutfitErrorSent : 1;
	unsigned int m_nNumberOfSpawnedActorsSoFar;
	unsigned int m_nSpawnPositionIndex;

	static SComponentMapEntry s_componentMap[0];

	~ZSpawnPointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void Init() override;
	void Start() override;
	virtual TEntityRef<ZActor> Spawn();

	ZSpawnPointEntity() = default;
	static void RegisterType();
	ZSpawnPointEntity(ZComponentCreateInfo& info);
	TEntityRef<ZBoxVolumeEntity> GetExcludeBox() const;
	int GetNumberOfSpawnedActorsSoFar() const;
	bool IsHighPriority() const;
	TEntityRef<ZActor> CreateEntity(const ZString& sDebugName, const ZResourcePtr& pEntityFactory);
	void AddEntityToSceneContext(const ZEntityRef& rEntity, const ZResourcePtr& pEntityFactory);
	void OnGizmoChanged();
};
