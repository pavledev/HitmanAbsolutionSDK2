#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZJobQueue.h"
#include "ZAnimationBufferPageManager.h"
#include "ZMutex.h"
#include "EAnimBlendMode.h"
#include "MR.h"
#include "NMP.h"
#include "SComponentMapEntry.h"
#include "TArray.h"
#include "TResourcePtr.h"
#include "ZVariantRef.h"

struct SVector4;
class ZAnimationBonePose;
class ZAnimationClipEntity;
class ZComponentCreateInfo;
class ZEntityRef;
class ZRigResource;
class ZSPUAnimationClip;
class ZSPUAnimationLibrary;
class ZString;
class ZTransitionClipEntity;
struct SQV;
struct STypeID;
struct ZAnimationClipInfo;
struct ZMeshRig;
template <class A, class B> class THashSet;
template <class T> class TArrayRef;
template <class T> class TDefaultHashSetPolicy;

class ZAnimationLibrary : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SampleCacheKey
	{
		unsigned short m_keyframeIndex;
		unsigned short m_fraction;
		unsigned int m_timestamp;

		SampleCacheKey() = default;
		void Clear();
	};

	class SampleCache
	{
	public:
		struct CacheNode
		{
			SampleCacheKey m_key;
			int m_nextNodeIndex;
			int m_nextLRUIndex;
			int m_prevLRUIndex;
			unsigned short m_bufferIndex;

			CacheNode() = default;
		};

		CacheNode* m_pNodes;
		int m_nNumBuckets;
		int m_nNumNodes;
		int m_nFirstFreeNode;
		int m_nOldestNode;
		int m_nNewestNode;

		SampleCache() = default;
		~SampleCache() = default;
		void CreateCache(const unsigned int nBuckets, const unsigned int nNodes);
		void ClearCache();
		unsigned short Find(const SampleCacheKey& key);
		void FastInsert(const SampleCacheKey& key, const unsigned short value);
		unsigned short EvictOldest(const unsigned int currTimestamp);
		void Grow();
		unsigned int GetEmptyNode();
		void UpdateLRU(int nodeIndex);
	};

	TEntityRef<ZAnimationClipEntity> m_defaultClip;
	TArray<TEntityRef<ZAnimationClipEntity>> m_animationClips;
	TArray<TEntityRef<ZTransitionClipEntity>> m_transitionClips;
	TArray<TEntityRef<ZAnimationClipEntity>> m_overrideClips;
	TArray<TEntityRef<ZAnimationClipEntity>> m_partialAnimationClips;
	TArray<TEntityRef<ZAnimationClipEntity>> m_sequenceClips;
	TResourcePtr<ZRigResource> m_pRigResource;
	unsigned int m_maxSamplingBuffers;
	unsigned int m_pageKiloByteSize;
	unsigned int m_maxLODForFractionalSampling;
	unsigned int m_timeStamp;
	bool m_bIsStreamedIn;
	bool m_bIsActivated;
	bool m_bInitialized;
	bool m_reallocateBuffers;
	ZJobQueue m_jobs;
	NMP::Memory::Resource m_bufferResource;
	TArray<NMP::DataBuffer*> m_samplingBuffers;
	short m_numSamplingBuffersUsed;
	ZAnimationBufferPageManager m_bonePoseBufferManager;
	TArray<unsigned short> m_aBoneCacheMeshRigIndices;
	unsigned int m_numBlendJobs;
	unsigned short m_numBoneCacheBuffers;
	unsigned int m_numSampleCacheHits;
	unsigned int m_numSampleCacheMisses;
	unsigned int m_numImmediateSampleRequests;
	TArray<ZAnimationClipInfo> m_clipInfo;
	unsigned int m_nNumBaseClips;
	unsigned int m_nBaseOverrideClipFlags;
	NMP::Memory::Resource m_spuAnimationLibrary;
	ZMutex m_asyncMutex;

	static SComponentMapEntry s_componentMap[0];

	~ZAnimationLibrary() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;

	ZAnimationLibrary() = default;
	static void RegisterType();
	ZAnimationLibrary(ZComponentCreateInfo& Info);
	bool FullyStreamedIn();
	void BeginQueuing();
	unsigned short QueueBoneCache(unsigned short source, unsigned short meshRigIndex);
	unsigned short QueueSampleAnimation(unsigned short clipIndex, float fFraction, unsigned int priority);
	unsigned short QueueBlend(unsigned short source0, unsigned short source1, float fWeight, EAnimBlendMode eBlendMode);
	unsigned short QueueIKLookat(unsigned short source, const SVector4& lookatTarget);
	unsigned int EndQueuing();
	void RegisterJobQueue(const TArrayRef<ZMeshRig> meshRigs, const TArrayRef<ZAnimationBonePose*> boneCacheArray, const TArrayRef<SQV*> renderPoseArray);
	void ExecuteJobQueue(const TArrayRef<ZMeshRig> meshRigs, const TArrayRef<ZAnimationBonePose*> boneCacheArray, const TArrayRef<SQV*> renderPoseArray);
	const ZSPUAnimationLibrary* GetSPUAnimationLibrary() const;
	void AllocateBuffers(const unsigned int numSamplingBuffers, const unsigned int bufferPageKiloByteSize, const unsigned int transformCount);
	unsigned short GetBufferIndexFromJob(unsigned short jobIndex) const;
	NMP::DataBuffer* GetBufferFromJob(const unsigned short jobIndex);
	const unsigned short GetMeshRigIndexForBoneCacheBuffer(unsigned int bufferIndex) const;
	const MR::Rig* GetRig() const;
	unsigned int GetNumAnimationClips() const;
	unsigned int GetNumOverrideClips() const;
	unsigned int GetBaseOverrideClipFlags() const;
	unsigned int GetNumTransitionClips() const;
	unsigned int GetNumPartialAnimationClips() const;
	unsigned int GetNumSequenceClips() const;
	unsigned int GetNumClipInfos() const;
	unsigned int GetNumTotalAnimationClips() const;
	const ZAnimationClipEntity* GetDefaultClip() const;
	unsigned short GetClipIndex(const ZAnimationClipEntity* clip) const;
	unsigned short GetSequenceClipIndex(const ZAnimationClipEntity* clip) const;
	const ZAnimationClipEntity* GetClip(unsigned short clipIndex) const;
	const TEntityRef<ZAnimationClipEntity> GetAnimationClip(unsigned int nIndex) const;
	const TEntityRef<ZAnimationClipEntity> GetOverrideAnimationClip(unsigned int nIndex) const;
	const TEntityRef<ZAnimationClipEntity> GetPartialAnimationClip(unsigned int nIndex) const;
	const TEntityRef<ZTransitionClipEntity> GetTransitionClip(unsigned int nIndex) const;
	const TEntityRef<ZTransitionClipEntity> GetSequenceClip(unsigned int nIndex) const;
	unsigned short AddSequenceClip(TEntityRef<ZAnimationClipEntity> pClip);
	void RemoveSequenceClip(TEntityRef<ZAnimationClipEntity> pClip);
	bool Initialize();
	void Deinitialize();
	void CompileSPUAnimationLibrary() const;
	void OnMaxSamplingBuffersChanged(const unsigned int& prevValue);
	void OnPageKiloByteSizeChanged(const unsigned int& prevValue);
	NMP::DataBuffer* ImmediateExecuteJob(const unsigned short jobIndex, NMP::DataBuffer* buffer);
	void ImmediateSampleAnimation(const ZSPUAnimationClip* clip, const float fraction, NMP::DataBuffer* buffer);
	void ReleaseSPUAnimationLibrary() const;
};
