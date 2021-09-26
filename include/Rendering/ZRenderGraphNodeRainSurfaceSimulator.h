#pragma once

#include "SVector2.h"
#include "ZResourcePtr.h"
#include "ZRenderGraphNode.h"
#include "IJobChain.h"
#include "ZRenderableEntity.h"

class ZRenderGraphNodeRainSurfaceSimulator : public ZRenderGraphNode
{
public:
	SVector2 m_vPuddleDropMinMax;
	SVector2 m_vRunningDropMinMax;
	float m_fPuddleNumDrops;
	float m_fRunningNumDrops;
	ZResourcePtr m_pCharacterReflectionMapPtr;
	float m_fCharacterRainIntensity;
	float m_fCharacterWetnessSpeed;
	float m_fCharacterWetnessDiffuseMul;
	float m_fCharacterWetnessSpecularAdd;
	float m_fCharacterWetnessSpecularMul;

	~ZRenderGraphNodeRainSurfaceSimulator() override = default;
	void Reflect(ZRenderableEntity* pRenderableEntity, IJobChain* pJobChain) override;

	ZRenderGraphNodeRainSurfaceSimulator() = default;
	SVector2 GetPuddleDropMinMax() const;
	SVector2 GetRunningDropMinMax() const;
	float GetPuddleNumDrops() const;
	float GetRunningNumDrops() const;
	ZResourcePtr GetCharacterReflectionMap() const;
	float GetCharacterRainIntensity() const;
	float GetCharacterWetnessSpeed();
	float GetCharacterWetnessDiffuseMul() const;
	float GetCharacterWetnessSpecularAdd() const;
	float GetCharacterWetnessSpecularMul() const;
};
