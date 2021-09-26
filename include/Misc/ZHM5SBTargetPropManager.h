#pragma once

#include "IComponentInterface.h"
#include "TRedBlackTree.h"
#include "ZVariantRef.h"

class ZSpatialEntity;
struct SComponentMapEntry;
struct STypeID;
template <class T> class TEntityRef;

class ZHM5SBTargetPropManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TRedBlackTree<TEntityRef<ZSpatialEntity> const> m_registeredProps;
	TRedBlackTree<TEntityRef<ZSpatialEntity> const> m_registeredPropsForLock;

	~ZHM5SBTargetPropManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5SBTargetPropManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	bool RegisterProp(const TEntityRef<ZSpatialEntity> rSpatialEntity, bool fRegisterForLock);
	void UnregisterProp(const TEntityRef<ZSpatialEntity> rSpatialEntity);
	bool IsRegistered(const TEntityRef<ZSpatialEntity> rSpatialEntity);
	const TRedBlackTree<TEntityRef<ZSpatialEntity> const>* GetPropRegisterForLock() const;
};
