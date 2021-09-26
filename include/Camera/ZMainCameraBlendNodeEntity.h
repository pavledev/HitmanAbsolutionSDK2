#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SVector3.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "ZVariantRef.h"

class ZCameraBlendNodeInterface;
class ZComponentCreateInfo;
struct STypeID;

class ZMainCameraBlendNodeEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZCameraBlendNodeInterface> m_source;
	float m_fBlend;
	float m_userInputWeight;
	SVector3 m_lookToDirection;
	float m_fBlendPosition;
	float m_fBlendOrientation;
	bool m_bUseSeparateBlendFactors;

	static SComponentMapEntry s_componentMap[0];

	~ZMainCameraBlendNodeEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZMainCameraBlendNodeEntity() = default;
	static void RegisterType();
	ZMainCameraBlendNodeEntity(ZComponentCreateInfo& info);
	SMatrix GetObjectToWorldMatrix(const SMatrix& mWorld) const;
	float GetFieldOfView(float fFoV) const;
	void OnBlendSet(const float& oldBlend);
	void OnUserInputWeightSet();
	void OnUseSeparateBlendSet();
	void OnSetLookToDirection(const SVector3& value);
	void OnHintLookToDirection(const SVector3& value);
};
