#pragma once

class IMorphemeEntity;
class ZMorphemeNetworkInstance;
class ZString;

class ZMovementAnimNode
{
public:
	ZMorphemeNetworkInstance* m_pMorphemeNetwork;
	unsigned int m_iNodeId;
	unsigned int m_iParentNodeId;

	virtual ~ZMovementAnimNode() = default;
	virtual void Init(ZMorphemeNetworkInstance* pMorphemeNetwork, ZString szName);
	virtual void Init(IMorphemeEntity* pMorphemeEntity, ZString szName);
	virtual void Init(ZMorphemeNetworkInstance* pMorphemeNetwork, unsigned int iNodeId);
	virtual void Init(IMorphemeEntity* pMorphemeEntity, unsigned int iNodeId);

	ZMovementAnimNode(ZMorphemeNetworkInstance* pMorphemeNetwork, ZString szName);
	ZMovementAnimNode(IMorphemeEntity* pMorphemeEntity, ZString szName);
	ZMovementAnimNode(ZMorphemeNetworkInstance* pMorphemeNetwork, unsigned int iNodeId);
	ZMovementAnimNode(IMorphemeEntity* pMorphemeEntity, unsigned int iNodeId);
	ZMovementAnimNode() = default;
	unsigned int GetNodeId() const;
	unsigned int GetParentNodeId() const;
	bool IsActive() const;
	bool IsRootNodeInStateMachine() const;
	void SetCurrentStateInStateMachine();
	float GetTimeFractionOfEvent(const ZString& szEventName, unsigned int iUserData) const;
	float GetTimeFraction() const;
	float GetDuration() const;
	void ForceAnimNodeActive(unsigned int iStopNode);
};
