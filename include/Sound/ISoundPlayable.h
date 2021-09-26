#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"

class ISoundGroup;
class ISoundPlayerChannel;
class IWaveBankData;
class ZSoundPlayerCallbackExtraData;
class ZWaveBankData;
struct SSoundTriggerPoint;
struct float4;
template <class T> class TRefCountPtr;
template <class T> class TResourcePtr;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) ISoundPlayable : public IComponentInterface
{
public:
	~ISoundPlayable() override = default;
	virtual void Activate() = 0;
	virtual void Deactivate() = 0;
	virtual ISoundPlayerChannel* Play(TResourcePtr<ZWaveBankData> resourcePtr, int param2, bool param3, unsigned int param4, bool param5, float4* param6, void* param7, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> delegate, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> delegate9, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> delegate10, void* param11, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> delegate12, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> delegate13, ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> delegate14) = 0;
	virtual ISoundPlayerChannel* PlayChannelAtPoint(SSoundTriggerPoint soundTriggerPoint) = 0;
	virtual void SetPausedState(bool param1) = 0;
	virtual void Stop(bool param1) = 0;
	virtual bool IsPlaying() const = 0;
	virtual bool IsPlayOnGameStart() const = 0;
	virtual bool IsPaused() const = 0;
	virtual float GetDuration() const = 0;
	virtual void SetPlayPosition(float param1) = 0;
	virtual float GetPlayPosition() = 0;
	virtual void SetGamePaused(bool param1) = 0;
	virtual bool IsGamePaused() const = 0;
	virtual ZEntityRef GetEntityRef() const = 0;
	virtual void SetDefaultPlayFailedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& delegate) = 0;
	virtual void SetDefaultPlayStartedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& delegate) = 0;
	virtual void SetDefaultPlayStoppedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& delegate) = 0;
	virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetDefaultPlayFailedCallback() = 0;
	virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& GetDefaultPlayStartedCallback() = 0;
	virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetDefaultPlayStoppedCallback() = 0;
	virtual void RemoveFailedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& delegate) = 0;
	virtual void RemoveStartedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& delegate) = 0;
	virtual void RemoveStoppedCallback(const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& delegate) = 0;
	virtual ISoundGroup* GetSoundGroup() = 0;

	static void RegisterType();
	ISoundPlayable() = default;
};
