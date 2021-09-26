#pragma once

#include "ZEvent.h"
#include "TEntityRef.h"
#include "ZActor.h"

class ZCollisionSensor
{
public:
	ZEvent<TEntityRef<ZActor>, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_ActorStaticCollisionEvent;

	virtual ~ZCollisionSensor() = default;

	ZCollisionSensor() = default;
	void Reset();
	ZEvent<TEntityRef<ZActor>, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetActorStaticCollisionEvent();
	void CollisionEventHandler(const TArrayRef<SCollisionInfo> col);
	TEntityRef<IHM5Item> GetItemInterface(IPhysicsObject* pCollider1, IPhysicsObject* pCollider2);
	TEntityRef<ZActor> GetActorInterface(IPhysicsObject* pCollider1, IPhysicsObject* pCollider2);
	bool TestActorStaticCollision(IPhysicsObject* pCollider1, IPhysicsObject* pCollider2);
};
