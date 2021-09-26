#pragma once

#include "TEntityRef.h"
#include "ICollisionManager.h"
#include "SMatrix.h"
#include "float4.h"

class IAnimPlayerEntity;
class ZEventNull;
class ZHM5BaseCharacter;
struct SBox;
struct float1;
template <class A, class B, class C, class D, class E> class ZEvent;

class __declspec(novtable) IHM5Door
{
public:
	enum EDoorState
	{
		DS_CLOSED = 0,
		DS_OPEN = 1,
		DS_OPENING = 2,
		DS_CLOSING = 3
	};

	enum EDoorType
	{
		DT_SINGLEDOOR = 0,
		DT_DOUBLEDOOR = 1
	};

	enum ECPDoorLockType
	{
		CPDLT_NORMAL_LOCK = 0,
		CPDLT_PUSH_BAR_PAD_LOCK = 1
	};

	enum EInitialState
	{
		IS_CLOSED = 0,
		IS_OPEN = 1,
		IS_OPEN_IN = 2,
		IS_OPEN_OUT = 3
	};

	enum EOpenDir
	{
		OD_AWAY = 0,
		OD_TOWARS = 1,
		OD_IN = 2,
		OD_OUT = 3
	};

	enum eCloseMode
	{
		CM_AUTOCLOSE = 0,
		CM_MANUALCLOSE = 1,
		CM_NEVERCLOSE = 2
	};

	enum EOpenMode
	{
		OM_TWO_WAY = 0,
		OM_OPEN_POS_SIDE_ONLY = 1,
		OM_OPEN_NEG_SIDE_ONLY = 2,
		OM_DISABLED = 3
	};

	virtual void OperateDoor(const TEntityRef<ZHM5BaseCharacter>& entityRef, bool param2, bool param3) = 0;
	virtual EDoorType GetDoorType() = 0;
	virtual EDoorState GetDoorState() = 0;
	virtual EOpenMode GetOpenMode() = 0;
	virtual ECPDoorLockType GetCPDoorLockType() = 0;
	virtual float4 GetWorldRefNormal() const = 0;
	virtual SBox GetDoorBoundingBox() = 0;
	virtual ZEvent<TEntityRef<IHM5Door>, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnDoorOpenedEvent() = 0;
	virtual ZEvent<TEntityRef<IHM5Door>, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnDoorClosedEvent() = 0;
	virtual ~IHM5Door() = default;
	virtual SMatrix GetPickLockMatPos(const SMatrix& matrix) = 0;
	virtual bool IsCheckpointDoor() = 0;
	virtual bool IsCharacterInside(TEntityRef<ZHM5BaseCharacter> entityRef) = 0;
	virtual bool IsHitmanBlockingDoor(const TEntityRef<ZHM5BaseCharacter>& entityRef) = 0;
	virtual SMatrix GetParentTransform() = 0;
	virtual TEntityRef<IAnimPlayerEntity> GetDoorAnimator() = 0;
	virtual bool LineIntersectsDoorBottom(const float4& param1, const float4& param2, float& param3, float& param4) = 0;
	virtual bool PointCloseToDoorBottom(const float4& param1, float param2, float& param3) = 0;
	virtual float1 CalcDotFromDeltaPositionToWorldRefNormal(const float4& param1) const = 0;
	virtual void SetOpenMode(EOpenMode openMode) = 0;
	virtual const float4& Get3dPromptPosition() const = 0;
	virtual void ShowPadlock(bool param1) = 0;
	virtual void OnLockDoor() = 0;
	virtual void OnUnlockDoor() = 0;

	static void RegisterType();
	IHM5Door() = default;
};
