#pragma once

#include "ZGeomEntity.h"
#include "IBoneAnimator.h"
#include "IBoneWeightManagerEntity.h"
#include "TComponentPtr.h"
#include "ZBoneEntity.h"
#include "SCamAlignData.h"

class ZLinkedEntity : public ZGeomEntity
{
public:
    TEntityRef<IBoneAnimator> m_BoneAnimator;
    TEntityRef<IBoneWeightManagerEntity> m_BoneWeightManagerEntity;
    TEntityRef<IBoneAnimator> m_pCurrentBoneAnimator;
    TComponentPtr<ZAnimationBonePose> m_pBoneCache;
    const ZAnimationBoneData* m_pBoneData;
    TArray<bool> m_aBoneVisibility;
    THashMap<unsigned int, TEntityRef<ZBoneEntity>, TDefaultHashMapPolicy<unsigned int, TEntityRef<ZBoneEntity> > > m_createdBoneEntities;
    SCamAlignData* m_pCameraAlignedBonesData;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_BonesChangedListeners;
    ZEvent<ZAnimationRig const*, SMatrix const*, ZEventNull, ZEventNull, ZEventNull> m_AnimationRigChangedListeners;
    float m_fBoneScale;
    __int8 m_bHasPrimitive : 1;
    __int8 m_bVisible : 1;
    __int8 m_bBonesChanged : 1;
    __int8 m_bBoundsUpdated : 1;
    __int8 m_bRealVisible : 1;
    __int8 m_bForceBoneUpdates : 1;
    unsigned __int32 m_eStoredGlowType : 3;

    virtual int GetBoneMeshID(const unsigned int);
    virtual int GetBoneMeshID(const ZString*);
    virtual SMatrix43* GetBoneWorldTransformByBoneGlobalID(SMatrix43* result, const unsigned int);
    virtual bool GetBoneWorldCenSizeByBoneGlobalID(const unsigned int, SVector3*, SVector3*);
    virtual SMatrix43* GetBoneLocalTransformByBoneGlobalID(SMatrix43* result, const unsigned int);
    virtual SMatrix43* GetBoneLocalTransformByBoneGlobalID(SMatrix43* result, const ZString*);
    virtual SMatrix* GetBoneLocalTransformByBoneGlobalIDWithDefault(SMatrix* result, const unsigned int);
    virtual SQV* GetBoneLocalTransformByBoneMeshIDSQV(SQV* result, const int);
    virtual SQV* GetBoneLocalTransformByBoneMeshIDRigSQV(SQV* result, const int);
    virtual bool GetBoneLocalCenSizeByBoneGlobalID(const unsigned int, SVector3*, SVector3*);
    virtual bool HasBone(const ZString*);
    virtual ZSpatialEntity* GetBoneEntity(const ZString*);
    virtual ZSpatialEntity* GetBoneEntity(const unsigned int);
    virtual const ZAnimationBoneData* GetBoneData();
    virtual void SetBoneData(const ZAnimationBoneData*);
    virtual const ZAnimationBonePose* GetBonePose();
    virtual void SetBoneCache(const TArrayRef<SQV>*);
    virtual void SetBindPose();
    virtual TArrayRef<bool>* GetBoneVisibilityArray(TArrayRef<bool>* result);
    virtual void SetBoneVisibilityArray(const unsigned int, const bool);
    virtual void SetBoneVisibility(const ZString*, const bool);
    virtual void SetBoneVisibilityByBoneGlobalID(const int, const bool);
    virtual bool GetBoneVisibilityByBoneGlobalID(const int);
    virtual bool AttachEntityToBone(ZSpatialEntity*, const unsigned int);
    virtual bool DetachEntityFromBone(ZSpatialEntity*, const unsigned int);
    virtual unsigned __int8 GetBodyPartByBoneMeshID(const int);
    virtual void SetForceBoneUpdates(const bool);
    virtual bool RealVisible();
    virtual SMatrix43* GetBoneWorldTransformByBoneMeshID(SMatrix43* result, const int, const ZAnimationBonePose*, const ZAnimationBoneHierarchy*);
    virtual SMatrix43* GetBoneWorldTransformByBoneMeshID(SMatrix43* result, const int);
    virtual bool GetBoneWorldCenSizeByBoneMeshID(const int, SVector3*, SVector3*);
    virtual SMatrix43* GetBoneLocalTransformByBoneMeshID(SMatrix43* result, const int);
    virtual bool GetBoneLocalCenSizeByBoneMeshID(const int, SVector3*, SVector3*);
    virtual bool HasPrimitive();
    virtual void EnsureBoneCacheInitialized();
    virtual void DestroyBoneCache();
    virtual bool IsRegisteredForBonesChangedListening(const ZDelegate<void __cdecl(void)>*);
    virtual void RegisterForBonesChangedListening(const ZDelegate<void __cdecl(void)>*);
    virtual void UnregisterForBonesChangedListening(const ZDelegate<void __cdecl(void)>*);
    virtual bool IsRegisteredForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>*);
    virtual void RegisterForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>*);
    virtual void UnregisterForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>*);
    virtual float GetBoneScale();
    virtual void SetBoneScale(float);
    virtual SMatrix43* GetBoneRelativeTransformByBoneMeshIDs(SMatrix43* result, int, int);

    class alignas(4) SBoneFitInfo
    {
    public:
        unsigned int m_nBoneGlobalID;
        float m_fRadius;
        bool m_bCenterInsteadOfPivot;
    };

    class ZCapsuleFit
    {
    public:
        SBoneFitInfo m_bone0;
        SBoneFitInfo m_bone1;
        SBoneFitInfo m_bone2;
        unsigned int m_EColiPart;
    };
};
