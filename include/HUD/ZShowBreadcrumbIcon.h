#pragma once

#include "ZSpatialEntity.h"
#include "EHUDIconType.h"

class ZShowBreadcrumbIcon : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	EHUDIconType m_eIconType;

	static SComponentMapEntry s_componentMap[0];

	~ZShowBreadcrumbIcon() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZShowBreadcrumbIcon() = default;
	static void RegisterType();
	ZShowBreadcrumbIcon(ZComponentCreateInfo& info);
	void OnShow();
	void OnHide();
	const float4 Get3DPos() const;
	EHUDIconType GetIconType() const;
};
