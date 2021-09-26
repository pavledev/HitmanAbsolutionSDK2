#pragma once

class ZResourceID;
class ZString;

class ZRuntimeResourceID
{
public:
	unsigned int m_IDHigh;
	unsigned int m_IDLow;

	static const unsigned long long INVALID_RUNTIME_RESOURCE_ID;
	static const unsigned long long BITMASK_STANDALONERESOURCE_ID_HIGH;
	static const unsigned long long BITMASK_LIBRARYRESOURCE_INDEX_HIGH;
	static const unsigned long long FLAG_BIT_LIBRARYRESOURCE_HIGH;
	static const unsigned long long FLAG_BIT_LIBRARY_HIGH;

	static void RegisterType();
	ZRuntimeResourceID() = default;
	~ZRuntimeResourceID() = default;
	bool operator==(const ZRuntimeResourceID& rhs) const;
	bool operator!=(const ZRuntimeResourceID& rhs) const;
	bool operator<(const ZRuntimeResourceID& rhs) const;
	bool IsEmpty() const;
	bool IsValid() const;
	ZString ToDebugString() const;
	ZString ToHexDebugString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
	unsigned int GetHashCode() const;
	unsigned long long GetID() const;
	static bool HasRemoteDatabase();
	static ZRuntimeResourceID QueryRuntimeResourceID(const ZResourceID& idResource);
	static ZResourceID QueryResourceID(const ZRuntimeResourceID& ridResource);
	static ZRuntimeResourceID Create(unsigned long long nResource);
	static ZRuntimeResourceID CreateLibraryResourceID(ZRuntimeResourceID ridLibrary, int indexInLibrary);
	bool IsLibraryResource() const;
	bool IsLibrary() const;
	ZRuntimeResourceID GetLibraryRuntimeResourceID() const;
	int GetIndexInLibrary() const;
	static void InitResolver();
	static void ShutdownResolver();
};
