#pragma once

#include "GFxState.h"

class GFxImageCreator : public GFxState
{
public:
	bool KeepImageBindData;

	~GFxImageCreator() override = default;

	GFxImageCreator() = default;
	GFxImageCreator(bool keepImageBindData);
};
