#pragma once

#include "ZMap.h"

class ZMapPoly : public ZMap
{
public:
	int m_nOrder;

	~ZMapPoly() override = default;
	float MapFunction(float fInput) const override;

	ZMapPoly() = default;
	ZMapPoly(const ZMapPoly& __that);
	ZMapPoly(int nOrder, bool bFlipInput, bool bFlipOutPut, bool bMirror, float fFirstHalf);
	void SetOrder(int i);
	ZMapPoly& operator=(const ZMapPoly& __that);
};
