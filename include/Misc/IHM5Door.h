#pragma once

#include "TEntityRef.h"
#include "ZHM5BaseCharacter.h"
#include "EDoorType.h"
#include "EDoorState.h"
#include "EOpenMode.h"
#include "ECPDoorLockType.h"
#include "IAnimPlayerEntity.h"

class IHM5Door
{
public:
    virtual void OperateDoor(const TEntityRef<ZHM5BaseCharacter>*, bool, bool);
    virtual EDoorType GetDoorType();
    virtual EDoorState GetDoorState();
    virtual EOpenMode GetOpenMode();
    virtual ECPDoorLockType GetCPDoorLockType();
    virtual float4* GetWorldRefNormal(float4* result);
    virtual SBox* GetDoorBoundingBox(SBox* result);
    virtual ZEvent<TEntityRef<IHM5Door>, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetOnDoorOpenedEvent();
    virtual ZEvent<TEntityRef<IHM5Door>, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetOnDoorClosedEvent();
    virtual ~IHM5Door();
    virtual SMatrix* GetPickLockMatPos(SMatrix* result, const SMatrix*);
    virtual bool IsCheckpointDoor();
    virtual bool IsCharacterInside(TEntityRef<ZHM5BaseCharacter>);
    virtual bool IsHitmanBlockingDoor(const TEntityRef<ZHM5BaseCharacter>*);
    virtual SMatrix* GetParentTransform(SMatrix* result);
    virtual TEntityRef<IAnimPlayerEntity>* GetDoorAnimator(TEntityRef<IAnimPlayerEntity>* result);
    virtual bool LineIntersectsDoorBottom(const float4*, const float4*, float*, float*);
    virtual bool PointCloseToDoorBottom(const float4*, float, float*);
    virtual float1* CalcDotFromDeltaPositionToWorldRefNormal(float1* result, const float4*);
    virtual void SetOpenMode(EOpenMode);
    virtual const float4* Get3dPromptPosition();
    virtual void ShowPadlock(bool);
    virtual void OnLockDoor();
    virtual void OnUnlockDoor();
};
