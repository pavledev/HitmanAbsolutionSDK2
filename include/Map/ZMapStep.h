#pragma once

#include "ZMap.h"

class ZMapStep : public ZMap
{
public:
	bool m_bStartStateHigh;
	unsigned int m_nNumTransitions;

	~ZMapStep() override = default;
	float MapFunction(float fInput) const override;

	ZMapStep() = default;
	ZMapStep(bool bStartStateHigh, unsigned int nNumTransitions);
};
