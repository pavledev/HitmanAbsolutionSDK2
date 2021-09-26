#pragma once

#include "ZSharedPointerTarget.h"
#include "TSharedPointer.h"
#include "EResourceReferenceFlags.h"
#include "ZResourcePtr.h"
#include "ZRuntimeResourceID.h"

class ZResourceDataBuffer;
class ZResourceStub;
template <class T> class TArray;

class ZResourceReader : public ZSharedPointerTarget
{
public:
	ZResourceStub* m_pStub;
	TSharedPointer<ZResourceDataBuffer> m_pResourceData;
	unsigned int m_nResourceDataSize;

	~ZResourceReader() override = default;
	virtual unsigned int GetResourceType() const;
	virtual unsigned int GetNumResourceIdentifiers() const;
	virtual ZRuntimeResourceID GetResourceIdentifier(unsigned int lResourceIdentifierIndex) const;
	virtual EResourceReferenceFlags GetResourceFlags(unsigned int lResourceIdentifierIndex) const;
	virtual void FillResourceIdentifierArray(TArray<ZRuntimeResourceID>& resourceIDs) const;
	virtual ZResourcePtr GetInstallTimeDependency(unsigned int lResourceIdentifierIndex) const;

	ZResourceReader() = default;
	ZResourceReader(ZResourceStub* pStub, TSharedPointer<ZResourceDataBuffer> pData, unsigned int dataSize);
	const void* GetResourceData(unsigned int nOffset) const;
	unsigned int GetResourceDataSize() const;
	void* Deserialize();
};
