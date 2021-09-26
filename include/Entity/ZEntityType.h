#pragma once

#include "EEntityTypeMapFlags.h"

class ZEntityRef;
class ZEventNull;
class ZString;
struct SExposedEntityData;
struct SInterfaceData;
struct SPinData;
struct SPropertyData;
struct SSubsetData;
struct STypeID;
template <class A, class B, class C, class D, class E> class ZEvent;
template <class T> class TArray;
template <class T> class TArrayIterator;

class ZEntityType
{
public:
	enum EntityTypeOwner
	{
		EOWNED_BY_FACTORY = 0,
		EOWNED_BY_ENTITY = 1
	};

	int m_nBorrowedPointersMask;
	TArray<SPropertyData>* m_pPropertyData;
	TArray<SInterfaceData>* m_pInterfaceData;
	TArray<SExposedEntityData>* m_pExposedEntityData;
	TArray<SSubsetData>* m_pSubsets;
	TArray<SPinData>* m_pInputPins;
	TArray<SPinData>* m_pOutputPins;
	ZEvent<ZEntityRef const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* m_pDeletionListeners;

	ZEntityType() = default;
	ZEntityType(EntityTypeOwner eOwner, ZEntityType* pType);
	ZEntityType(EntityTypeOwner eOwner);
	~ZEntityType() = default;
	bool IsOwnedByEntity() const;
	bool HasBorrowedPointer(EEntityTypeMapFlags eMap) const;
	void ClearBorrowedPointerFlag(EEntityTypeMapFlags eMap);
	int GetValidMapsFlag() const;
	SInterfaceData* GetInterfaceData(STypeID* type);
	SExposedEntityData* GetExposedEntityData(const ZString& sName);
	SSubsetData* GetSubsetData(const ZString& sName);
	bool FindFirstProperty(unsigned int nPropertyID, TArrayIterator<SPropertyData>* it);
	bool FindProperties(unsigned int nPropertyID, TArrayIterator<SPropertyData>* itBegin, TArrayIterator<SPropertyData>* itEnd);
	bool FindFirstInputPin(unsigned int nPinID, TArrayIterator<SPinData>* it);
	bool FindInputPins(unsigned int nPinID, TArrayIterator<SPinData>* itBegin, TArrayIterator<SPinData>* itEnd);
	bool FindFirstOutputPin(unsigned int nPinID, TArrayIterator<SPinData>* it);
	bool FindOutputPins(unsigned int nPinID, TArrayIterator<SPinData>* itBegin, TArrayIterator<SPinData>* itEnd);
};
