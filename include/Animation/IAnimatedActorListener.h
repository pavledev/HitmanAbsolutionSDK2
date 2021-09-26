#pragma once

class __declspec(novtable) IAnimatedActorListener
{
public:
	virtual ~IAnimatedActorListener() = default;
	virtual void OnMoveStart() = 0;
	virtual void OnMove() = 0;
	virtual void OnMoveStopping() = 0;
	virtual void OnStanding() = 0;
	virtual void OnActStart() = 0;
	virtual void OnActInFullbody() = 0;
	virtual void OnActEnteredLoop() = 0;
	virtual void OnActStopping() = 0;
	virtual void OnReactionStart() = 0;
	virtual void OnReactionStopping() = 0;
	virtual void OnOrderCompleted() = 0;

	IAnimatedActorListener() = default;
};
