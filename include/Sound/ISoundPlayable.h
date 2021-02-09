#pragma once

#include "IComponentInterface.h"
#include "ISoundPlayerChannel.h"
#include "ZWaveBankData.h"
#include "SSoundTriggerPoint.h"
#include "ISoundGroup.h"

class ISoundPlayable : public IComponentInterface
{
public:
    virtual void Activate();
    virtual void Deactivate();
    virtual ISoundPlayerChannel* Play(TResourcePtr<ZWaveBankData>, int, bool, unsigned int, bool, float4*, void*, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>, void*, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>);
    virtual ISoundPlayerChannel* PlayChannelAtPoint(SSoundTriggerPoint);
    virtual void SetPausedState(bool);
    virtual void Stop(bool);
    virtual bool IsPlaying();
    virtual bool IsPlayOnGameStart();
    virtual bool IsPaused();
    virtual float GetDuration();
    virtual void SetPlayPosition(float);
    virtual float GetPlayPosition();
    virtual void SetGamePaused(bool);
    virtual bool IsGamePaused();
    virtual ZEntityRef* GetEntityRef(ZEntityRef* result);
    virtual void SetDefaultPlayFailedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>*);
    virtual void SetDefaultPlayStartedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>*);
    virtual void SetDefaultPlayStoppedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>*);
    virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>* GetDefaultPlayFailedCallback();
    virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>* GetDefaultPlayStartedCallback();
    virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>* GetDefaultPlayStoppedCallback();
    virtual void RemoveFailedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>*);
    virtual void RemoveStartedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>*);
    virtual void RemoveStoppedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>*);
    virtual ISoundGroup* GetSoundGroup();
};
