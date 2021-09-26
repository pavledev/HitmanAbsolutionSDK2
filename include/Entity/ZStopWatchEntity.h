#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

struct SGameUpdateEvent;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZStopWatchEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bEnabled;
	float m_fSeconds;
	float m_fDuration;
	bool m_bSendTotalSecondsOnChanged;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snTotalSeconds;
	static unsigned int m_snFinished;

	~ZStopWatchEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;

	ZStopWatchEntity() = default;
	static void RegisterType();
	ZStopWatchEntity(ZComponentCreateInfo& Info);
	float GetCurrent() const;
	float GetDuration() const;
	void GameUpdate(const SGameUpdateEvent& updateEvent);
	void OnReset();
	void OnStop();
	void OnStart();
	void OnSetTotalSeconds(float fSeconds);
	void OnGetTotalSeconds();
	void OnActivateForTargetTracker();
};
