#pragma once

#include "GRefCountBase.h"

class GFxMovieView;
class GFxValue;

class __declspec(novtable) GFxFunctionHandler : public GRefCountBase<GFxFunctionHandler, 2>
{
public:
	struct Params
	{
		GFxValue* pRetVal;
		GFxMovieView* pMovie;
		GFxValue* pThis;
		GFxValue* pArgsWithThisRef;
		GFxValue* pArgs;
		unsigned int ArgCount;
		void* pUserData;
	};

	~GFxFunctionHandler() override = default;
	virtual void Call(const Params& params) = 0;

	GFxFunctionHandler() = default;
};
