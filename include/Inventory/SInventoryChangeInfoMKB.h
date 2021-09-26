#pragma once

struct SInventoryChangeInfoMKB
{
	bool m_bCancelledSelection;
	bool m_bUnholsteredStoredSlot;
	bool m_DualWieldChange;

	SInventoryChangeInfoMKB() = default;
	~SInventoryChangeInfoMKB() = default;
	void Reset();
};
