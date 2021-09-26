#pragma once

#include "ZString.h"
#include "ZVariantRef.h"

class ZEntityImpl;
class ZEntityType;
struct STypeID;
template <class T> class TArray;
template <class T> class alignas(8) ZDelegate;

class ZEntityRef
{
public:
	class ZNULL
	{
	};

	ZEntityType** m_pEntityTypePtrPtr;

	static void RegisterType();
	ZEntityRef(ZNULL* __formal);
	ZEntityRef(const ZEntityRef& rhs);
	ZEntityRef() = default;
	~ZEntityRef() = default;
	void* QueryInterfacePtr(STypeID* interfaceID) const;
	ZString ToString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
	bool IsNull() const;
	ZEntityImpl* GetEntityImpl() const;
	void FillSubsetArray(const ZString& subsetName, TArray<ZEntityRef>& entities, bool bChildSet) const;
	ZString GetDebugName() const;
	ZString GetDebugNameScenePath() const;
	bool IsRegisteredForDeletionListening(const ZDelegate<void __cdecl(ZEntityRef const&)>& fpCallback) const;
	void RegisterForDeletionListening(const ZDelegate<void __cdecl(ZEntityRef const&)>& fpCallback) const;
	void UnregisterForDeletionListening(const ZDelegate<void __cdecl(ZEntityRef const&)>& fpCallback) const;
	ZEntityRef& operator=(ZNULL* __formal);
	ZEntityRef& operator=(const ZEntityRef& rhs);
	bool operator==(ZNULL* __formal) const;
	bool operator==(const ZEntityRef& rhs) const;
	bool operator!=(ZNULL* __formal) const;
	bool operator!=(const ZEntityRef& rhs) const;
	bool operator<(const ZEntityRef& rhs) const;
	bool operator>(const ZEntityRef& rhs) const;
	ZEntityType** GetEntityTypePtrPtr() const;
	static ZEntityRef FromEntityTypePtrPtr(ZEntityType** pEntityTypePtrPtr);
	static ZEntityRef FromTEntityRef(ZVariantRef entityRef);
	unsigned int GetHashCode() const;
};
