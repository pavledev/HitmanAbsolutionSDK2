#pragma once

#include "SSBAnim.h"
#include "SHM5SBShared.h"

class ZHM5SBAnimDatabase
{
public:
	char m_szPoseBuffer[1024];
	char* m_pBufferEnd;
	SSBAnim m_aSBAnim[96];
	unsigned int m_nNumAnims;
	const SHM5SBShared& m_SBShared;
	unsigned int m_nTagNode;
	unsigned int m_nExecutionNode;
	SBWeaponNodes m_aWeaponNodes[4];
	ESBWeaponType m_eCurrentSBWeapon;

	static const unsigned int POSE_BUFFER_SIZE;
	static const unsigned int NUM_ANIMS;

	ZHM5SBAnimDatabase() = default;
	ZHM5SBAnimDatabase(const SHM5SBShared& SBShared);
	~ZHM5SBAnimDatabase() = default;
	const SSBAnim* GetNextAnim(const SSBAnim* pCurrentAnim, float fShortRotation, float fMinRotation, float fMaxRotation, bool bHipPose);
	const SSBAnim* GetEndAnim(const SSBAnim* pCurrentAnim);
	const SSBAnim* GetReloadAnim(const SSBAnim* pCurrentAnim);
	void FindAnimations();
	void SetCurrentSBWeaponType(ESBWeaponType eSBWeaponType);
	void SetExecutionNode();
	unsigned int GetTagNode() const;
	void Transit(const SSBAnim* pAnim);
	void SetAsDefaultState(const SSBAnim* pAnim);
	void AddCameraProfiles();
	const char* GetPose(const char* pszString, bool bAllowAdd);
	float CalculateRotation(unsigned int nNodeID, ZMorphemeNetworkInstance* pNetWork) const;
	SSBAnim::ESBHand GetExecutionHand(const char* pszHand) const;
	SSBAnim::ESBRecoil GetRecoil(const char* pszHand) const;
	void PrintPoses();
	void VerifyAnimations();
	void VerifySBWeaponType(unsigned int nIndex);
};
