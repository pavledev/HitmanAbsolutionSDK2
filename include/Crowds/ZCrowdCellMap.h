#pragma once

class ZCrowdCellMap
{
public:
	unsigned int m_nNumCells;
	short* m_aHeadIndices;

	ZCrowdCellMap() = default;
	~ZCrowdCellMap() = default;
	void Allocate(unsigned int nNumCells);
	void Deallocate();
	void SetHeadIndex(unsigned int nCellIndex, short nHead);
	short GetHeadIndex(unsigned int nCellIndex) const;
	short* GetHeadIndices() const;
};
