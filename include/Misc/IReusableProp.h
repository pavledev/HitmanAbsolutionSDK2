#pragma once

class __declspec(novtable) IReusableProp
{
public:
	virtual ~IReusableProp() = default;
	virtual void UseOnce() = 0;
	virtual void ResetUsedFlag() = 0;
	virtual bool IsUsed() const = 0;

	IReusableProp() = default;
};
