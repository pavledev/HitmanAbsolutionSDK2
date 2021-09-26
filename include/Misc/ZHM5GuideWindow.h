#pragma once

#include "ZHM5BaseGuide.h"
#include "ZTextListData.h"
#include "ZHM5GuideLedge.h"

class ZHM5GuideWindow : public ZHM5BaseGuide
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_pHelper;
	float m_fWidth;
	float m_fDepth;
	TEntityRef<ZSpatialEntity> m_WindowFrame;
	float m_fOffsetFromSide;
	bool m_bAccessibleFromRight;
	bool m_bAccessibleFromLeft;
	bool m_bClosed;
	bool m_bPushVictim;
	TResourcePtr<ZTextListData> m_pTextListResource;
	ZString m_sEnterTextID;
	ZString m_sCachedEnterString;
	bool m_bIgnoreTransformCallback;
	ZHM5GuideLedge* m_pConnectedWindows[2];
	float4 m_vClimbThrougPoints[2];

	static SComponentMapEntry s_componentMap[0];

	~ZHM5GuideWindow() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue) override;
	void RemoveConnection(ZHM5BaseGuide* pBaseGuide) override;

	ZHM5GuideWindow() = default;
	static void RegisterType();
	ZHM5GuideWindow(ZComponentCreateInfo& pInfo);
	void CalculateAABB();
	TEntityRef<ZSpatialEntity> GetWindowFrame();
	void GetWindowMatCenSize(SMatrix& m, float4& c, float4& s);
	float4 GetWindowCorner(bool bRightCorner) const;
	float4 GetSneakPastWindowPromptPos(bool bRightSide) const;
	void SetLedgeForWindow(ZHM5GuideLedge* pLedge);
	ZHM5GuideLedge* GetLedgeForWindow(int nIndex);
	float4* GetClimbThroughPoints();
	float GetWidth();
	float GetDepth();
	float GetHeight() const;
	float GetOffsetFromSide();
	bool IsAccessibleFromRight();
	bool IsAccessibleFromLeft();
	bool IsClosed();
	bool CanPushVictims() const;
	float4 CalcGetWindowPeekPos(bool bRight);
	float GetMinWindowOffset() const;
	float GetMinWindowWidth() const;
	float GetMinWindowDepth() const;
	bool IsBlocked();
	void SignalOnStarted();
	void SignalOnDone();
	bool HasEnterString() const;
	const ZString& GetLocalizedEnterString() const;
	void UpdateCachedString();
	void OnTextListResourceChanged();
	void OnEnterTextIDChanged();
	void OnWidthChanged();
	void OnDepthChanged();
	void OnWindowFrameChanged();
	void OnOffsetFromSideChanged();
	void RecalcWindowProperties();
	void OnHelperChanged();
};
