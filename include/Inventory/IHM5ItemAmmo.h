#pragma once

#include "IComponentInterface.h"
#include "eAmmoType.h"

class __declspec(novtable) IHM5ItemAmmo : public IComponentInterface
{
public:
	~IHM5ItemAmmo() override = default;
	virtual int GetNumberOfAmmo() const = 0;
	virtual void SetNumberOfAmmo(int param1) = 0;
	virtual bool IsInfinite() const = 0;
	virtual eAmmoType GetAmmoType() const = 0;

	static void RegisterType();
	IHM5ItemAmmo() = default;
};
