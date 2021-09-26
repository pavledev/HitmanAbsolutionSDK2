#pragma once

#include "ECCNodeType.h"
#include "ECCNodeSubtype.h"

struct SAnimNodeNPC
{
	ECCNodeType m_eNodeType;
	ECCNodeSubtype m_eNodeSubtype;
	unsigned int m_nNodeNum;
	unsigned int m_anNodeId[2];
	unsigned int m_anParentNodeId[2];
	float m_fAnimDuration;

	SAnimNodeNPC() = default;
	~SAnimNodeNPC() = default;
};
