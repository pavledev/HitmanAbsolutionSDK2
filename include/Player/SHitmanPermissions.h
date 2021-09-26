#pragma once

#include "TFixedArray.h"
#include "EHitmanPermissionFlag.h"
#include "eHitmanPermissionReason.h"

struct SHitmanPermissions
{
	TFixedArray<unsigned int, 7> m_iPermissions;

	bool HitmanHasPermission(const EHitmanPermissionFlag& eQuery) const;
	SHitmanPermissions(const SHitmanPermissions& __that);
	SHitmanPermissions() = default;
	~SHitmanPermissions() = default;
	void ResetAllHitmanPermissions();
	void HitmanPermissionChange(EHitmanPermissionFlag permission, eHitmanPermissionReason reason, bool bAllow);
	void HitmanPermissionAllow(EHitmanPermissionFlag permission, eHitmanPermissionReason reasonAllow);
	void HitmanPermissionDisallow(EHitmanPermissionFlag permission, eHitmanPermissionReason reasonDisallow);
};
