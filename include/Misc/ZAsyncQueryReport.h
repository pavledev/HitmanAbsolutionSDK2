#pragma once

#include "NxSceneQuery.h"

class ZAsyncQueryReport : public NxSceneQueryReport
{
public:
    virtual NxQueryReportResult onBooleanQuery(void* userData, bool result);
    virtual NxQueryReportResult onRaycastQuery(void* userData, NxU32 nbHits, const NxRaycastHit* hits);
    virtual NxQueryReportResult onShapeQuery(void* userData, NxU32 nbHits, NxShape** hits);
    virtual NxQueryReportResult onSweepQuery(void* userData, NxU32 nbHits, NxSweepQueryHit* hits);
    virtual ~ZAsyncQueryReport();
};