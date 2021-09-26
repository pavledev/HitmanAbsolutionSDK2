#pragma once

#include "SGameInput.h"
#include "SHM5InputControllerAnalog.h"
#include "TEntityRef.h"
#include "ZHM5InputConverter.h"

class IHM5InputControlMapping;
struct SGameplayInputControlBind;

class ZHM5InputControlScheme
{
public:
	enum eThresholds
	{
		eThresh_Shoot = 0,
		eThresh_PrecisionShoot = 1,
		eThresh_AimOTS = 2,
		eThresh_CamSensitivityVer = 3,
		eThresh_CamSensitivityHor = 4,
		eThresh_MouseSensitivity = 5,
		eThresh_NUM = 6
	};

	struct SControlSchemeMappings
	{
		IHM5InputControlMapping* pInGameStandard;
		IHM5InputControlMapping* pInGameDead;
		IHM5InputControlMapping* pInGameCutSequence;
		IHM5InputControlMapping* pInGameCloseCombat;
		IHM5InputControlMapping* pInGameInteractiveCut;
		IHM5InputControlMapping* pInGameInventory;
		IHM5InputControlMapping* pInGameHintMessage;
		IHM5InputControlMapping* pInGameDragging;
		IHM5InputControlMapping* pInGameInstinctMode;
		IHM5InputControlMapping* pInGameShootingBallet;
		IHM5InputControlMapping* pInGameAgility;

		SControlSchemeMappings() = default;
	};

	struct SGameStateForInput
	{
		union 
		{
			unsigned int m_nGameState;

			struct 
			{
				bool m_bHitmanIsDead : 1;
				bool m_bHitmanInCutSequence : 1;
				bool m_bHitmanInAgilityMove : 1;
				bool m_bHitmanInstinctMode : 1;
				bool m_bHitmanShootingBallet : 1;
				bool m_bHitmanSBAllowRemoveControl : 1;
				bool m_bHitmanCloseCombat : 1;
				bool m_bHitmanInteractiveCut : 1;
				bool m_bHitmanInSafeZone : 1;
				bool m_bHitmanIsRunning : 1;
				bool m_bHitmanPickupNear : 1;
				bool m_bHitmanUsablePropNear : 1;
				bool m_bHitmanIsDragging : 1;
				bool m_bHitmanCanDragBody : 1;
				bool m_bHitmanCanTakeDisguise : 1;
				bool m_bHitmanCanPushFromRail : 1;
				bool m_bHitmanCanTakeHumanShield : 1;
				bool m_bHitmanCanCoverToCover : 1;
				bool m_bHitmanCanSurrender : 1;
				bool m_bHitmanGeneralAction : 1;
				bool m_bHitmanCanOperateDoor : 1;
				bool m_bWeaponsInventoryShown : 1;
				bool m_bHintMessageSlowdown : 1;
				bool m_bHitmanPrimaryLedgePrompt : 1;
			};
		};
	};

	struct SPersistentState
	{
		union 
		{
			unsigned int m_unionInt;

			struct 
			{
				bool m_bMappingsInitialized : 1;
				bool m_bOptionTriggersForShoot : 1;
				bool m_bOptionLeftHanded : 1;
				bool m_bOptionSwitchSticks : 1;
				bool m_bReInit : 1;
				bool m_bRemoveCameraControl : 1;
				bool m_bRemoveMovementControl : 1;
				bool m_bRemoveAimControl : 1;
			};
		};
	};

	SGameInput m_GameInput;
	float m_Thresholds[6];
	const SHM5InputControllerAnalog& m_fInputControllerAnalog;
	ZHM5InputConverter* const m_pInputConverter;
	TEntityRef<ZHitman5> m_pHitman;
	SControlSchemeMappings m_mappings;
	IHM5InputControlMapping* m_pCurrentMapping;
	SGameStateForInput m_gameState;
	SPersistentState m_PersistentState;
	bool m_iInputControlFlags[95];
	ZGameTime m_tLastControlMappingChange;
	ZGameTime m_tInstinctButtonHold;
	ZGameTime m_tDragBodyCounter;
	ZHM5InputConverter::EControlSchemes m_controlScheme;

	float GetThreshold(eThresholds eVal) const;
	ZHM5InputControlScheme() = default;
	ZHM5InputControlScheme(ZHM5InputConverter* pInputConverter, const TEntityRef<ZHitman5>& pHitman, ZHM5InputConverter::EControlSchemes controlScheme);
	~ZHM5InputControlScheme() = default;
	void SetControlMappings(SControlSchemeMappings& argm);
	void InitMappings();
	void Reset();
	void Update();
	const TEntityRef<ZHitman5> Hitman() const;
	const ZHM5InputConverter* const GetInputConverter() const;
	const SGameStateForInput& GetGameState() const;
	const SPersistentState& GetPersistentState() const;
	SGameInput* GetGameInput();
	SGameplayInputControlBind GenerateControlBind(const EHM5GameInputFlag gameplayAction, const InputControlNamesp::eHM5InputAction inputAction);
	bool QueryInputFlag(InputControlNamesp::eHM5InputAction inputAction) const;
	void SetTimerInstinctButtonHold(const ZGameTime tTime);
	ZGameTime GetTimerInstinctButtonHold() const;
	void RemoveCameraControl(bool bRemoveCameraControl);
	void RemoveMovementControl(bool bRemoveMovementControl);
	void RemoveAimControl(bool bRemoveAimControl);
	void SetLeftHanded(bool bSet);
	void SetSwitchSticks(bool bSet);
	void SetCamSensitivityVer(const float fValV);
	void SetCamSensitivityHor(const float fValH);
	void SetMouseSensitivity(const float fVal);
	const float* GetAnalogGameInput() const;
	float* GetAnalogGameInput_ForMappings();
	void SetAnalogThresholds();
	void UpdateAnalogValues();
	void UpdateActivatingFlags(const TArray<SGameplayInputControlBind>& currentBinds);
};
