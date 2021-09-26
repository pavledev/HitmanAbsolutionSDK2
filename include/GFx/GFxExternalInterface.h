#pragma once

#include "GFxState.h"
#include "GFxMovieView.h"
#include "GFxValue.h"

class __declspec(novtable) GFxExternalInterface : public GFxState
{
public:
	~GFxExternalInterface() override = default;
	virtual void Callback(GFxMovieView* fxMovieView, const char* param2, const GFxValue* fxValue, unsigned int param4) = 0;

	GFxExternalInterface() = default;
};
