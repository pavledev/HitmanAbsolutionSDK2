#pragma once

#include "SMatrix.h"

class __declspec(novtable) ISoundListenerPositionReceiver
{
public:
	virtual void OnListenerPositionUpdated(const SMatrix& matrix) = 0;
	virtual ~ISoundListenerPositionReceiver() = default;

	static void RegisterType();
	ISoundListenerPositionReceiver() = default;
};
