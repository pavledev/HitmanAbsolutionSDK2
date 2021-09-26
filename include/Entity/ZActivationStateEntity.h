#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZActivatableRootEntity;
class ZComponentCreateInfo;
class ZStreamingStateEntity;
struct STypeID;

class ZActivationStateEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZStreamingStateEntity> m_pRequiredStreamingState;
	TArray<TEntityRef<ZActivatableRootEntity>> m_aActivatableRoots;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnActivated;

	~ZActivationStateEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZActivationStateEntity() = default;
	static void RegisterType();
	ZActivationStateEntity(ZComponentCreateInfo& info);
	TEntityRef<ZStreamingStateEntity> GetRequiredStreamingState() const;
	const TArray<TEntityRef<ZActivatableRootEntity>>& GetActivatableRoots();
	void SignalOnActivated();
	void OnActivate();
	void OnStreamIn();
	void OnActivatableRootsChanged();
};
