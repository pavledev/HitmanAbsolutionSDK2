#pragma once

class __declspec(novtable) ISoundUpdateListener
{
public:
	virtual void OnSoundUpdate() = 0;
	virtual ~ISoundUpdateListener() = default;

	static void RegisterType();
	ISoundUpdateListener() = default;
};
