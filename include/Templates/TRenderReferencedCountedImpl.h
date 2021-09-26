#pragma once

template <class A, int B>
class TRenderReferencedCountedImpl : public A
{
public:
    int m_ReferenceCount;

	~TRenderReferencedCountedImpl() override = default;
	virtual void AddRef();
	virtual unsigned int Release();

    TRenderReferencedCountedImpl() = default;
};
