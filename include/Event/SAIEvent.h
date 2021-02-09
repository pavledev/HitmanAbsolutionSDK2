#pragma once

struct SAIEvent
{
    unsigned __int32 m_type : 31;
    unsigned __int32 m_bHandled : 1;
    unsigned int m_start;
    unsigned int m_end;
};
