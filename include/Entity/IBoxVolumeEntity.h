#pragma once

#include "ITriggerVolume.h"

struct SVector3;

class __declspec(novtable) IBoxVolumeEntity : public ITriggerVolume
{
public:
	~IBoxVolumeEntity() override = default;
	virtual const SVector3& GetGlobalSize() = 0;

	static void RegisterType();
	IBoxVolumeEntity(const IBoxVolumeEntity& __that);
	IBoxVolumeEntity() = default;
	IBoxVolumeEntity& operator=(const IBoxVolumeEntity& __that);
};
