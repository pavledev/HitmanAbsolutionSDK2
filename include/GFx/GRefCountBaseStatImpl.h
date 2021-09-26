#pragma once

template <class A, int B>
class GRefCountBaseStatImpl : public A
{
public:
	~GRefCountBaseStatImpl() override = default;

	GRefCountBaseStatImpl() = default;
	static void* operator new(unsigned int sz);
	static void operator delete(void* p);
};
