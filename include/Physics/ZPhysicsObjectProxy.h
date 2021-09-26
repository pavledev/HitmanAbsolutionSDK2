#pragma once

class IPhysicsObject;
template <class T> class TList;

class ZPhysicsObjectProxy
{
public:
	enum
	{
		INITIAL_POOL_SIZE = 500
	};

	IPhysicsObject* m_pObj;
	unsigned int m_nNumRefs;

	static TList<ZPhysicsObjectProxy*>* s_aPhysicsObjectProxyPool;

	~ZPhysicsObjectProxy() = default;
	ZPhysicsObjectProxy() = default;
	void DetachObject();
	static ZPhysicsObjectProxy* CreateProxy(const IPhysicsObject* pObj);
	static void ReleaseProxy(ZPhysicsObjectProxy* pProxy);
	static void Cleanup();
};
