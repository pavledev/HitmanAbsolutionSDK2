#pragma once

#include "SSceneInitParameters.h"
#include "ZEvent.h"
#include "ZEventNull.h"
#include "ZThreadEvent.h"
#include "ZThread.h"

class ZLoadingTransitionHandler
{
public:
    alignas(8) SSceneInitParameters SceneInitParameters;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> TransitionUpdateEvent;
    ZThreadEvent m_sceneBeingDestroyedEvent;
    alignas(8) ZThread m_transitionThread;
    bool m_bHasStarted;
    bool m_bInterrupted;

    virtual ~ZLoadingTransitionHandler();
    virtual void TransitionStart();
    virtual bool TransitionUpdate();
    virtual void TransitionFinish();
    virtual void OnSceneLoaded();
};
