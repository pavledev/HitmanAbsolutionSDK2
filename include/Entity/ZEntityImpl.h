#pragma once

#include "IEntity.h"
#include "ZEntityType.h"

class ZEntityImpl : IEntity
{
public:
    ZEntityType* m_pEntityType;

    virtual void Init();
    virtual void Start();
};
