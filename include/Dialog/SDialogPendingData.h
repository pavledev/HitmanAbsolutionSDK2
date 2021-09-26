#pragma once

#include "TEntityRef.h"

class ZActor;
class ZHM5BaseCharacter;
struct SDialogInstanceData;

struct SDialogPendingData
{
	SDialogInstanceData* m_pDialog;
	TEntityRef<ZActor> m_pSpeaker;
	TEntityRef<ZHM5BaseCharacter> m_pTarget;
	float m_fWeighting;

	SDialogPendingData(const SDialogPendingData& __that);
	SDialogPendingData() = default;
	~SDialogPendingData() = default;
	SDialogPendingData& operator=(const SDialogPendingData& __that);
};
