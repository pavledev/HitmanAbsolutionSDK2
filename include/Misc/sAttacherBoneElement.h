#pragma once

#include "TEntityRef.h"
#include "IHM5Item.h"

class sAttacherBoneElement
{
public:
    TEntityRef<IHM5Item> rItem;
    int m_nBoneId;
};
