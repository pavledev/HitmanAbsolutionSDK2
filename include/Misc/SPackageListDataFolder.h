#pragma once

#include "ZString.h"
#include "TArray.h"
#include "SPackageListDataSection.h"

class SPackageListDataFolder
{
public:
    ZString name;
    TArray<SPackageListDataSection> sections;
};
