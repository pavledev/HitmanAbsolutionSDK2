#pragma once

class __declspec(novtable) ISubtitledPlayer
{
public:
	virtual ~ISubtitledPlayer() = default;
	virtual float GetPlayPosition() = 0;

	ISubtitledPlayer() = default;
};
