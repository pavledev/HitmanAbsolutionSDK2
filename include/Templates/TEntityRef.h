#pragma once

#include "ZEntityRef.h"
#include "ZConstructorInfo.h"

class IClassType;
struct STemplatedTypeName1;

template <class T>
class TEntityRef
{
public:
	class ZNULL
	{
	};

	ZEntityRef m_entityRef;
	T* m_pInterfaceRef;

	static STemplatedTypeName1 s_typeName;
	static ZConstructorInfo s_constructors[0];
	static IClassType s_typeInfo;

	TEntityRef() = default;
	//TEntityRef(ZNULL* __formal) = default;
	//TEntityRef(const ZEntityRef& rhs) = default;
	TEntityRef(const TEntityRef& rhs) = default;
	//TEntityRef& operator=(ZNULL* __formal) = default;
	TEntityRef& operator=(const TEntityRef& rhs) = default;

	T* operator->() const
	{
		return this->m_pInterfaceRef;
	}

	T* GetRawPointer() const
	{
		return this->m_pInterfaceRef;
	}

	bool IsNull() const
	{
		return this->m_pInterfaceRef == 0;
	}

	bool operator==(ZNULL* __formal) const
	{
		return this->m_pInterfaceRef == 0;
	}

	bool operator==(const TEntityRef& rhs) const
	{
		return this->m_entityRef.m_pEntityTypePtrPtr == rhs.m_entityRef.m_pEntityTypePtrPtr;
	}

	bool operator!=(ZNULL* __formal) const
	{
		return this->m_pInterfaceRef != 0;
	}

	bool operator!=(const TEntityRef& rhs) const
	{
		return this->m_entityRef.m_pEntityTypePtrPtr != rhs.m_entityRef.m_pEntityTypePtrPtr;
	}

	~TEntityRef() = default;
};
