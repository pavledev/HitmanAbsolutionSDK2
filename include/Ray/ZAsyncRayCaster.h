#pragma once

#include "ZAsyncQueryReport.h"
#include "TFixedArray.h"
#include "TStack.h"
#include "TIntrusiveList.h"
#include "TMap.h"
#include "TArray.h"

class IAsyncRayHandle;
class IPhysicsObject;
class NxScene;
class NxSceneQuery;
class ZAsyncRayHandle;
class ZRayQueryInput;
class ZRayQueryOutput;
class ZRuntimeResourceID;
template <class T> class TIntrusiveListAccessor;

class ZAsyncRayCaster
{
public:
	NxScene* m_pPhysXWorld;
	NxSceneQuery* m_pSceneQuery;
	bool m_bExecute;
	ZAsyncQueryReport m_QueryReport;
	TFixedArray<ZAsyncRayHandle, 750> m_HandlePool;
	TStack<ZAsyncRayHandle*, TArray<ZAsyncRayHandle*>> m_FreeHandles;
	TIntrusiveList<ZAsyncRayHandle, TIntrusiveListAccessor<ZAsyncRayHandle>> m_ActiveHandles;
	TArray<ZAsyncRayHandle*> m_QueuedHandles;
	int m_nSuspendCount;
	TMap<ZRayQueryOutput*, ZRuntimeResourceID> m_storedBlockingMaterials;

	static const unsigned int nMaxAsyncRayHandles;

	virtual ~ZAsyncRayCaster() = default;

	ZAsyncRayCaster() = default;
	ZAsyncRayCaster(NxScene* pPhysXWorld);
	IAsyncRayHandle* AsyncRayCastClosestHit(const ZRayQueryInput& sInput);
	void ExecuteAsyncRayCasts();
	void FinishAsyncRayCasts();
	void DeleteAllQueries(bool bRecreate);
	void Suspend();
	void Resume();
	bool IsSuspended() const;
	bool IssueRayCastQuery(ZAsyncRayHandle* pHandle);
	void PruneReleased();
	void ProcessPendingHandles();
	bool CreateSceneQuery();
	void DestroySceneQuery();
	void ClearPhysicObjectReferences(const IPhysicsObject* pPhysicsObject);
};
