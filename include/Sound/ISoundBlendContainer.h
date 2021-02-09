#pragma once

#include "IComponentInterface.h"
#include "TArray.h"

class ISoundBlendContainer : public IComponentInterface
{
public:
    virtual void PlayFromGUI(const TArray<float>*);
    virtual void UpdateFromGUI(const TArray<float>*);
    virtual void StopFromGUI();
    virtual void SetTrackMuteState(int, bool);
    virtual void ReleaseSustainPointAt(unsigned int);
    virtual int GetNumSourceParameters();
    virtual int GetSourceParameterIndexFromID(unsigned int);
};
