#pragma once

#include "TEntityRef.h"
#include "ZShowBreadcrumbIcon.h"
#include "SHUDIconInfo.h"

class SBreadcrumb
{
public:
    TEntityRef<ZShowBreadcrumbIcon> ent;
    SHUDIconInfo icon;
};
