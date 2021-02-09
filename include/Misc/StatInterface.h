#pragma once

#include "GStat.h"

class StatInterface
{
public:
    virtual ~StatInterface();
    virtual GStat::StatType GetType(GStat*);
    virtual unsigned int GetStatCount(GStat*);
    virtual void GetStat(GStat*, GStat::StatValue*, unsigned int);
    virtual unsigned int GetStatDataSize();
    virtual void Init(GStat*);
    virtual void Add(GStat*, GStat*);
    virtual void SetMin(GStat*, GStat*);
    virtual void SetMax(GStat*, GStat*);
    virtual void Reset(GStat*);
};
