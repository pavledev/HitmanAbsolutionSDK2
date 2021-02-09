#pragma once

#include "ISubtitledPlayer.h"
#include "IWaveBankData.h"
#include "ZDelegate.h"
#include "TRefCountPtr.h"
#include "ZSoundPlayerCallbackExtraData.h"
#include "float4.h"
#include "TEntityRef.h"
#include "ISoundChannelGroup.h"

class ISoundPlayerChannel : public ISubtitledPlayer
{
public:
    virtual void SetGloballyPaused(bool);
    virtual void SetChannelPaused(bool);
    virtual void Stop();
    virtual IWaveBankData* GetWavebankData();
    virtual int GetSubSound();
    virtual void* GetCallbackUserData();
    virtual void* GetUserData();
    virtual void SetOwner(struct ISoundPlayerChannelOwner*);
    virtual void SetFailedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>);
    virtual void SetStartedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>);
    virtual void SetStoppedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>);
    virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>* GetFailedCallback();
    virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>* GetStartedCallback();
    virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>* GetStoppedCallback();
    virtual void SetChannelFlags(unsigned int);
    virtual unsigned int GetChannelFlags();
    virtual unsigned int GetUniqueID();
    virtual float GetAudibility(bool);
    virtual float GetRawAudibility(const float4*);
    virtual void SetAttenuation(float);
    virtual void SetPitch(float);
    virtual void SetPitchFromMultiplier(float);
    virtual void SetPlayPosition(float);
    virtual float GetLength();
    virtual void SetCallbackUserData(void*);
    virtual void SetUserData(void*);
    virtual void SetChannelGroup(TEntityRef<ISoundChannelGroup>);
    virtual void SetDelay(float);
    virtual void SetMode2D();
    virtual void SetLowpassCutoffFrequency(float);
    virtual void SetSeqCallbackUserData(void*);
    virtual void* GetSeqCallbackUserData();
    virtual void ClearSequenceCallbacks();
};
