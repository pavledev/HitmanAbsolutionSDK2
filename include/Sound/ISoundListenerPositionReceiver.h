#pragma once

#include "SMatrix.h"

class ISoundListenerPositionReceiver
{
public:
	virtual void OnListenerPositionUpdated(SMatrix*);
	virtual ~ISoundListenerPositionReceiver();
};
