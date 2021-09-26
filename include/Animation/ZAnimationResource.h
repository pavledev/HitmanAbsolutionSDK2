#pragma once

#include "ZRuntimeResourceID.h"
#include "SMatrix43.h"
#include "MR.h"

class ZAnimatedBoneScales;
class ZFoVAnimation;
class ZResourcePending;

class ZAnimationResource
{
public:
	ZAnimationResource* m_pNext;
	ZAnimationResource* m_pPrevious;
	ZRuntimeResourceID m_ridResource;
	SMatrix43 m_sequenceOrigin;
	ZFoVAnimation* m_pFoVAnimation;
	ZAnimatedBoneScales* m_pAnimatedBoneScales;
	MR::IAnimSource* m_pAnimationSource;
	MR::RigToAnimMap* m_pRigToAnimMap;
	MR::EventSequenceHeader* m_pEventSequenceHeader;
	MR::Rig* m_pRig;

	ZAnimationResource() = default;
	ZAnimationResource(ZResourcePending& resourcePending);
	~ZAnimationResource() = default;
	MR::IAnimSource* GetAnimationSource() const;
	MR::Rig* GetRig() const;
	MR::RigToAnimMap* GetRigToAnimMap() const;
	ZRuntimeResourceID GetRuntimeResourceID() const;
	SMatrix43 GetSequenceOrigin() const;
	ZFoVAnimation* GetFoVAnimation() const;
	ZAnimatedBoneScales* GetAnimatedBoneScales() const;
	ZAnimationResource& operator=(const ZAnimationResource& __that);
};
