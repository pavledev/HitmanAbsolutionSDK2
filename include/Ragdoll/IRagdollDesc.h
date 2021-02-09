#pragma once

#include "TArrayRef.h"
#include "ZAnimationRig.h"
#include "SBodyPartDesc.h"
#include "SBodyJointDesc.h"

class IRagdollDesc
{
public:
    virtual ~IRagdollDesc();
    virtual const TArrayRef<unsigned int>* GetRagdollBodyParts(const TArrayRef<unsigned int>* result);
    virtual const TArrayRef<unsigned int>* GetConstraintBoneMap(const TArrayRef<unsigned int>* result);
    virtual unsigned int GetRootBoneId();
    virtual float GetMassPercentage(const unsigned int);
    virtual float GetTotalMass();
    virtual const TArrayRef<unsigned int>* GetBodyPartIgnoreCollisionPairs(const TArrayRef<unsigned int>* result);
    virtual const ZAnimationRig* GetRig();
    virtual void SetRig(const ZAnimationRig*);
    virtual TArrayRef<SBodyPartDesc> GetBodyPartDescs();
    virtual TArrayRef<SBodyJointDesc> GetBodyJointDescs();
};
