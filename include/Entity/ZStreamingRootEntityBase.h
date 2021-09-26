#pragma once

#include "ZEntityImpl.h"

class ZComponentCreateInfo;
class ZEntityRef;
template <class A, class B> class THashSet;
template <class T> class TArray;
template <class T> class TDefaultHashSetPolicy;

class ZStreamingRootEntityBase : public ZEntityImpl
{
public:
	~ZStreamingRootEntityBase() override = default;
	void Init() override;

	ZStreamingRootEntityBase() = default;
	static void RegisterType();
	ZStreamingRootEntityBase(const ZStreamingRootEntityBase& __that);
	ZStreamingRootEntityBase(ZComponentCreateInfo& Info);
	void GetStreamableEntities(TArray<ZEntityRef>& streamableEntities) const;
	void GetStreamableEntities(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableEntities) const;
	ZStreamingRootEntityBase& operator=(const ZStreamingRootEntityBase& __that);
};
