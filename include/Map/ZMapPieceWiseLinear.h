#pragma once

#include "ZMap.h"

class ZMapPieceWiseLinear : public ZMap
{
public:
	float m_fLine1StartX;
	float m_fLine2StartX;
	float m_fLine2StartY;

	~ZMapPieceWiseLinear() override = default;
	float MapFunction(float fInput) const override;

	ZMapPieceWiseLinear() = default;
	ZMapPieceWiseLinear(float fLine1StartX, float fLine2StartX, float fLine2StartY, bool bFlipInput, bool bFlipOutPut, bool bMirror, float fFirstHalf);
	void SetLineParams(float fLine1StartX, float fLine2StartX, float fLine2StartY);
};
