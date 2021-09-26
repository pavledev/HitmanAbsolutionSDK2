#pragma once

#include "GRefCountImplCore.h"

class GRefCountImpl : public GRefCountImplCore
{
public:
	~GRefCountImpl() override = default;

	GRefCountImpl() = default;
};
