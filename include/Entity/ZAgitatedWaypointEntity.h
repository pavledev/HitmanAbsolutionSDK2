#pragma once

#include "ZSpatialEntity.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SVector3.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZAgitatedWaypointEntity : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fMinDelay;
	ZResourcePtr m_pGizmo;
	bool m_bHideOnStart;
	SVector3 m_vSubPosition0;
	SVector3 m_vSubPosition1;
	SVector3 m_vSubPosition2;
	float m_fSubAngle0;
	float m_fSubAngle1;
	float m_fSubAngle2;

	static SComponentMapEntry s_componentMap[0];

	~ZAgitatedWaypointEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;

	ZAgitatedWaypointEntity() = default;
	static void RegisterType();
	ZAgitatedWaypointEntity(ZComponentCreateInfo& info);
	float GetMinDelay() const;
	SMatrix GetSubWaypointMatrix(unsigned int nSubIndex) const;
	void OnGizmoChanged();
};
