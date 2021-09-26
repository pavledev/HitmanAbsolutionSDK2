#pragma once

#include "EGameEventArgType.h"

class SGameEventArgs
{
public:
	EGameEventArgType m_eType;

	virtual ~SGameEventArgs() = default;

	SGameEventArgs() = default;
	SGameEventArgs(const EGameEventArgType t);
	EGameEventArgType GetType() const;
};
