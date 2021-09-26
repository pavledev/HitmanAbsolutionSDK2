#pragma once

#include "TEntityRef.h"
#include "ELookAtConstraintType.h"
#include "EAimConstraintType.h"
#include "sFeetInfo.h"
#include "sHandInfo.h"
#include "sHeadInfo.h"
#include "ZGameTime.h"
#include "HandReTargetMode.h"
#include "ZAimBuffer.h"
#include "sMuzzleInfo.h"
#include "sLedgeInfo.h"
#include "sLedgeFeetLockInfo.h"
#include "sLedgeHangBoneBuffer.h"
#include "SSBAimInfo.h"
#include "SRecoilEntry.h"
#include "SImpactAnimEntry.h"
#include "SLedgeAimInfo.h"
#include "ZMapPoly.h"
#include "SHM5AimInfo.h"
#include "SHM5LookAtInfo.h"
#include "AimMode.h"
#include "SMatrix.h"
#include "SQV.h"
#include "SQuaternion.h"
#include "TArrayRef.h"
#include "ZEntityRef.h"
#include "float4.h"
#include "sFiberWireInfos.h"
#include "sLedgeHangInfos.h"

class IMorphemeEntity;
class ZHitmanMorphemePostProcessorFiberWireCallback;
class ZHitmanMorphemePostProcessorLedgeHangCallback;
class ZMorphemePostProcessorInfo;
template <class A, class B, class C> class THashMap;
template <class A, class B> class TDefaultHashMapPolicy;

class ZHitmanMorphemePostProcessor
{
public:
	TEntityRef<IMorphemeEntity> m_pMorpheme;
	bool m_bActive;
	ELookAtConstraintType m_ConstraintType;
	EAimConstraintType m_AimConstraintType;
	float4 m_vAimDir[2];
	float4 m_vAimPos[2];
	float4 m_vAimPosWorld[2];
	float4 m_vDestAimPosWorld[2];
	int m_nAimBoneId;
	float m_AimWeights[7];
	int m_nAimDepth;
	float m_aAim;
	float m_bAim;
	int m_nAimDirBoneMajorAxis;
	int m_nAimDirBoneId[2];
	sFeetInfo m_FeetInfo;
	sHandInfo m_HandInfo;
	sHeadInfo m_HeadInfo;
	SMatrix m_mvHitman;
	float m_fMinForeArmRot;
	AimMode::eAimMode m_eAimMode;
	float m_fAimOverallWeight;
	ZGameTime m_tAimStartTime[2];
	HandReTargetMode::eHandReTargetMode m_eHandRetargetMode;
	float m_fAimLookAtWeight;
	ZAimBuffer m_AimBoneBuffer;
	sMuzzleInfo m_MuzzleInfo[2];
	bool m_bAimMirrored;
	float m_fTwoHandLookAtAimBound;
	sLedgeInfo m_LedgeInfo;
	sLedgeFeetLockInfo m_LedgeFeetLockInfo;
	ZHitmanMorphemePostProcessorLedgeHangCallback* m_pLHCallBack;
	sLedgeHangInfos m_LedgeHangInfo;
	sLedgeHangInfos m_OldLedgeHangInfo;
	sLedgeHangBoneBuffer m_LHBoneBuffer;
	float m_fLHCurrentWeight;
	float m_fLHTargetWeight;
	ZHitmanMorphemePostProcessorFiberWireCallback* m_pFWCallback;
	sFiberWireInfos m_FWInfo;
	sFiberWireInfos m_FWOldInfo;
	float m_fFWTargetWeight;
	float m_fFWCurrentWeight;
	float m_fFWBlendOutTime;
	SSBAimInfo m_sSBAimInfo;
	int m_anSBAimBones[8];
	float m_afSBOneHandHWeights[8];
	float m_afSBOneHandVWeights[8];
	float m_afSBOneHandHLWeights[8];
	float m_afSBOneHandVLWeights[8];
	float m_afSBTwoHandHWeights[8];
	float m_afSBTwoHandVWeights[8];
	float m_afSBOneHandHLookAtWeights[8];
	float m_afSBOneHandVLookAtWeights[8];
	SQuaternion m_aqSBAimDelta[8];
	int m_anSBAimPoseBones[17];
	SQV m_asqvSBAimPose[17];
	unsigned int m_nSBAimPose;
	float4 m_vPoseLookAtPos;
	SMatrix m_mvPelvisOffset;
	SRecoilEntry m_aRecoils[3];
	int m_anRecoilBones[15];
	unsigned int m_nRecoilRHandIndex;
	unsigned int m_nRecoilLHandIndex;
	bool m_bRecoilBonesInitilized;
	SQV m_aRecoilAnimCache[15];
	unsigned int m_nRecoilAnimId;
	bool m_bRecoilMirrorAnim;
	bool m_bRecoilActive;
	unsigned int m_anRecoilMask[15];
	SImpactAnimEntry m_ImpactAnim;
	unsigned int m_anImpactAnimIds[4];
	int m_anImpactBones[10];
	bool m_abTwoHandedBone[10];
	bool m_bImpactBonesInitilized;
	SQuaternion m_aImpactAnimCache[4][10];
	TArrayRef<SQV> m_BoneCache;
	float m_fTimeMultiplier;
	unsigned int m_nComponentSelector;
	SLedgeAimInfo m_LedgeAimInfo;
	ZMapPoly m_MapPoly;
	float m_fSneakFraction;
	SHM5AimInfo m_AimInfo;
	float m_afHorizontalWeights[8];
	float m_afVerticalWeights[8];
	int m_anAimBones[8];
	int m_anAimLookAtBones[2];
	bool m_bAimAndLookAtBonesInitialized;
	SQuaternion m_aAimPoseBlendBuffer[8];
	SQuaternion m_aAimDeltaBuffer[8];
	SQuaternion m_aAimLookAtPoseBlendBuffer[2];
	SQuaternion m_aAimLookAtDeltaBuffer[2];
	int m_anLookAtBones[6];
	float m_afLookAtHorizontalWeights[6];
	float m_afLookAtVerticalWeights[6];
	SQuaternion m_aqLookAtDeltaBuffer[6];
	SQuaternion m_aqLookAtPoseBuffer[6];
	SHM5LookAtInfo m_sLookAtInfo;

	static const unsigned int NUM_DEFAULT_AIM_BONES;
	static const unsigned int NUM_SB_AIM_BONES;
	static const unsigned int NUM_SB_POSE_BONES;
	static const unsigned int NUM_RECOIL_BONES;
	static const unsigned int NUM_IMPACT_ANIMS;
	static const unsigned int NUM_IMPACT_BONES;
	static const int NUM_AIM_LOOK_AT_BONES;

	ZHitmanMorphemePostProcessor() = default;
	ZHitmanMorphemePostProcessor(const TEntityRef<IMorphemeEntity>& pMorpheme);
	~ZHitmanMorphemePostProcessor() = default;
	void ResetPostProcessor();
	void Activate();
	void DeActivate();
	bool IsActive();
	void SetMorphemeEntity(const ZEntityRef& pMorphemeEntity);
	void SetAimPos(const float4& vAimPos, const SMatrix& MuzzleMatPos);
	void SetAimPosDirect(const float4& vAimPos, const SMatrix& MuzzleMatPos);
	void SetSecAimPos(const float4& vAimPos, const SMatrix& MuzzleMatPos);
	void SetSecAimPosDirect(const float4& vAimPos, const SMatrix& MuzzleMatPos);
	void SetAimWeights(float* pWeights, int nSize);
	void SetAimLimitAngles(float fVert, float fHor);
	void SetMinForeArmRot(float fMinRot);
	void SetAimOverallWeight(float fWeight);
	void SetAimStartTime();
	void SetSecAimStartTime();
	void SetAimConstraintType(EAimConstraintType ConstraintType);
	void SetLedgeAimInfo(const SLedgeAimInfo& LedgeAim);
	void SetTimeMultiplier(float fMultiplier);
	void EnableLedgeManipulation(bool bEnable);
	void SetLedgeManipultionInfos(sLedgeInfo& info);
	void SetComponentSelector(unsigned int nValue);
	void SetLHCallBack(ZHitmanMorphemePostProcessorLedgeHangCallback* pCallBack);
	void SetLHTargetWeight(float fWeight);
	void SetLHTargetWeightDirect(float fWeight);
	void ResetLHInfos();
	const sLedgeHangInfos* GetLHOldInfo();
	void SetFWCallback(ZHitmanMorphemePostProcessorFiberWireCallback* pCallback);
	void SetFWTargetWeight(float fWeight);
	void ResetFWInfos();
	void SetFWBlendOutTime(float fVal);
	void SetSBAimInfo(const SSBAimInfo& sSBAimInfo);
	void ResetSBAimPose();
	void SetPelvisOffset(const SMatrix& mPelvisOffset);
	bool IsRecoilActive() const;
	void ResetRecoil();
	void ResetBonesMapped();
	void PlayImpactAnimation(unsigned int nAnimNodeID, unsigned int nAnimNodeID2, float fNodeBlendWeight, bool bKeepHandsRelative);
	bool IsPlayingImpactAnimation() const;
	void ResetImpactAnim();
	void UpdateAim2(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy, EAimConstraintType ConstraintType);
	void SetSneakFraction2(float fSneakFraction);
	void SetAimInfo2(const SHM5AimInfo& AimInfo);
	void SetLookAtInfo(const SHM5LookAtInfo& rLookAtInfo);
	static void CalculateRelativeWeights(float* pWeights, unsigned int nNumWeights);
	void UpdateBones(ZMorphemePostProcessorInfo& info);
	void DisplayPPStatus();
	int BuildInverseBoneMap(int nStartIdx, int nEndIdx, int* pInverseBoneMap, const TArrayRef<int> hierarchy);
	void SetWeights(float* pWeights, int nSize, float* pDestArray, int nMaxDepth);
	SQV GetModelBone(int nMeshBoneId, const SQuaternion* pDeltaBoneBuffer, const int* pDeltaBoneList, unsigned int nNumDeltaBones, const int* pPoseBoneList, const SQV* pSQVPose, unsigned int nNumPoseBones, const TArrayRef<int> hierarchy) const;
	SQV GetModelBone(int nMeshBoneId, const SQuaternion* pDeltaBoneBuffer, const int* pBoneList, unsigned int nNumBones, const TArrayRef<int> hierarchy) const;
	SQV GetModelBone(int idx, const TArrayRef<int> hierarchy);
	SQV GetModelBindPoseBone(int idx, const TArrayRef<int> hierarchy, const TArrayRef<SQV> bindPose);
	SMatrix GetWorldBone(int idx, const TArrayRef<int> hierarchy);
	void SwapHandAttachers(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	void UpdateLookAt(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	float4 WVectorFromYawPitch(float fYaw, float fPitch);
	void WVectorToYawPitch(const float4& v, float& fYaw, float& fPitch);
	void NormalizeYawPitch(float& fYaw, float& fPitch);
	float NormalizeRad(float f);
	void UpdateLedgeAim(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateBlindFire(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateFeetInfo(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	void UpdateHandInfo(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	float4 ReCalcHandTarget(bool bRight, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	void UpdateHeadInfo(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	void ReTargetFeet(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	void ReTargetHands(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy, HandReTargetMode::eHandReTargetMode eRetargetMode);
	void RePositionPelvis(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	float4 CalculateAimLookAtPos(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy, float t);
	bool AimInPlace(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy, float fAngleThresHold, bool bRightHand);
	float4 ModifyAimPosWorld(int nIndex, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy);
	void UpdateLedgeManipulation(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateLedgeLockFeet(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateLedgeHang(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateFiberWire(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateShootingBallet(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdatePelvisOffset(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateWeaponRecoil(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void UpdateImpactAnim(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void DisplayBoneMatPos(int nBoneIdx, const TArrayRef<int> hierarchy, int nAxisMask);
	void InitAimProperties();
	void InitLedgeManipulationProperties();
	void InitLedgeFeetLockProperties();
	void LockFeet(bool bLock);
	void InitLedgeHangPropertes();
	void InitFiberWireProperties();
	void FiberWireBendSpine(float fDeltaTime, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap, const TArrayRef<SQV> bindPose, const TArrayRef<int> hierarchy);
	void InitSBProperties();
	void InitPelvisOffset();
	void InitializeRecoilBones(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap);
	void InitializeImpactBones(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap);
	void GetImpactCache(unsigned int& nCacheIndex, unsigned int& nCacheIndex2, const SImpactAnimEntry& ImpactAnim);
	void InitializeAimAndLookAtBones(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap);
	float4 GetIntersection(const float4& vO, const float4& vP, const float4& vDir, const float4& vAimPoint) const;
	void BlendBones(SQV* pBoneBuffer, const SQV* pSource0, const SQV* pSource1, float fFraction, unsigned int nNumBones) const;
	void BlendQuats(SQuaternion* pQuatBuffer, const SQuaternion* pSource0, const SQuaternion* pSource1, const float fFraction, const unsigned int nNumBones) const;
	void BlendBonesFiltered(SQV* pBoneBuffer, float* pFractions, const SQV* pSource0, const SQV* pSource1, float fFraction0, float fFraction1, unsigned int nNumBones, const unsigned int* pFilter);
	void BlendToBoneCache(const SQV* pBoneBuffer, const float* pFractions, const int* pBoneList, unsigned int nNumBones);
	void BlendToBoneCache(const SQV* pBoneBuffer, const float* pFractions, const int* pBoneList, unsigned int nNumBones, const SQuaternion& qPelvisBindRot, const float4& vPelvisBindPos, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap);
	void AlignToShotPos(const float4& vAimPos, const SMatrix& mHandAttacherToMuzzle, float fFraction, int nAlignBone, int nAttacherBone, const TArrayRef<int> hierarchy);
	void RecalculateMuzzle(int& nAttacherBone, float4& vMuzzlePos, float4& vMuzzleDir, int nTopBone, unsigned int nHighPose, unsigned int nLowPose, float fLowFraction, const TArrayRef<int> hierarchy);
	void RecalculateMuzzles(int* pAttacherBones, float4* pMuzzlePos, float4* pMuzzleDir, unsigned int nNumAttachers, int nTopBone, unsigned int nHighPose, unsigned int nLowPose, float fLowFraction, bool bMirror, const TArrayRef<int> hierarchy);
	float4 GetAimLookAtPos(float& fWeight, const float4& vAimPos, const SQuaternion* pDeltaBuffer, const int* pBoneList, const unsigned int nNumBones, const TArrayRef<int> hierarchy) const;
	int GetBoneIndex(int nMeshBoneId, const int* pBoneList, unsigned int nNumBones) const;
	void ConstrainBoneOnElipse(const int nConstrainBone, const int nAlignBone, const float fRadiusX, const float fRadiusY, const float4& vCenter, const SQV& sqvIdleContrain, const TArrayRef<int> hierarchy);
	float4 CalculateSBLookAtPoint(int nLookAtRelativeBone, const int* pPoseBoneList, const SQV* pSQVPose, unsigned int nNumPoseBones, const float4& vMuzzlePos, const float4& vMuzzleDir, const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& globalToMeshIDMap, const TArrayRef<int> hierarchy) const;
	void CalculateLookAtDeltaBuffer(SQuaternion* pDeltaBuffer, const int* pBoneList, unsigned int nNumBones, const SMatrix& mRotationBase, const float4& vLookAtPos, int nTopBone, float fWeight, const float* pHorizontalWeights, const float* pVerticalWeights, const TArrayRef<int> hierarchy) const;
	void CalculateAimDeltaBuffer(SQuaternion* pDeltaBuffer, const int* pBoneList, unsigned int nNumBones, const float4& vAimPos, float4* pMuzzlePos, float4* pMuzzleDir, const int* pAttacherBone, unsigned int nNumAttachers, float fAttacherFraction, float fWeight, const float* pHorizontalWeights, const float* pVerticalWeights, const TArrayRef<int> hierarchy) const;
	void CalculateSBAimDeltaBuffer(SQuaternion* pDeltaBuffer, const int* pDeltaBoneList, unsigned int nNumDeltaBones, const int* pPoseBoneList, const SQV* pSQVPose, unsigned int nNumPoseBones, const float4& vAimPos, const float4& vMuzzlePos, const float4& vMuzzleDir, int nAttacher, float fWeight, const float* pHorizontalWeights, const float* pVerticalWeights, const TArrayRef<int> hierarchy) const;
};
