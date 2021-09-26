#pragma once

class __declspec(novtable) IAmdDxExtInterface
{
public:
	virtual unsigned int AddRef() = 0;
	virtual unsigned int Release() = 0;
	virtual ~IAmdDxExtInterface() = 0;

	IAmdDxExtInterface() = default;
};
