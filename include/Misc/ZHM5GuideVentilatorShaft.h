#pragma once

#include "ZSpatialEntity.h"
#include "IHM5ActionEntityListener.h"
#include "ZSpline.h"
#include "ZHM5VentilatorShaftNodeEntity.h"

class ZHM5VentilatorShaftNodeEntity;
class ZHitman5;

class ZHM5GuideVentilatorShaft : public ZSpatialEntity, public IHM5ActionEntityListener
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TArray<TEntityRef<ZHM5VentilatorShaftNodeEntity>> m_Nodes;
	TEntityRef<ZHM5Action> m_Action;
	ZSpline* m_pSpline;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5GuideVentilatorShaft() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	bool GetActionAABB(const ZHM5Action* pAction, float4& vMin, float4& vMax) const override;
	bool IsActionValid(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;
	bool ActivateAction(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;

	ZHM5GuideVentilatorShaft() = default;
	static void RegisterType();
	ZHM5GuideVentilatorShaft(ZComponentCreateInfo& pInfo);
	ZSpline* GetVentilatorSpline() const;
	float GetDistanceToMountPoint(const float4& p0, unsigned int iIdx) const;
	float GetDistanceToMountPoint(const TEntityRef<ZHitman5>& pHitman, unsigned int iIdx) const;
	unsigned int GetClosestMountPointIdx(const float4& p0) const;
	unsigned int GetSplineIdxFromGuideIdx(unsigned int iIdx) const;
	ZSplinePosition GetSplinePositionFromGuideIdx(unsigned int iIdx) const;
	float4 GetMountPosition(unsigned int iIdx) const;
	float4 GetMountDirection(unsigned int iIdx) const;
	float GetEntranceHeight(unsigned int iIdx) const;
	const TEntityRef<ZSpatialEntity>& GetEntrancePeekPosition(unsigned int iIdx) const;
	unsigned int GetNodeIdxFromMountIdx(unsigned int iIdx) const;
	ZHM5VentilatorShaftNodeEntity::EType GetNodeType(unsigned int iIdx) const;
	TEntityRef<ZHM5VentilatorShaftNodeEntity> GetNode(unsigned int iIdx) const;
	ZHM5VentilatorShaftNodeEntity::EType GetMountNodeType(unsigned int iMountIdx) const;
	void ActivateEnterAnimationOnEntrance(unsigned int iIdx);
	void ActivateExitForwardAnimationOnEntrance(unsigned int iIdx);
	void ActivateExitBackwardsAnimationOnEntrance(unsigned int iIdx);
	void UpdatePosition(const ZSplinePosition& SplinePosition);
	float4 GetArmMovement(const ZSplinePosition& SplinePosition) const;
	bool IsNodeInList(TEntityRef<ZHM5VentilatorShaftNodeEntity>& Ref);
	float4 GetClosestGuidePositionFromWorldPos(const float4& p0) const;
	ZSpline* GetSpline() const;
	TEntityRef<ZHitman5> Hitman() const;
	void OnNodeChanged(TEntityRef<ZHM5VentilatorShaftNodeEntity>& Ref);
	void UpdateNodes();
};
