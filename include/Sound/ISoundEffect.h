#pragma once

#include "IComponentInterface.h"
#include "ISoundEffectAttachable.h"
#include "ZGameTime.h"

class __declspec(novtable) ISoundEffect : public IComponentInterface
{
public:
	~ISoundEffect() override = default;
	virtual FMOD::DSP* CreateEffectInstance(ISoundEffectAttachable* soundEffectAttachable, void* param2) = 0;
	virtual void DestroyEffectInstance(void* param1) = 0;
	virtual void UpdateAll() = 0;
	virtual void SetActive(const bool param1) = 0;
	virtual void Update(ZGameTime gameTime, bool param2) = 0;

	static void RegisterType();
	ISoundEffect() = default;
};
