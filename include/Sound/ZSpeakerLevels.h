#pragma once

#include "TArray.h"

class ZSpeakerLevels
{
public:
	TArray<float> m_aSpeakerMatrix;

	static float s_fIdentityMatrix[64];

	static void RegisterType();
	ZSpeakerLevels(const ZSpeakerLevels& other);
	ZSpeakerLevels() = default;
	const TArrayRef<float> GetSpeakerLevelsArray() const;
	static float* GetIdentityMatrix();
	unsigned int GetHashCode() const;
	bool operator==(const ZSpeakerLevels& rhs) const;
	~ZSpeakerLevels() = default;
	ZSpeakerLevels& operator=(const ZSpeakerLevels& __that);
};
