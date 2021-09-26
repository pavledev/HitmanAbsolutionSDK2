#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "STokenID.h"
#include "TSet.h"
#include "TArrayIterator.h"

class ZContentKitEntity;
class ZContentKitMenuSetup;

class ZShadowContentKitList
{
public:
	struct SEntry
	{
		TSet<TEntityRef<ZContentKitEntity>> m_rKits;
		TEntityRef<ZContentKitMenuSetup> m_rMenu;
		STokenID m_CachedToken;

		SEntry(const SEntry& __that);
		SEntry(const TEntityRef<ZContentKitEntity>& rKit, const TEntityRef<ZContentKitMenuSetup>& rMenu);
		SEntry() = default;
		SEntry& operator=(const SEntry& rRHS);
		const TEntityRef<ZContentKitEntity> GetFirstKit() const;
		~SEntry() = default;
	};

	TArray<SEntry> m_List;

	ZShadowContentKitList() = default;
	~ZShadowContentKitList() = default;
	void Clear();
	bool RegisterKit(const TEntityRef<ZContentKitEntity>& rKit, const TEntityRef<ZContentKitMenuSetup>& rMenu);
	bool UnregisterKit(const TEntityRef<ZContentKitEntity>& rKit);
	TEntityRef<ZContentKitEntity> FindKitByID(const STokenID& id);
	TEntityRef<ZContentKitMenuSetup> FindKitMenuByID(const STokenID& id);
	TArrayIterator<SEntry> FindEntryByID(const STokenID& id);
	TArrayIterator<SEntry> FindEntryByKit(const TEntityRef<ZContentKitEntity>& rKit);
	void DumpContent();
};
