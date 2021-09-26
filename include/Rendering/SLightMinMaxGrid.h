#pragma once

#include "SVector2.h"
#include "SLightMinMaxGridRange.h"

struct SLightMinMaxGrid
{
	SVector2* m_pData;
	bool* m_pValid;
	SLightMinMaxGridRange m_PriorityRanges[3];
	SLightMinMaxGridRange m_PrevCellUpdate[3];
	unsigned int m_nNumReadCells;
	unsigned int m_nNumWrittenCells;

	SLightMinMaxGrid() = default;
	~SLightMinMaxGrid() = default;
	void SetValid(unsigned int nX, unsigned int nY);
	bool IsValid(unsigned int nX, unsigned int nY) const;
	void SetMinMax(unsigned int nX, unsigned int nY, float fValMin, float fValMax);
	SVector2 GetMinMaxInRange(SLightMinMaxGridRange& range, unsigned int nSplit) const;
	bool FindNextGridCellUpdate(SLightMinMaxGridRange& range);
	const SLightMinMaxGridRange& GetPriorityRange(unsigned int nIndex);
	void SetPriorityRange(SLightMinMaxGridRange& range, unsigned int nIndex);
	void GetPreviousCellUpdate(SLightMinMaxGridRange& range, unsigned int nIndex);
	void SetPreviousCellUpdate(SLightMinMaxGridRange& range, unsigned int nIndex);
	void IncrNumReadCells();
	unsigned int GetNumReadCells() const;
	void IncrNumWrittenCells();
	unsigned int GetNumWrittenCells() const;
	void SetDirty();
};
