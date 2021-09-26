#include "TBinaryTree.h"
#include "BaseAddresses.h"
#include "ZSpatialEntity.h"

template <>
unsigned int TBinaryTree<TEntityRef<ZSpatialEntity> const>::BeginOffset()
{
	return BaseAddresses::hitman5Dll + 0x1E17E0;
}

template <>
unsigned int TBinaryTree<TEntityRef<ZSpatialEntity> const>::EndOffset()
{
	return BaseAddresses::hitman5Dll + 0x6D2100;
}
