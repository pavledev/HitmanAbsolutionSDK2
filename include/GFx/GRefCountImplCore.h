#pragma once

class GRefCountImplCore
{
public:
	volatile int RefCount;

	virtual ~GRefCountImplCore() = default;

	GRefCountImplCore() = default;
};
