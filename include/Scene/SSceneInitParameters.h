#pragma once

#include "ZString.h"

struct SSceneInitParameters
{
	ZString m_SceneResource;
	ZString m_StreamingState;

	SSceneInitParameters(const ZString& sceneResource, ZString streamingState);
	SSceneInitParameters() = default;
	~SSceneInitParameters() = default;
	SSceneInitParameters& operator=(const SSceneInitParameters& __that);
};
