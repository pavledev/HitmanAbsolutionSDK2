#pragma once

#include "ZEntityImpl.h"
#include "SVector4.h"
#include "SVector3.h"
#include "SMatrix43.h"
#include "float4.h"
#include "TEntityRef.h"
#include "SMatrix.h"
#include "SComponentMapEntry.h"
#include "ZEntityRef.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"

class ZBoundedEntity;
class ZComponentCreateInfo;
class ZEventNull;
struct SQuaternion;
struct STypeID;
template <class A, class B, class C, class D, class E> class ZEvent;
template <class T> class alignas(8) ZDelegate;

class ZSpatialEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EIncludeFlags
	{
		INCLUDE_NONE = 0,
		INCLUDE_CHILDREN = 1
	};

	enum ERoomBehaviour
	{
		ROOM_STATIC = 0,
		ROOM_DYNAMIC = 1
	};

	struct SHelperPrimitiveResource
	{
		bool bAllocated;
		bool bVisible;
		SMatrix43 mTransform;
		ZResourcePtr pHelperPrimitiveResource;

		SHelperPrimitiveResource() = default;
		~SHelperPrimitiveResource() = default;
	};

	ZSpatialEntity* m_pTransformParent;
	ZSpatialEntity* m_pTransformChildren;
	ZSpatialEntity* m_pTransformNext;
	ZSpatialEntity* m_pTransformPrev;
	ZEntityRef m_transformParentID;
	SVector4 m_vObjectToParentRotation;
	SVector3 m_vObjectToParentTranslation;
	bool m_bVisible;
	bool m_bIsPrivate;
	bool m_bDisplayBounds : 1;
	bool m_bDisplayPivot : 1;
	bool m_bDisplayHelpers : 1;
	bool m_bDisplayHelperPrimitive : 1;
	bool m_bEditorSelected : 1;
	bool m_bEditorVisible : 1;
	bool m_bParentHidden : 1;
	bool m_bSceneChild : 1;
	bool m_bFPSDrawMode : 1;
	bool m_bNotifyChange : 1;
	bool m_bRoomDynamicAlways : 1;
	bool m_bRoomDynamic : 1;
	bool m_bParentDynamic : 1;
	bool m_bIsDynamic : 1;
	bool m_bIncludeInParentsBounds : 1;
	bool m_bUpdateBoundsPending : 1;
	ZEvent<ZEntityRef const&, SMatrix43 const&, ZEventNull, ZEventNull, ZEventNull>* m_pTransformChangeCallBackEvent;

	static SComponentMapEntry s_componentMap[0];

	~ZSpatialEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void SetVisible(bool bVisible);
	virtual const ZBoundedEntity* QueryBoundedEntity() const;
	virtual ZBoundedEntity* QueryBoundedEntity();
	virtual void SetPrivate(bool bPrivate);
	virtual bool IsPrivate() const;
	virtual void SetFPSDrawMode(bool bFPSDrawMode);
	virtual void SetEditorSelected(bool bSelected);
	virtual bool GetEditorSelected() const;
	virtual void SetEditorVisible(bool bVisible);
	virtual bool GetEditorVisible() const;
	virtual void SetTransformParent(TEntityRef<ZSpatialEntity> Parent);
	virtual TEntityRef<ZSpatialEntity> GetTransformParentEntityPtr() const;
	virtual ZSpatialEntity* GetScene() const;
	virtual void CalculateBounds(float4& vMin_, float4& vMax_, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags);
	virtual float4 GetLocalCenter() const;
	virtual float4 GetLocalHalfSize() const;
	virtual void OnObjectToParentChanged();
	virtual void OnTransformParentIDChanged();
	virtual void OnVisibleChanged(const bool& bWasVisible);
	virtual void OnSpatialChange();

	ZSpatialEntity() = default;
	static void RegisterType();
	void OnSetVisible(bool bVisible);
	void OnMakeVisible();
	void OnMakeInvisible();
	ZSpatialEntity(const ZSpatialEntity& __that);
	ZSpatialEntity(ZComponentCreateInfo& Info);
	bool GetVisible() const;
	bool IsFPSDrawMode() const;
	ZSpatialEntity* GetTransformParent() const;
	void AttachChild(ZSpatialEntity* pChild);
	void DetachChild(ZSpatialEntity* pChild);
	void AttachTo(ZSpatialEntity* pParent);
	void Detach();
	void GetObjectToWorldMatrixTo3x4Mem(float4* pOutputMatrix3x4Input) const;
	void GetObjectToWorldMatrixTo4x3Mem(SMatrix43& mOutput) const;
	SMatrix GetObjectToWorldMatrix() const;
	void SetObjectToParentMatrix(const SMatrix& mObjectToParent);
	void SetObjectToParentMatrixVerify(const SMatrix& mObjectToParent);
	void SetObjectToWorldMatrixNoChangeHandlers(const SMatrix& mObjectToWorld);
	void SetObjectToWorldMatrix(const SMatrix& mObjectToWorld);
	void SetWorldPosition(const float4& vWorldPosition);
	void SetLocalPosition(const float4& vLocalPosition);
	const float4 GetLocalPosition() const;
	float4 GetLocalPosition(const float4& vWorldPosition) const;
	float4 GetWorldPosition() const;
	float4 GetWorldPosition(const float4& vLocalPosition) const;
	float4 GetLocalDirection(const float4& vWorldDirection) const;
	float4 GetWorldDirection(const float4& vLocalDirection) const;
	SMatrix TransformObjectToWorld(const SMatrix& mMatrix) const;
	SMatrix TransformWorldToObject(const SMatrix& mMatrix) const;
	void RegisterObjectToWorldChangeCallBack(const ZDelegate<void __cdecl(ZEntityRef const&, SMatrix43 const&)>& CallBack);
	void UnregisterObjectToWorldChangeCallBack(const ZDelegate<void __cdecl(ZEntityRef const&, SMatrix43 const&)>& CallBack);
	bool GetParentHidden();
	bool GetSceneChild();
	void SetTransformParentInternal(ZSpatialEntity* pTransformParent);
	void SetTransformChildren(ZSpatialEntity* pTransformChildren);
	void SetTransformNext(ZSpatialEntity* pTransformNext);
	void SetTransformPrev(ZSpatialEntity* pTransformPrev);
	void SetRoomDynamicAlways();
	ZSpatialEntity* GetTransformChildren() const;
	ZSpatialEntity* GetTransformNext() const;
	ZSpatialEntity* GetTransformPrev() const;
	const SMatrix GetObjectToParentMatrix() const;
	void OnIsPrivateChanged();
	void OnFPSDrawModeChanged();
	void OnRoomBehaviourChanged();
	ERoomBehaviour GetRoomBehaviour() const;
	void SetRoomBehaviour(ERoomBehaviour eRoomBehaviour, bool bPostInit);
	void SetRoomBehaviour(ERoomBehaviour eRoomBehaviour);
	SMatrix43 GetObjectToParent() const;
	void SetObjectToParent(const SMatrix43& mat, bool bPostInit);
	void OnObjectToWorldChanged();
	void SetParentHiddenRec(bool bParentHidden);
	void SetParentDynamic(bool bParentDynamic);
	void SetIsSceneChildRec(bool bIsSceneChild);
	void GetObjectToWorldSQVInternal(SQuaternion& qRes, float4& vRes) const;
	void NotifyChange();
	void NotifyChangeChildrenRec();
	ZSpatialEntity& operator=(const ZSpatialEntity& __that);
};
