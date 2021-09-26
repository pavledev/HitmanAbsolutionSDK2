#pragma once

#include "ZBoundedEntity.h"
#include "IGateEntity.h"
#include "ZPresenceState.h"
#include "ZResourcePtr.h"
#include "SColorRGB.h"

class ZGateEntity : public ZBoundedEntity, public IGateEntity, public ZPresenceState
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bIsOpen;
	bool m_bSound;
	bool m_bVisibility;
	bool m_bPerception;
	bool m_bReasoning;
	SColorRGB m_ClosedColor;
	SVector3 m_vPortalSize;
	ZEntityRef m_RoomLeft;
	bool m_bFlipLeftNormal;
	ZEntityRef m_RoomRight;
	float m_fClipDistance;
	TArray<ZEntityRef> m_Clients;
	ZResourcePtr m_pHelper;
	SVector3 m_vConnectorOffset;
	bool m_bActive : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZGateEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	void OnObjectToParentChanged() override;
	virtual void SetOpen(bool bOpen);

	float4 GetPortalSize() const override;
	float4 GetConnectorOffset() const override;
	const TArray<ZEntityRef>& GetClientList() const override;
	const ZEntityRef& GetRoomLeft() const override;
	const ZEntityRef& GetRoomRight() const override;
	bool IsReasoning() const override;
	bool IsOpen() const override;
	const SColorRGB& GetClosedColor() const override;
	float GetClipDistance() const override;

	void OnStreamActivateStateChanged() override;

	ZGateEntity() = default;
	static void RegisterType();
	ZGateEntity(ZComponentCreateInfo& Info);
	void OnRoomChanged(const ZEntityRef& rCurrentRoom, const ZEntityRef& rOldRoom);
	void OnOpen();
	void OnClose();
	void OnSetIsOpen(bool bIsOpen);
	void OnIsOpenChanged();
	void OnSoundChanged();
	void OnVisibilityChanged();
	void OnPerceptionChanged();
	void OnReasoningChanged();
	void OnRoomLeftChanged(const ZEntityRef& oldRoom);
	void OnRoomRightChanged(const ZEntityRef& oldRoom);
	void OnClipDistanceChanged();
	void OnFlipNormalChanged();
	void OnPortalSizeChanged();
	void OnConnectorOffsetChanged();
	void OnClosedColorChanged();
	void OnHelperChanged();
};
