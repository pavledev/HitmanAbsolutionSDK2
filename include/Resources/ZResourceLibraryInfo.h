#pragma once

#include "TArray.h"
#include "ZResourceID.h"
#include "SResourceLibraryEntry.h"
#include "ZRuntimeResourceID.h"
#include "ZString.h"

class ZResourceDataBuffer;
class ZResourceStub;
template <class T> class TSharedPointer;

class ZResourceLibraryInfo
{
public:
	enum
	{
		GLOBAL_LIBRARIES_STATE = -1,
		NON_STREAMED_LIBRARIES_STATE = -2,
		INIT_LIBRARIES_STATE = -3
	};

	enum
	{
		GLOBAL = 1,
		NON_STREAMED = 2,
		MEDIA_STREAMED = 4,
		INIT_LIBRARY = 8,
		DYNAMIC = 16
	};

	TArray<int> m_StreamingStates;
	ZResourceStub* m_pLibraryStub;
	ZResourceID m_ResourceID;
	ZRuntimeResourceID m_MapResourceID;
	ZRuntimeResourceID m_SourceResourceID;
	TArray<SResourceLibraryEntry> m_Entries;
	char m_Flags;
	unsigned int m_nStartFilePosition;
	TArray<unsigned int> m_EntryFilePositions;
	TArray<ZString> m_Languages;
	int m_LocalizationCategory;

	ZResourceLibraryInfo() = default;
	ZResourceLibraryInfo(const ZResourceLibraryInfo& __that);
	ZResourceLibraryInfo(const ZResourceID& rid, ZResourceStub* pLibraryStub, unsigned int nStartFilePos, char flags, TArray<int> states, ZRuntimeResourceID ridSource, ZRuntimeResourceID ridMap, const TArray<ZString>& languages, int localizationCategory);
	~ZResourceLibraryInfo() = default;
	void Initialize(int nEntries);
	ZRuntimeResourceID GetSourceRuntimeResourceID() const;
	ZRuntimeResourceID GetMapResourceID() const;
	bool IsGlobal() const;
	bool IsInitLibrary() const;
	bool IsNonStreamed() const;
	bool IsMediaStreamed() const;
	bool IsDynamic() const;
	void SetSourceRuntimeResourceID(ZRuntimeResourceID rid);
	bool CanBeLoadedInCurrentConfiguration() const;
	bool IsLoadedInState(int nState) const;
	TArray<int> GetStreamingStateIndices() const;
	unsigned int GetStartFilePosition() const;
	ZResourceID GetResourceID() const;
	ZRuntimeResourceID GetRuntimeResourceID() const;
	unsigned int GetEntryCount() const;
	SResourceLibraryEntry GetEntry(unsigned int nIndex) const;
	unsigned int GetEntryFilePosition(unsigned int nIndex) const;
	void SetEntryFilePosition(unsigned int nIndex, unsigned int nPosition);
	bool IsValid(unsigned int nIndex) const;
	void SetEntry(unsigned int nIndex, SResourceLibraryEntry entry);
	void SetResourceStub(unsigned int nIndex, ZResourceStub* pStub);
	bool InstallResource(unsigned int nIndex, TSharedPointer<ZResourceDataBuffer> pResourceData);
	void AddRefToEntries();
	void ReleaseEntries();
	void ReleaseEntryHeaders();
	static ZString GetFriendlyStateName(int state);
	ZResourceLibraryInfo& operator=(const ZResourceLibraryInfo& __that);
};
