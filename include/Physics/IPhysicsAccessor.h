#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"

class IPhysicsObject;
class ZSpatialEntity;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) IPhysicsAccessor : public IComponentInterface
{
public:
	~IPhysicsAccessor() override = default;
	virtual TEntityRef<ZSpatialEntity> GetSpatialOwner() const = 0;
	virtual bool IsPhysicsObject() const = 0;
	virtual IPhysicsObject* GetPhysicsObject() const = 0;
	virtual bool IsRegisteredForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>& param1) const = 0;
	virtual void RegisterForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>& param1) = 0;
	virtual void UnregisterForPhysicsObjectListening(const ZDelegate<void __cdecl(IPhysicsAccessor const*, IPhysicsObject const*, IPhysicsObject const*)>& param1) = 0;

	static void RegisterType();
	IPhysicsAccessor() = default;
};
