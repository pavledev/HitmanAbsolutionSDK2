#pragma once

#include "ZEntityImpl.h"
#include "ECCLeeState.h"
#include "TEntityRef.h"
#include "ZCheckPointEntity.h"
#include "ZSequenceEntity.h"
#include "ZHM5ValueEntity_float32.h"
#include "ZActivationStateEntity.h"
#include "SPendingCheckpointData.h"
#include "IInputDevice.h"

class alignas(8) ZCheckPointManagerEntity : public ZEntityImpl
{
public:
    ECCLeeState m_eState;
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
    __int8 m_bDebugMenuActive : 1;
    __int8 m_bIsInitialized : 1;
    __int8 m_bCpJumpKeyboardDownPrev : 1;
    __int8 m_bLevelIntroScreenShown : 1;
    __int8 m_bLevelEndPending : 1;
    __int8 m_bLevelEnded : 1;
    __int8 m_bDeactivatingEntities : 1;
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
};
