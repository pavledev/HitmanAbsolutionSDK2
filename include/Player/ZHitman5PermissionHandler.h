#pragma once

#include "SHitmanPermissions.h"
#include "EHitmanPermissionFlag.h"
#include "eHitmanPermissionReason.h"

class ZHitman5;
template <class T> class TEntityRef;

class ZHitman5PermissionHandler
{
public:
	SHitmanPermissions m_Permissions;

	ZHitman5PermissionHandler(const ZHitman5PermissionHandler& __that);
	ZHitman5PermissionHandler() = default;
	~ZHitman5PermissionHandler() = default;
	bool HitmanHasPermission(const EHitmanPermissionFlag& eQuery) const;
	void RetriggerPermissionCalls(const TEntityRef<ZHitman5>& pHitman) const;
	void ResetHitmanPermissionHandler();
	void ChangeInventorySelect(const TEntityRef<ZHitman5>& pHitman, eHitmanPermissionReason reason, bool bAllow);
	void ChangeCanHolsterItem(const TEntityRef<ZHitman5>& pHitman, eHitmanPermissionReason reason, bool bAllow);
	void ChangeCanDualWield(const TEntityRef<ZHitman5>& pHitman, eHitmanPermissionReason reason, bool bAllow);
	void ChangeCameraControl(const TEntityRef<ZHitman5>& pHitman, eHitmanPermissionReason reason, bool bAllow);
	void ChangeMovementControl(const TEntityRef<ZHitman5>& pHitman, eHitmanPermissionReason reason, bool bAllow);
	void ChangeAimControl(const TEntityRef<ZHitman5>& pHitman, eHitmanPermissionReason reason, bool bAllow);
	void ChangeCanOpenNotebook(const TEntityRef<ZHitman5>& pHitman, eHitmanPermissionReason reason, bool bAllow);
};
