#pragma once

#include "TRefCountPtr.h"
#include "ZGridJob.h"
#include "ZGameTime.h"

template<class T>
class ZGridJobRequest
{
public:
    TRefCountPtr<ZGridJob> m_pJob;
    ZGameTime m_tLastJob;
};
