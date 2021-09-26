#pragma once

#include "SGameEventArgs.h"
#include "EGameEventArgType.h"

class __declspec(novtable) IGameStatsListener
{
public:
	virtual ~IGameStatsListener() = default;
	virtual void ProcessGameEvent(const SGameEventArgs& gameEventArgs) = 0;
	virtual EGameEventArgType GetArgType() const = 0;

	IGameStatsListener() = default;
};
