#pragma once

#include "GRefCountBaseStatImpl.h"
#include "GRefCountImpl.h"

template <class A, int B>
class GRefCountBase : public GRefCountBaseStatImpl<GRefCountImpl, B>
{
public:
	enum
	{
		StatType = B
	};

	~GRefCountBase() override = default;

	GRefCountBase() = default;
};
