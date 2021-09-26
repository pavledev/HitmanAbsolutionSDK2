#pragma once

struct SBWeaponNodes
{
	const char* m_pszName;
	unsigned int m_nTagNode;
	unsigned int m_nExecutionNode;
	unsigned int m_nStartIndex;
	unsigned int m_nEndIndex;
	unsigned int m_nWildCardTransitID;

	SBWeaponNodes() = default;
	~SBWeaponNodes() = default;
};
