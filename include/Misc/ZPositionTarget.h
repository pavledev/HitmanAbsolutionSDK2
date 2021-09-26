#pragma once

#include "SVector3.h"
#include "TRefCountPtr.h"
#include "float4.h"

struct SKnownEntity;
template <class T> class TRefCountPtrArg;

class ZPositionTarget
{
public:
	SVector3 wsTargetPosition;
	TRefCountPtr<SKnownEntity> rTargetEntity;

	ZPositionTarget(const ZPositionTarget& __that);
	ZPositionTarget(TRefCountPtrArg<SKnownEntity> targetEntity);
	ZPositionTarget(const float4& wsPosition);
	ZPositionTarget() = default;
	bool IsSet() const;
	void Clear();
	float4 Position() const;
	float4 AimToPosition() const;
	float4 LookAtPosition() const;
	bool operator==(const ZPositionTarget& rhs);
	float4 GetFixedPosition() const;
	float4 GetTargetPosition() const;
	~ZPositionTarget() = default;
	ZPositionTarget& operator=(const ZPositionTarget& __that);
};
