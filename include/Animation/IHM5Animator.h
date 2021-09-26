#pragma once

#include "IBoneAnimator.h"
#include "ZGameTime.h"

class ZHM5Ragdoll;
class ZLinkedEntity;
struct SQV;
template <class T> class TArray;
template <class T> class TArrayRef;
template <class T> class TEntityRef;

class __declspec(novtable) IHM5Animator : public IBoneAnimator
{
public:
	enum EBoneAnimator
	{
		BA_ANIMATION = 0,
		BA_RAGDOLL = 1,
		BA_BLENDING = 2,
		BA_POWEREDRAGDOLL = 3
	};

	~IHM5Animator() override = default;
	virtual void SetLinked(const TEntityRef<ZLinkedEntity>& entityRef) = 0;
	virtual void SetRagdoll(ZHM5Ragdoll* ragdoll) = 0;
	virtual void StartPoweredRagdoll() = 0;
	virtual bool IsPoweredRagdollStopping() = 0;
	virtual void StopPoweredRagdoll(float param1, bool param2) = 0;
	virtual void SetBlending(const float& param1, const TArrayRef<SQV> arrayRef) = 0;
	virtual EBoneAnimator GetCurrentAnimator() const = 0;
	virtual void SetCurrentAnimator(EBoneAnimator boneAnimator) = 0;
	virtual void SetUpdateRagdollOnce() = 0;
	virtual bool IsRagdollControlled() const = 0;
	virtual ZGameTime GetLastBodyPartPoseInWorldSpace(TArray<SQV>& array) = 0;

	static void RegisterType();
	IHM5Animator() = default;
};
