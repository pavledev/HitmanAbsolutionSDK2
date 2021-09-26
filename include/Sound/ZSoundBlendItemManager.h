#pragma once

#include "SItemPair.h"
#include "ZSoundBlendItemInstance.h"

class ZSoundBlendItemManager
{
public:
	SItemPair m_CurrentItems;
	ZSoundBlendItemInstance* m_pInstances[2];
	unsigned int m_nNextSlot;

	ZSoundBlendItemManager() = default;
	void IntroduceNewItemPair(const SItemPair& newItems, SItemPair& stopItems, SItemPair& startItems);
	void SetCrossFadeRatio(float fPrimarySource);
	TEntityRef<ZSoundBlendItem> GetItem(int index);
	void CreateFirstItemPair(const SItemPair& newItems);
	void AddItemInstance(ZSoundBlendItemInstance* pInstance);
	void RemoveItemInstance(ZSoundBlendItemInstance* pInstance);
	~ZSoundBlendItemManager() = default;
};
