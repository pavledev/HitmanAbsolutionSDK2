#pragma once

#include "IType.h"

struct SNamedPropertyInfo;
struct SBaseClassInfo;
struct SInputPinEntry;
struct SComponentMapEntry;
class ZConstructorRef;

class IClassType
{
public:
	enum
	{
		INVALID_BASECLASS_OFFSET = 2147483648
	};

	IType type;
	unsigned short m_nProperties;
	unsigned short m_nConstructors;
	unsigned short m_nBaseClasses;
	unsigned short m_nInterfaces;
	unsigned short m_nInputPins;
	const SNamedPropertyInfo* m_pProperties;
	const ZConstructorInfo* m_pConstructors;
	const SBaseClassInfo* m_pBaseClasses;
	const SComponentMapEntry* m_pInterfaces;
	const SInputPinEntry* m_pInputPins;

	IClassType() = default;
	~IClassType() = default;
	unsigned int GetTypeSize() const;
	unsigned int GetTypeAlignment() const;
	STypeID* GetTypeID() const;
	void Destruct(void* pObject) const;
	TArrayRef<SNamedPropertyInfo const> GetProperties() const;
	TArrayRef<SComponentMapEntry const> GetInterfaces() const;
	TArrayRef<SInputPinEntry const> GetInputPins() const;
	unsigned int GetNumberOfProperties() const;
	void CollectAllInputPins(TArray<SInputPinEntry const*>* pList) const;
	ZConstructorRef GetConstructors() const;
	unsigned int GetNumberOfDirectBaseClasses() const;
	const IClassType* GetDirectBaseClassType(unsigned int nBaseClass) const;
	int GetDirectBaseClassOffset(unsigned int nBaseClass) const;
	unsigned int GetBaseClassOffset(STypeID* id) const;
};
