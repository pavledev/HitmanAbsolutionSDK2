#pragma once

class IHM5InputControlMapping;

class SControlSchemeMappings
{
public:
    IHM5InputControlMapping* pInGameStandard;
    IHM5InputControlMapping* pInGameDead;
    IHM5InputControlMapping* pInGameCutSequence;
    IHM5InputControlMapping* pInGameCloseCombat;
    IHM5InputControlMapping* pInGameInteractiveCut;
    IHM5InputControlMapping* pInGameInventory;
    IHM5InputControlMapping* pInGameHintMessage;
    IHM5InputControlMapping* pInGameDragging;
    IHM5InputControlMapping* pInGameInstinctMode;
    IHM5InputControlMapping* pInGameShootingBallet;
    IHM5InputControlMapping* pInGameAgility;
};
