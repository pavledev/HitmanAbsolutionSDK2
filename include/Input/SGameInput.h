#pragma once

#include "EHM5AnalogGameInputValues.h"

struct SGameInput
{
	float m_AnalogGameInput[8];
	bool m_iGameInputFlags[67];
	bool m_iPreviousGameInputFlags[67];
	bool m_iGameInputUpdatingFlags[67];
	bool m_iGameInputActivatingFlags[67];
	bool m_iConsumedGameInputFlags[67];

	bool QueryGameInputFlag(EHM5GameInputFlag gameAction) const;
	bool IsGameInputUpdatingFlag(EHM5GameInputFlag gameAction) const;
	bool QueryGameInputActivatingFlag(EHM5GameInputFlag gameAction) const;
	void MarkGameInputFlagConsumed(EHM5GameInputFlag flagToSet);
	bool QueryConsumedGameInputFlag(EHM5GameInputFlag gameAction) const;
	float* GetAnalogGameInput();
	float GetAnalogGameInput(EHM5AnalogGameInputValues flag) const;
	bool QueryPreviousGameInputFlag(EHM5GameInputFlag gameAction) const;
	SGameInput() = default;
	~SGameInput() = default;
	void SetGameInputFlag(EHM5GameInputFlag flagToUpdate);
	void ResetGameInputFlag(EHM5GameInputFlag flagToReset);
	void GetGameInputFlags(bool* pInputFlags) const;
	void SetGameInputUpdatingFlag(EHM5GameInputFlag flagToUpdate);
	void SetPreviousGameInputFlags(const bool* pFlags);
	void SetGameInputActivatingFlag(EHM5GameInputFlag flagToSet);
	void ResetInputFlags();
};
