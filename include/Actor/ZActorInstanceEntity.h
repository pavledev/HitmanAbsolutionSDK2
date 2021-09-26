#pragma once

#include "ZEntityImpl.h"
#include "IBoneAnimator.h"
#include "TResourcePtr.h"
#include "TEntityRef.h"
#include "ZGameTime.h"
#include "SBoneAnimatorInfo.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZAnimationBoneData;
class ZAnimationBonePose;
class ZComponentCreateInfo;
class ZEntityRef;
namespace OC3Ent {
namespace Face {
class FxActor;
class FxActorInstance;
class FxAnimSet;
class FxName;
}  // namespace Face
}  // namespace OC3Ent
struct SGameUpdateEvent;
struct SMatrix;
struct SPlaybackOptions;
struct STypeID;
struct float4;

class ZActorInstanceEntity : public ZEntityImpl, public IBoneAnimator
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EFFXMode
	{
		eFFX_MODE_DISABLE = 0,
		eFFX_MODE_OVERWRITE = 1
	};

	TResourcePtr<OC3Ent::Face::FxActor> m_ActorResource;
	TEntityRef<IBoneAnimator> m_BoneAnimator;
	ZString m_animationName;
	bool m_bLoop;
	TArray<ZEntityRef> m_AdditionalAnimSets;
	EFFXMode m_eBlendMode;
	OC3Ent::Face::FxActorInstance* m_pActorInstance;
	SBoneAnimatorInfo m_BoneAnimatorInfo;
	int m_nRootBoneIndex;
	int m_nMeshHeadBoneID;
	unsigned int m_nClientEventId;
	TArray<ZEntityRef> m_animSets;
	OC3Ent::Face::FxAnimSet* m_pMediaStreamedAnimSet;
	unsigned int m_nMediaStreamAnimSetID;
	float m_fHeadControlWeight;
	float m_fEyeControlWeight;
	bool m_bAllowHeadControl;
	bool m_bAllowEyeControl;
	bool m_bApplyAnimationAsDeltas;
	ZGameTime m_pauseTime;
	bool m_bPaused;
	TArray<int> m_aFaceFxIDToMeshID;
	unsigned int m_aFxChannelLoopEventInfo[2];
	int m_nCurrentLoopChannel;

	static SComponentMapEntry s_componentMap[0];
	static const int NumFxChannelLoopEventInfos;

	~ZActorInstanceEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void Initialize();
	virtual void Uninitialize();

	void UpdateBones(const ZAnimationBoneData* pBoneData, ZAnimationBonePose* pBoneCache, const SMatrix& mvCurrentWorldTransform, const SMatrix* pCameraMatrix) override;
	bool TryCalculateBounds(float4& vMin, float4& vMax, const float4& vPrevMin, const float4& vPrevMax, const ZAnimationBoneData* pBoneData) const override;
	void SetBoneAnimatorInfo(const SBoneAnimatorInfo& boneAnimatorInfo) override;

	ZActorInstanceEntity() = default;
	static void RegisterType();
	ZActorInstanceEntity(const ZActorInstanceEntity& __that);
	ZActorInstanceEntity(ZComponentCreateInfo& Info);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void SetTime(float fTime);
	unsigned int PlayAnimation(const OC3Ent::Face::FxName& groupName, const OC3Ent::Face::FxName& animName, bool bLooping, const SPlaybackOptions& options);
	unsigned int PlayAnimation(OC3Ent::Face::FxAnimSet* pAnimSet, const char* sAnimationName, bool bLooping);
	unsigned int PlayAnimation(const char* sAnimationName, bool bLooping, const SPlaybackOptions& options);
	bool PlayMediaStreamedAnimation(const void* pMediaStreamedData, unsigned int nStreamSize, const char* sAnimationName, bool bLooping);
	void StopMediaStreamedAnimation();
	void StopAnimation(unsigned int nAnimationID);
	void StopAllAnimations();
	bool IsEventPlaying(unsigned int nEventID) const;
	void SetEyeControlAllowed(bool bAllowEyeControl);
	void SetHeadControlAllowed(bool bAllowHeadControl);
	void SetApplyDeltaAnims(bool bApplyAsDelta);
	void MountAnimSet(OC3Ent::Face::FxAnimSet* pAnimSet);
	void Pause();
	void Resume();
	void SetFFXMode(EFFXMode eMode);
	EFFXMode GetFFXMode() const;
	bool DistanceCull(const SMatrix* pCameraMatrix, const float4& vPos);
	unsigned int FindNodeIndex(const char* sNodeName) const;
	void SetNodeValue(unsigned int nNodeIndex, float fValue);
	void OnPlay();
	void OnPlaySpecific(const ZString& sAnimation);
	void OnStop();
	void OnActorResourceChanged();
	void OnBoneAnimatorChanged();
	void CreateRigBinding();
	ZActorInstanceEntity& operator=(const ZActorInstanceEntity& __that);
};
