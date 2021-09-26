#pragma once

#include "TEntityRef.h"
#include "ZHitman5.h"
#include "SHM5InputControllerAnalog.h"
#include "SHM5InputKeyboardFlags.h"
#include "ZInputAction.h"
#include "InputControlNamesp.h"

class ZHM5InputConverter;

class ZHM5InputControl
{
public:
	struct SInputBinding
	{
		InputControlNamesp::eHM5InputAction m_eInput;
		ZInputAction m_InputAction;

		SInputBinding() = default;
		SInputBinding(InputControlNamesp::eHM5InputAction eInput, const char* pName);
		~SInputBinding() = default;
	};

	TEntityRef<ZHitman5> m_pHitman;
	SHM5InputControllerAnalog m_AnalogInputs;
	SHM5InputKeyboardFlags m_InputKeyboardFlags;
	ZHM5InputConverter* m_pInputConverter;
	bool m_iInputControllerFlags[95];
	ZGameTime m_tReturnedFromMenu;
	bool m_bActive;
	int m_nBindingsDisabledCount;

	ZHM5InputControl() = default;
	ZHM5InputControl(const ZHM5InputControl& __that);
	ZHM5InputControl(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5InputControl() = default;
	void Init();
	void EnableInputControl(bool bValue);
	void Update();
	void InputSystem_ReturnFromMenu();
	const bool* GetInputControlFlags() const;
	const SHM5InputControllerAnalog& GetInputControllerAnalog() const;
	const SHM5InputKeyboardFlags& GetInputKeyboardFlags() const;
	bool GetInputActionIDandType(const InputControlNamesp::eHM5InputAction action, InputControlNamesp::eHM5InputActionID& actionID, InputControlNamesp::eHM5InputActionType& actionType) const;
	bool IsInputActionActivating(InputControlNamesp::eHM5InputAction inputAction) const;
	ZHM5InputConverter* GetInputConverter();
	void DisableBindings();
	void EnableBindings();
	bool QueryInputControllerFlag(const InputControlNamesp::eHM5InputAction& eQuery) const;
	void ResetAllFlags();
	void InitInputControlSystem();
	void UpdateThumbStickInput();
	void UpdateControllerInput();
	void UpdateKeyboardInput();
	void UpdateMouseInput();
	ZHM5InputControl& operator=(const ZHM5InputControl& __that);
};
