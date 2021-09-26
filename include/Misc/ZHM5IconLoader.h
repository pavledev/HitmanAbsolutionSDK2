#pragma once

#include "IComponentInterface.h"
#include "TMap.h"
#include "ESingletonIconType.h"
#include "ZRuntimeResourceID.h"
#include "TFixedArray.h"
#include "ZDynamicResourceLibrary.h"
#include "TQueue.h"

class ZHM5IconLoader : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum
	{
		TECHNIQUEIDS = 30,
		CPIMAGESIDS = 64,
		OUTFITSIDS = 100,
		CHALLENGESIDS = 80,
		WEAPONSIDS = 80,
		RATINGSIDS = 60,
		TOTALIDS = 414
	};

	struct SLoaderLib
	{
		ZRuntimeResourceID m_ResourceID;
		ZDynamicResourceLibrary* m_pLib;
		short m_iRefCount;
		bool m_bMarkedForDeletion;

		SLoaderLib() = default;
		void Reset();
		void IncrementRefCount();
		void DecrementRefCount();
	};

	TMap<ESingletonIconType, ZRuntimeResourceID> m_pSingletonIcons;
	TFixedArray<SLoaderLib, 414> m_LoaderLibs;
	TQueue<int, TBlockArray<int>> m_LoadingQueue;

	~ZHM5IconLoader() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5IconLoader() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void PreloadResource(const ZRuntimeResourceID rID);
	void UnloadResource(const ZRuntimeResourceID rID);
	ZString GetIconPathFromResourceID(const ZRuntimeResourceID rID) const;
	ZString GetSingletonIconPathOfTypeFromResourceID(ESingletonIconType eIconType, const ZRuntimeResourceID rID);
	void ReleaseSingletonIconOfType(ESingletonIconType eIconType);
	void ComponentDeactivate();
	void OnClearScene();
	void OnGameStop(const ZString& sEvent, const ZVariantRef& val);
	bool InitializeResourceLib(unsigned int iLibIndex);
	bool WaitUntilResoureIsReady(ZDynamicResourceLibrary* pLib) const;
	ZString GetIconPathFromLib(ZDynamicResourceLibrary* pLib) const;
	void ReleaseAllLibs();
	void DeleteAndResetLib(int iLibIndex);
	void HandleQueue();
	void FrameUpdate(const SGameUpdateEvent& gameEvent);
	bool Find(const SLoaderLib*& lib, const ZRuntimeResourceID rID) const;
	bool Find(SLoaderLib*& lib, const ZRuntimeResourceID rID, int& iIndex);
	bool Find(SLoaderLib*& lib, const ZRuntimeResourceID rID);
	bool Insert(SLoaderLib*& lib, const ZRuntimeResourceID rID);
};
