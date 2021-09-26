#pragma once

#include "TRefCountPtr.h"
#include "ZGameTime.h"

class ZGridJob;

template <class T>
class ZGridJobRequest
{
public:
	TRefCountPtr<ZGridJob> m_pJob;
	ZGameTime m_tLastJob;

	ZGridJobRequest() = default;
	~ZGridJobRequest() = default;
};
