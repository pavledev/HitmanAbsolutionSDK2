#pragma once

#include "ZEntityImpl.h"
#include "EActionType.h"
#include "TEntityRef.h"
#include "TResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZEntityRef.h"
#include "ZString.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZBoxVolumeEntity;
class IEntity;
class IHM5Item;
class ZComponentCreateInfo;
class ZGeomEntity;
class ZHM5BaseCharacter;
class ZHM5BaseMovement;
class ZHitman5;
class ZIllegalActionEntity;
class ZSpatialEntity;
class ZTextListData;
struct SMatrix43;
struct STypeID;
struct float1;

class ZHM5Action : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	EActionType m_eActionType;
	ZEntityRef m_Object;
	TEntityRef<ZBoxVolumeEntity> m_rActivateBoxVolume;
	ZString m_sActionName;
	bool m_bVisible;
	ZEntityRef m_Listener;
	ZString m_sDefaultItemName;
	TResourcePtr<ZTextListData> m_pTextListResource;
	ZString m_sExitTextID;
	ZString m_sCachedString;
	ZString m_sCachedExitString;
	TEntityRef<ZSpatialEntity> m_3dPromptPosition;
	TEntityRef<ZIllegalActionEntity> m_rIllegalActionEntity;
	TEntityRef<IHM5Item> m_rUserDataItem;
	ZHM5BaseMovement* m_pActionMovement;
	float4 m_vObjectCenter;
	float4 m_vObjectSize;
	bool m_bObjectDirty;
	bool m_bCallbackRegistered;
	ZEntityRef m_OwnListener;
	ZEntityRef m_rVentShaftInstance;
	float m_fButtonHeightOffset;

	static SComponentMapEntry s_componentMap[0];
	static const float s_fACTIONS_INTERACTRANGE;
	static const float s_fACTIONS_INTERACTDOORS;
	static const float s_fACTIONS_FARPROMPTRANGEPICKUPS;
	static const float s_fACTIONS_FARPROMPTRANGEAGILITY;
	static const float s_fACTIONS_FARPROMPTRANGE;

	~ZHM5Action() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	ZHM5Action() = default;
	static void RegisterType();
	ZHM5Action(ZComponentCreateInfo& pInfo);
	void OnActionNameChanged();
	void OnActionTypeChanged();
	void OnSetObject(const ZEntityRef& rOldRef);
	void OnVisibleChanged();
	void OnDefaultItemNameChanged();
	void OnExitTextIDChanged();
	void OnTextListResourceChanged();
	void OnEnable();
	void OnDisable();
	EActionType GetActionType() const;
	void SetActionType(const EActionType ActionType);
	void SetObject(const ZEntityRef& rObject);
	ZEntityRef GetListener() const;
	void SetListener(const ZEntityRef& rRef);
	ZEntityRef GetOwnListener() const;
	void SetOwnListener(const ZEntityRef& rRef);
	void SetActionName(const ZString& ActionName);
	const ZString& GetLocalisedText() const;
	bool HasExitString() const;
	const ZString& GetLocalizedExitString() const;
	bool IsVisible() const;
	void SetVisible(const bool bValue);
	void GetObjectAABB(float4& vMin, float4& vMax) const;
	void GetObjectCenter(float4& vCenter) const;
	bool UpdateObjectAABB() const;
	void Execute(const TEntityRef<ZHM5BaseCharacter>& pOperator);
	ZSpatialEntity* GetGeomSpatial(const ZEntityRef& rRef) const;
	ZSpatialEntity* GetGeomSpatial() const;
	ZSpatialEntity* GetSpatial(const ZEntityRef& rRef) const;
	ZSpatialEntity* GetSpatial() const;
	void SetMovement(ZHM5BaseMovement* pMovement);
	ZHM5BaseMovement* GetMovement() const;
	void SetUserDataItem(const TEntityRef<IHM5Item>& pUserDataItem);
	TEntityRef<IHM5Item> GetUserDataItem() const;
	bool IsDirty() const;
	void Show(const bool bShow);
	void Reset();
	TEntityRef<IEntity> GetActionObject() const;
	TEntityRef<ZBoxVolumeEntity> GetActivateBoxVolume() const;
	bool IsInsideBoxVolume(const TEntityRef<ZHM5BaseCharacter>& pOperator) const;
	bool IsInsideBoxVolumeAndOriented(const TEntityRef<ZHM5BaseCharacter>& pOperator) const;
	void SetObjectMatPosDirty();
	bool IsAABBOverlappingObjectAABB(const float4& vMin, const float4& vMax);
	bool IsHitmanAABBOverlappingActionAABB();
	void AttachToAABBTree();
	void DetachFromAABBTree();
	void GeomTransformChangeCallback(const ZEntityRef& rEntity, const SMatrix43& m0);
	void RegisterObjectToWorldChangeCallBack(ZSpatialEntity* pEntity);
	void RegisterObjectToWorldChangeCallBack(const ZEntityRef& rRef);
	void UnregisterObjectToWorldChangeCallBack(ZSpatialEntity* pEntity);
	void UnregisterObjectToWorldChangeCallBack(const ZEntityRef& rRef);
	void SetVentShaftInstance(const ZEntityRef& rEntity);
	const ZEntityRef& GetVentShaftInstance() const;
	bool GetDist2DSq(const float4& vCharacter, float1& vDist2DSq) const;
	bool IsNearAction(const float4& vCharacter, const float fRange) const;
	static float4 GetHitmanPos(const TEntityRef<ZHitman5>& rHitman);
	float4 Get3dPromptPosition() const;
	float4 GetFarFeedbackRayPos(const float4& vOrigin, int iStyle);
	void CalculateVerticalLineToActionSpatial(const float4& vCenter, const float4& vTop, float4& vFrom, float4& vTo) const;
	bool IsIllegal() const;
	void SetButtonHeightOffset(float fHeight);
	float GetButtonHeightOffset() const;
	void UpdateCachedString();
	bool CalculateObjectAABB(float4& vMin, float4& vMax) const;
	ZGeomEntity* GetGeomEntity() const;
};
