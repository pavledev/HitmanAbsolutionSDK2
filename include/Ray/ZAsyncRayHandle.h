#pragma once

#include "IAsyncRayHandle.h"
#include "ERayType.h"
#include "TArray.h"
#include "ZRayQueryInput.h"
#include "ZRayQueryOutput.h"

struct NxRayHit;

class ZAsyncRayHandle : public IAsyncRayHandle
{
public:
	enum EHandleState
	{
		EHANDLESTATE_CONSTRUCTED = 0,
		EHANDLESTATE_PENDING = 1,
		EHANDLESTATE_PROCESSED = 2,
		EHANDLESTATE_RELEASED = 3,
		EHANDLESTATE_DESTROYED = 4
	};

	ZAsyncRayHandle* m_pNext;
	ZAsyncRayHandle* m_pPrevious;
	EHandleState m_eState;
	ZRayQueryInput m_Input;
	ZRayQueryOutput m_Output;
	ERayType m_eRayType;
	TArray<NxRayHit> m_aHits;

	bool IsReady() const override;
	void Release() override;
	const ZRayQueryInput& GetRayCastInput() const override;
	const ZRayQueryOutput& GetRayCastOutput() const override;
	~ZAsyncRayHandle() override = default;

	ZAsyncRayHandle() = default;
	void Initialize(const ZRayQueryInput& sInput);
	void Process();
};
