#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZStreamingRootEntity;
struct STypeID;
template <class T> class TEntityRef;

class ZStreamingStateEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZString m_Name;
	TArray<TEntityRef<ZStreamingRootEntity>> m_StreamingRoots;
	bool m_bIsReady;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snStateReady;

	~ZStreamingStateEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZStreamingStateEntity() = default;
	static void RegisterType();
	ZStreamingStateEntity(const ZStreamingStateEntity& __that);
	ZStreamingStateEntity(ZComponentCreateInfo& Info);
	const ZString& GetName() const;
	const TArray<TEntityRef<ZStreamingRootEntity>>& GetStreamingRoots() const;
	void SetStateReady(bool bReady);
	bool IsReady();
	void OnStreamingRootsChanged(const TArray<TEntityRef<ZStreamingRootEntity>>& oldValue);
	ZStreamingStateEntity& operator=(const ZStreamingStateEntity& __that);
};
