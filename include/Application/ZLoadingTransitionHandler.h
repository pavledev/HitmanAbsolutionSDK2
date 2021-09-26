#pragma once

#include "SSceneInitParameters.h"
#include "ZEvent.h"
#include "ZThreadEvent.h"
#include "ZThread.h"

class ZEventNull;

class __declspec(novtable) ZLoadingTransitionHandler
{
public:
	SSceneInitParameters SceneInitParameters;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> TransitionUpdateEvent;
	ZThreadEvent m_sceneBeingDestroyedEvent;
	ZThread m_transitionThread;
	bool m_bHasStarted;
	bool m_bInterrupted;

	virtual ~ZLoadingTransitionHandler() = default;
	virtual void TransitionStart() = 0;
	virtual bool TransitionUpdate() = 0;
	virtual void TransitionFinish() = 0;
	virtual void OnSceneLoaded() = 0;

	ZLoadingTransitionHandler() = default;
	ZLoadingTransitionHandler(SSceneInitParameters* pSceneParam);
	void StartThread();
	bool HasStarted();
	void Interrupt();
	void NotifySceneDestroyed();
	void NotifySceneLoaded();
	void WaitForCompletion();
	unsigned int TransitionThread(void* transition);
};
