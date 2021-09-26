#pragma once

class __declspec(novtable) IMusicComposition
{
public:
	virtual ~IMusicComposition() = default;
	virtual void JumpTo() = 0;

	IMusicComposition() = default;
};
