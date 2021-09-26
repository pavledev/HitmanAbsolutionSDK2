#include "TBinaryTreeIterator.h"
#include "BaseAddresses.h"
#include "ZSpatialEntity.h"
#include "ZGlobalOutfitKit.h"
#include "TPair.h"

template <>
unsigned int TBinaryTreeIterator<TEntityRef<ZSpatialEntity> const>::NodeOffset()
{
	return BaseAddresses::hitman5Dll + 0x6D19B0;
}

template <>
unsigned int TBinaryTreeIterator<TEntityRef<ZSpatialEntity> const>::IncrementOperatorOffset()
{
	return BaseAddresses::hitman5Dll + 0x1E0810;
}

template <>
unsigned int TBinaryTreeIterator<TPair<STokenID const, TEntityRef<ZGlobalOutfitKit>>>::NodeOffset()
{
	return BaseAddresses::hitman5Dll + 0x1CA630;
}
