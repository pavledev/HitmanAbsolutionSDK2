#pragma once

#include "IComponentInterface.h"
#include "ERayLayer.h"
#include "SGameSpecificCollisionFilterCallbacks.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ICollisionManager;
class IPhysicsObject;
class ZFilterGroupMask;
class ZSpatialEntity;
struct SComponentMapEntry;
struct SMatrix;
struct STypeID;
struct float4;

class ZHM5CollisionManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ICollisionManager* m_pCollisionManager;

	~ZHM5CollisionManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5CollisionManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	unsigned int GetRayFilter(ERayLayer eRayLayer) const;
	IPhysicsObject* CreateStaticCollisionBox(const float4& vHalfSize, const SMatrix& mTransform, const ZEntityRef& entity, unsigned short nCollisionLayer);
	static TEntityRef<ZSpatialEntity> GetSpatialFromCollision(ZEntityRef entity);
	static unsigned short MapCollisionLayerToOpaque(const unsigned short nLayer);
	static bool GetRayLayerFilterGroupMask(const unsigned int nRayLayer, ZFilterGroupMask& mask);
	static SGameSpecificCollisionFilterCallbacks GetGameSpecificCollisionFilterCallbacks();
	static bool IsCollisionLayerOpaque(const unsigned short nLayer);
	static ZString GetLevelAndCheckpointName();
};
