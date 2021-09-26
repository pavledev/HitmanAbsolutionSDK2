#pragma once

#include "ZGridNodeRef.h"

class __declspec(novtable) INodeRatingDebug
{
public:
	virtual ~INodeRatingDebug() = default;
	virtual float GetNodeDebugRating(const ZGridNodeRef& gridNodeRef) = 0;
	virtual float GetNodeDebugTextRatingScale() = 0;

	INodeRatingDebug() = default;
};
