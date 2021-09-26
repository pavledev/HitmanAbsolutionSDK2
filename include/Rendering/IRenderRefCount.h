#pragma once

class __declspec(novtable) IRenderRefCount
{
public:
	virtual ~IRenderRefCount() = default;
	virtual void AddRef() = 0;
	virtual unsigned int Release() = 0;

	IRenderRefCount() = default;
};
