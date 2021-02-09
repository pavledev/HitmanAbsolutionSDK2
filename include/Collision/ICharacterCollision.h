#pragma once

#include "IComponentInterface.h"
#include "SMatrix.h"

class ICharacterCollision : public IComponentInterface
{
public:
	virtual SMatrix* GetCollisionCheckedMatPos(SMatrix* result, const SMatrix*);

	ICharacterCollision();
	ICharacterCollision(ICharacterCollision const&);
	ICharacterCollision* operator=(ICharacterCollision const&);
};