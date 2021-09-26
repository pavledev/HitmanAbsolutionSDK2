#pragma once

#include "ZLinkedEntity.h"
#include "TEntityRef.h"
#include "TMultiMap.h"
#include "ERenderGlowTypes.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SMatrix43.h"
#include "SQV.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "TEnumerator.h"
#include "ZEvent.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"

class IRenderMaterialEntity;
class IRenderPrimitive;
class ZAnimationBoneData;
class ZAnimationBoneHierarchy;
class ZAnimationBonePose;
class ZAnimationRig;
class ZComponentCreateInfo;
class ZEventNull;
class ZSpatialEntity;
class ZString;
struct STypeID;
struct SVector3;
template <class T> class TRefCountPtr;
template <class T> class alignas(8) ZDelegate;

class ZLinkedProxyEntity : public ZLinkedEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZLinkedEntity> m_Target;
	TArray<TRefCountPtr<IRenderPrimitive>> m_OwnPrimitives;
	unsigned int m_nOwnPrimitiveChangeCounter;
	TMultiMap<unsigned int, ZSpatialEntity*> m_OwnBoneAttachments;
	bool m_bOwnBoneAttachmentsCollected;

	static SComponentMapEntry s_componentMap[0];

	~ZLinkedProxyEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void ClearPrimitives() override;
	void ClearDecalPrimitives() override;
	bool IsPrimitiveAdded(const TRefCountPtr<IRenderPrimitive>& pPrimitive) const override;
	void AddPrimitive(const TRefCountPtr<IRenderPrimitive>& pPrimitive) override;
	void AddPrimitiveNoBoundsUpdate(const TRefCountPtr<IRenderPrimitive>& pPrimitive) override;
	void RemovePrimitive(const TRefCountPtr<IRenderPrimitive>& pPrimitive) override;
	void RemovePrimitiveNoBoundsUpdate(const TRefCountPtr<IRenderPrimitive>& pPrimitive) override;
	void PrimitiveUpdated(const TRefCountPtr<IRenderPrimitive>& pPrimitive, bool bUpdateBounds) override;
	TEnumerator<TRefCountPtr<IRenderPrimitive> const> GetPrimitiveEnumerator() const override;
	TEnumerator<TRefCountPtr<IRenderPrimitive>> GetPrimitiveEnumerator() override;
	unsigned int GetPrimitivesCount() const override;
	unsigned int GetPrimitiveChangeCounter() const override;
	bool GetCastShadows() const override;
	float GetLODScale() const override;
	float GetLODOffset() const override;
	void SetCastShadows(bool bCastShadows) override;
	void SetLODScale(float fLODScale) override;
	void SetLODOffset(float fLODOffset) override;
	void AttachMaterialModifier(IRenderMaterialEntity* pMaterialModifier) override;
	void DetachMaterialModifier(IRenderMaterialEntity* pMaterialModifier) override;
	TEnumerator<IRenderMaterialEntity* const> GetMaterialModifiers() const override;
	TEnumerator<IRenderMaterialEntity*> GetMaterialModifiers() override;
	void ClearMaterialModifiers() override;
	void SetOverrideMaterial(IRenderMaterialEntity* pMaterial) override;
	void ForceUpdateOverrideMaterial(IRenderMaterialEntity* pMaterial) override;
	IRenderMaterialEntity* GetOverrideMaterial() const override;
	const ERenderGlowTypes GetGlowType() const override;
	void SetGlowType(const ERenderGlowTypes eGlowType) override;
	ZResourcePtr GetResourcePtr() const override;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetResourceChangedEvent() const override;
	ZResourcePtr ChangePrimitiveResourcePtr(const ZResourcePtr& resourcePtr) override;
	void HandlePrimitiveChanged(const ZResourcePtr& oldValue) override;
	int GetBoneMeshID(const unsigned int nBoneGlobalID) const override;
	int GetBoneMeshID(const ZString& sBoneName) const override;
	SMatrix43 GetBoneWorldTransformByBoneGlobalID(const unsigned int nBoneGlobalID) const override;
	bool GetBoneWorldCenSizeByBoneGlobalID(const unsigned int nBoneGlobalID, SVector3& vCen, SVector3& vSize) const override;
	SMatrix43 GetBoneLocalTransformByBoneGlobalID(const unsigned int nBoneGlobalID) const override;
	SMatrix43 GetBoneLocalTransformByBoneGlobalID(const ZString& sBoneName) const override;
	SMatrix GetBoneLocalTransformByBoneGlobalIDWithDefault(const unsigned int nBoneGlobalID) const override;
	SQV GetBoneLocalTransformByBoneMeshIDSQV(const int nBoneMeshID) const override;
	SQV GetBoneLocalTransformByBoneMeshIDRigSQV(const int nBoneMeshID) const override;
	bool GetBoneLocalCenSizeByBoneGlobalID(const unsigned int nBoneGlobalID, SVector3& vCen, SVector3& vSize) const override;
	bool HasBone(const ZString& sBoneName) const override;
	ZSpatialEntity* GetBoneEntity(const ZString& sBoneName) override;
	ZSpatialEntity* GetBoneEntity(const unsigned int nBoneGlobalID) override;
	const ZAnimationBoneData* GetBoneData() const override;
	void SetBoneData(const ZAnimationBoneData* pBoneData) override;
	const ZAnimationBonePose* GetBonePose() const override;
	void SetBoneCache(const TArrayRef<SQV>& boneCache) override;
	void SetBindPose() override;
	TArrayRef<bool> GetBoneVisibilityArray() const override;
	void SetBoneVisibilityArray(const unsigned int nSize, const bool bDefaultVisibility) override;
	void SetBoneVisibility(const ZString& sBoneName, const bool bBoneIsVisible) override;
	void SetBoneVisibilityByBoneGlobalID(const int nBoneGlobalID, const bool bBoneIsVisible) override;
	bool GetBoneVisibilityByBoneGlobalID(const int nBoneGlobalID) const override;
	bool AttachEntityToBone(ZSpatialEntity* pEntity, const unsigned int nBoneGlobalID) override;
	bool DetachEntityFromBone(ZSpatialEntity* pEntity, const unsigned int nBoneGlobalID) override;
	unsigned char GetBodyPartByBoneMeshID(const int nBoneMeshID) const override;
	void SetForceBoneUpdates(const bool bForceBoneUpdates) override;
	bool RealVisible() const override;
	SMatrix43 GetBoneWorldTransformByBoneMeshID(const int nBoneMeshID, const ZAnimationBonePose* pBonePose, const ZAnimationBoneHierarchy* pHierarchy) const override;
	SMatrix43 GetBoneWorldTransformByBoneMeshID(const int nBoneMeshID) const override;
	bool GetBoneWorldCenSizeByBoneMeshID(const int nBoneMeshID, SVector3& vCen, SVector3& vSize) const override;
	SMatrix43 GetBoneLocalTransformByBoneMeshID(const int nBoneMeshID) const override;
	bool GetBoneLocalCenSizeByBoneMeshID(const int nBoneMeshID, SVector3& vCen, SVector3& vSize) const override;
	bool HasPrimitive() const override;
	void EnsureBoneCacheInitialized() override;
	void DestroyBoneCache() override;
	bool IsRegisteredForBonesChangedListening(const ZDelegate<void __cdecl(void)>& fpCallback) const override;
	void RegisterForBonesChangedListening(const ZDelegate<void __cdecl(void)>& fpCallback) override;
	void UnregisterForBonesChangedListening(const ZDelegate<void __cdecl(void)>& fpCallback) override;
	bool IsRegisteredForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>& fpCallback) const override;
	void RegisterForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>& fpCallback) override;
	void UnregisterForAnimationRigChangedListening(const ZDelegate<void __cdecl(ZAnimationRig const*, SMatrix const*)>& fpCallback) override;
	float GetBoneScale() const override;
	void SetBoneScale(float fScale) override;

	ZLinkedProxyEntity() = default;
	static void RegisterType();
	ZLinkedProxyEntity(ZLinkedProxyEntity& __that);
	ZLinkedProxyEntity(ZComponentCreateInfo& Info);
	void SetTarget(TEntityRef<ZLinkedEntity> target, bool bNonDestructive);
	void ClearTarget(bool bNonDestructive);
	TEntityRef<ZLinkedEntity> GetTargetRef() const;
	TEnumerator<TRefCountPtr<IRenderPrimitive>> GetOwnPrimitiveEnumerator();
	unsigned int GetOwnPrimitivesCount() const;
	bool HasOwnPrimitive() const;
	ZResourcePtr GetOwnResourcePtr() const;
	unsigned int GetOwnPrimitiveChangeCounter() const;
	TEnumerator<IRenderMaterialEntity* const> GetOwnMaterialModifiers() const;
	TEnumerator<IRenderMaterialEntity*> GetOwnMaterialModifiers();
	const ZLinkedEntity* GetTarget() const;
	ZLinkedEntity* GetTarget();
	void AddOwnPrimitive(const TRefCountPtr<IRenderPrimitive>& pPrimitive);
	void RemoveOwnPrimitive(const TRefCountPtr<IRenderPrimitive>& pPrimitive);
	void CollectOWnBoneAttachments();
	void AttachOWnBoneAttachmentsToTarget(TEntityRef<ZLinkedEntity> target);
	void UpdateOwnBoneAttachmentsBasedOnTarget(TEntityRef<ZLinkedEntity> target);
	void ClearTargetOfOwnData(bool bNonDestructive);
	ZLinkedProxyEntity& operator=(ZLinkedProxyEntity& __that);
};
