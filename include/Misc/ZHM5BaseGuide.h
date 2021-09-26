#pragma once

#include "ZBoundedEntity.h"
#include "SMatrix.h"
#include "TArrayRef.h"
#include "ZRayQueryOutput.h"

class ZHitman5;

class ZHM5BaseGuide : public ZBoundedEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum eGuideType
	{
		eJumpGuide = 1,
		eLedgeGuide = 2,
		eLadderGuide = 4,
		eWindowGuide = 8
	};

	struct SLimits
	{
		float m_fMinX;
		float m_fMaxX;
		float m_fMinY;
		float m_fMaxY;

		SLimits() = default;
	};

	eGuideType m_eGuideType;
	float4 m_vAABBCen;
	float4 m_vAABBHalfSize;
	bool m_bGuideValid : 1;
	bool m_bIgnoreTransformCallback : 1;
	bool m_bEnabled : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5BaseGuide() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	bool GetEditorVisible() const override;
	virtual eGuideType GetGuideType() const;
	virtual void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue);
	virtual bool IsGuideValid() const;
	virtual bool IsPointOnGuide(const SMatrix& mvMatPos);
	virtual bool IsPointConnectedToGuide(const SMatrix& mvMatPos);
	virtual void RemoveConnection(ZHM5BaseGuide* pBaseGuide);
	virtual bool IsMountableFromTop() const;
	virtual float4 Calc3dPromptPos(const float4& vPoint) const;
	virtual SLimits GetLimits();
	virtual void Activate_InitSafeZones(const TArrayRef<ZRayQueryOutput>& aAlignResults);

	ZHM5BaseGuide() = default;
	static void RegisterType();
	ZHM5BaseGuide(ZComponentCreateInfo& pInfo);
	float4 GetGuideSideDir() const;
	void GetExtends(float4& vCen, float4& vHalfSize);
	TEntityRef<ZHitman5> Hitman() const;
	void OnEnable();
	void OnDisable();
};
