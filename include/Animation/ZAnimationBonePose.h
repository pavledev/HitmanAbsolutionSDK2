#pragma once

#include "IComponentInterface.h"
#include "TArrayRef.h"
#include "ZVariantRef.h"

class ZAnimationRig;
class ZAnimationBoneHierarchy;
class ZComponentCreateInfo;
struct SBoneDefinition;
struct SComponentMapEntry;
struct SQV;
struct STypeID;
struct SVector3;
struct float4;

class ZAnimationBonePose : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	void* m_pData;
	unsigned int m_nNumBones;
	unsigned int m_nAllocationSize;
	bool m_bHasBoneScales;
	bool m_bBoundsCalculated;

	~ZAnimationBonePose() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	static void RegisterType();
	ZAnimationBonePose(ZComponentCreateInfo& createInfo);
	ZAnimationBonePose() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void SetBonePose(const SQV* aBonePose, int nBoneCount);
	void SetFromBindSpacePose(const ZAnimationRig& rAnimRig, const SQV* aBindSpacePose);
	void CopyFrom(TArrayRef<SQV const> source);
	void CopyFrom(const ZAnimationBonePose& source);
	const SQV& operator[](unsigned int nIndex) const;
	SQV& operator[](unsigned int nIndex);
	const SQV& GetQV(int nIndex) const;
	unsigned int GetBoneCount() const;
	TArrayRef<SQV const> ToArrayRef() const;
	TArrayRef<SQV> ToArrayRef();
	TArrayRef<SVector3 const> GetBoneScales() const;
	TArrayRef<SVector3> GetBoneScales();
	void AllocateBoneScales();
	void ClearBoneScales();
	void Dump(const ZAnimationRig& rig) const;
	bool IsValid() const;
	const float4* GetBounds() const;
	float4* GetBounds();
	void GetBounds(float4& vMin, float4& vMax) const;
	void SetBounds(const float4& vMin, const float4& vMax);
	void CalculateBounds(const ZAnimationBoneHierarchy& hierarchy, const SBoneDefinition* pBoneDefs);
	bool AreBoundsCalculated() const;
	const float4& GetMinBound() const;
	float4& GetMinBound();
	const float4& GetMaxBound() const;
	float4& GetMaxBound();
	void SetNeedsBoundsCalculated();
	void ClearBoundsCalculated();
	void Allocate(unsigned int nNumBones);
	const SQV* GetBones() const;
	SQV* GetBones();
	const SVector3* GetScales() const;
	SVector3* GetScales();
};
