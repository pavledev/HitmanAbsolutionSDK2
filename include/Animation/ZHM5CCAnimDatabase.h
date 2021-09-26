#pragma once

#include "SAnimNodeHitman.h"
#include "SAnimNodeNPC.h"
#include "TEntityRef.h"
#include "ZHitman5.h"

class ZHM5CCAnimDatabase
{
public:
	SAnimNodeHitman m_aHitmanAnimNodes[165];
	unsigned int m_nHitmanNumNodes;
	unsigned int m_nHitmanNumNodesNoChildNetworks;
	unsigned int m_nHitmanCCNode;
	unsigned int m_nHitmanRootNode[2];
	unsigned int m_nHitmanBossRootNode[2];
	unsigned int m_anHitmanNodeCount[45][9];
	unsigned int m_nCCIdleRequest;
	SAnimNodeHitman* m_apSortedAnimList[165];
	unsigned int m_nSortedListSize;
	SAnimNodeNPC m_aNPCAnimNodes[165];
	unsigned int m_anNPCNodeCount[45][9];
	unsigned int m_nNPCNumNodes;
	unsigned int m_nNPCNumNodesNoChildNetworks;
	unsigned int m_anNPCRootNodes[2];
	unsigned int m_nNPCCCNode;
	unsigned int m_nNPCBlendNode;
	unsigned int m_anNPCPassiveIdleNodes[2];
	unsigned int m_anNPCPacifyIdleNodes[2];
	unsigned int m_anNPCFightIdleNodes[2];
	bool m_bNPCNodesFound;
	bool m_bHitmanNodesFound;
	bool m_bNPCChildNodesFound;
	bool m_bHitmanChildNodesFound;
	TEntityRef<ZHitman5> m_pHitman;

	static const int NUM_ANIM_NODES;

	ZHM5CCAnimDatabase() = default;
	ZHM5CCAnimDatabase(TEntityRef<ZHitman5> pHitman);
	static bool IsIdleNode(ECCNodeType eNodeType);
	static bool IsCoverTakeDown(ECCNodeType eNodeType);
	static bool IsCoverCornerTakeDown(ECCNodeType eNodeType);
	static bool IsStairNode(ECCNodeType eNodeType);
	static bool IsMurderTakeDownNode(ECCNodeType eNodeType);
	static bool IsBloodyTakeDownNode(ECCNodeType eNodeType);
	static bool IsTakeDownNode(ECCNodeType eNodeType);
	static bool IsReactNode(ECCNodeType eNodeType);
	static bool IsPropNode(ECCNodeType eNodeType);
	static bool IsPropBashNode(ECCNodeType eNodeType);
	static bool IsChokeNode(ECCNodeType eNodeType);
	static bool IsNoiseNode(ECCNodeType eNodeType);
	static bool IsStrangleFinishNode(ECCNodeType eNodeType);
	static bool IsChainFinishNode(ECCNodeType eNodeType);
	static bool IsBossNode(ECCNodeType eNodeType);
	static ECCNodeType GetNodeTypeFromAnimSet(ECCWeaponAnimSet eAnimSet);
	static ECCWeaponAnimSet GetAnimSetFromNodeType(ECCNodeType eNodeType);
	void FindHitmanNodes(ZMorphemeNetworkInstance* pNetWork, const ZString& szParent, ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nNodeParent, unsigned int nNetworkIndex);
	void FindHitmanNodes(IMorphemeEntity* pMorpheme);
	void FindHitmanChildNetworkNodes(IMorphemeEntity* pMorpheme);
	unsigned int GetHitmanCCNode() const;
	unsigned int GetHitmanRootNode(unsigned int nNetworkIndex) const;
	unsigned int GetHitmanNodeCount(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype) const;
	const SAnimNodeHitman* GetHitmanNode(const SAnimNodeNPC* pNodeNPC) const;
	const SAnimNodeHitman* GetHitmanNode(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nNodeNum) const;
	void ResetHitmanNodes();
	void ResetHitmanChildNetworkNodes(ZMorphemeNetworkInstance* pNetWork);
	void ResetNPCChildNetworkNodes(ZMorphemeNetworkInstance* pNetWork);
	void SortAnimList(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype);
	unsigned int GetSortedAnimListSize() const;
	const SAnimNodeHitman* GetSortedAnim(unsigned int nIndex) const;
	void UpdateTimeStamp(ECCNodeType eType, unsigned int nNum);
	unsigned int GetNPCCCNode() const;
	unsigned int GetNPCBlendNode() const;
	unsigned int GetNPCRootNode(unsigned int nNetworkIndex) const;
	unsigned int GetNPCPassiveIdleNode(unsigned int nNetworkIndex) const;
	unsigned int GetNPCFightIdleNode(unsigned int nNetworkIndex) const;
	unsigned int GetNPCPacifyIdleNode(unsigned int nNetworkIndex) const;
	bool NPCNodesFound() const;
	void ResetNPCAnimDurations();
	void UpdateNPCAnimDurations(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nNum, unsigned int nNetworkIndex, ZMorphemeNetworkInstance* pNetWork);
	void FindNPCNodes(ZMorphemeNetworkInstance* pNetWork, const ZString& szParent, ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nNodeParent, unsigned int nNetworkIndex);
	void FindNPCNodes(TEntityRef<IMorphemeEntity> rMorpheme);
	void FindNPCChildNetworkNodes(const TEntityRef<ZActor>& rActor);
	const SAnimNodeNPC* GetNPCNode(const SAnimNodeHitman* pNodeHitman) const;
	const SAnimNodeNPC* GetNPCNode(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nNum) const;
	ZString GetName(ECCNodeType eNodeType) const;
	ZString GetName(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nNodeNum) const;
	void RetrieveNodeData(ZMorphemeNetworkInstance* pNetWork, unsigned int nStart);
	void VerifyNodes();
	ZString GetSubtypeName(ECCNodeSubtype eNodeSubtype) const;
	~ZHM5CCAnimDatabase() = default;
};
