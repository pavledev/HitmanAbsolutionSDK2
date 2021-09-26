#pragma once

class IPhysicsObject;
class ZPhysicsObjectProxy;

class ZPhysicsObjectRef
{
public:
	ZPhysicsObjectProxy* m_pProxy;

	ZPhysicsObjectRef(const IPhysicsObject* pObj);
	ZPhysicsObjectRef(const ZPhysicsObjectRef& pOther);
	ZPhysicsObjectRef() = default;
	~ZPhysicsObjectRef() = default;
	ZPhysicsObjectRef& operator=(const IPhysicsObject* pObj);
	ZPhysicsObjectRef& operator=(const ZPhysicsObjectRef& pOther);
	IPhysicsObject* operator->() const;
	bool operator==(const IPhysicsObject* pObj) const;
	IPhysicsObject* Get() const;
};
