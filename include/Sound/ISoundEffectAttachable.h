#pragma once

namespace FMOD {
class DSP;
}  // namespace FMOD

class __declspec(novtable) ISoundEffectAttachable
{
public:
	virtual ~ISoundEffectAttachable() = default;
	virtual void AttachEffectInstance(FMOD::DSP* dsp, void* param2) = 0;
	virtual bool IsSilent() const = 0;

	ISoundEffectAttachable() = default;
};
