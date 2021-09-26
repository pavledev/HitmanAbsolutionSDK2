#pragma once

class __declspec(novtable) IEnumeratorImpl
{
public:
	virtual void* GetNext(const void* param1) = 0;
	virtual void Release() = 0;
	virtual ~IEnumeratorImpl() = default;

	IEnumeratorImpl() = default;
};
