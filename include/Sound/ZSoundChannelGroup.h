#pragma once

#include "ZSoundChannelGroupBase.h"
#include "ESoundChannelGroup.h"

class ZSoundChannelGroup : public ZSoundChannelGroupBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZString m_sGroupName;
	TEntityRef<ISoundChannelGroup> m_pParentGroup;
	ESoundChannelGroup m_eParentMapping;
	ESoundChannelGroup m_eMapping;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundChannelGroup() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	const ZString& GetGroupName() const override;
	void Init() override;
	void Start() override;
	virtual ESoundChannelGroup GetMapping() const;

	ZSoundChannelGroup() = default;
	static void RegisterType();
	ZSoundChannelGroup(ZComponentCreateInfo& info);
	void ConnectToParentChannelGroup();
};
