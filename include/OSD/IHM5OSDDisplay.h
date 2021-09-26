#pragma once

class IHM5OSD;

class __declspec(novtable) IHM5OSDDisplay
{
public:
	virtual void Update(IHM5OSD* ihmosd) = 0;
	virtual ~IHM5OSDDisplay() = default;

	IHM5OSDDisplay() = default;
};
