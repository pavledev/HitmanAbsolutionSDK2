#pragma once

#include "ZActorAnimationProgram.h"

class ZControlledAnimLocomotion : public ZActorAnimationProgram
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bAdvanceAnimation;
	float m_fAnimPrct;
	float m_fAnimDuration;
	SMatrix m_mvMatPos;
	SMatrix m_mvStartMatPos;
	SMatrix m_mvTargetMatPos;
	unsigned int m_nAnimNodeId;
	unsigned int m_nAnimSMNodeId;
	ZString m_sAnimName;
	ZString m_sAnimSMName;

	~ZControlledAnimLocomotion() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	EActorAnimationStatusUpdate Update(float fDeltaTime) override;

	static void RegisterType();
	ZControlledAnimLocomotion(ZActorAnimationState* pContext, const ZString& sAnimSMName, const ZString& sAnimName);
	ZControlledAnimLocomotion() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void SetAnimPrct(float fAnimPrct);
	void SetGroundMatPos(const SMatrix& mvMatPos);
	void SetStartMatPos(const SMatrix& mvStartMatPos);
	void SetTargetMatPos(const SMatrix& mvTargetMatPos);
	void SetAdvanceAnimation(bool bAdvanceAnim);
	bool IsAnimActive();
	ZString GetFullPathAnimName(const ZString& sFullPathSMName);
};
