#pragma once

#include "ZHM5BaseGuide.h"
#include "ZHitman5.h"

class ZHM5GuideController
{
public:
	ZHM5BaseGuide* m_pNearestGuide;
	ZHM5BaseGuide* m_pNearestFarPromptGuide;
	TEntityRef<ZHitman5> m_pHitman;
	ZHM5BaseGuide* m_QueryGuides[128];

	ZHM5GuideController() = default;
	ZHM5GuideController(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5GuideController() = default;
	void Init();
	void Update();
	ZHM5BaseGuide* GetNearestGuide();
	ZHM5BaseGuide* GetNearestFarPromptGuide();
	ZHM5BaseGuide* GetNearestGuideToPoint(SVector3 vPoint, unsigned int nGuideFilter);
	ZHM5BaseGuide* GetGuideUpDown280(unsigned int nGuideFilter, bool bUp);
	unsigned int GetGuidesHitmanStandigOn(ZHM5BaseGuide** pGuides, unsigned int nSize, unsigned int nGuideFilter);
	ZHM5GuideWindow* GetWindowGuideForActor(const TEntityRef<ZActor>& pActor);
	bool CanHMUseLedgeGuide(const SMatrix& mvHMMatPos, const float4& vHMFacing, ZHM5BaseGuide* pGuide, bool& bCanShowFarPrompt);
	bool CanHMUseLadderGuide(const SMatrix& mvHMMatPos, const float4& vHMFacing, ZHM5BaseGuide* pGuide, bool& bCanShowFarPrompt);
	bool CheckGuideUpDown280(const SMatrix& mvHMMatPos, ZHM5BaseGuide* pGuide, const float4& vBoxHalfSize, bool bUp);
	bool CanHMUseWindowGuide(const float4& vHMFacing, ZHM5BaseGuide* pGuide, bool& bCanShowFarPrompt);
	TEntityRef<ZHitman5> Hitman() const;
};
