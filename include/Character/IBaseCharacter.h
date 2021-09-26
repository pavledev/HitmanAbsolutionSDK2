#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"

class ZSpatialEntity;
struct SHitInfo;
template <class T> class TEntityRef;

class __declspec(novtable) IBaseCharacter : public IComponentInterface
{
public:
	~IBaseCharacter() override = default;
	virtual void YouGotHit(const SHitInfo& hitInfo) = 0;
	virtual bool CanProjectileHitCharacter(const SHitInfo& hitInfo) = 0;
	virtual unsigned short GetCollisionLayer() const = 0;
	virtual bool RegisterAttachment(unsigned int param1, TEntityRef<ZSpatialEntity> entityRef) = 0;
	virtual void UnregisterAttachment(unsigned int param1, TEntityRef<ZSpatialEntity> entityRef) = 0;
	virtual bool IsRagdoll() const = 0;
	virtual ZEntityRef GetLinkedEntityBase() const = 0;

	static void RegisterType();
	IBaseCharacter() = default;
};
