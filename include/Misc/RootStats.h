#pragma once

struct RootStats
{
    unsigned int SysMemFootprint;
    unsigned int SysMemUsedSpace;
    unsigned int PageMapFootprint;
    unsigned int PageMapUsedSpace;
    unsigned int BookkeepingFootprint;
    unsigned int BookkeepingUsedSpace;
    unsigned int DebugInfoFootprint;
    unsigned int DebugInfoUsedSpace;
    unsigned int UserDebugFootprint;
    unsigned int UserDebugUsedSpace;
};
