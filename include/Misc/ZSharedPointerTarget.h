#pragma once

#include "ISharedPointerTarget.h"

class ZSharedPointerTarget : public ISharedPointerTarget
{
public:
	long m_iRefCount;

	~ZSharedPointerTarget() override = default;
	void AddReference() const override;
	void RemoveReference() const override;
	unsigned int GetRefCount() const override;

	ZSharedPointerTarget(const ZSharedPointerTarget& __that);
	ZSharedPointerTarget() = default;
	ZSharedPointerTarget& operator=(const ZSharedPointerTarget& __that);
};
