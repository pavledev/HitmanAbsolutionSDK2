#pragma once

#include "ZMovementAnimNode.h"
#include "float4.h"

class IMorphemeEntity;
class ZMorphemeNetworkInstance;
class ZString;

class ZMovementAnimNodeEx : public ZMovementAnimNode
{
public:
	float4 m_vGroundMovement;
	float m_fLength;
	float m_fDuration;
	float m_fSpeed;

	~ZMovementAnimNodeEx() override = default;
	void Init(ZMorphemeNetworkInstance* pMorphemeNetwork, ZString szName) override;
	void Init(IMorphemeEntity* pMorphemeEntity, ZString szName) override;
	void Init(ZMorphemeNetworkInstance* pMorphemeNetwork, unsigned int iNodeId) override;
	void Init(IMorphemeEntity* pMorphemeEntity, unsigned int iNodeId) override;

	ZMovementAnimNodeEx(ZMorphemeNetworkInstance* pMorphemeNetwork, ZString szName);
	ZMovementAnimNodeEx(ZMorphemeNetworkInstance* pMorphemeNetwork, unsigned int iNodeId);
	ZMovementAnimNodeEx() = default;
	float GetLength() const;
};
