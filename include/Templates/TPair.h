#pragma once

template <class A, class B>
class TPair
{
public:
	A m_key;
	B m_value;

	TPair<A, B>(A key, B value) : m_key(key), m_value(value) 
	{

	}
};