#pragma once

#include "GFxState.h"
#include "GFxMovieView.h"

class __declspec(novtable) GFxFSCommandHandler : public GFxState
{
public:
	~GFxFSCommandHandler() override = default;
	virtual void Callback(GFxMovieView* fxMovieView, const char* param2, const char* param3) = 0;

	GFxFSCommandHandler() = default;
};
