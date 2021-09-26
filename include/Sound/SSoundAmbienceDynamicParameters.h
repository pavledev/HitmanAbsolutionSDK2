#pragma once

struct SSoundAmbienceDynamicParameters
{
	float m_fParamAttenuation;
	float m_fParamPitch;
	float m_fParam3DWeight;
	float m_fParamMixtureWeight;
	float m_fParamRetriggerMinTime;
	float m_fParamRetriggerMaxTime;
	float m_fParamRetriggerTimeMultiplier;
	float m_fParamRetriggerProbability;
	float m_fParamLowpassCutoffFrequency;
	float m_fWeightGate;
	float m_fWeightHybrid;

	SSoundAmbienceDynamicParameters() = default;
	~SSoundAmbienceDynamicParameters() = default;
};
