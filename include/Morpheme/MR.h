#pragma once

#include "NMP.h"
#include "SQV.h"
#include "SBindPoseQV.h"
#include "SRawFacePoseCollection.h"
#include "SFacePoseFloatChannelCollection.h"
#include "ZAnimatedBoneScales.h"
#include "SMorphemeData.h"
#include "SCalcDeformBoneData.h"

struct MR
{
    class Network;
    struct NetworkDef;
    class NodeTransit;

    class alignas(16) Rig
    {
    public:
        NMP::Quat m_blendFrameOrientation;
        NMP::Hierarchy* m_hierarchy;
        unsigned int m_trajectoryBoneIndex;
        unsigned int m_characterRootBoneIndex;
        NMP::StringTable* m_boneNameMap;
        NMP::Quat* m_boneQuat;
        NMP::Vector3* m_bonePos;
        unsigned int m_spuMemoryRequirements;
        unsigned int* m_aGlobalIDToRigID;
        unsigned int m_nGlobalIDToRigIDCount;
    };

    struct RigToAnimMap
    {
        unsigned int m_numRigToAnim;
        unsigned int m_numAnimToRig;
        unsigned __int16* m_pRigToAnim;
        unsigned __int16* m_pAnimToRig;
    };

    class AnimScalingFacial
    {
    public:
        const RigToAnimMap* rigToAnimMap;
        unsigned int rigToAnimMapSize;
        bool bEnableAnimationScaling;
        const SQV* pCharacterBindPose;
        const int* pMeshIDToRigID;
        unsigned int nMeshIDToRigIDCount;
        const SBindPoseQV* pAnimBindPose;
        unsigned int nAnimBindPoseSize;
        const NMP::BitArray* pAnimBindPoseUsedFlags;
        unsigned int nAnimBindPoseUsedFlagsSize;
        bool bEnableFacialAnimations;
        unsigned int nFaceBoneRootIndex;
        float fTime;
        const SRawFacePoseCollection* pFacePoseCollection;
        unsigned int nFacePoseCollectionSize;
        const SFacePoseFloatChannelCollection* pFloatChannelCollection;
        unsigned int nFloatChannelCollectionSize;
    };

    class TimeFraction
    {
    public:
        float m_value;
    };

    class EventDef
    {
    public:
        TimeFraction m_startTime;
        TimeFraction m_duration;
        unsigned int m_userData;
    };

    class EventDefDuration
    {
    public:
        TimeFraction m_startTime;
        TimeFraction m_duration;
        unsigned int m_userData;
    };

    class EventsSequenceDefBase
    {
    public:
        unsigned int m_numEvents;
        unsigned int m_type;
        char* m_name;
        unsigned int m_userData;
    };

    class EventsSequenceDef : public EventsSequenceDefBase
    {
    public:
        EventDef* m_events;
    };

    class EventsSequenceDefDuration : public EventsSequenceDefBase
    {
    public:
        EventDefDuration* m_events;
    };

    class EventSequenceHeader
    {
    public:
        unsigned int m_timeStretchEventSequenceIndex;
        unsigned int m_numEventSequences;
        EventsSequenceDef** m_eventSequences;
        unsigned int** m_customData;
        unsigned int m_numDurationEventSequences;
        EventsSequenceDefDuration** m_durationEventSequences;
    };

    class TrajectoryControlBase
    {
    public:
        void m_getTrajAtTime(TrajectoryControlBase*, float, NMP::Quat*, NMP::Vector3*);

        unsigned int m_trajectorySize;
    };

    class IAnimSource
    {
    public:
        Rig* m_pRig;
        RigToAnimMap* m_pRigToAnimMap;
        EventSequenceHeader* m_pEvents;
        ZAnimatedBoneScales* m_pAnimatedBoneScales;

        virtual ~IAnimSource();
        virtual void computeAtTime(float, const Rig*, const RigToAnimMap*, AnimScalingFacial*, NMP::DataBuffer*);
        virtual void computeAtTimeSingleTransform(float, Rig*, RigToAnimMap*, unsigned int, NMP::Vector3*, NMP::Quat*);
        virtual float getDuration();
        virtual float getSampleFrequency();
        virtual unsigned int getNumChannelSets();
        virtual TrajectoryControlBase* getTrajectoryChannelData();
        virtual NMP::StringTable* getChannelNameTable();
        virtual void locate();
        virtual void dislocate();
        virtual void relocate(const void*);
        virtual unsigned int getSectionByteOffset();
    };

    class AttribDataTimeUpdate
    {
    public:
        float m_value;
    };

    class EventSeqPosition
    {
    public:
        unsigned int m_eventIndex;
        float m_eventFraction;
    };

    class AttribDataEventUpdate
    {
    public:
        EventSeqPosition m_eventFrom;
        EventSeqPosition m_eventTo;
    };

    class AttribDataDuration
    {
    public:
        float m_duration;
        float m_durationReciprocal;
        unsigned int m_updateFrame;
    };

    class EventTimeStretch
    {
    public:
        TimeFraction m_startTime;
        TimeFraction m_timeToNextEvent;
        unsigned int m_userData;
    };

    class EventsSequenceTimeStretch
    {
    public:
        unsigned int m_startEventIndex;
        unsigned int m_numEvents;
        EventTimeStretch m_events[16];
    };

    class AttribDataEventSequence
    {
    public:
        EventsSequenceTimeStretch m_eventSequenceClip;
    };

    class alignas(16) AttribDataPosQuatChannel
    {
    public:
        NMP::Quat m_quat;
        NMP::Vector3 m_pos;
        bool m_filteredOut;
    };

    class NodeRef
    {
    public:
        unsigned __int16 m_nodeId;

        enum UnkEnum : __int32
        {
            INVALID_ID = 0xFFFF
        };
    };

    class Z16BitFixedPointFraction
    {
    public:
        unsigned __int16 m_nValue;
    };

    class TriggeredEvent
    {
    public:
        const char* m_pszSourceSequenceName;
        unsigned __int16 m_nSourceSequenceUserData;
        NodeRef m_sourceNode;
        unsigned int m_nSourceEventUserData;
        Z16BitFixedPointFraction m_nFractionThrough;
        Z16BitFixedPointFraction m_nWeight;
    };

    class TriggeredEventsBuffer
    {
    public:
        unsigned int m_numAllocatedEntries;
        unsigned int m_numUsedEntries;
        TriggeredEvent* m_pEventsTriggered;
    };

    class DurationEventsPool
    {
    public:
        NMP::Pool* m_eventsPool;
        unsigned int m_maxNumUsedEntries;
    };

    class EventDuration
    {
    public:
        unsigned int m_userData;
        float m_eventSpaceStartPoint;
        float m_eventSpaceMidPoint;
        float m_eventSpaceDuration;
        float m_weight;
        bool m_processed;
        EventDuration* m_next;
    };

    class EventsSequenceDuration
    {
    public:
        DurationEventsPool* m_eventsPool;
        unsigned int m_numEvents;
        const char* m_pszSourceSequenceName;
        unsigned int m_userData;
        unsigned int m_numTimeStretchEvents;
        EventDuration* m_eventsListHead;
        EventDuration* m_eventsListTail;
    };

    class EventsSequenceDurationSet
    {
    public:
        unsigned int m_numEventSequences;
        EventsSequenceDuration m_sequences[2];
    };

    class AttribDataSampleEvents
    {
    public:
        unsigned int m_numEventSequences;
        EventsSequenceDef** m_eventSequences;
        TriggeredEventsBuffer m_triggeredEvBuffer;
        EventsSequenceDurationSet m_eventsSequenceDurationSet;
    };

    class TriggeredEventsPool
    {
    public:
        NMP::SequentialFitAllocator m_allocator;
    };

    class AttribDataInt
    {
    public:
        int m_value;
    };

    class AttribDataTime
    {
    public:
        bool m_setTimeCalled;
        float m_time;
        TimeFraction m_timeFraction;
        float m_deltaTimeFraction;
        float m_prevTimeFraction;
    };

    class AttribDataEventSeqPos
    {
    public:
        EventSeqPosition m_event;
    };

    class IControlParamNode
    {
    public:
        virtual ~IControlParamNode();
        virtual void updateControl(Network*);
        virtual void SetAsVector(float4*);
        virtual float4* GetAsVector(float4* result);
        virtual void SetAsFloat(float);
        virtual float GetAsFloat();
        virtual STypeID* GetTypeID();
    };

    class AttribDataFloat
    {
    public:
        float m_value;
    };

    template<class T>
    class Flags
    {
    public:
        T m_flags;
    };

    class INode
    {
    public:
        virtual ~INode();
        virtual void setTime(Network*, const AttribDataTimeUpdate*);
        virtual void setTimeFraction(Network*, const AttribDataTimeUpdate*);
        virtual void updateTime(Network*, const AttribDataTimeUpdate*);
        virtual void updateTimeFraction(Network*, const AttribDataTimeUpdate*);
        virtual void updateToEvent(Network*, const AttribDataEventUpdate*);
        virtual AttribDataDuration* updateDuration(Network*);
        virtual AttribDataEventSequence* updateEventSequence(Network*);
        virtual void updateTrajectoryChannel(Network*, AttribDataPosQuatChannel*);
        virtual AttribDataSampleEvents* sampleEvents(Network*, TriggeredEventsPool*, const AttribDataInt*);
        virtual void queueTransforms(Network*);
        virtual AttribDataDuration* getDuration(Network*);
        virtual AttribDataTime* getTime(Network*);
        virtual AttribDataEventSequence* getEventSequence(Network*);
        virtual AttribDataEventSeqPos* getEvent(Network*);
        virtual AttribDataSampleEvents* getSampledEvents(Network*);
        virtual void setEvent(Network*, const AttribDataEventSeqPos*);
        virtual const IAnimSource* getAnimSource(const Network*);
        virtual IAnimSource* getAnimSource(Network*);
        virtual IControlParamNode* asControlParamNode();
        virtual NodeTransit* asTransitNode();
        virtual void updateConnections(Network*);
        virtual void initialiseConnections(Network*);
        virtual void deinitialiseConnections(Network*);
        virtual unsigned int* getSampledNodes(Network*, unsigned int*, unsigned int*);
        virtual INode* clone(Network*, NMP::SequentialFitAllocator*);
    };

    enum BufferableDataType : __int32
    {
        kBUFFERABLE_DATA_TYPE_OUTPUT_TRANSFORMS = 0x0,
        kBUFFERABLE_DATA_TYPE_OUTPUT_MATRIX_TRANSFORMS = 0x0,
        kBUFFERABLE_DATA_TYPE_OUTPUT_TRAJECTORY_CHANNEL_DELTAS = 0x1,
        kBUFFERABLE_DATA_TYPE_OUTPUT_DURATION = 0x2,
        kBUFFERABLE_DATA_TYPE_OUTPUT_EVENT_SEQUENCE = 0x5,
        kBUFFERABLE_DATA_TYPE_OUTPUT_EVENT = 0x6,
        kBUFFERABLE_DATA_TYPE_OUTPUT_CONDITION_SET_STATE = 0xD,
        kBUFFERABLE_DATA_TYPE_OUTPUT_TIME = 0x3,
        kBUFFERABLE_DATA_TYPE_OUTPUT_FLOAT = 0x8,
        kBUFFERABLE_DATA_TYPE_OUTPUT_VECTOR = 0x9,
        kBUFFERABLE_DATA_TYPE_OUTPUT_BOOL = 0xB,
        kBUFFERABLE_DATA_TYPE_OUTPUT_VECTOR3 = 0x9,
        kBUFFERABLE_DATA_TYPE_OUTPUT_VECTOR4 = 0xA,
        kBUFFERABLE_DATA_TYPE_DEBUG_FLOAT = 0xB,
        kBUFFERABLE_DATA_TYPE_DEBUG_INT = 0xC,
        kBUFFERABLE_DATA_TYPE_DEBUG_VECTOR3 = 0xD,
        kBUFFERABLE_DATA_TYPE_DEBUG_VECTOR4 = 0xE,
        kBUFFERABLE_DATA_TYPE_DEBUG_QUATERNION = 0xF,
        kBUFFERABLE_DATA_TYPE_DEBUG_BOOL = 0x10,
        kBUFFERABLE_DATA_TYPE_DEBUG_FLOAT_BUFFER = 0x11,
        kBUFFERABLE_DATA_TYPE_DEBUG_VECTOR4_BUFFER = 0x12,
        kBUFFERABLE_DATA_TYPE_DEBUG_QUATERNION_BUFFER = 0x13,
        kBUFFERABLE_DATA_TYPE_DEBUG_TRANSFORMS_BUFFER = 0x14,
        kBUFFERABLE_DATA_TYPE_DEBUG_MATRIX_TRANSFORMS_BUFFER = 0x15,
        kBUFFERABLEDATATYPECOUNT = 0x16
    };

    class Node : public INode
    {
    public:
        unsigned int m_nodeDef;

        virtual bool isTransitionComplete();
        virtual unsigned int tidyCompleteTransition(Network*);
        virtual unsigned int getBufferedDataTypeSize(Network*, BufferableDataType, char*);
        virtual bool getBufferedData(Network*, BufferableDataType, void*, unsigned int, char*);
    };

    class alignas(4) NodeBlendBase : public Node
    {
    public:
        AttribDataTime m_time;
        AttribDataFloat m_weighting;
        AttribDataSampleEvents m_sampledEvents;
        char m_blendMode;
        char m_trajectoryBlendMode;
        char m_additiveBlendSourceNum;
        alignas(2) Flags<unsigned short> m_flags;
        NodeRef m_blendSource0NodeID;
        NodeRef m_blendSource1NodeID;
    };

    class NodeTransit : public NodeBlendBase
    {
    public:
        float m_transitionDuration;
        float m_transitionDurationReciprocal;
        float m_transitionTime;
    };

    class alignas(4) NodePassThrough : public Node
    {
    public:
        NodeRef m_nSourceNodeId;
    };

    class alignas(4) NodeStateMachine : public NodePassThrough
    {
    public:
        NodeRef m_activeStateID;
        unsigned int m_targetStateID;
        unsigned int m_defaultStateID;

        class alignas(4) STransitionArg
        {
            unsigned int m_nTargetNodeID;
            float m_fDuration;
            unsigned int m_nEventOffset;
            bool m_bEventOffsetRelativeToSource;
            bool m_bMatchEvents;
        } m_wildCardTransitionArg;

        unsigned int m_nWildCardTransitNodeID;
        unsigned __int16 m_nSatisfiedFlagsOffset;
        bool m_bAuthoredWildCardTransition;
    };

    class NodeDef
    {
    public:
        unsigned int m_typeID;
        unsigned int m_nodeID;
        const char* m_pName;
        const MR::NodeDef* m_pParent;

        virtual ~NodeDef();
        virtual NodeDef** getChildNodes();
        virtual const NodeDef** getChildNodesConst(); //original name is getChildNodes
        virtual unsigned int getNumChildNodes();
        virtual unsigned int getChildNodeConfigNodeIDs(unsigned int, unsigned int, unsigned int*);
        virtual unsigned int getBufferableDataTypes(NetworkDef*, BufferableDataType*, unsigned int, char**, char*, unsigned int, const unsigned int, BufferableDataType*, char**);
        virtual unsigned int getNumInputParameters();
        virtual unsigned int getInputParameters(unsigned int*, unsigned int);
        virtual NMP::Memory::Format* getMemoryRequirements(NMP::Memory::Format* result);
        virtual NMP::Memory::Format* getMemoryRequirements(NMP::Memory::Format* result, const void*);
        virtual NodeDef* createDef(unsigned int, const NMP::Memory::Resource*, const void*, const char*);
        virtual Node* init(NMP::Memory::Resource*, Network*);
        virtual void remapAnimationIndex(unsigned int*, unsigned int);
        virtual void resolveAnimationIndex(IAnimSource**, unsigned int);
        virtual bool checkDiscreteEventsAgainstClipFractions();
        virtual bool dislocate();
        virtual bool locate();
        virtual unsigned int getTransformBufferReqs(unsigned int**);
    };

    struct TransformBuffersCount
    {
        unsigned int m_numTranformBufferTypesUsed;
        unsigned int m_transformBufferTypes[8];
        unsigned int m_transformBufferCounts[8];
    };

    struct NetworkDef
    {
        unsigned int m_numAnimations;
        IAnimSource** m_animLibrary;
        Rig* m_rig;
        unsigned int m_numNodeNames;
        const char* m_nodeNames;
        unsigned int m_numNodeDefs;
        unsigned int m_numDummyBlendTreeDefs;
        NodeDef** m_nodeDefs;
        unsigned int m_maxDurationEventsPoolSize;
        unsigned int m_rootNodeID;
        unsigned int m_numNodeStateMachines;
        unsigned int* m_nodeStateMachineNodeIDs;
        unsigned int m_numInterfaceControlParameters;
        unsigned int* m_interfaceControlParameterNodeIDs;
        unsigned int m_numPersistentNodes;
        unsigned int* m_persistentNodeIDs;

        struct _NetworkHash
        {
            unsigned __int8 b[16];
        } m_networkHash;

        NMP::StringTable* m_requestIDStringTable;
        TransformBuffersCount m_maxTransformBufferReqs;
    };

    struct ConstructedNode
    {
        Node* node;
        unsigned __int32 typeID : 31;
        __int8 bActive : 1;
    };

    class IVariationInstance
    {
    public:
        virtual ~IVariationInstance();
        virtual IAnimSource* GetAnimSource(const ZString*);
    };

    class Network : public Node
    {
    public:
        unsigned int m_updateFrame;
        unsigned int m_numNodeStateMachines;
        NodeStateMachine** m_nodeStateMachines;
        unsigned int m_numNodes;
        bool* m_bufferNodeData;
        unsigned int* m_activeNodes;
        unsigned int m_numActiveNodes;
        NetworkDef* m_networkDefinition;
        TriggeredEventsBuffer m_outputEventsBuffer;
        AttribDataTimeUpdate m_timeData;
        AttribDataInt m_sampleDurationEvents;
        AttribDataTimeUpdate m_frameDeltaTime;
        TriggeredEventsPool m_triggeredEventsPool;
        DurationEventsPool* m_durationEventsPool;
        NMP::SequentialFitAllocator m_allocator;
        AttribDataPosQuatChannel m_trajectoryDelta;
        void* m_pOwner;
        ConstructedNode* m_constructedNodes;
        IVariationInstance* m_pVariationInstance;
        const SMorphemeData* m_pMorphemeData;
        volatile unsigned int m_taskStatus;
        TArrayRef<SQV> m_boneCache;
        char* m_transformTasks;
        unsigned int m_taskOffset;
        unsigned int m_taskSize;
        int m_transformCountCur;
        int m_transformCountMax;
        void* m_transformPool;
        void* m_transformFreeList;
        NMP::DataBuffer* m_transformStack[32];
        unsigned int m_transformStackOffset;
        SCalcDeformBoneData m_DeformBonesData;

        virtual Node* init(NMP::Memory::Resource*, MR::NodeDef*, MR::Network*, MR::Node*);
        virtual AttribDataPosQuatChannel* getPosQuatChannel(MR::Network*);
    };

};