#pragma once

#include "TMap.h"
#include "ZHM5Action.h"
#include "IAsyncRayHandle.h"
#include "ZGameTime.h"

class ZHM5ActionClient;

class ZHM5ActionClientRayCaster
{
public:
	enum EResultType
	{
		eRT_FarFeedback = 0,
		eRT_Pickup = 1,
		eRT_NUM = 2
	};

	enum EQueryState
	{
		eRS_NoRequest = 0,
		eRS_NewInQueue = 1,
		eRS_ResultClear = 2,
		eRS_ResultHit = 3
	};

	enum
	{
		RAY_ORIGINS = 2,
		RAY_TARGETS = 3
	};

	struct SActionRayResult
	{
		ZGameTime m_tLastQuery;
		EQueryState m_eState;
		float m_fDistanceSq;
		unsigned char m_iRayStyle;
		unsigned char m_iRayResults;

		SActionRayResult(const SActionRayResult& __that);
		SActionRayResult() = default;
		SActionRayResult& operator=(const SActionRayResult& __that);
	};

	struct SRayResults
	{
		SActionRayResult m_res[2];
		bool m_bRefreshed;

		SRayResults(const SRayResults& __that);
		SRayResults() = default;
	};

	TMap<ZHM5Action*, SRayResults> m_ActionQueries;
	ZHM5ActionClient* m_pActionClient;
	IAsyncRayHandle* m_pRayCastHandle;
	ZHM5Action* m_pRayCastKey;
	EResultType m_eRayCastType;
	bool m_bOpenForNewQuerries;

	ZHM5ActionClientRayCaster() = default;
	ZHM5ActionClientRayCaster(ZHM5ActionClient* pActionClient);
	~ZHM5ActionClientRayCaster() = default;
	void Reset();
	void UpdateStart();
	bool TestFarFeedbackVisibility(ZHM5Action* pAction, float fDistanceSq);
	bool TestPickupActionAccess(ZHM5Action* pAction, float fDistanceSq);
	void ProcessQueriesAndFireRay();
	void SetRayCastKey(ZHM5Action* key, EResultType type);
	bool Test(ZHM5Action* pAction, float fDistanceSq, EResultType type);
	const ZHM5ActionClient* const GetActionClient() const;
};
