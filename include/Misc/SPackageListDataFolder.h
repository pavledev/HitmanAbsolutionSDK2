#pragma once

#include "ZString.h"
#include "TArray.h"

struct SPackageListDataSection;

struct SPackageListDataFolder
{
	ZString name;
	TArray<SPackageListDataSection> sections;

	SPackageListDataFolder() = default;
	~SPackageListDataFolder() = default;
};
