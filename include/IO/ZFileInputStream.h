#pragma once

#include "IInputStream.h"
#include "ZRefCount.h"
#include "IBaseInputStream.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct SComponentMapEntry;
struct STypeID;
struct _iobuf;

class ZFileInputStream : public IInputStream
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZRefCount m_refcount;
	_iobuf* m_pFile;
	int m_nLength;
	ZString m_sLastErrorMessage;

	~ZFileInputStream() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	bool IsValid() override;
	bool IsSeekable() override;
	int GetLength() override;
	int GetPosition() override;
	void Close() override;
	ZString GetLastErrorMessage() override;
	int Skip(int nCount) override;
	int Seek(int offset, IBaseInputStream::ESeekOrigin origin) override;
	int Read(void* pBuffer, int nCount) override;

	ZFileInputStream() = default;
	ZFileInputStream(ZComponentCreateInfo& Info);
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
};
