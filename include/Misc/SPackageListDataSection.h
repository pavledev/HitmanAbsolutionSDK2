#pragma once

#include "TArray.h"

class ZString;

struct SPackageListDataSection
{
	TArray<ZString> sceneResourceIDs;
	TArray<ZString> resources;

	SPackageListDataSection() = default;
	~SPackageListDataSection() = default;
};
