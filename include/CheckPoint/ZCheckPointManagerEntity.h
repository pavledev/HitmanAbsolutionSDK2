#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "STokenID.h"
#include "TArray.h"
#include "TResourcePtr.h"
#include "ZGameTime.h"
#include "ZString.h"
#include "ZVariantRef.h"

class IInputDevice;
class ISequenceEntity;
class ZActivatableRootEntity;
class ZActivationStateEntity;
class ZCheckPointEntity;
class ZComponentCreateInfo;
class ZHM5ValueEntity_bool;
class ZHM5ValueEntity_float32;
class ZSequenceEntity;
class ZStreamingStateEntity;
class ZTextListData;
struct SGameUpdateEvent;
struct STypeID;

class ZCheckPointManagerEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EActivationState
	{
		eIdle = 0,
		eWaitingForStreamingState = 1
	};

	struct SPendingCheckpointData
	{
		TEntityRef<ZCheckPointEntity> m_pCheckPointEntity;
		bool m_bUseSave;
		bool m_bSaveBeforeChange;
		bool m_bRestoring;

		SPendingCheckpointData() = default;
		~SPendingCheckpointData() = default;
	};

	EActivationState m_eState;
	TArray<TEntityRef<ZCheckPointEntity>> m_aCheckPoints;
	TEntityRef<ISequenceEntity> m_initialCutSequence;
	TArray<TEntityRef<ZSequenceEntity>> m_benchmarkCutSequences;
	TArray<TEntityRef<ZHM5ValueEntity_bool>> m_storedBoolValueEntities;
	TArray<TEntityRef<ZHM5ValueEntity_float32>> m_storedFloatValueEntities;
	ZString m_sLevelName;
	TResourcePtr<ZTextListData> m_pTextListResource;
	TEntityRef<ZCheckPointEntity> m_pCurrentCheckPoint;
	TEntityRef<ZActivationStateEntity> m_pCurrentActivationState;
	TEntityRef<ZStreamingStateEntity> m_pPendingStreamingState;
	TEntityRef<ZCheckPointEntity> m_pMemorizePendingCheckpoint;
	TEntityRef<ZActivationStateEntity> m_pendingActivionState;
	SPendingCheckpointData m_PendingCheckpointData;
	TEntityRef<ZCheckPointEntity> m_pOldCheckPoint;
	int m_iCurrentJumpPoint;
	bool m_bDebugMenuActive : 1;
	bool m_bIsInitialized : 1;
	bool m_bCpJumpKeyboardDownPrev : 1;
	bool m_bLevelIntroScreenShown : 1;
	bool m_bLevelEndPending : 1;
	bool m_bLevelEnded : 1;
	bool m_bDeactivatingEntities : 1;
	IInputDevice* m_pGamePadDevice;
	int m_iDeviceIdStart;
	int m_iDeviceIdLeftThumb;
	int m_iDeviceIdRightThumb;
	int m_iDeviceIdLeftTrigger;
	unsigned int m_iSelectedCP;
	bool m_bLastJump;
	bool m_bGamePaused;
	ZGameTime m_LevelIntroScreenEndTime;
	TArray<TEntityRef<ZActivatableRootEntity>> m_ActivatedRoots;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_sUnpauseIntroCut;

	~ZCheckPointManagerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;
	void Init() override;

	ZCheckPointManagerEntity() = default;
	static void RegisterType();
	ZCheckPointManagerEntity(ZComponentCreateInfo& info);
	TEntityRef<ZCheckPointEntity> GetCurrentCheckPoint() const;
	int GetCurrentCheckPointIndex() const;
	TEntityRef<ZCheckPointEntity> GetCheckpoint(unsigned int iId) const;
	int GetCheckpointIndex(TEntityRef<ZCheckPointEntity> pCheckpoint) const;
	int GetCheckpointIndex(const STokenID& sTokenID) const;
	TEntityRef<ZCheckPointEntity> GetContractsCheckpoint(int iId) const;
	TEntityRef<ZCheckPointEntity> GetNextCheckPoint(TEntityRef<ZCheckPointEntity> pCheckPoint) const;
	bool IsEndCheckpoint(TEntityRef<ZCheckPointEntity> pCheckpoint) const;
	bool IsReadyAfterLoad() const;
	void OnLevelEnded();
	const TEntityRef<ZCheckPointEntity>& GetPendingCheckpoint();
	void SetPendingStreamingState(const TEntityRef<ZStreamingStateEntity>& pStreamingState);
	void SetPendingActivationState(const TEntityRef<ZActivationStateEntity>& pActivationState);
	TEntityRef<ZActivationStateEntity> GetCurrentActivationState() const;
	bool ActivateNextJumpPoint(bool bResetHitman);
	void ActivateInitialJumpPoint(bool bResetHitman);
	bool IsDeactivatingEntities() const;
	const TArray<TEntityRef<ZHM5ValueEntity_bool>>& GetStoredBoolValueEntities() const;
	const TArray<TEntityRef<ZHM5ValueEntity_float32>>& GetStoredFloatValueEntities() const;
	TArray<TEntityRef<ZSequenceEntity>>& GetBenchmarkCutSequences();
	void StartIntroCut(bool bStartPaused);
	void UnpauseIntroCut();
	void UnpauseIntroScreen();
	void SetPendingCheckpoint(const TEntityRef<ZCheckPointEntity>& pCheckPoint, bool bUseSave, bool bSaveBeforeChange, bool bRestoring);
	void StreamInCheckpoint(const TEntityRef<ZCheckPointEntity>& pCheckPoint);
	void ActivateForwardSpawn(int iIndex, bool bResetHitman);
	void ActivateJumpPoint(int iIndex, bool bResetHitman);
	void OnFrameUpdate(const SGameUpdateEvent& updateEvent);
	TEntityRef<ZStreamingStateEntity> GetStreamingStateFromCheckpoint(const TEntityRef<ZCheckPointEntity>& rPendingCheckpoint, bool bRestoring) const;
	int GetCheckpointFromStreamingState(TEntityRef<ZStreamingStateEntity> pStreaminStateEntity);
	void SetStreamingState(TEntityRef<ZStreamingStateEntity> pStreamingState);
	bool ActivatePendingActivatableState();
	void SetActivatedActivatableRoots(const TArray<TEntityRef<ZActivatableRootEntity>>& roots);
	void DeactivateCurrentCheckpoint();
	void ActivatePendingCheckpoint();
	void HandleCheckpointSelect();
	void DrawCheckpointSelectMenu();
	void GameEventHandler(const ZString& sEvent, const ZVariantRef& __formal);
	void OnIntroCutEnded(ISequenceEntity* __formal);
	void ShowLevelIntroScreen();
	void HideLevelIntroScreen();
	void PauseGame(bool bPause);
};
