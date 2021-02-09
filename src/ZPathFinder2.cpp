#include "ZPathfinder2.h"
#include "Function.h"
#include "BaseAddresses.h"

bool ZPathfinder2::LineBlocked(ZPF5Location* lFrom, ZPF5Location* lTo)
{
	return Function::CallMethodAndReturn<bool, ZPathfinder2*, ZPF5Location*, ZPF5Location*>(BaseAddresses::runtimePathFinder + 0xEE70, this, lFrom, lTo);
}

bool ZPathfinder2::IsLineBlocked(ZPF5Location* lFrom, ZPF5Location* lTo)
{
	return Function::CallMethodAndReturn<bool, ZPathfinder2*, ZPF5Location*, ZPF5Location*>(BaseAddresses::runtimePathFinder + 0xCB80, this, lFrom, lTo);
}

bool ZPathfinder2::TraceLine(ZPF5Location* lFinal, ZPF5Location* lFrom, float4* vDestination, ZPF5LineHitInfo* pLineHitInfo, unsigned __int16 nAllowedRegionMask)
{
	return Function::CallMethodAndReturn<bool, ZPathfinder2*, ZPF5Location*, ZPF5Location*, float4*, ZPF5LineHitInfo*, unsigned __int16>(BaseAddresses::runtimePathFinder + 0xCE60, this, lFinal, lFrom, vDestination, pLineHitInfo, nAllowedRegionMask);
}

bool ZPathfinder2::TraceLineRobust(ZPF5Location* lFinal, ZPF5Location* lFrom, float4* vDestination, ZPF5LineHitInfo* pLineHitInfo, unsigned __int16 nAllowedRegionMask)
{
	return Function::CallMethodAndReturn<bool, ZPathfinder2*, ZPF5Location*, ZPF5Location*, float4*, ZPF5LineHitInfo*, unsigned __int16>(BaseAddresses::runtimePathFinder + 0xB990, this, lFinal, lFrom, vDestination, pLineHitInfo, nAllowedRegionMask);
}
