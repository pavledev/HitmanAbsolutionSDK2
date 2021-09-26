#pragma once

#include "IWaveBankData.h"
#include "EWaveBankMemoryLoadRTType.h"
#include "EWaveBankRTFormat.h"
#include "TResourcePtr.h"
#include "TSharedPointer.h"
#include "ZRuntimeResourceID.h"

class ZResourcePending;
class ZResourceReader;
class ZWaveBankFSBData;
struct SWaveBankFXData;
struct SWaveBankResourceData;

class ZWaveBankData : public IWaveBankData
{
public:
	TResourcePtr<ZWaveBankFSBData> m_pRAMResource;
	TResourcePtr<SWaveBankFXData> m_pFXResource;
	TSharedPointer<ZResourceReader> m_pReader;
	const SWaveBankResourceData* m_pData;
	ZRuntimeResourceID m_resourceID;

	const TResourcePtr<SWaveBankFXData>& GetFXResource() const override;
	ZRuntimeResourceID GetRuntimeResourceID() const override;
	bool IsNotDucking() const override;
	~ZWaveBankData() override = default;

	ZWaveBankData() = default;
	ZWaveBankData(ZResourcePending& resourcePending);
	EWaveBankMemoryLoadRTType GetLoadType() const;
	EWaveBankRTFormat GetFormat() const;
	int GetTrackCount() const;
	int GetChannelCount() const;
	unsigned int GetSoundDataSize() const;
	const void* GetSoundData() const;
	float GetDuration() const;
	ZRuntimeResourceID GetStreamResourceID() const;
	bool IsPlaceholder() const;
};
