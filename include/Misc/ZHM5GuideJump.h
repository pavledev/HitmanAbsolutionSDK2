#pragma once

#include "ZHM5BaseGuide.h"
#include "eEdgeEnd.h"

class ZRayQueryInput;

class ZHM5GuideJump : public ZHM5BaseGuide
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum eJumpType
	{
		eJump4m_Straight = 0,
		eJump8_4m_Down = 1,
		eJump6_2m_Down = 2,
		eJump6_2m_Up = 3,
		eJump8_4m_Down_Short_Roll = 4
	};

	enum EForceDismountBehavior
	{
		eDontCare = 0,
		eForceStand = 1,
		eForceSneak = 2
	};

	enum EForceDropDownDirection
	{
		eFaceDontCare = 0,
		eFaceLedge = 1,
		eFaceLeft = 2,
		eFaceRight = 3,
		eTurn180 = 4
	};

	struct SCheckedPos
	{
		float4 m_vPos;
		bool m_bSafe;

		SCheckedPos() = default;
		void Reset();
	};

	struct SSafeZone
	{
		float m_fFromX;
		float m_fToX;
		bool m_bSafe;

		SSafeZone() = default;
		void Reset();
	};

	IPhysicsObject* m_pAnchor;
	SMatrix m_mvAnchorMatPos;
	float4 m_vAnchorHalfSize;
	bool m_bKickNPCIsAccident;
	bool m_bBodyDumpEnabled;
	bool m_bDumpedBodyHidden;
	bool m_bHangable;
	bool m_bHangAutoDismount;
	SVector2 m_vSize;
	TEntityRef<ZHM5GuideJump> m_LandingZone;
	eJumpType m_JumpType;
	EForceDismountBehavior m_eForceGettingUpBehavior;
	EForceDismountBehavior m_eForceDropDownBehavior;
	EForceDropDownDirection m_eForceDropDownDirection;
	bool m_bDisableAnchor;
	bool m_bAllowDropDown;
	bool m_bMountableFromBottom;
	SVector3 m_vPlaneNormal;
	SVector3 m_vCenterToEdgeDir;
	float m_fPullIn;
	ZHM5BaseGuide* m_pLeftSideConnectedGuide;
	ZHM5BaseGuide* m_pRightSideConnectedGuide;
	TArray<SSafeZone> m_SafeZones;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnJump;
	static unsigned int m_snOnJumpLandGrab;
	static unsigned int m_snOnJumpLand;

	~ZHM5GuideJump() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue) override;
	bool IsPointOnGuide(const SMatrix& mvMatPos) override;
	bool IsPointConnectedToGuide(const SMatrix& mvMatPos) override;
	void RemoveConnection(ZHM5BaseGuide* pBaseGuide) override;
	ZHM5BaseGuide::SLimits GetLimits() override;
	void Activate_InitSafeZones(const TArrayRef<ZRayQueryOutput>& aAlignResults) override;
	virtual float4 CalcGetLineEdgeIntersection(const float4& vStart, const float4& vEnd, bool bClamp, float fEdgeThreshold);
	virtual void OnSizeChanged();
	virtual void OnLandingZoneChanged();
	virtual void OnDisableAnchorChanged();

	ZHM5GuideJump() = default;
	static void RegisterType();
	ZHM5GuideJump(ZComponentCreateInfo& pInfo);
	void CalculateAABB();
	float4 GetCenterToEdgeDir();
	float4 GetLocalEdgePoint0() const;
	float4 GetLocalEdgePoint1() const;
	float4 GetClosestEdgeEndPointToPoint(const float4& vPoint);
	bool GetPointSide(const float4& vPoint) const;
	float4 GetEdgeEndPoint(bool bRight) const;
	float4 CalcGetClosestPointToEdge(const float4& vPoint, const float4& vPullDir, float fEdgeThreshold);
	float4 CalcGetClosestPointToEdge(const float4& vPoint, float fEdgeThreshold);
	eEdgeEnd IsPointOnTheEdgeEnd(const float4& vPoint, float fEdgeThreshold);
	bool IsInEarlyJumpZone(SMatrix43 mvMatPos);
	bool IsInMountFromTopZone(SMatrix43 mvMatPos);
	SVector2 GetSize() const;
	IPhysicsObject* HasAnchor();
	bool MapPointToSafePoint(float4& vPoint);
	float PullInLength();
	ZHM5BaseGuide* GetConnectedGuide(bool bRight);
	bool IsPointOnLedgeLimits(const float4& vWorldPoint, float fThreshold);
	ZHM5BaseGuide* GetGuideForPoint(const float4& vWorldPoint);
	SMatrix GetRotationToPoint(const float4& vPoint, float fTurnCornerDist);
	bool DropDownAllowed() const;
	bool MountableFromBottom() const;
	bool IsHangAble() const;
	bool AutoDismountFromHang() const;
	EForceDismountBehavior GetForceGettingUpBehavior() const;
	EForceDismountBehavior GetForceDropDownBehavior() const;
	EForceDropDownDirection GetForceDropDownDirection() const;
	void SignalJumpPin();
	void SignalJumpLandGrabPin();
	void SignalJumpLandPin();
	bool GetDumpedBodyHidden() const;
	bool GetBodyDumpEnabled() const;
	bool ShouldCreateAnchor() const;
	void CalcAnchorMatPosSize();
	IPhysicsObject* GenerateColiAtEdge();
	void AlignPosToColi(float4& vPos);
	void InitSafeZones(const TArrayRef<ZRayQueryOutput>& aAlignResults);
	void BuildSafeZoneRaycasts(TArray<ZRayQueryInput>& outQueries);
	bool IsPointSafe(const float4& vPoint);
	unsigned int GetSafeZoneIndex(const float4& vPoint);
	void CollectConnectedGuides();
	void SetConnectedGuide(ZHM5BaseGuide* pGuide, bool bRight);
	float GetCosAngleBetweenGuide(ZHM5BaseGuide* pGuide) const;
	ZHM5BaseGuide* GetConnectedGuideToPoint(const float4& vPoint, unsigned int nGuideFilter, bool bIgnoreInvalid);
};
