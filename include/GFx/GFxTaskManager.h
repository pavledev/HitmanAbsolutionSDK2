#pragma once

#include "GFxState.h"
#include "GFxTask.h"

class __declspec(novtable) GFxTaskManager : public GFxState
{
public:
	~GFxTaskManager() override = default;
	virtual bool AddTask(GFxTask* fxTask) = 0;
	virtual bool AbandonTask(GFxTask* fxTask) = 0;
	virtual void RequestShutdown() = 0;

	GFxTaskManager() = default;
};
