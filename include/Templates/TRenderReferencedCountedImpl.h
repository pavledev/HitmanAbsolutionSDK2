#pragma once

template<class A, int B>
class TRenderReferencedCountedImpl : A
{
public:
    int m_ReferenceCount;
};
