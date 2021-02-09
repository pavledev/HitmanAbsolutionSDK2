#pragma once

#include "ECCDUsage.h"
#include "IPhysicsSystem.h"
#include "IRagdollDesc.h"
#include "TMap.h"
#include "IFixedConstraint.h"
#include "SRagdollRuntimeParams.h"

class ZBaseRagdoll
{
public:
    bool m_bIsActivated;
    ECCDUsage m_eCCDUsage;
    ECollisionPriority m_eSolverPriority;
    IPhysicsSystem* m_pSystem;
    IRagdollDesc* m_pRagdollDesc;
    float m_fAge;
    TMap<unsigned int, unsigned int> m_BodyPartMapper;
    TMap<unsigned int, IBaseConstraint*> m_LockMapper;
    TArray<IFixedConstraint*> m_apPhantomConstraints;
    unsigned int m_nBodyPartActivationRoot;
    bool m_bHasPhantomBodyParts;
    TArray<unsigned int> m_anLocalCBM;
    TArray<unsigned int> m_anParentBeginIndices;
    TArray<unsigned int> m_anChildIndices;
    SRagdollRuntimeParams m_Params;

    virtual ~ZBaseRagdoll();
};
