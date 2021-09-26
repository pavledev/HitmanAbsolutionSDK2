#pragma once

#include "TArrayRef.h"

class ZAnimationRig;
struct SBodyJointDesc;
struct SBodyPartDesc;

class __declspec(novtable) IRagdollDesc
{
public:
	virtual ~IRagdollDesc() = default;
	virtual const TArrayRef<unsigned int> GetRagdollBodyParts() const = 0;
	virtual const TArrayRef<unsigned int> GetConstraintBoneMap() const = 0;
	virtual unsigned int GetRootBoneId() const = 0;
	virtual float GetMassPercentage(const unsigned int param1) const = 0;
	virtual float GetTotalMass() const = 0;
	virtual const TArrayRef<unsigned int> GetBodyPartIgnoreCollisionPairs() const = 0;
	virtual const ZAnimationRig* GetRig() const = 0;
	virtual void SetRig(const ZAnimationRig* animationRig) = 0;
	virtual TArrayRef<SBodyPartDesc> GetBodyPartDescs() = 0;
	virtual TArrayRef<SBodyJointDesc> GetBodyJointDescs() = 0;

	IRagdollDesc() = default;
};
