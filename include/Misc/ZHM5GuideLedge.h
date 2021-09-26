#pragma once

#include "ZHM5GuideJump.h"
#include "ZTextListData.h"

class SWindowZone;
class ZHM5GuideWindow;

class ZHM5GuideLedge : public ZHM5GuideJump
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SWindowZone
	{
		float4 mvFrom;
		float4 mvTo;
		ZHM5GuideWindow* m_pWindow;

		SWindowZone() = default;
		void Reset();
		bool IsPointInZone(const float4& vPoint);
		float4 PushPointOutOfZone(const float4& vPoint);
	};

	bool m_bMountableFromTop;
	bool m_bWalkable;
	bool m_bMountDismountLeft;
	bool m_bMountDismountRight;
	TResourcePtr<ZTextListData> m_pTextListResource;
	ZString m_sEnterTextID;
	ZString m_sCachedEnterString;
	SMatrix33 m_mLeftMDMArea;
	SMatrix33 m_mRightMDMArea;
	SVector3 m_vLeftMDMArea;
	SVector3 m_vRightMDMArea;
	TArray<SWindowZone> m_WindowZones;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5GuideLedge() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Init() override;
	void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue) override;
	bool IsMountableFromTop() const override;
	ZHM5BaseGuide::SLimits GetLimits() override;
	void Activate_InitSafeZones(const TArrayRef<ZRayQueryOutput>& aAlignResults) override;
	void OnSizeChanged() override;
	void OnLandingZoneChanged() override;
	virtual void OnWalkableChanged();
	virtual void OnMountDismountLeftChanged();
	virtual void OnMountDismountRightChanged();
	virtual void OnMountableFromTopChanged();

	ZHM5GuideLedge() = default;
	static void RegisterType();
	ZHM5GuideLedge(ZComponentCreateInfo& pInfo);
	bool IsWalkAble();
	bool IsMountDismountFromLeft();
	bool IsMountDismountFromRight();
	bool CanMountFromLeftRight(const float4& vPos, const float4& vFacing, bool& bRight);
	float4 ClearWindow(const float4& vWorldPoint);
	float4 ClearWindowForced(const float4& vWorldPoint, bool bRight);
	bool ClearFromWindow(const float4& vWorldPoint);
	bool ReachedWindowZone(const float4& vWorldPoint, bool bFromRight);
	ZHM5GuideWindow* GetWindowToPoint(const float4& vWorldPoint, bool bFromRight);
	bool CanMountFromWalk();
	SMatrix GetMountingArea(bool bRight) const;
	void FireEvent(const ZString& sPin, const ZVariantRef& data);
	bool HasEnterString() const;
	const ZString& GetLocalizedEnterString() const;
	void UpdateCachedString();
	void OnTextListResourceChanged();
	void OnEnterTextIDChanged();
	void CalcLeftRightMountDismountArea();
	void InitWindowZones();
};
