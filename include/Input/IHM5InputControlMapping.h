#pragma once

#include "ZHM5InputControlScheme.h"
#include "SGameplayInputControlBind.h"

class __declspec(novtable) IHM5InputControlMapping
{
public:
	enum
	{
		eSCRight_Triggers = 0,
		eSCRight_Bumpers = 1,
		eSCLeft_Triggers = 2,
		eSCLeft_Bumpers = 3,
		eSC_NUM = 4
	};

	enum
	{
		eSCE_Surrender = 0,
		eSCE_Instinct = 1,
		eSCE_Reload = 2,
		eSCE_Run = 3,
		eSCE_Shoot = 4,
		eSCE_Precision = 5,
		eSCE_Toss = 6,
		eSCE_Drop = 7,
		eSCE_Aim = 8,
		SCElem_NUM = 9
	};

	ZHM5InputControlScheme* const m_pControlScheme;
	TArray<SGameplayInputControlBind> m_GameplayInputControlBinds;

	static EUIText s_ControllerLayoutNames_Alpha[28];
	static EUIText s_ControllerLayoutNames_Gamma[28];
	static InputControlNamesp::eHM5InputAction s_ShoulderControls[4][9];

	virtual ~IHM5InputControlMapping() = default;
	virtual void HandleFaceButtons() = 0;
	virtual void HandleStickButtons() = 0;
	virtual void HandleShoulderControls() = 0;
	virtual void HandleDPad() = 0;
	virtual void HandleGeneric() = 0;
	virtual void HandleCollisions() = 0;
	virtual void InitFaceButtons() = 0;
	virtual void InitStickButtons() = 0;
	virtual void InitShoulderControls() = 0;
	virtual void InitDpad() = 0;
	virtual void InitGeneric() = 0;

	void CallInitializers(const ZHM5InputControlScheme* const pVerifyThis);
	void CallHandlers();
	const TArray<SGameplayInputControlBind>& GetGameplayInputControlBinds() const;
	IHM5InputControlMapping() = default;
	IHM5InputControlMapping(ZHM5InputControlScheme* const pControlScheme);
	void AddGameplayInputBinding(EHM5GameInputFlag gameplayFlag, InputControlNamesp::eHM5InputAction inputAction);
	void SetGameInputFlag(EHM5GameInputFlag flagToSet, bool bVal);
	void ResetGameInputFlag(EHM5GameInputFlag flagToReset);
	void UpdateGameInputFlag(EHM5GameInputFlag flagToUpdate, InputControlNamesp::eHM5InputAction inputActionToRead);
	bool QueryInputFlag(InputControlNamesp::eHM5InputAction inputAction) const;
	bool QueryPreviousGameInputFlag(EHM5GameInputFlag gameplayAction) const;
	bool QueryGameInputFlag(EHM5GameInputFlag gameplayAction);
};
