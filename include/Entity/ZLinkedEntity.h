#pragma once

#include "ZGeomEntity.h"
#include "TComponentPtr.h"
#include "ShootColiId.h"
#include "ERenderGlowTypes.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SMatrix43.h"
#include "SQV.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "TEntityRef.h"
#include "THashMap.h"
#include "ZEvent.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"
#include "float4.h"

struct SCapsule;
class IBoneAnimator;
class IBoneWeightManagerEntity;
class ZAnimationBoneData;
class ZAnimationBoneHierarchy;
class ZAnimationBonePose;
class ZAnimationRig;
class ZBoneEntity;
class ZComponentCreateInfo;
class ZEventNull;
class ZSpatialEntity;
class ZString;
struct SCamAlignData;
struct STypeID;
struct SVector3;
template <class A, class B> class TDefaultHashMapPolicy;
template <class T> class alignas(8) ZDelegate;

class ZLinkedEntity : public ZGeomEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SBoneFitInfo
	{
		unsigned int m_nBoneGlobalID;
		float m_fRadius;
		bool m_bCenterInsteadOfPivot;

		SBoneFitInfo(const unsigned int nBoneGlobalId, const float fRadius, const bool bCenterInsteadOfPivot);
		SBoneFitInfo() = default;
		float4 GetPos(const ZLinkedEntity* pLinked) const;
	};

	class ZCapsuleFit
	{
	public:
		SBoneFitInfo m_bone0;
		SBoneFitInfo m_bone1;
		SBoneFitInfo m_bone2;
		unsigned int m_EColiPart;

		ZCapsuleFit(const SBoneFitInfo bone0, const SBoneFitInfo bone1, const SBoneFitInfo bone2, const ShootColiId::ValueType& EColiId);
		SCapsule GetCapsule(const ZLinkedEntity* pLinked) const;
	};

	TEntityRef<IBoneAnimator> m_BoneAnimator;
	TEntityRef<IBoneWeightManagerEntity> m_BoneWeightManagerEntity;
	TEntityRef<IBoneAnimator> m_pCurrentBoneAnimator;
	TComponentPtr<ZAnimationBonePose> m_pBoneCache;
	const ZAnimationBoneData* m_pBoneData;
	TArray<bool> m_aBoneVisibility;
	THashMap<unsigned int, TEntityRef<ZBoneEntity>, TDefaultHashMapPolicy<unsigned int, TEntityRef<ZBoneEntity>>> m_createdBoneEntities;
	SCamAlignData* m_pCameraAlignedBonesData;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_BonesChangedListeners;
	ZEvent<ZAnimationRig const*, SMatrix const*, ZEventNull, ZEventNull, ZEventNull> m_AnimationRigChangedListeners;
	float m_fBoneScale;
	bool m_bHasPrimitive : 1;
	bool m_bVisible : 1;
	bool m_bBonesChanged : 1;
	bool m_bBoundsUpdated : 1;
	bool m_bRealVisible : 1;
	bool m_bForceBoneUpdates : 1;
	unsigned int m_eStoredGlowType : 3;

	static SComponentMapEntry s_componentMap[0];

	~ZLinkedEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	void OnVisibleOnScreenChanged(bool bVisibleOnScreen) override;
	const ERenderGlowTypes GetGlowType() const override;
	void SetGlowType(const ERenderGlowTypes eGlowType) override;
	void HandlePrimitiveChanged(const ZResourcePtr& oldValue) override;
	virtual int GetBoneMeshID(const unsigned int nBoneGlobalID) const;
	virtual int GetBoneMeshID(const ZString& sBoneName) const;
	virtual SMatrix43 GetBoneWorldTransformByBoneGlobalID(const unsigned int nBoneGlobalID) const;
	virtual bool GetBoneWorldCenSizeByBoneGlobalID(const unsigned int nBoneGlobalID, SVector3& vCen, SVector3& vSize) const;
	virtual SMatrix43 GetBoneLocalTransformByBoneGlobalID(const unsigned int nBoneGlobalID) const;
	virtual SMatrix43 GetBoneLocalTransformByBoneGlobalID(const ZString& sBoneName) const;
	virtual SMatrix GetBoneLocalTransformByBoneGlobalIDWithDefault(const unsigned int nBoneGlobalID) const;
	virtual SQV GetBoneLocalTransformByBoneMeshIDSQV(const int nBoneMeshID) const;
	virtual SQV GetBoneLocalTransformByBoneMeshIDRigSQV(const int nBoneMeshID) const;
	virtual bool GetBoneLocalCenSizeByBoneGlobalID(const unsigned int nBoneGlobalID, SVector3& vCen, SVector3& vSize) const;
	virtual bool HasBone(const ZString& sBoneName) const;
	virtual ZSpatialEntity* GetBoneEntity(const ZString& sBoneName);
	virtual ZSpatialEntity* GetBoneEntity(const unsigned int nBoneGlobalID);
	virtual const ZAnimationBoneData* GetBoneData() const;
	virtual void SetBoneData(const ZAnimationBoneData* pBoneData);
	virtual const ZAnimationBonePose* GetBonePose() const;
	virtual void SetBoneCache(const TArrayRef<SQV>& boneCache);
	virtual void SetBindPose();
	virtual TArrayRef<bool> GetBoneVisibilityArray() const;
	virtual void SetBoneVisibilityArray(const unsigned int nSize, const bool bDefaultVisibility);
	virtual void SetBoneVisibility(const ZString& sBoneName, const bool bBoneIsVisible);
	virtual void SetBoneVisibilityByBoneGlobalID(const int nBoneGlobalID, const bool bBoneIsVisible);
	virtual bool GetBoneVisibilityByBoneGlobalID(const int nBoneGlobalID) const;
	virtual bool AttachEntityToBone(ZSpatialEntity* pEntity, const unsigned int nBoneGlobalID);
	virtual bool DetachEntityFromBone(ZSpatialEntity* pEntity, const unsigned int nBoneGlobalID);
	virtual unsigned char GetBodyPartByBoneMeshID(const int nBoneMeshID) const;
	virtual void SetForceBoneUpdates(const bool bForceBoneUpdates);
	virtual bool RealVisible() const;
	virtual SMatrix43 GetBoneWorldTransformByBoneMeshID(const int nBoneMeshID, const ZAnimationBonePose* pBonePose, const ZAnimationBoneHierarchy* pHierarchy) const;
	virtual SMatrix43 GetBoneWorldTransformByBoneMeshID(const int nBoneMeshID) const;
	virtual bool GetBoneWorldCenSizeByBoneMeshID(const int nBoneMeshID, SVector3& vCen, SVector3& vSize) const;
	virtual SMatrix43 GetBoneLocalTransformByBoneMeshID(const int nBoneMeshID) const;
	virtual bool GetBoneLocalCenSizeByBoneMeshID(const int nBoneMeshID, SVector3& vCen, SVector3& vSize) const;
	virtual bool HasPrimitive() const;
	virtual void EnsureBoneCacheInitialized();
	virtual void DestroyBoneCache();
	virtual bool IsRegisteredForBonesChangedListening(const ZDelegate<void __cdecl(void)>& fpCallback) const;
	virtual void RegisterForBonesChangedListening(const ZDelegate<void __cdecl(void)>& fpCallback);
	virtual void UnregisterForBonesChangedListening(const ZDelegate<void __cdecl(void)>& fpCallback);
	virtual bool IsRegisteredForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>& fpCallback) const;
	virtual void RegisterForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>& fpCallback);
	virtual void UnregisterForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>& fpCallback);
	virtual float GetBoneScale() const;
	virtual void SetBoneScale(float fScale);
	virtual SMatrix43 GetBoneRelativeTransformByBoneMeshIDs(int midStartBone, int midAncestorBone) const;

	ZLinkedEntity() = default;
	static void RegisterType();
	ZLinkedEntity(ZLinkedEntity& __that);
	ZLinkedEntity(ZComponentCreateInfo& Info);
	SCamAlignData* GetBoneCameraAlignData();
	void CopyBonePoseFromLinkedEntity(TEntityRef<ZLinkedEntity> pSourceLinkedEntity);
	void ClearPrimitiveData();
	bool FrameUpdatePre(const SMatrix* pCameraMatrix);
	void FrameUpdate(const SMatrix* pCameraMatrix);
	void OnBoneAnimatorChanged();
	void OnBoneWeightManagerEntityChanged();
	bool UpdateBoneCache(bool bPostUpdateBounds, const SMatrix* pCameraMatrix);
	void UpdateBoneEntities();
	void InitPrimitiveData();
	void OnHideBone(const ZString& sBoneName);
	void OnShowBone(const ZString& sBoneName);
	void OnBonesChanged();
	void SendBoneAnimatorInfo();
	void SendEmptyBoneAnimatorInfo();
	void ResizeBoneCache();
	SQV CalcBoneLocalTransformByBoneMeshID(int nBoneMeshID) const;
	SQV CalcBoneLocalTransformByBoneMeshID(int nBoneMeshID, const ZAnimationBonePose* pBonePose, const ZAnimationBoneHierarchy* pHierarchy, int nEndBoneMeshID) const;
	SQV CalcBoneLocalTransformByBoneMeshID(int nBoneMeshID, const ZAnimationRig* pAnimRig, int nEndBoneMeshID) const;
	void FindCameraAlignBones();
	ZLinkedEntity& operator=(ZLinkedEntity& __that);
};
