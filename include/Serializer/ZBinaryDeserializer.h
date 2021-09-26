#pragma once

#include "IComponentInterface.h"
#include "ZRefCount.h"
#include "TArray.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct SComponentMapEntry;
class ICustomDeserializer;
class IInputStream;
struct STypeID;

class ZBinaryDeserializer : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRefCount m_refcount;
	IInputStream* stream;
	TArray<unsigned char> buffer;
	TArray<ICustomDeserializer*> customSerializers;

	static const char* VERSION_STRING;
	static const unsigned int VERSION;

	~ZBinaryDeserializer() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZBinaryDeserializer() = default;
	int GetRefCount() const;
	ZBinaryDeserializer(ZComponentCreateInfo& createInfo);
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void SetInputStream(IInputStream* inputStream);
	unsigned int RequiredAlignment();
	unsigned int BytesNeededForDeserialization();
	void DeserializeInto(void* memory);
	void* DeserializeInPlace();
	void RegisterCustomDeserializer(ICustomDeserializer* customSerializer);
};
