#pragma once

#include "GRefCountBase.h"

class __declspec(novtable) GFxTask : public GRefCountBase<GFxTask, 2>
{
public:
	enum TaskType
	{
		Type_Computation = 65536,
		Type_IO = 131072,
		Type_Mask = 16711680
	};

	enum TaskId
	{
		Id_Unknown = 65537,
		Id_MovieDecoding = 65538,
		Id_MovieDataLoad = 131073,
		Id_MovieImageLoad = 131074,
		Id_MovieBind = 131075
	};

	enum TaskState
	{
		State_Idle = 0,
		State_Pending = 1,
		State_Running = 2,
		State_Abandoned = 3,
		State_Finished = 4
	};

	TaskId ThisTaskId;
	volatile TaskState CurrentState;

	~GFxTask() override = default;
	virtual void Execute() = 0;

	GFxTask() = default;
};
