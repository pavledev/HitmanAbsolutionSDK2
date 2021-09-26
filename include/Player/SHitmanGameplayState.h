#pragma once

#include "EHitmanGState.h"

struct SHitmanGameplayState
{
	unsigned int m_iHitmanGameState;
	unsigned int m_iValidationState;

	bool QueryHitmanFlag(EHitmanGState eQuery) const;
	bool QueryHitmanFlagALL(EHitmanGState eQuery1, EHitmanGState eQuery2, EHitmanGState eQuery3, EHitmanGState eQuery4, EHitmanGState eQuery5, EHitmanGState eQuery6, EHitmanGState eQuery7) const;
	bool QueryHitmanFlagAny(EHitmanGState eQuery1, EHitmanGState eQuery2, EHitmanGState eQuery3, EHitmanGState eQuery4, EHitmanGState eQuery5, EHitmanGState eQuery6, EHitmanGState eQuery7) const;
	SHitmanGameplayState() = default;
	~SHitmanGameplayState() = default;
	void SetHitmanFlagVal(EHitmanGState eFlag, bool bSet);
	void SetHitmanFlag(EHitmanGState flagToSet);
	void ResetHitmanFlag(EHitmanGState flagToReset);
	void ResetAllHitmanState();
	void ResetHitmanFlags(EHitmanGState eQuery1, EHitmanGState eQuery2, EHitmanGState eQuery3, EHitmanGState eQuery4, EHitmanGState eQuery5, EHitmanGState eQuery6, EHitmanGState eQuery7);
};
