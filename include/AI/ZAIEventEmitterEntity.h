#pragma once

#include "ZGameStatsEntityBase.h"
#include "EGameEventArgType.h"
#include "SComponentMapEntry.h"
#include "SGameEventArgs.h"
#include "ZVariantRef.h"

class ZAIGameState;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZAIEventEmitterEntity : public ZGameStatsEntityBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_AlertableActorOnScreenCooldown;
	float m_AlertableGuardOnScreenCooldown;

	static SComponentMapEntry s_componentMap[0];
	static const unsigned int s_pinidSoundTensionAmbient;
	static const unsigned int s_pinidSoundTensionUpToYellow;
	static const unsigned int s_pinidSoundTensionDownToYellow;
	static const unsigned int s_pinidSoundTensionUpToOrange;
	static const unsigned int s_pinidSoundTensionDownToOrange;
	static const unsigned int s_pinidSoundTensionUpToRed;

	~ZAIEventEmitterEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;
	virtual void SendSignals(const ZAIGameState& oldState, const ZAIGameState& newState);

	void ProcessGameEvent(const SGameEventArgs& args) override;
	EGameEventArgType GetArgType() const override;

	ZAIEventEmitterEntity() = default;
	static void RegisterType();
	ZAIEventEmitterEntity(ZComponentCreateInfo& info);
	void SignalSoundTensionAmbient();
	void SignalSoundTensionUpToYellow();
	void SignalSoundTensionDownToYellow();
	void SignalSoundTensionUpToOrange();
	void SignalSoundTensionDownToOrange();
	void SignalSoundTensionUpToRed();
};
