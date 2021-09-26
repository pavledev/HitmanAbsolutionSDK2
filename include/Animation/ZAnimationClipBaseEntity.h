#pragma once

#include "ZEntityImpl.h"
#include "ESyncEvent.h"
#include "MR.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZEntityRef;
namespace NMP {
class DataBuffer;
}  // namespace NMP
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;

class ZAnimationClipBaseEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bStreamedIn;

	static SComponentMapEntry s_componentMap[0];

	~ZAnimationClipBaseEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;

	ZAnimationClipBaseEntity() = default;
	static void RegisterType();
	ZAnimationClipBaseEntity(ZComponentCreateInfo& info);
	void sampleAnimation(const MR::IAnimSource* animSource, float fFraction, NMP::DataBuffer* buffer) const;
	ESyncEvent getFirstSyncEvent(const MR::IAnimSource* animSource) const;
};
