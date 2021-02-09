#pragma once

struct SGameStateForInput
{
    union
    {
        unsigned int m_nGameState;
        
        struct
        {
            __int8 m_bHitmanIsDead : 1;
            __int8 m_bHitmanInCutSequence : 1;
            __int8 m_bHitmanInAgilityMove : 1;
            __int8 m_bHitmanInstinctMode : 1;
            __int8 m_bHitmanShootingBallet : 1;
            __int8 m_bHitmanSBAllowRemoveControl : 1;
            __int8 m_bHitmanCloseCombat : 1;
            __int8 m_bHitmanInteractiveCut : 1;
            __int8 m_bHitmanInSafeZone : 1;
            __int8 m_bHitmanIsRunning : 1;
            __int8 m_bHitmanPickupNear : 1;
            __int8 m_bHitmanUsablePropNear : 1;
            __int8 m_bHitmanIsDragging : 1;
            __int8 m_bHitmanCanDragBody : 1;
            __int8 m_bHitmanCanTakeDisguise : 1;
            __int8 m_bHitmanCanPushFromRail : 1;
            __int8 m_bHitmanCanTakeHumanShield : 1;
            __int8 m_bHitmanCanCoverToCover : 1;
            __int8 m_bHitmanCanSurrender : 1;
            __int8 m_bHitmanGeneralAction : 1;
            __int8 m_bHitmanCanOperateDoor : 1;
            __int8 m_bWeaponsInventoryShown : 1;
            __int8 m_bHintMessageSlowdown : 1;
            __int8 m_bHitmanPrimaryLedgePrompt : 1;
        };
    };
};
