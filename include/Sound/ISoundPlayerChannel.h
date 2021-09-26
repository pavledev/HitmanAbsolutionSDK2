#pragma once

#include "ISubtitledPlayer.h"

class ISoundPlayerChannelOwner;
class ISoundChannelGroup;
class IWaveBankData;
class ZSoundPlayerCallbackExtraData;
struct float4;
template <class T> class TEntityRef;
template <class T> class TRefCountPtr;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) ISoundPlayerChannel : public ISubtitledPlayer
{
public:
	~ISoundPlayerChannel() override = default;
	virtual float GetPlayPosition() = 0;
	virtual void SetGloballyPaused(bool param1) = 0;
	virtual void SetChannelPaused(bool param1) = 0;
	virtual void Stop() = 0;
	virtual IWaveBankData* GetWavebankData() = 0;
	virtual int GetSubSound() = 0;
	virtual void* GetCallbackUserData() = 0;
	virtual void* GetUserData() = 0;
	virtual void SetOwner(ISoundPlayerChannelOwner* soundPlayerChannelOwner) = 0;
	virtual void SetFailedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> delegate) = 0;
	virtual void SetStartedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)> delegate) = 0;
	virtual void SetStoppedCallback(ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)> delegate) = 0;
	virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetFailedCallback() const = 0;
	virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>)>& GetStartedCallback() const = 0;
	virtual const ZDelegate<void __cdecl(ISoundPlayerChannel*, IWaveBankData*, int, void*)>& GetStoppedCallback() const = 0;
	virtual void SetChannelFlags(unsigned int param1) = 0;
	virtual unsigned int GetChannelFlags() = 0;
	virtual unsigned int GetUniqueID() const = 0;
	virtual float GetAudibility(bool param1) = 0;
	virtual float GetRawAudibility(const float4& param1) = 0;
	virtual void SetAttenuation(float param1) = 0;
	virtual void SetPitch(float param1) = 0;
	virtual void SetPitchFromMultiplier(float param1) = 0;
	virtual void SetPlayPosition(float param1) = 0;
	virtual float GetLength() = 0;
	virtual void SetCallbackUserData(void* param1) = 0;
	virtual void SetUserData(void* param1) = 0;
	virtual void SetChannelGroup(TEntityRef<ISoundChannelGroup> entityRef) = 0;
	virtual void SetDelay(float param1) = 0;
	virtual void SetMode2D() = 0;
	virtual void SetLowpassCutoffFrequency(float param1) = 0;
	virtual void SetSeqCallbackUserData(void* param1) = 0;
	virtual void* GetSeqCallbackUserData() = 0;
	virtual void ClearSequenceCallbacks() = 0;

	static void RegisterType();
	ISoundPlayerChannel() = default;
};
