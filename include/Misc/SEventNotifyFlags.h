#pragma once

struct SEventNotifyFlags
{
	bool m_bStandNotified;
	bool m_bMoveStartNotified;
	bool m_bMoveNotified;
	bool m_bMoveStoppingNotified;
	bool m_bActStartNotified;
	bool m_bActStoppingNotified;
	bool m_bActEnteredLoopNotified;
	bool m_bActInFullbodyNotified;
	bool m_bReactionStartNotified;
	bool m_bReactionStoppingNotified;

	SEventNotifyFlags() = default;
	~SEventNotifyFlags() = default;
	void ClearStandFlags();
	void ClearMoveFlags();
	void ClearActFlags();
	void ClearReactionFlags();
	void ClearAllFlags();
};
