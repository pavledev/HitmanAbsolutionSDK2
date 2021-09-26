#pragma once

#include "ZAnimationClipEntity.h"
#include "NMP.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZSPUTransitionClip;
class ZComponentCreateInfo;
struct STypeID;
template <class T> class TEntityRef;

class ZTransitionClipEntity : public ZAnimationClipEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bMustAlwaysBeUsed;
	TArray<TEntityRef<ZAnimationClipEntity>> m_sourceClips;
	TArray<TEntityRef<ZAnimationClipEntity>> m_targetClips;

	static SComponentMapEntry s_componentMap[0];

	~ZTransitionClipEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZTransitionClipEntity() = default;
	static void RegisterType();
	ZTransitionClipEntity(ZComponentCreateInfo& info);
	NMP::Memory::Format getTransitionTableRequirements() const;
	bool compileSPUTransitionClip(ZSPUTransitionClip* spuClip, unsigned short clipIndex) const;
	unsigned short* compileSPUTransitionTable(unsigned short* transitionTable) const;
};
