#pragma once

#include "EAimCandidateType.h"
#include "ZRayQueryInput.h"
#include "ZRayQueryOutput.h"
#include "SMatrix.h"
#include "float1.h"
#include "TEntityRef.h"
#include "float4.h"

class ZActor;
class ZSpatialEntity;

struct SAimCandidate
{
	EAimCandidateType m_eType;
	ZRayQueryInput m_ColiIn;
	ZRayQueryOutput m_ColiOut;
	SMatrix m_mvMatCen;
	float4 m_vHalfSize;
	float m_fZ;
	float m_fDistSq;
	float m_fDistMult;
	float1 m_fDist;

	union 
	{
		unsigned char m_nFlags;

		struct 
		{
			bool m_bExcluded : 1;
			bool m_bRayCast : 1;
			bool m_bExcludeFromSlowdown : 1;
		};
	};

	TEntityRef<ZActor> m_Actor;
	unsigned int m_nBoneId;
	TEntityRef<ZSpatialEntity> m_rPropEntity;

	SAimCandidate(const SAimCandidate& __that);
	SAimCandidate(EAimCandidateType eType);
	SAimCandidate() = default;
	bool operator==(const SAimCandidate& other) const;
	bool operator!=(const SAimCandidate& other) const;
	void Reset();
	bool IsValid() const;
	bool IsActorType() const;
	bool IsPropType() const;
	~SAimCandidate() = default;
	SAimCandidate& operator=(const SAimCandidate& __that);
};
