#pragma once

#include "TArray.h"
#include "ZString.h"

class SPackageListDataSection
{
public:
    TArray<ZString> sceneResourceIDs;
    TArray<ZString> resources;
};
