#pragma once

#include "ZSoundBlendContainerBase.h"
#include "ESoundCollisionType.h"
#include "ESOUND_3DROLLOFF_TYPE.h"
#include "TSharedValue.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

struct SSoundPhysicsEventParameters;
class ZComponentCreateInfo;
class ZCurve;
class ZSoundBlendEvent;
class ZSoundPlayerChannel;
struct SFMODRolloffCurve;
struct STypeID;
struct float4;

class ZSoundBlendContainerPhysics : public ZSoundBlendContainerBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ESoundCollisionType m_eCollisionType;
	float m_fMinDistance;
	float m_fMaxDistance;
	float m_fMinDistanceLoud;
	float m_fMaxDistanceLoud;
	ESOUND_3DROLLOFF_TYPE m_e3dRolloffType;
	TSharedValue<ZCurve> m_RolloffCurve;
	float m_aTempParams[10];
	TSharedValue<SFMODRolloffCurve> m_aCustomRolloffCurve;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendContainerPhysics() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void OnChannelReady(ZSoundPlayerChannel* pChannel) override;
	bool IsPhysics() const override;
	void SetupAndStartEvent(bool bStartedFromGUI, const float4& vTargetPos) override;
	float GetAbsoluteFromNormal(int nIndex, float fNormalizedParam) const override;
	float GetNormalizedParameter(int nIndex, float fParam) const override;

	int GetNumSourceParameters() const override;
	int GetSourceParameterIndexFromID(unsigned int nParameterID) override;

	ZSoundBlendContainerPhysics() = default;
	static void RegisterType();
	ZSoundBlendContainerPhysics(ZComponentCreateInfo& Info);
	ZSoundBlendEvent* GenerateEvent(unsigned int nUniqueID);
	bool IsEmptyImpact(const SSoundPhysicsEventParameters& pParams) const;
	void OnMinMaxDistanceChanged();
	void On3dRolloffTypeChanged();
	void OnRolloffCurveChanged();
	float GetParameter(int nIndex, const SSoundPhysicsEventParameters& pParams) const;
};
