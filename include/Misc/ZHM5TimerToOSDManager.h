#pragma once

#include "TFixedArray.h"
#include "UserFBIcons.h"
#include "TArrayIterator.h"

class ZUserFeedbackManager;

class ZHM5TimerToOSDManager
{
public:
	enum ETimerToOSDManager_Command
	{
		eStart = 0,
		eStop = 1
	};

	struct STimerTOOSDElement_Comp
	{
		TEntityRef<UserFBIcons::IHM5TimerToOSD> m_CompKey;

		STimerTOOSDElement_Comp(TEntityRef<UserFBIcons::IHM5TimerToOSD>& Key);
		bool operator()(const UserFBIcons::STimerToOSDElement& other);
		~STimerTOOSDElement_Comp() = default;
	};

	TFixedArray<UserFBIcons::STimerToOSDElement, 6> m_rTimers;
	const ZUserFeedbackManager* const m_pUserFBManager = {};

	static float s_fDisplayTextTime[0];

	TArrayIterator<UserFBIcons::STimerToOSDElement const> ArrayGetBegin() const;
	const TArrayIterator<UserFBIcons::STimerToOSDElement const> ArrayGetEnd() const;
	ZHM5TimerToOSDManager() = default;
	ZHM5TimerToOSDManager(ZUserFeedbackManager* pUserFB);
	~ZHM5TimerToOSDManager() = default;
	void OnStart();
	void Update();
	void Reset();
	void TimerToOSD_Register(TEntityRef<UserFBIcons::IHM5TimerToOSD>& obj, ETimerToOSDManager_Command eComm);
	void SetupElement(const TEntityRef<UserFBIcons::IHM5TimerToOSD>& obj, UserFBIcons::STimerToOSDElement& elem);
	void ArrayPushNew(TEntityRef<UserFBIcons::IHM5TimerToOSD>& obj);
	void ArrayRemove(TEntityRef<UserFBIcons::IHM5TimerToOSD>& obj);
	void ArrayFillGaps();
	void DisplayTextMessage(const UserFBIcons::STimerToOSDElement& elem);
};
