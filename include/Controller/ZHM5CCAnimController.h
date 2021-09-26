#pragma once

#include "ZHM5CCAnimDatabase.h"
#include "ZActor.h"
#include "ZFindAnimPositions.h"
#include "ZFindAnimPositionsStairs.h"
#include "SAnimTime.h"
#include "ZHM5CCTargetController.h"
#include "HM5Utils.h"
#include "ZHM5CCEffects.h"

class ZHM5CCAnimController
{
public:
	ZHM5CCAnimDatabase* m_pAnimDatabase;
	ZMorphemeNetworkInstance* m_pNetWork;
	unsigned int m_nNetworkIndex;
	TEntityRef<ZHitman5> m_pHitman;
	TEntityRef<ZActor> m_rActor;
	bool m_bAlignHitman;
	SMatrix m_mAlignStart;
	SMatrix m_mAlignEnd;
	SMatrix m_mAlignStartNPC;
	SMatrix m_mAlignEndNPC;
	const SAnimNodeHitman* m_pCurrentNode;
	ZFindAnimPositions m_FindAnimPositions;
	ZFindAnimPositions m_FindAnimPositionsRunTime;
	ZFindAnimPositionsStairs m_FindAnimPositionsStairs;
	SAnimTime m_aAnimTime[2];
	bool m_bFightOnStairs;
	ECCNodeSubtype m_eNodeSubtype;
	ZHM5CCTargetController* m_pTargetController;
	ZPathfinder2* m_pPathfinder;
	ZPF5Location m_StairLocation;
	bool m_bFirstAttack;
	bool m_bFakeAttack;
	float m_fBlendFraction;
	HM5Utils::SAnimBlend m_AnimBlendHitman;
	HM5Utils::SAnimBlend m_AnimBlendNPC;
	ZMapPoly m_MapPoly;
	ECCNodeType m_ePropBackNodeType;
	TEntityRef<ZHM5CCEffects> m_rEffects;
	bool m_bForceAlign;
	bool m_bCoverCornerTakeDown;
	SMatrix m_aBlendMats[6];
	HM5Utils::SAnimBlend m_aAnimBlends[6];
	bool m_bUseEarlyEndRagdoll;
	unsigned short m_nAllowMask;

	static const unsigned int NUM_ANIM_BLENDS;

	ZHM5CCAnimController() = default;
	ZHM5CCAnimController(ZHM5CCAnimDatabase* pAnimDatabase, TEntityRef<ZHitman5> pHitman, ZHM5CCTargetController* pTargetController, ZMorphemeNetworkInstance* pNetwork);
	~ZHM5CCAnimController() = default;
	bool Update(SCloseCombatEvents& Events, float fDeltaTime);
	const SAnimNodeHitman* SelectAnimation(ECCNodeType eNodeType, bool bFirstAttack, const TEntityRef<ZActor>& rActor, unsigned int nAnimNum, bool bUseMirror, bool bForceAlign, const float4& vHitmanForcedPos);
	float GetAnimationTime() const;
	float GetAnimFraction() const;
	void UpdateGroundMovement(SMatrix& mFrom, SMatrix& mTo);
	SMatrix GetNPCAlignMatrix();
	float GetAnimBlendFraction() const;
	void UpdateEffects();
	bool PastFirstImpact() const;
	void SetNetwork(ZMorphemeNetworkInstance* pNetwork);
	void SetPropBackNodeType(ECCNodeType eNodeType);
	ECCNodeSubtype GetNodeSubtypeAttack(const TEntityRef<ZActor>& rActor) const;
	unsigned int GetNetworkIndex();
	const TEntityRef<ZHM5CCEffects>& GetEffects();
	void ReinitializeMorphemeData(IMorphemeEntity* pMorphemeEntity);
	float GetGroundBlendFraction() const;
	bool UseEarlyEndRagdoll() const;
	SCloseCombatEvents GenerateEvents(const SAnimTime& AnimTime);
	unsigned int GetAnimList(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int* anAnims, unsigned int nSize);
	unsigned int GetSafeAnim();
	unsigned int GetMirrorAnim();
	void FindAnimPosDebug();
	bool FindAnimPos(SMatrix& mHitmanResult, SMatrix& mNPCResult, const SAnimNodeHitman* pAnimHitman, const SMatrix& mHitman, const bool bNPCMove, const bool bConstrainHitman);
	void FindAnimPosStairs(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nAnim, const SMatrix& mHitman);
	void UpdateAnimFractions();
	void CalculateStartSafeDir(ECCNodeType eNodeType, ECCNodeSubtype eNodeSubtype, unsigned int nAnim);
	void FindStartConditions(ECCNodeType& eType, SMatrix& mHitman);
	void SampleAnimations(const SAnimNodeHitman* pAnimHitman, SAnimSample& AnimSampleHitman, SAnimSample& AnimSampleNCP);
	void SampleAnimationsSafe(const SAnimNodeHitman* pAnimHitman, SAnimSample& AnimSampleHitman, SAnimSample& AnimSampleNCP, float fRadius);
	bool FireEvent(float fFraction, const SAnimTime& AnimTime) const;
	ECCNodeSubtype GetNodeSubtypeReact(bool bAllowFront) const;
	ECCNodeSubtype GetInstinctAlignment() const;
	SMatrix GetPropEffectMatrix(const TEntityRef<ZHM5BaseCharacter>& rBaseChar, float fEffectFraction, const SAnimNodeHitman* pNode) const;
	void ForceAlignNPC(const SMatrix& mHitman, const SMatrix& mNPC, const SMatrix& mFreeAttacher);
	void InitAttack(ZFindAnimPositions& FindAnimPositions, const SAnimNodeHitman* pAnimHitman, const bool bAlignHitman) const;
	void SampleAnimation(ZFindAnimPositions& FindAnimPositions, const SAnimNodeHitman* pAnimHitman, const float fFraction, const unsigned int nHitmanIndex, const bool bApplyGroundDelta) const;
	void NPCShootIntoGround(SMatrix& mNPC) const;
};
