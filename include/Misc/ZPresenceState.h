#pragma once

class __declspec(novtable) ZPresenceState
{
public:
	enum EntityStateFlags
	{
		ESF_STREAMED = 1,
		ESF_ACTIVATED = 2,
		ESF_EDITMODE = 4
	};

	unsigned char m_nEntityState;

	virtual ~ZPresenceState() = default;
	virtual void OnStreamActivateStateChanged() = 0;

	ZPresenceState(const ZPresenceState& __that);
	ZPresenceState() = default;
	void StreamInHelper();
	void StreamOutHelper();
	bool IsStreamedInHelper();
	void OnEnterEditModeHelper();
	void OnExitEditModeHelper();
	void ActivateHelper();
	void DeactivatHelper();
	bool GetStreamedFlag() const;
	bool GetActivatedFlag() const;
	bool GetEditModeFlag() const;
	ZPresenceState& operator=(const ZPresenceState& __that);
};
