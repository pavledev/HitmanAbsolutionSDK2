#pragma once

class ICharacterController;
class ZRayQueryInput;
class ZRayQueryOutput;

class __declspec(novtable) IBoneCollidable
{
public:
	virtual bool CheckLineCollision(const ZRayQueryInput& rayQueryInput, ZRayQueryOutput* rayQueryOutput) const = 0;
	virtual ICharacterController* GetCharacterController() const = 0;
	virtual ~IBoneCollidable() = default;

	static void RegisterType();
	IBoneCollidable() = default;
};
