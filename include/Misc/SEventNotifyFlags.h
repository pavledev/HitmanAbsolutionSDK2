#pragma once

class SEventNotifyFlags
{
public:
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
};
