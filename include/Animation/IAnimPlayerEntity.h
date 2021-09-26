#pragma once

class ZString;

class __declspec(novtable) IAnimPlayerEntity
{
public:
	virtual bool ContainsAnimation(const ZString& string) = 0;
	virtual bool RequestAnimationByName(const ZString& string) = 0;
	virtual void SetIsPlaying(bool param1) = 0;
	virtual void SetTrajectoryFlag(bool param1) = 0;
	virtual void SetTime(float param1) = 0;
	virtual float GetDuration() const = 0;
	virtual void ResetTime() = 0;
	virtual ~IAnimPlayerEntity() = default;

	static void RegisterType();
	IAnimPlayerEntity() = default;
};
