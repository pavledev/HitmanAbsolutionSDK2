#pragma once

#include "IComponentInterface.h"

class IHM5BaseCharacter : public IComponentInterface
{
public:
    IHM5BaseCharacter();
    IHM5BaseCharacter(IHM5BaseCharacter const&);
    IHM5BaseCharacter* operator=(IHM5BaseCharacter const&);
    static void RegisterType();
};
