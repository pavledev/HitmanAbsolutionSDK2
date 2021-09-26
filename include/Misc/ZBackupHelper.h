#pragma once

#include "ZGameTime.h"

class ZBackupHelper
{
public:
	bool m_bCombatZonesReset;
	bool m_bSpawnMessageShown;
	int m_nActorsSpawned;
	ZGameTime m_lastBackupTime;

	ZBackupHelper() = default;
	~ZBackupHelper() = default;
	void Reset();
	void Update();
	void UpdateBackup();
	void UpdateZoneStates();
	void StartBackupDialog();
};
