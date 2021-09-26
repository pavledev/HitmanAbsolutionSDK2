#pragma once

#include <NxSceneQuery.h>

class NxShape;
struct NxRaycastHit;
struct NxSweepQueryHit;

class ZAsyncQueryReport : public NxSceneQueryReport
{
public:
	NxQueryReportResult onBooleanQuery(void* userData, bool result) override;
	NxQueryReportResult onRaycastQuery(void* userData, unsigned int nbHits, const NxRaycastHit* hits) override;
	NxQueryReportResult onShapeQuery(void* userData, unsigned int nbHits, NxShape** hits) override;
	NxQueryReportResult onSweepQuery(void* userData, unsigned int nbHits, NxSweepQueryHit* hits) override;
	~ZAsyncQueryReport() override = default;

	ZAsyncQueryReport() = default;
};
