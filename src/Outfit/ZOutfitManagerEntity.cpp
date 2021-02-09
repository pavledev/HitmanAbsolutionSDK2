#include "ZOutfitManagerEntity.h"

TEntityRef<ZHM5Outfit>* ZOutfitManagerEntity::GetOutfit(TEntityRef<ZHM5Outfit>* result, STokenID outfitToken)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHM5Outfit>*, ZOutfitManagerEntity*, TEntityRef<ZHM5Outfit>*, STokenID>(BaseAddresses::hitman5Dll + 0x1E475, this, result, outfitToken);
}

//TEntityRef<ZHM5Outfit> ZOutfitManagerEntity::GetOutfit(STokenID outfitToken)
//{
//	return Function::CallMethodAndReturn<TEntityRef<ZHM5Outfit>, ZOutfitManagerEntity*, STokenID>(BaseAddresses::hitman5Dll + 0x1E475, this, outfitToken);
//}

void ZOutfitManagerEntity::RegisterType()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x20A8B);
}
