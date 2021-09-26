#pragma once

#include "TEntityRef.h"

class ZActor;
struct SDialogInstanceData;

struct SDialogSlotData
{
	SDialogInstanceData* m_pDialog;
	SDialogInstanceData* m_pResponseDialog;
	TEntityRef<ZActor> m_pSpeaker;
	TEntityRef<ZActor> m_pResponseSpeaker;

	SDialogSlotData(const SDialogSlotData& __that);
	SDialogSlotData() = default;
	~SDialogSlotData() = default;
	SDialogSlotData& operator=(const SDialogSlotData& __that);
};
