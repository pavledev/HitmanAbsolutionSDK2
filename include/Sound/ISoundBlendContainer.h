#pragma once

#include "IComponentInterface.h"

template <class T> class TArray;

class __declspec(novtable) ISoundBlendContainer : public IComponentInterface
{
public:
	~ISoundBlendContainer() override = default;
	virtual void PlayFromGUI(const TArray<float>& array) = 0;
	virtual void UpdateFromGUI(const TArray<float>& array) = 0;
	virtual void StopFromGUI() = 0;
	virtual void SetTrackMuteState(int param1, bool param2) = 0;
	virtual void ReleaseSustainPointAt(unsigned int param1) = 0;
	virtual int GetNumSourceParameters() const = 0;
	virtual int GetSourceParameterIndexFromID(unsigned int param1) = 0;

	static void RegisterType();
	ISoundBlendContainer() = default;
};
