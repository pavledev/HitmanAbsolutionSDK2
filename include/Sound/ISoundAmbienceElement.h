#pragma once

#include "IComponentInterface.h"
#include "ESoundAmbienceOperation.h"

struct SSoundAmbienceDynamicParameters;
struct SVector3;

class __declspec(novtable) ISoundAmbienceElement : public IComponentInterface
{
public:
	~ISoundAmbienceElement() override = default;
	virtual void ForceStart() = 0;
	virtual void ForceStop() = 0;
	virtual void SetGamePaused(bool param1) = 0;
	virtual void SetTempSpatialPosition(const SVector3& vector3, unsigned int param2) = 0;
	virtual void SetTempSpatialOcclusionAttenuation(float param1, unsigned int param2) = 0;
	virtual void SetTempSpatialOcclusionLowpassCutoff(float param1, unsigned int param2) = 0;
	virtual void AddDynamicParameters(float param1, float param2, bool param3) = 0;
	virtual void AmbienceTraverse(unsigned int param1, ESoundAmbienceOperation soundAmbienceOperation, SSoundAmbienceDynamicParameters* soundAmbienceDynamicParameters) = 0;
	virtual void UpdatePause() = 0;
	virtual bool IsInside() = 0;

	static void RegisterType();
	ISoundAmbienceElement() = default;
};
