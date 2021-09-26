#pragma once

#include "TRenderReferencedCountedImpl.h"

template <class A, int B>
class TRenderResourceImpl : public TRenderReferencedCountedImpl<A, 0>
{
public:
	~TRenderResourceImpl() override = default;

	TRenderResourceImpl() = default;
};
