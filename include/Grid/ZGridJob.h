#pragma once

#include "EPriority.h"
#include "STypeID.h"
#include "ZGridSearchIterator.h"

class ZGridJob
{
public:
    int m_nRefCount;
    bool m_bCompleted;
    EPriority m_priority;
    STypeID* m_resultType;

    virtual ~ZGridJob();
    virtual bool OnUpdate(ZGridSearchIterator*, bool);
    virtual const void* OnGetResult();
};
