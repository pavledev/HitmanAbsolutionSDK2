#pragma once

#include "IComponentInterface.h"
#include "SMatrix.h"

class __declspec(novtable) ICharacterCollision : public IComponentInterface
{
public:
	~ICharacterCollision() override = default;
	virtual SMatrix GetCollisionCheckedMatPos(const SMatrix& matrix) = 0;

	static void RegisterType();
	ICharacterCollision() = default;
};
