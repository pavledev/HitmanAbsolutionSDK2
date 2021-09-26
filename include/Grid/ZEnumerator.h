#pragma once

#include "ZGridNodeRef.h"

class ZGridNodeRef::ZEnumerator
{
public:
	const ZGridNodeRef& m_Me;
	ZGridNodeRef m_Current;
	int m_nCurrentDirection;

	ZEnumerator(const ZGridNodeRef& me);
	bool MoveNext();
	const ZGridNodeRef& Current() const;
};
