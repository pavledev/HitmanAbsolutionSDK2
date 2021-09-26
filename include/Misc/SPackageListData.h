#pragma once

#include "TArray.h"

struct SPackageListDataFolder;

struct SPackageListData
{
	TArray<SPackageListDataFolder> folders;

	SPackageListData() = default;
	~SPackageListData() = default;
};
