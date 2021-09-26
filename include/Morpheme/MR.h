#pragma once

#include "NMP.h"
#include "SCalcDeformBoneData.h"
#include "Enumeration.h"
#include "TArrayRef.h"
#include "float4.h"

class IVariationInstance;
class ZAnimatedBoneScales;
struct SBindPoseQV;
struct SFacePoseFloatChannelCollection;
struct SMorphemeData;
struct SQV;
struct SRawFacePoseCollection;
struct STypeID;

struct MR
{
    class Network;
    class NodeTransit;

	class Rig
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

		static const unsigned int NO_PARENT_BONE;
		static const unsigned int INVALID_BONE_INDEX;
		static const unsigned int BONE_NAME_NOT_FOUND;

		Rig() = default;
		~Rig() = default;
	};

	class RigToAnimMap
	{
	public:
		unsigned int m_numRigToAnim;
		unsigned int m_numAnimToRig;
		unsigned short* m_pRigToAnim;
		unsigned short* m_pAnimToRig;

		RigToAnimMap() = default;
		~RigToAnimMap() = default;
	};

	struct AnimScalingFacial
	{
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

		AnimScalingFacial() = default;
		~AnimScalingFacial() = default;
	};

	class TimeFraction
	{
	public:
		float m_value;

		TimeFraction() = default;
		~TimeFraction() = default;
	};

	class EventDef
	{
	public:
		TimeFraction m_startTime;
		TimeFraction m_duration;
		unsigned int m_userData;

		EventDef() = default;
		~EventDef() = default;
		void init(TimeFraction startTime, TimeFraction duration, unsigned int userData);
		TimeFraction getStartTime() const;
		void setUserData(unsigned int userData);
		unsigned int getUserData() const;
	};

	class EventDefDuration
	{
	public:
		TimeFraction m_startTime;
		TimeFraction m_duration;
		unsigned int m_userData;

		EventDefDuration() = default;
		~EventDefDuration() = default;
		void locate();
	};

	class EventsSequenceDefBase
	{
	public:
		unsigned int m_numEvents;
		unsigned int m_type;
		char* m_name;
		unsigned int m_userData;

		EventsSequenceDefBase() = default;
		~EventsSequenceDefBase() = default;
	};

	class EventsSequenceDef : public EventsSequenceDefBase
	{
	public:
		EventDef* m_events;

		EventsSequenceDef() = default;
		~EventsSequenceDef() = default;
	};

	class EventsSequenceDefDuration : public EventsSequenceDefBase
	{
	public:
		EventDefDuration* m_events;

		bool locate();
		EventsSequenceDefDuration() = default;
		~EventsSequenceDefDuration() = default;
	};

	struct EventSequenceHeader
	{
		unsigned int m_timeStretchEventSequenceIndex;
		unsigned int m_numEventSequences;
		EventsSequenceDef** m_eventSequences;
		unsigned int** m_customData;
		unsigned int m_numDurationEventSequences;
		EventsSequenceDefDuration** m_durationEventSequences;

		EventSequenceHeader() = default;
		~EventSequenceHeader() = default;
		unsigned int getNumDiscreteEventSequences() const;
		EventsSequenceDef** getDiscreteEventSequences() const;
		EventsSequenceDef* getTimeStretchEventSequence() const;
		void locate();
	};

	class TrajectoryControlBase
	{
	public:
		void (*m_getTrajAtTime)(const TrajectoryControlBase* trajectoryControlBase, float param2, NMP::Quat& quat, NMP::Vector3& vector3);
		unsigned int m_trajectorySize;

		TrajectoryControlBase() = default;
		~TrajectoryControlBase() = default;
	};

	class __declspec(novtable) IAnimSource
	{
	public:
		Rig* m_pRig;
		RigToAnimMap* m_pRigToAnimMap;
		const EventSequenceHeader* m_pEvents;
		const ZAnimatedBoneScales* m_pAnimatedBoneScales;

		virtual ~IAnimSource() = default;
		virtual void computeAtTime(float param1, const Rig* rig, const RigToAnimMap* rigToAnimMap, AnimScalingFacial* animScalingFacial, NMP::DataBuffer* dataBuffer) const = 0;
		virtual void computeAtTimeSingleTransform(float param1, const Rig* rig, const RigToAnimMap* rigToAnimMap, unsigned int param4, NMP::Vector3* vector3, NMP::Quat* quat) const = 0;
		virtual float getDuration() const = 0;
		virtual float getSampleFrequency() const = 0;
		virtual unsigned int getNumChannelSets() const = 0;
		virtual const TrajectoryControlBase* getTrajectoryChannelData() const = 0;
		virtual const NMP::StringTable* getChannelNameTable() const = 0;
		virtual void locate() = 0;
		virtual void dislocate() = 0;
		virtual void relocate(const void* param1) = 0;
		virtual unsigned int getSectionByteOffset() const = 0;

		IAnimSource() = default;
	};

	struct AttribDataTimeUpdate
	{
		float m_value;

		AttribDataTimeUpdate() = default;
		~AttribDataTimeUpdate() = default;
	};

	class EventSeqPosition
	{
	public:
		unsigned int m_eventIndex;
		float m_eventFraction;

		EventSeqPosition() = default;
		EventSeqPosition(unsigned int idx, float frac);
		EventSeqPosition(float evt);
		~EventSeqPosition() = default;
		unsigned int index() const;
		float fraction() const;
		void set(unsigned int idx, float frac);
		void set(float evt);
		void setIndex(unsigned int idx);
	};

	struct AttribDataEventUpdate
	{
		EventSeqPosition m_eventFrom;
		EventSeqPosition m_eventTo;

		AttribDataEventUpdate() = default;
		~AttribDataEventUpdate() = default;
	};

	struct AttribDataDuration
	{
		float m_duration;
		float m_durationReciprocal;
		unsigned int m_updateFrame;

		AttribDataDuration() = default;
		~AttribDataDuration() = default;
		bool isUpdated(unsigned int updateFrame) const;
		void setUpdated(unsigned int updateFrame);
	};

	class EventTimeStretch
	{
	public:
		TimeFraction m_startTime;
		TimeFraction m_timeToNextEvent;
		unsigned int m_userData;

		EventTimeStretch() = default;
		~EventTimeStretch() = default;
	};

	class EventsSequenceTimeStretch
	{
	public:
		unsigned int m_startEventIndex;
		unsigned int m_numEvents;
		EventTimeStretch m_events[16];

		EventsSequenceTimeStretch() = default;
		~EventsSequenceTimeStretch() = default;
	};

	struct AttribDataEventSequence
	{
		EventsSequenceTimeStretch m_eventSequenceClip;

		AttribDataEventSequence() = default;
		~AttribDataEventSequence() = default;
	};

	struct AttribDataPosQuatChannel
	{
		NMP::Quat m_quat;
		NMP::Vector3 m_pos;
		bool m_filteredOut;

		AttribDataPosQuatChannel() = default;
		~AttribDataPosQuatChannel() = default;
	};

	struct NodeRef
	{
		enum
		{
			INVALID_ID = 65535
		};

		unsigned short m_nodeId;

		NodeRef() = default;
		~NodeRef() = default;
	};

	class Z16BitFixedPointFraction
	{
	public:
		unsigned short m_nValue;

		static const unsigned short VALUE_ONE;

		Z16BitFixedPointFraction() = default;
		~Z16BitFixedPointFraction() = default;
		operator float() const;
		static float FixedPointToFloat(unsigned short nValue);
	};

	class TriggeredEvent
	{
	public:
		const char* m_pszSourceSequenceName;
		unsigned short m_nSourceSequenceUserData;
		NodeRef m_sourceNode;
		unsigned int m_nSourceEventUserData;
		Z16BitFixedPointFraction m_nFractionThrough;
		Z16BitFixedPointFraction m_nWeight;

		TriggeredEvent() = default;
		~TriggeredEvent() = default;
		void setSourceEventUserData(unsigned int userData);
		unsigned int getSourceEventUserData() const;
		const char* getSourceSequenceName() const;
		unsigned short getSourceSequenceUserData() const;
		float getWeight() const;
		void setSourceNode(NodeRef sourceNode);
	};

	class TriggeredEventsBuffer
	{
	public:
		unsigned int m_numAllocatedEntries;
		unsigned int m_numUsedEntries;
		TriggeredEvent* m_pEventsTriggered;

		TriggeredEventsBuffer() = default;
		~TriggeredEventsBuffer() = default;
	};

	class DurationEventsPool
	{
	public:
		NMP::Pool* m_eventsPool;
		unsigned int m_maxNumUsedEntries;

		DurationEventsPool() = default;
		~DurationEventsPool() = default;
		unsigned int getMaxNumUsedEntries() const;
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

		EventDuration() = default;
		~EventDuration() = default;
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

		EventsSequenceDuration() = default;
		~EventsSequenceDuration() = default;
	};

	class EventsSequenceDurationSet
	{
	public:
		unsigned int m_numEventSequences;
		EventsSequenceDuration m_sequences[2];

		EventsSequenceDurationSet() = default;
		~EventsSequenceDurationSet() = default;
	};

	struct AttribDataSampleEvents
	{
		unsigned int m_numEventSequences;
		EventsSequenceDef** m_eventSequences;
		TriggeredEventsBuffer m_triggeredEvBuffer;
		EventsSequenceDurationSet m_eventsSequenceDurationSet;

		AttribDataSampleEvents(const AttribDataSampleEvents& __that);
		AttribDataSampleEvents() = default;
		void tidy();
		~AttribDataSampleEvents() = default;
		AttribDataSampleEvents& operator=(const AttribDataSampleEvents& __that);
	};

	class TriggeredEventsPool
	{
	public:
		NMP::SequentialFitAllocator m_allocator;

		TriggeredEventsPool() = default;
		~TriggeredEventsPool() = default;
	};

	struct AttribDataInt
	{
		int m_value;

		AttribDataInt() = default;
		~AttribDataInt() = default;
	};

	struct AttribDataTime
	{
		bool m_setTimeCalled;
		float m_time;
		TimeFraction m_timeFraction;
		float m_deltaTimeFraction;
		float m_prevTimeFraction;

		AttribDataTime() = default;
		~AttribDataTime() = default;
	};

	struct AttribDataEventSeqPos
	{
		EventSeqPosition m_event;

		AttribDataEventSeqPos() = default;
		~AttribDataEventSeqPos() = default;
	};

	struct __declspec(novtable) IControlParamNode
	{
		virtual ~IControlParamNode() = default;
		virtual void updateControl(Network* network) = 0;
		virtual void SetAsVector(const float4& param1) = 0;
		virtual float4 GetAsVector() const = 0;
		virtual void SetAsFloat(float param1) = 0;
		virtual float GetAsFloat() const = 0;
		virtual STypeID* GetTypeID() const = 0;

		IControlParamNode() = default;
	};

	struct AttribDataFloat
	{
		float m_value;

		AttribDataFloat() = default;
		~AttribDataFloat() = default;
	};

	struct __declspec(novtable) INode
	{
		virtual ~INode() = default;
		virtual void setTime(Network* network, const AttribDataTimeUpdate& attribDataTimeUpdate) = 0;
		virtual void setTimeFraction(Network* network, const AttribDataTimeUpdate& attribDataTimeUpdate) = 0;
		virtual void updateTime(Network* network, const AttribDataTimeUpdate& attribDataTimeUpdate) = 0;
		virtual void updateTimeFraction(Network* network, const AttribDataTimeUpdate& attribDataTimeUpdate) = 0;
		virtual void updateToEvent(Network* network, const AttribDataEventUpdate& attribDataEventUpdate) = 0;
		virtual AttribDataDuration* updateDuration(Network* network) = 0;
		virtual AttribDataEventSequence* updateEventSequence(Network* network) = 0;
		virtual void updateTrajectoryChannel(Network* network, AttribDataPosQuatChannel& attribDataPosQuatChannel) = 0;
		virtual AttribDataSampleEvents* sampleEvents(Network* network, TriggeredEventsPool* triggeredEventsPool, const AttribDataInt& attribDataInt) = 0;
		virtual void queueTransforms(Network* network) = 0;
		virtual AttribDataDuration* getDuration(Network* network) = 0;
		virtual AttribDataTime* getTime(Network* network) = 0;
		virtual AttribDataEventSequence* getEventSequence(Network* network) = 0;
		virtual AttribDataEventSeqPos* getEvent(Network* network) = 0;
		virtual AttribDataSampleEvents* getSampledEvents(Network* network) = 0;
		virtual void setEvent(Network* network, const AttribDataEventSeqPos& attribDataEventSeqPos) = 0;
		virtual const IAnimSource* getAnimSource(const Network* network) const = 0;
		virtual IAnimSource* getAnimSource(Network* network) = 0;
		virtual IControlParamNode* asControlParamNode() = 0;
		virtual NodeTransit* asTransitNode() = 0;
		virtual void updateConnections(Network* network) = 0;
		virtual void initialiseConnections(Network* network) = 0;
		virtual void deinitialiseConnections(Network* network) = 0;
		virtual unsigned int* getSampledNodes(Network* network, unsigned int* param2, unsigned int* param3) const = 0;
		virtual INode* clone(Network* network, NMP::SequentialFitAllocator& sequentialFitAllocator) = 0;

		INode() = default;
	};

	enum BufferableDataType
	{
		kBUFFERABLE_DATA_TYPE_OUTPUT_TRANSFORMS = 0,
		kBUFFERABLE_DATA_TYPE_OUTPUT_MATRIX_TRANSFORMS = 0,
		kBUFFERABLE_DATA_TYPE_OUTPUT_TRAJECTORY_CHANNEL_DELTAS = 1,
		kBUFFERABLE_DATA_TYPE_OUTPUT_DURATION = 2,
		kBUFFERABLE_DATA_TYPE_OUTPUT_EVENT_SEQUENCE = 5,
		kBUFFERABLE_DATA_TYPE_OUTPUT_EVENT = 6,
		kBUFFERABLE_DATA_TYPE_OUTPUT_CONDITION_SET_STATE = 13,
		kBUFFERABLE_DATA_TYPE_OUTPUT_TIME = 3,
		kBUFFERABLE_DATA_TYPE_OUTPUT_FLOAT = 8,
		kBUFFERABLE_DATA_TYPE_OUTPUT_VECTOR = 9,
		kBUFFERABLE_DATA_TYPE_OUTPUT_BOOL = 11,
		kBUFFERABLE_DATA_TYPE_OUTPUT_VECTOR3 = 9,
		kBUFFERABLE_DATA_TYPE_OUTPUT_VECTOR4 = 10,
		kBUFFERABLE_DATA_TYPE_DEBUG_FLOAT = 11,
		kBUFFERABLE_DATA_TYPE_DEBUG_INT = 12,
		kBUFFERABLE_DATA_TYPE_DEBUG_VECTOR3 = 13,
		kBUFFERABLE_DATA_TYPE_DEBUG_VECTOR4 = 14,
		kBUFFERABLE_DATA_TYPE_DEBUG_QUATERNION = 15,
		kBUFFERABLE_DATA_TYPE_DEBUG_BOOL = 16,
		kBUFFERABLE_DATA_TYPE_DEBUG_FLOAT_BUFFER = 17,
		kBUFFERABLE_DATA_TYPE_DEBUG_VECTOR4_BUFFER = 18,
		kBUFFERABLE_DATA_TYPE_DEBUG_QUATERNION_BUFFER = 19,
		kBUFFERABLE_DATA_TYPE_DEBUG_TRANSFORMS_BUFFER = 20,
		kBUFFERABLE_DATA_TYPE_DEBUG_MATRIX_TRANSFORMS_BUFFER = 21,
		kBUFFERABLEDATATYPECOUNT = 22
	};

	class Node : public INode
	{
	public:
		unsigned int m_nodeDef;

		~Node() override = default;

		Node() = default;
	};

	enum ETaskIdentifier
	{
		kTaskIdentifier_Network = 0,
		kTaskIdentifier_Anim = 1,
		kTaskIdentifier_AnimIOI = 2,
		kTaskIdentifier_ApplyBindPose = 3,
		kTaskIdentifier_Blend2 = 4,
		kTaskIdentifier_Blend2AndReTarget = 5,
		kTaskIdentifier_ChildNetwork = 6,
		kTaskIdentifier_DeltaAnim = 7,
		kTaskIdentifier_DeltaAnimMatchEvents = 8,
		kTaskIdentifier_Select = 9,
		kTaskIdentifier_HeadController = 10,
		kTaskIdentifier_LookAt = 11,
		kTaskIdentifier_SelectiveFeatherBlend = 12,
		kTaskIdentifier_SelectiveFeatherBlendForwardEvents = 13,
		kTaskIdentifier_ComputeWorldTransforms = 14,
		kTaskIdentifier_Mirror = 15,
		kTaskIdentifier_MirrorMatchEvents = 16,
		kTaskIdentifier_CutSequence = 17,
		kTaskIdentifier_Variation = 18,
		kTaskIdentifier_PartialMirrorAim = 19,
		kTaskIdentifier_PelvisOffset = 20,
		kTaskIdentifier_Filter = 21,
		kTaskIdentifier_FeatherBlend2 = 22,
		kTaskIdentifier_LockFoot = 23,
		kTaskIdentifier_HeadLook = 24,
		kTaskIdentifier_SingleFrame = 25,
		kTaskIdentifier_TwoBoneIK = 26,
		kTaskIdentifier_ScaleAnim = 27,
		kTaskIdentifier_SneakModifier = 28,
		kTaskIdentifier_OutputTransformBuffer = 29
	};

	struct __declspec(novtable) TransformTaskBase
	{
		enum
		{
			TASK_QUEUE_SIZE = 7168
		};

		unsigned int m_nodeID;
		Enumeration<ETaskIdentifier, unsigned short> m_taskId;
		unsigned short m_size;

		virtual ~TransformTaskBase() = default;
		virtual NMP::DataBuffer* run(Network* network) = 0;

		TransformTaskBase() = default;
	};

	class NodeBlendBase : public Node
	{
	public:
		enum
		{
			FLAG_LOOPS = 1,
			FLAG_OPTIMIZE_SOURCE_0 = 2,
			FLAG_OPTIMIZE_SOURCE_1 = 4,
			FLAG_IGNORE_EVENT_WEIGHT_SOURCE_0 = 8,
			FLAG_IGNORE_EVENT_WEIGHT_SOURCE_1 = 16,
			FLAG_CUSTOM_0 = 32,
			FLAG_CUSTOM_1 = 64,
			FLAG_CUSTOM_2 = 128,
			FLAG_CUSTOM_3 = 256
		};

		struct TransformTask : TransformTaskBase
		{
			enum
			{
				TRANSFORM_COUNT_DELTA_MAX = 0,
				TRANSFORM_COUNT_DELTA_FINAL = -1
			};

			float m_weighting;
			unsigned char m_blendMode;
			unsigned char m_additiveBlendSourceNum;

			~TransformTask() override = default;

			TransformTask() = default;
		};

		AttribDataTime m_time;
		AttribDataFloat m_weighting;
		AttribDataSampleEvents m_sampledEvents;
		unsigned char m_blendMode;
		unsigned char m_trajectoryBlendMode;
		unsigned char m_additiveBlendSourceNum;
		NMP::Flags<unsigned short> m_flags;
		NodeRef m_blendSource0NodeID;
		NodeRef m_blendSource1NodeID;

		~NodeBlendBase() override = default;

		NodeBlendBase() = default;
	};

	class NodeTransit : public NodeBlendBase
	{
	public:
		enum
		{
			FLAG_IGNORE_SOURCE_TRAJECTORY = 32
		};

		float m_transitionDuration;
		float m_transitionDurationReciprocal;
		float m_transitionTime;

		~NodeTransit() override = default;

		NodeTransit() = default;
	};

	class NodePassThrough : public Node
	{
	public:
		NodeRef m_nSourceNodeId;

		~NodePassThrough() override = default;

		NodePassThrough() = default;
	};

	class NodeStateMachine : public NodePassThrough
	{
	public:
		struct STransitionArg
		{
			unsigned int m_nTargetNodeID;
			float m_fDuration;
			unsigned int m_nEventOffset;
			bool m_bEventOffsetRelativeToSource;
			bool m_bMatchEvents;

			STransitionArg() = default;
		};

		NodeRef m_activeStateID;
		unsigned int m_targetStateID;
		unsigned int m_defaultStateID;
		STransitionArg m_wildCardTransitionArg;
		unsigned int m_nWildCardTransitNodeID;
		unsigned short m_nSatisfiedFlagsOffset;
		bool m_bAuthoredWildCardTransition;

		~NodeStateMachine() override = default;

		NodeStateMachine() = default;
	};

	class __declspec(novtable) NodeDef
	{
	public:
		unsigned int m_typeID;
		unsigned int m_nodeID;
		const char* m_pName;
		const NodeDef* m_pParent;

		virtual ~NodeDef() = default;
		virtual unsigned int getChildNodeConfigNodeIDs(unsigned int param1, unsigned int param2, unsigned int* param3) const = 0;
		virtual NMP::Memory::Format getMemoryRequirements() = 0;
		virtual NMP::Memory::Format getMemoryRequirements(const void* param1) = 0;
		virtual NodeDef* createDef(unsigned int param1, const NMP::Memory::Resource* resource, const void* param3, const char* param4) const = 0;
		virtual Node* init(NMP::Memory::Resource* resource, Network* network) = 0;

		NodeDef() = default;
	};

	class TransformBuffersCount
	{
	public:
		unsigned int m_numTranformBufferTypesUsed;
		unsigned int m_transformBufferTypes[8];
		unsigned int m_transformBufferCounts[8];

		TransformBuffersCount() = default;
		~TransformBuffersCount() = default;
	};

	class NetworkDef
	{
	public:
		struct _NetworkHash
		{
			unsigned char b[16];
		};

		struct NetworkHash
		{
			unsigned char b[16];
		};

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
		_NetworkHash m_networkHash;
		NMP::StringTable* m_requestIDStringTable;
		TransformBuffersCount m_maxTransformBufferReqs;

		NetworkDef() = default;
		~NetworkDef() = default;
	};

	struct ConstructedNode
	{
		Node* node;
		unsigned int typeID : 31;
		bool bActive : 1;

		ConstructedNode() = default;
		~ConstructedNode() = default;
	};

	class Network : public Node
	{
	public:
		enum
		{
			TASK_IDLE = 0,
			TASK_RUNNING = 1,
			TASK_COMPLETED = 2
		};

		enum
		{
			TRANSFORM_BUFFER_STACK_SIZE = 32
		};

		struct TransformTask : TransformTaskBase
		{
			enum
			{
				TRANSFORM_COUNT_DELTA_MAX = 0,
				TRANSFORM_COUNT_DELTA_FINAL = 0
			};

			SQV* boneCache;
			int* meshIDToRigIDMap;
			int* meshHierarchy;
			unsigned int boneCount;

			~TransformTask() override = default;

			TransformTask() = default;
		};

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

		~Network() override = default;

		Network() = default;
	};
};