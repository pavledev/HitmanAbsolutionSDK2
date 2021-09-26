#pragma once

#include "ISoundModifiable.h"
#include "ISoundEffectAttachable.h"

class ZString;
namespace FMOD {
class ChannelGroup;
}  // namespace FMOD

class __declspec(novtable) ISoundChannelGroup : public ISoundModifiable, public ISoundEffectAttachable
{
public:
	~ISoundChannelGroup() override = default;
	virtual FMOD::ChannelGroup* GetFMODChannelGroup() = 0;
	virtual const ZString& GetGroupName() const = 0;
	virtual void SetConfigAttenuation(float param1) = 0;
	virtual void SetAudibilityWeight(float param1) = 0;

	static void RegisterType();
	ISoundChannelGroup() = default;
};
