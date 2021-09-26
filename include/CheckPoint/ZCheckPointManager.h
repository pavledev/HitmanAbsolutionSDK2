#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "TEntityRef.h"
#include "SCheckpointSaveData.h"
#include "EMenuId.h"
#include "STokenID.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZActivationStateEntity;
class ZCheckPointEntity;
class ZCheckPointFlow;
class ZCheckPointManagerEntity;
class ZEntityRef;
class ZEventNull;
class ZObjectiveEntity;
class ZSpatialEntity;
class ZStreamingStateEntity;
class ZString;
struct SComponentMapEntry;
struct STypeID;
template <class T> class alignas(8) ZDelegate;

class ZCheckPointManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZEvent<TEntityRef<ZCheckPointEntity> const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_CheckPointActivatedEvent;
	ZEvent<TEntityRef<ZCheckPointEntity> const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_CheckPointDeactivatedEvent;
	TEntityRef<ZCheckPointManagerEntity> m_pCheckPointManagerEntity;
	ZCheckPointFlow* m_pCheckPointFlow;
	int m_iInitialCheckpointIndexContracts;
	TArray<ZEntityRef> m_aConstructedItems;
	TArray<ZEntityRef> m_aConstructedItemsReferenced;
	int m_nEditorStartCheckpoint;
	int m_nForwardSpawnCheckpoint;
	int m_nForwardSpawnIndex;
	SCheckpointSaveData m_ForwadSpawnSaveData;
	TArray<STokenID> m_ForwardSpawnDeadActors;
	unsigned short* m_ForwardSpawnRatingSave;
	TArray<bool> m_bForwardSpawnTitleAchieved;
	TArray<ZString> m_ForwardSpawnActiveObjectives;
	TArray<ZString> m_ForwardSpawnCompletedObjectives;
	bool m_bLoadScrenActive;
	bool m_bIsRestoring;
	bool m_bCheckpointRestarting;
	bool m_bForwardSpawnSpottetOnCheckpoint;

	~ZCheckPointManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZCheckPointManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void Deactivate();
	bool IsReadyAfterLoad() const;
	void HiddenFramesStated();
	void SetCheckPointManagerEntity(const TEntityRef<ZCheckPointManagerEntity>& pManager);
	TEntityRef<ZCheckPointManagerEntity> GetCheckPointManagerEntity() const;
	ZCheckPointFlow* GetCheckPointFlow() const;
	void RegisterToCheckPointChanges(const ZDelegate<void __cdecl(TEntityRef<ZCheckPointEntity> const&)>& activated, const ZDelegate<void __cdecl(TEntityRef<ZCheckPointEntity> const&)>& deactivated);
	void UnregisterToCheckPointChanges(const ZDelegate<void __cdecl(TEntityRef<ZCheckPointEntity> const&)>& activated, const ZDelegate<void __cdecl(TEntityRef<ZCheckPointEntity> const&)>& deactivated);
	void SetCheckpointRestarting(bool restarting);
	bool IsCheckpointRestarting() const;
	bool IsDeactivatingEntities() const;
	void OnCheckPointActivated(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void OnCheckPointpPreDeactive(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void OnCheckPointDeactivated(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void CheckpointStore(SCheckpointSaveData* pCheckpointData, bool bDropStoredItems);
	void CheckpointRestore(SCheckpointSaveData* pCheckpointData, bool bForwardSpawn, bool bResetting);
	SCheckpointSaveData* GetCheckpointData(int nCP, bool bAutoCreate);
	bool HandleLevelEnd(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void SceneDeactivating();
	void InvalidateCheckpointSave();
	void SetInitialCheckpointContracts(int iCheckpoint);
	int GetInitialCheckpointContracts() const;
	bool IsForwardSpawnValid();
	void ResetForwardSpawn();
	void StoreForwardSpawn(TEntityRef<ZSpatialEntity>& pForwardSpawnSpatial);
	void RestoreForwardSpawn();
	int GetForwardSpawnIndex(int nCheckpointIndex);
	bool IsActorEnabledByForwardSpawn(const STokenID& token) const;
	SCheckpointSaveData* GetForwardSpawnSaveData();
	bool ShouldResetHitman() const;
	bool ShouldStartIntroCutPaused() const;
	void ExitToMenu(EMenuId eMenuId);
	void ActivatableRootsChanged(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void ActivationStateRootsChanged(const TEntityRef<ZActivationStateEntity>& pActivationState);
	void CheckpointEntityActivated(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void CheckpointJump(int iCheckPoint);
	void CheckpointJump(TEntityRef<ZStreamingStateEntity> pStreamingState);
	void CheckpointJump(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	TEntityRef<ZCheckPointEntity> GetCurrentCheckpoint();
	const STokenID& GetCurrentCheckpointToken();
	int GetCurrentCheckpointIndex();
	void SetEditorStartCheckpoint(int nStartCheckpoint);
	int GetEditorStartCheckpoint() const;
	void SetLoadScreenActive(bool bActive);
	bool IsRestoring();
	bool IsLoadScreenActive() const;
	bool CheckPointCyclerWrapper_IsCycleCheckPointsEnabled() const;
	bool CheckPointCyclerWrapper_IsCycleLevelsEnabled() const;
	static TEntityRef<ZObjectiveEntity> FindObjectiveByTitle(const ZString& sTitle, TArray<TEntityRef<ZObjectiveEntity>> aObjectives);
	void DeleteContructedItems();
	void DeleteReferencedContructedItems();
};
