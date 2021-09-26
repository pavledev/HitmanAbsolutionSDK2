#pragma once

#include "float4.h"
#include "ECollisionSupport.h"
#include "ZPhysicsObjectRef.h"

struct SCollisionInfo
{
	float4 m_vColliderLinearVelocity;
	float4 m_vColliderAngularVelocity;
	float4 m_vListenerLinearVelocity;
	float4 m_vListenerAngularVelocity;
	float4 m_vContactPoint;
	float4 m_vContactNormal;
	float4 m_vContactForce;
	unsigned int m_nSupportCount;
	ECollisionSupport m_eSupport;
	unsigned int m_nID;
	ZPhysicsObjectRef m_pCollider;
	ZPhysicsObjectRef m_pListener;

	static void RegisterType();
	SCollisionInfo(const SCollisionInfo& __that);
	SCollisionInfo() = default;
	~SCollisionInfo() = default;
	SCollisionInfo& operator=(const SCollisionInfo& __that);
};
