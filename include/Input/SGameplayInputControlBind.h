#pragma once

#include "EHM5GameInputFlag.h"
#include "InputControlNamesp.h"

struct SGameplayInputControlBind
{
	EHM5GameInputFlag m_eGameInputAction;
	InputControlNamesp::eHM5InputActionID m_eControlID;
	InputControlNamesp::eHM5InputActionType m_eControlType;
	InputControlNamesp::eHM5InputAction m_eControlAction;

	SGameplayInputControlBind() = default;
	~SGameplayInputControlBind() = default;
};
