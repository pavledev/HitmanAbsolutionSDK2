#pragma once

#include "IComponentInterface.h"

class __declspec(novtable) ISoundModifiable : public IComponentInterface
{
public:
	~ISoundModifiable() override = default;
	virtual float GetAttenuation() const = 0;
	virtual void SetAttenuationGain(float param1) = 0;
	virtual float GetPitchShift() const = 0;
	virtual void SetPitchShift(float param1) = 0;

	static void RegisterType();
	ISoundModifiable() = default;
};
