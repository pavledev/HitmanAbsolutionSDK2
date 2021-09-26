#pragma once

#include "ZSoundPlayableBase.h"
#include "ISoundBlendContainer.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TArrayIterator.h"
#include "ZEntityRef.h"
#include "ZGameTime.h"
#include "ZVariantRef.h"

class ZSoundBlendEvent;
class ZComponentCreateInfo;
class ZSoundPlayerChannel;
struct STypeID;
struct float4;

class __declspec(novtable) ZSoundBlendContainerBase : public ZSoundPlayableBase, public ISoundBlendContainer
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bUseGameTime;
	bool m_bDebugShowParameters;
	float m_fCooldownTime;
	int m_nPriority;
	TArray<ZEntityRef> m_Tracks;
	TArray<ZSoundBlendEvent*> m_pEvents;
	unsigned int m_nEventID;
	TArray<ZSoundPlayerChannel*> m_ActiveChannels;
	ZGameTime m_lastPlayTime;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendContainerBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Activate() override;
	void Deactivate() override;
	void Play() override;
	void Stop() override;
	ZEntityRef GetEntityRef() const override;
	bool IsPlaying() const override;
	TArrayIterator<ZSoundPlayerChannel*> ChannelsBegin() override;
	TArrayIterator<ZSoundPlayerChannel*> ChannelsEnd() override;
	bool ChannelsEmpty() const override;
	int GetNumChannels() const override;
	int GetNumInputChannels() const override;
	void OnPlay() override;
	void OnStop() override;
	virtual bool IsPhysics() const;
	virtual void SetupAndStartEvent(bool param1, const float4& param2) = 0;
	virtual float GetAbsoluteFromNormal(int param1, float param2) const = 0;
	virtual float GetNormalizedParameter(int param1, float param2) const = 0;

	void PlayFromGUI(const TArray<float>& params) override;
	void UpdateFromGUI(const TArray<float>& params) override;
	void StopFromGUI() override;
	void SetTrackMuteState(int nTrackIndex, bool bIsMuted) override;
	void ReleaseSustainPointAt(unsigned int index) override;
	virtual int GetNumSourceParameters() const = 0;
	virtual int GetSourceParameterIndexFromID(unsigned int param1) = 0;

	ZSoundBlendContainerBase() = default;
	static void RegisterType();
	ZSoundBlendContainerBase(ZComponentCreateInfo& info);
	void RegisterBlendEventToContainer(ZSoundBlendEvent* pEvent);
	void UnregisterBlendEventFromContainer(ZSoundBlendEvent* pEvent);
	void AddChannel(ZSoundPlayerChannel* pChannel);
	void RemoveChannel(ZSoundPlayerChannel* pChannel);
	void UnloadStreamableItems();
	bool UseGameTime() const;
	void ProcessTracks();
	void StopAllChannels();
};
