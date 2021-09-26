#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "EContractCheckpointId.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TResourcePtr.h"
#include "ZVariantRef.h"

class IMusicComposition;
class IRoomEntity;
class ISoundAmbienceElement;
class ZActivatableRootEntity;
class ZComponentCreateInfo;
class ZEntityRef;
class ZHM5ForwardSpawnEntity;
class ZObjectiveEntity;
class ZSpatialEntity;
class ZStreamingStateEntity;
struct STokenID;
struct STypeID;

class ZCheckPointEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<IRoomEntity>> m_rooms;
	TEntityRef<ZStreamingStateEntity> m_pRequiredStreamingState;
	TArray<TEntityRef<ZHM5ForwardSpawnEntity>> m_aForwardSpawn;
	TArray<TEntityRef<ZSpatialEntity>> m_aJumpPoints;
	TArray<TEntityRef<ZActivatableRootEntity>> m_aActivatableRoots;
	TEntityRef<ISoundAmbienceElement> m_pInitialSoundAmbience;
	TEntityRef<IMusicComposition> m_pInitialComposition;
	EContractCheckpointId m_eContractsCheckpointId;
	TArray<TEntityRef<ZObjectiveEntity>> m_aCurrentObjectives;
	TResourcePtr<ZEntityRef> m_TokenResource;
	bool m_bUseNextCheckpointStramingStateOnRestore;
	TArray<TEntityRef<ZActivatableRootEntity>> m_aEnabledActivatableRoots;
	int m_nCPNumber;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnActivated;
	static unsigned int m_snOnDeactivated;
	static unsigned int m_snOnRestore;
	static unsigned int m_snOnTransition;

	~ZCheckPointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZCheckPointEntity() = default;
	static void RegisterType();
	ZCheckPointEntity(ZComponentCreateInfo& info);
	void SignalOnActivated();
	void SignalOnRestore();
	void SignalOnTransition();
	void SignalOnDeactivated();
	bool IsActive();
	TEntityRef<ZStreamingStateEntity> GetRequiredStreamingState() const;
	const TArray<TEntityRef<ZHM5ForwardSpawnEntity>>& GetForwardSpawn() const;
	const TArray<TEntityRef<ZSpatialEntity>>& GetJumpPoints() const;
	const TArray<TEntityRef<ZActivatableRootEntity>>& GetActivatableRoots();
	void AssignCPNumber(int num);
	int GetCPNumber() const;
	EContractCheckpointId GetContractsCheckpointId() const;
	const STokenID& GetTokenID() const;
	bool GetUseNextCheckpointStramingStateOnRestore() const;
	void ActivateSound();
	void OnActivate();
	void OnStreamNext();
	void OnStreamIn();
	void OnUpdateScore();
	void OnActivatableRootsChanged();
	void UpdateObjectives();
};
