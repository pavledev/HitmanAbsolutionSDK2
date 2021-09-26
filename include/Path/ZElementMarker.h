#pragma once

class ZElementMarker
{
public:
	unsigned int m_nElements;
	unsigned int m_nBlockCount;
	unsigned int* m_aMarks;

	ZElementMarker() = default;
	ZElementMarker(unsigned int nElements);
	~ZElementMarker() = default;
	void ClearMarks();
	void MarkElement(unsigned int nElement);
	bool IsElementMarked(unsigned int nElement) const;
};
