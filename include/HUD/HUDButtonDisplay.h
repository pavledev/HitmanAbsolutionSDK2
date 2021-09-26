#pragma once

#include "TFixedArray.h"
#include "EButtonState.h"
#include "EButtonPressType.h"
#include "EActionType.h"
#include "EUIText.h"
#include "EControllerButton.h"
#include "EButtonDisplay.h"
#include "EHM5GameInputFlag.h"
#include "GFxValue.h"
#include "InputControlNamesp.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "ZString.h"

class ZHitman5;
class IScaleformPlayer;
struct SGameplayInputControlBind;
struct SPromptToDisplay;
struct SVector2;

class HUDButtonDisplay
{
public:
	struct SButtonStatus
	{
		EButtonDisplay eButtonDisplay;
		EControllerButton eButton;
		EButtonState state;
		bool dirty;
		bool fixed;
		bool enabled;
		bool activated;
		GFxValue mc;
		ZString text;
		float x;
		float y;
		float z;
		float scale;
		float width;
		float delta;
		float buttonValue;
		float totalTime;
		float currentTime;

		SButtonStatus() = default;
		~SButtonStatus() = default;
	};

	IScaleformPlayer* m_mcHUD;
	GFxValue m_aButtonClips;
	TFixedArray<SButtonStatus, 9> m_aButtons;
	TFixedArray<SButtonStatus, 9> m_aButtonsLastFrame;
	bool m_bScaleformUpdatePrompts;
	bool m_bScaleformClearPrompts;
	bool m_bInstinctActive;
	bool m_bIsInputDeviceLastChanged;
	bool m_bRosettaVisible;
	TArray<SPromptToDisplay> m_aScaleformPrompts;
	TArray<SGameplayInputControlBind> m_aControlBinds;

	HUDButtonDisplay() = default;
	~HUDButtonDisplay() = default;
	static EButtonDisplay GetButtonDisplayForAction(const EActionType eActionType);
	static EHM5GameInputFlag GetGameplayFlag(EButtonDisplay buttonDisplay);
	static EControllerButton GetButtonForAction(const InputControlNamesp::eHM5InputActionID eInputActionID);
	void UpdatePrompts(unsigned char iCount, const SPromptToDisplay* const pActivePrompts);
	short GetButtonIndex(EButtonDisplay eButtonDisplay);
	short ShowButton(EButtonDisplay eButtonDisplay, const ZString& sButtonText, EControllerButton nButton, EButtonPressType eButtonType, bool bEnabled, InputControlNamesp::eHM5InputAction inputAction, bool bIllegalAction);
	void HideButton(EButtonDisplay eButtonDisplay);
	void Move3DButton(short buttonIndex, const SVector2& screenPos, float distance);
	void PositionButton(short buttonIndex, short buttonIndex2D);
	void ActivateButton(short buttonIndex);
	void EnableButton(short buttonIndex, bool bEnabled);
	void Arrange3DButtons();
	void StartButtonBlinking(short buttonIndex);
	void StopButtonBlinking(short buttonIndex);
	void StartButtonTimer(short buttonIndex, float fTotalTime);
	void StopButtonTimer(short buttonIndex);
	void UpdateButtonTimers(float fTimeDelta);
	void Reset();
	void Clear();
	void MarkDirty();
	void CleanUp();
	TEntityRef<ZHitman5> Hitman() const;
	bool HitmanExists() const;
	ZString GetText(EUIText nTextId);
	void OnHUDMovieClipResourcesChanged();
	void SetHUDMovieClip(IScaleformPlayer* pFlashMovie);
	void ReleaseFlashValues();
	static EButtonPressType GetButtonPressType(InputControlNamesp::eHM5InputActionType inputActionType);
	void ScaleformUpdatePrompts();
};
