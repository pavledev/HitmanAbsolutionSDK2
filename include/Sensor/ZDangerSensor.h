#pragma once

#include "TArrayRef.h"
#include "ZGridJobRequest.h"
#include "TArray.h"
#include "TRefCountPtr.h"
#include "ZGameTime.h"
#include "ZGridNodeRef.h"
#include "float4.h"

class ZActor;
class ZGridFloatField;
template <class T> class TEntityRef;

class ZDangerSensor
{
public:
	struct SDisturbance
	{
		float4 m_vPos;
		ZGameTime m_tStart;

		SDisturbance(const SDisturbance& __that);
		SDisturbance() = default;
		SDisturbance& operator=(const SDisturbance& __that);
	};

	TArrayRef<TEntityRef<ZActor>> m_aActors;
	TArray<SDisturbance> m_aDisturbances;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_dangerFieldRequest;
	TRefCountPtr<ZGridFloatField> m_dangerField;
	int m_eState;
	int m_nCandidateIndex;
	ZGameTime m_tLastDecayTime;
	float m_fDecayRate;
	float m_fInfluenceMaxDistance;

	ZDangerSensor() = default;
	~ZDangerSensor() = default;
	void Reset();
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	TRefCountPtr<ZGridFloatField> GetDangerField();
	float GetDangerFieldValue(ZGridNodeRef rNode);
	void AddDisturbance(const float4& vPos);
	void State_AddDeadBodies();
	void State_AddDisturbances();
	void State_AddGuards();
	void State_Decay();
	float DangerField_AddDangerInfluence(const ZGridNodeRef& node, float fDistance, float fCurrentValue);
	float DangerField_AddDecayInfluence(const ZGridNodeRef& node, float fDistance, float fCurrentValue);
};
