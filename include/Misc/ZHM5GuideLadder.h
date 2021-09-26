#pragma once

#include "ZHM5BaseGuide.h"

class ZHM5GuideLadder : public ZHM5BaseGuide
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	int m_nNumOfRungs;
	ZResourcePtr m_pHelper;
	float m_fHeight;
	SMatrix m_mvMountDismountBottom;
	SMatrix m_mvMountDismountTop;
	float4 m_vBottomMountDir;
	float4 m_vTopMountDir;
	bool m_bIgnoreTransformCallback;

	static SComponentMapEntry s_componentMap[0];
	static const float RUNG_HEIGHT_DIFF;
	static const float LADDER_WIDTH;
	static const float LADDER_DISMOUNT_HEIGHT;
	static const unsigned int MIN_NUM_OF_RUNGS;

	~ZHM5GuideLadder() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Init() override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;
	void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue) override;

	ZHM5GuideLadder() = default;
	static void RegisterType();
	ZHM5GuideLadder(ZComponentCreateInfo& pInfo);
	void CalculateAABB();
	SMatrix GetMountDismountBottomMatPos();
	SMatrix GetMountDismountTopMatPos();
	float4 GetBottomMountDir();
	float4 GetTopMountDir();
	float4 GetPosBetweenRung(const float4& vWorldPos, float fPrct, bool bFromTopRung);
	int GetNumOfRungs();
	void OnNumOfRungsChanged();
	void OnHelperChanged();
	void RecalcLadderProperties();
};
