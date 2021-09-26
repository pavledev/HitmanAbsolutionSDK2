#pragma once

#include "ZHM5InputControl.h"

class ZHM5InputControlScheme;

class ZHM5InputConverter
{
public:
	enum EControlSchemes
	{
		eControlScheme_Alpha = 0,
		eControlScheme_Beta = 1,
		eControlScheme_Gamma = 2,
		eControlScheme_Keyboard = 3
	};

	ZHM5InputControl* const m_pInputControl;
	ZHM5InputControlScheme* m_pControlSchemeAlpha;
	ZHM5InputControlScheme* m_pControlSchemeBETA;
	ZHM5InputControlScheme* m_pControlSchemeGamma;
	ZHM5InputControlScheme* m_pControlSchemeKeyboard;
	TEntityRef<ZHitman5> m_pHitman;
	EControlSchemes m_eActiveControlScheme;
	EControlSchemes m_eSelectedControlScheme;

	ZHM5InputConverter() = default;
	ZHM5InputConverter(ZHM5InputControl* pInputControl, const TEntityRef<ZHitman5>& pHitman);
	~ZHM5InputConverter() = default;
	void Init();
	void Update();
	const ZHM5InputControl* GetInputControl() const;
	void ResetControlSchemes();
	void SetSwitchSneak_ShoulderCam(bool bSet);
	void SetLeftHanded(bool bSet);
	void SetCamSensitivityVer(float fVal);
	void SetCamSensitivityHor(float fVal);
	void SetActiveControlScheme(bool bSet);
	void SetMouseSensitivity(float fVal);
	void RemoveCameraControl_All(bool bRemoveCameraControl);
	void RemoveMovementControl_All(bool bRemoveMovementControl);
	void RemoveAimControl_All(bool bRemoveAimControl);
};
