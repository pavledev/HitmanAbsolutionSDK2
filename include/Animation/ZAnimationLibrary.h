#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZAnimationClipEntity.h"
#include "ZTransitionClipEntity.h"
#include "ZRigResource.h"
#include "ZJobQueue.h"
#include "ZAnimationBufferPageManager.h"
#include "ZAnimationClipInfo.h"

class ZAnimationLibrary : public ZEntityImpl
{
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
    __int16 m_numSamplingBuffersUsed;
    ZAnimationBufferPageManager m_bonePoseBufferManager;
    TArray<unsigned short> m_aBoneCacheMeshRigIndices;
    unsigned int m_numBlendJobs;
    unsigned __int16 m_numBoneCacheBuffers;
    unsigned int m_numSampleCacheHits;
    unsigned int m_numSampleCacheMisses;
    unsigned int m_numImmediateSampleRequests;
    TArray<ZAnimationClipInfo> m_clipInfo;
    unsigned int m_nNumBaseClips;
    unsigned int m_nBaseOverrideClipFlags;
    NMP::Memory::Resource m_spuAnimationLibrary;
    ZMutex m_asyncMutex;

    class SampleCacheKey
    {
    public:
        unsigned __int16 m_keyframeIndex;
        unsigned __int16 m_fraction;
        unsigned int m_timestamp;
    };

    class SampleCache
    {
    public:
        class alignas(4) CacheNode
        {
        public:
            ZAnimationLibrary::SampleCacheKey m_key;
            int m_nextNodeIndex;
            int m_nextLRUIndex;
            int m_prevLRUIndex;
            unsigned __int16 m_bufferIndex;
        }* m_pNodes;

        int m_nNumBuckets;
        int m_nNumNodes;
        int m_nFirstFreeNode;
        int m_nOldestNode;
        int m_nNewestNode;
    };
};
