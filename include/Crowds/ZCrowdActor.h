#pragma once

#include "ZEntityImpl.h"
#include "TFixedArray.h"
#include "ZCrowdActorCore.h"
#include "ZCrowdActorSensorInput.h"
#include "SCrowdActorSensor.h"
#include "TEntityRef.h"
#include "ZCharacterController.h"
#include "ZAnimationLibrary.h"
#include "ZCrowdRegion.h"
#include "ZCrowdActorState.h"

class ZCrowdEntity;

class alignas(16) ZCrowdActor : public ZEntityImpl
{
public:
    TFixedArray<unsigned char, 44> m_aStateMemoryBuffer;
    ZCrowdActorCore* m_pCore;
    ZCrowdActorSensorInput* m_pSensorInput;
    SCrowdActorSensor* m_pSensor;
    TEntityRef<ZCrowdEntity> m_pCrowdEntity;
    ZCrowdActorState* m_pCurState;
    float m_nTimeInState;
    __int8 m_bBeingPushed : 1;
    __int8 m_bStopFlag : 1;
    __int8 m_bWasScaredByRegion : 1;
    __int8 m_bNeverFlee : 1;
    __int8 m_bSelected : 1;
    __int8 m_bAllowRandomStateChanges : 1;
    float m_nSelectedTimer;
    unsigned __int8 m_eFlowUsage;
    unsigned __int8 m_nActorTemplateIndex;
    unsigned __int8 m_nCurrentAccessFlags;
    unsigned __int8 m_nGrantedAccessFlags;
    unsigned __int8 m_eWantedGait;
    unsigned __int8 m_eWantedSpeed;
    SVector2 m_vWantedDirection;
    SVector2 m_vWantedFacing;
    unsigned int m_nAnimSourceID;
    unsigned int m_nAnimSourceDataIndex;
    ZAnimationLibrary* m_pAnimLib;
    ZCharacterController* m_pCharacterController;
    __int16 m_nPusherActorIndex;
    float m_nTotalPushTime;
    float m_nRemainingPushTime;
    float4 m_vPushVelocity;
    SVector4 m_vLookatTarget;
    ZCrowdRegion* m_pLookatRegion;
    float m_blendDelta;
    float m_nLookAtHMTimeOut;
    float m_aHomePosition[2];
    ZCrowdRegion* m_pCurCrowdRegion;
    unsigned __int8 m_nVisualVariationIndex;
    float m_nSizeModifier;
    TEntityRef<ZLinkedEntity> m_pDrivingEntity;
    unsigned __int8 m_nPossesionType;

    enum EPossessionType : __int32
    {
        PT_NONE = 0x0,
        PT_CLOSE_COMBAT = 0x1,
        PT_ACT = 0x2
    };

    enum EAnimationOverride : unsigned __int32
    {
        AO_DISABLE_ALL = 0xFFFFFFFE,
        AO_NORMAL_IDLE = 0xFFFFFFFF
    };
};
