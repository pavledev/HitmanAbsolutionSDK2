#pragma once

#include "TSharedPointer.h"
#include "MR.h"
#include "ZRuntimeResourceID.h"

class ZResourcePending;
class ZResourceReader;

class ZRigResource
{
public:
	TSharedPointer<ZResourceReader> m_pReader;
	MR::Rig* m_pRig;
	ZRuntimeResourceID m_ridResource;

	ZRigResource() = default;
	ZRigResource(const ZRigResource& __that);
	ZRigResource(ZResourcePending& resourcePending);
	~ZRigResource() = default;
	MR::Rig* GetRig() const;
	ZRuntimeResourceID GetRuntimeResourceID() const;
	static void InitializeGlobalBoneMap(MR::Rig* pRig);
	static void FreeGlobalBoneMap(MR::Rig* pRig);
	void GlobalBoneRegistryReset();
	ZRigResource& operator=(const ZRigResource& __that);
};
