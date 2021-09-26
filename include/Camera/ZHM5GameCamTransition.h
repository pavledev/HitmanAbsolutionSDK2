#pragma once

#include "ZEntityImpl.h"
#include "ECameraState.h"
#include "SHM5GameCamTransition.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZHM5GameCamTransition : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fTransitionTime;
	bool m_bTransitionWhileMoving;
	bool m_bAlignToBaseAngles;
	bool m_bIgnoreProfileAlignment;
	TArray<ECameraState> m_aeFromStates;
	TArray<ECameraState> m_aeToStates;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5GameCamTransition() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5GameCamTransition() = default;
	static void RegisterType();
	ZHM5GameCamTransition(ZComponentCreateInfo& pInfo);
	SHM5GameCamTransition GetTransition() const;
	const TArray<ECameraState>& GetFromStates() const;
	const TArray<ECameraState>& GetToStates() const;
	void SetTransitionWhileMoving(bool bTransitWhileMoving);
};
