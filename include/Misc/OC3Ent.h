#pragma once

struct OC3Ent
{
	struct Face
	{
		class FxClass;
		class FxArchive;
		class FxAnim;
		class FxFaceGraphNodeLink;
		class FxAnimSet;
		class FxActorInstance;
		
		template<class T>
		class FxTreeBase;

		class FxLazyLoader;

		class FxUseAllocator
		{

		};

		class FxObject : FxUseAllocator
		{
		public:
			virtual FxClass* GetClassDesc();
			virtual unsigned __int16 GetCurrentVersion();
			virtual ~FxObject();
			virtual void Serialize(FxArchive*);
		};

		class FxArchiveStore : FxUseAllocator
		{
		public:
			virtual bool OpenRead();
			char gap4[4];
			virtual bool Close();
			virtual bool Read(char*, unsigned int);
			virtual bool Write(const char*, unsigned int);
			virtual int Tell();
			virtual void Seek(const int);
			virtual int Length();
			virtual ~FxArchiveStore();
			virtual void Destroy();
			virtual unsigned int GetClassSize();
		};

		struct PrivateImpl
		{
			template<class T>
			class FxNoBase
			{

			};
		};

		template<class T>
		class FxSafeBool : public PrivateImpl::FxNoBase<T>
		{

		};

		template<class A, class B, class C>
		class FxTreeNodeBase : public FxObject
		{
		public:
			A key;
			B item;
			unsigned int height;
			C* parent;
			C* children[2];
		};

		template<class A, class B>
		class FxAVLNode : public FxTreeNodeBase<A, B, FxAVLNode<A, B>>
		{
		public:
			__int16 balance;
		};

		template<class A, class B>
		class FxAVLTree : public FxTreeBase<FxAVLNode<A, B>>
		{

		};

		template<class T>
		class FxTreeBase
		{
		public:
			T* _root;
			unsigned int _numNodes;

			template<class T>
			class IteratorBase : public FxSafeBool<T>
			{
			public:
				FxTreeBase<T>* _tree;
				T* _node;
			};

			template<class T>
			class Iterator : public IteratorBase<T>
			{

			};

			virtual ~FxTreeBase();
			virtual void Clear();
			virtual void _copy(FxTreeBase*);
			virtual Iterator<T>* _insert(Iterator<T>* result, T**, const unsigned int*, FxObject* const*);
			virtual bool _remove(FxAVLNode<unsigned int, FxObject*>**);
		};

		template<class T>
		class FxArrayBase
		{
		public:
			T* _v;
			unsigned int _allocatedCount;
			unsigned int _usedCount;
		};

		template<class T>
		class FxArray
		{
		public:
			FxArrayBase<T> _container;
		};

		template<class T>
		class FxShortStringOptimizationBase
		{
		public:
			T _sv[16];
			T* _v;
			unsigned int _allocatedCount;
			unsigned int _usedCount;
		};

		template<class T>
		class FxStringBase
		{
		public:
			FxShortStringOptimizationBase<T> _container;
		};

		class FxRefObject : FxObject
		{
		public:
			unsigned int _referenceCount;
		};

		class alignas(4) FxNameEntry : FxRefObject
		{
		public:
			const FxStringBase<char>* _pString;
		};

		class FxName
		{
		public:
			FxNameEntry* _pNameEntry;
		};

		class FxArchiveNameEntry
		{
		public:
			FxStringBase<char> NameStr;
			FxName Name;
		};

		template<class A, class B, int C, class D>
		class HashBinType : OC3Ent::Face::FxAVLTree<A, B>
		{
		public:
			void _computeHeightAndBalance(OC3Ent::Face::FxAVLNode<A, B>*);
		};

		template<class A, class B, int C, class D>
		class FxHashTable
		{
		public:
			unsigned int _numItems;
			unsigned int _numInsertions;
			unsigned int _numRemovals;
			unsigned int _numCollisions;
			unsigned int _numProbes;
			HashBinType<A, B, C, D> _hashBins[1 << C];
		};

		class FxArchiveDirectory
		{
		public:
			unsigned int NumArchiveBytes;
			FxAVLTree<unsigned int, FxArchiveNameEntry> IdToNameMap;
			FxAVLTree<FxStringBase<char>, unsigned int> NameToIdMap;
			FxHashTable<FxStringBase<char>, unsigned short, 7, char const*> ClassVersions;
		};

		class FxArchiveInternalData
		{
		public:
			FxAVLTree<unsigned int, FxObject*> IdToObjectMap;
			FxAVLTree<FxObject*, unsigned int> ObjectToIdMap;
			FxArray<FxLazyLoader*> LazyLoaders;
			OC3Ent::Face::FxArchiveDirectory Directory;
		};

		class FxArchive : FxUseAllocator
		{
		public:
			FxArchiveStore* _store;

			enum FxArchiveMode
			{
				AM_LinearLoad = 0x0,
				AM_LazyLoad = 0x1,
				AM_CreateDirectory = 0x2,
				AM_ApproximateMemoryUsage = 0x3,
				AM_Save = 0x4,
				AM_Load = 0x0
			} _mode;

			enum FxArchiveByteOrder
			{
				ABO_LittleEndian = 0x0,
				ABO_BigEndian = 0x1,
			} _byteOrder;

			unsigned int _fileFormatVersion;
			unsigned int _sdkVersion;
			char* _sdkVersionString;
			unsigned int _sdkVersionStringSize;
			char* _licenseeName;
			unsigned int _licenseeNameSize;
			char* _licenseeProjectName;
			unsigned int _licenseeProjectNameSize;
			unsigned int _licenseeVersion;
			FxArchiveInternalData* _pInternalData;
			void(__cdecl* _progressCallback)(float);
			float _updateFrequency;
			int _numBytesProcessed;
			float _numBytesTotal;
			float _progress;
			float _lastProgress;
		};

		class alignas(4) FxLazyLoader
		{
		public:
			FxArchive* _archive;
			int _pos;
			bool _isLoaded;

			virtual ~FxLazyLoader();
			virtual void Load();
			virtual void Unload();
		};

		class FxNamedObject : public FxObject
		{
		public:
			FxName _name;
		};

		class FxClass : public FxUseAllocator
		{
		public:
			FxName _name;
			unsigned __int16 _currentVersion;
			const FxClass* _pBaseClassDesc;
			unsigned int _numChildren;
			unsigned int _size;
			FxObject* (__cdecl* _constructObjectFn)();
		};

		class FxDataContainer
		{
		public:
			void* _userData;
		};

		class FxAnimKey
		{
		public:
			float _time;
			float _value;
			float _slopeIn;
			float _slopeOut;
			void* _userData;
		};

		class FxAnimCurve : public FxNamedObject, public FxDataContainer
		{
		public:
			FxArray<FxAnimKey> _keys;
			unsigned int _cachedPos;
			float _firstKeyTime;
			float _firstKeyValue;
			float _lastKeyTime;
			float _lastKeyValue;
		};

		class FxCompressedAnimCurve : public FxNamedObject
		{
		public:
			float _min_value;
			float _max_value;
			int _start_frame;
			unsigned __int8* _keys;
			int _cached_segment_start_key_frame;
			float _cached_segment_start_key_time;
			float _cached_segment_start_key_value;
			float _cached_segment_start_key_slope_out;
			float _cached_segment_end_key_time;
			float _cached_segment_end_key_value;
			float _cached_segment_end_key_slope_in;
			float _cached_segment_delta_time;
			float _cached_segment_one_over_delta_time;
			unsigned __int8* _cached_segment_end_key_control_byte;
		};

		class FxRange
		{
		public:
			float rangeMin;
			float rangeMax;
		};

		enum FxEventSubclassType : __int32
		{
			EST_None = 0x0,
			EST_FxChildEvent = 0x1,
			EST_FxEvent = 0x2
		};

		class FxVec3
		{
		public:
			float x;
			float y;
			float z;
		};

		class FxQuat
		{
		public:
			float w;
			float x;
			float y;
			float z;
		};

		class FxBoneTransform
		{
		public:
			FxVec3 position;
			FxQuat rotation;
			FxVec3 scale;
		};

		class FxBone : public FxNamedObject
		{
		public:
			FxBoneTransform _transform;
		};

		class FxMasterBoneList
		{
		public:
			class FxMasterBoneListEntry
			{
			public:
				class FxBoneLink
				{
				public:
					unsigned int nodeIndex;
					FxBoneTransform optimizedBone;
				};

				unsigned int weightNodeIndex;
				FxBone refBone;
				FxArray<FxBoneLink> links;
			};

			bool _defaultPoseNeedsCreation;
			FxArray<FxMasterBoneListEntry> _refBones;
			FxArray<FxBoneTransform> _defaultTransforms;
			FxArray<FxBoneTransform> _currentTransforms;
			FxArray<float> _refBoneWeights;
			FxArray<float> _currentBoneWeights;
			FxArray<int> _clientIndexes;

			virtual ~FxMasterBoneList();
		};

		enum FxInputOp : unsigned __int32
		{
			IO_Invalid = 0xFFFFFFFF,
			IO_Sum = 0x0,
			IO_Multiply = 0x1,
			IO_Max = 0x2,
			IO_Min = 0x3
		};

		enum FxFaceGraphNodeUserPropertyType : __int32
		{
			UPT_Integer = 0x0,
			UPT_Bool = 0x1,
			UPT_Real = 0x2,
			UPT_String = 0x3,
			UPT_Choice = 0x4
		};

		class FxFaceGraphNodeUserProperty : public FxNamedObject
		{
		public:
			FxFaceGraphNodeUserPropertyType _propertyType;
			int _integerProperty;
			float _realProperty;
			FxArray<FxStringBase<char>> _choices;
		};

		enum FxLinkFnType : unsigned __int32
		{
			LFT_Invalid = 0xFFFFFFFF,
			LFT_Null = 0x0,
			LFT_Linear = 0x1,
			LFT_Quadratic = 0x2,
			LFT_Cubic = 0x3,
			LFT_Sqrt = 0x4,
			LFT_Negate = 0x5,
			LFT_Inverse = 0x6,
			LFT_OneClamp = 0x7,
			LFT_Constant = 0x8,
			LFT_Corrective = 0x9,
			LFT_ClampedLinear = 0xA,
			LFT_TrueQuadratic = 0xB,
			LFT_First = 0x0,
			LFT_Last = 0xB,
			LFT_NumLinkFnTypes = 0xC
		};

		class FxLinkFnParameters
		{
		public:
			FxArray<float> parameters;
		};

		class FxFaceGraphNode : public FxNamedObject, public FxDataContainer
		{
		public:
			class FxFaceGraphNodeJumpList
			{
			public:
				const FxClass* _nodeType;
				FxArray<FxFaceGraphNode*> _jumpList;
			};

			class Iterator
			{
			public:
				FxFaceGraphNode* const* _fgNodeListIter;
			};

			bool _hasBeenVisited;
			float _min;
			float _max;
			FxInputOp _inputOperation;
			FxArray<FxFaceGraphNodeLink> _inputs;
			FxArray<FxFaceGraphNode*> _outputs;
			FxArray<FxFaceGraphNodeUserProperty> _userProperties;

			virtual FxFaceGraphNode* Clone();
			virtual void CopyData(FxFaceGraphNode*);
			virtual bool SetMin(float);
			virtual bool HasFixedMin();
			virtual bool SetMax(float);
			virtual bool HasFixedMax();
			virtual void SetNodeOperation(FxInputOp);
			virtual bool HasFixedNodeOperation();
			virtual bool AddInputLink(const FxFaceGraphNodeLink*);
		};

		class FxFaceGraphNodeLink : public FxObject, public FxDataContainer
		{
		public:
			FxName _inputName;
			FxFaceGraphNode* _input;
			FxName _linkFnName;
			FxLinkFnType _linkFnType;
			FxLinkFnParameters _linkFnParams;
		};

		class FxFaceGraph : public FxObject
		{
		public:
			FxArray<FxFaceGraphNode*> _nodes;
			FxHashTable<FxStringBase<char>, FxFaceGraphNode*, 11, char const*>* _pNodeHash;
			FxArray<FxFaceGraphNode::FxFaceGraphNodeJumpList> _jumpLists;
		};

		enum FxCompiledFaceGraphNodeType : unsigned __int32
		{
			NT_Invalid = 0xFFFFFFFF,
			NT_Combiner = 0x0,
			NT_Delta = 0x1,
			NT_CurrentTime = 0x2,
			NT_GenericTarget = 0x3,
			NT_BonePose = 0x4,
			NT_MorphTarget = 0x5,
			NT_MaterialParameter = 0x6,
			NT_MaterialParameterUE3 = 0x7,
			NT_MorphTargetUE3 = 0x8,
			NT_BoneWeight = 0x9,
			NT_First = 0x0,
			NT_Last = 0x9,
			NT_NumNodeTypes = 0xA
		};

		class FxCompiledFaceGraphLink
		{
		public:
			unsigned int nodeIndex;
			float defaultValue;
			OC3Ent::Face::FxLinkFnType linkFnType;
			float linkFnParams[4];
		};

		class FxCompiledFaceGraphNode
		{
		public:
			FxCompiledFaceGraphNodeType nodeType;
			float nodeMin;
			float oneOverNodeMin;
			float nodeMax;
			float oneOverNodeMax;
			FxInputOp inputOperation;
			FxArray<FxCompiledFaceGraphLink> inputLinks;
		};

		class FxBitset
		{
		public:
			unsigned int _length;
			unsigned int _numSetBits;
			FxArrayBase<unsigned int> _container;
		};

		class alignas(4) FxCompiledFaceGraph
		{
			FxArray<FxCompiledFaceGraphNode> nodes;
			FxArray<FxName> nodeNames;
			FxArray<FxArray<FxFaceGraphNodeUserProperty> > nodeUserProperties;
			FxBitset activeBits;
			FxBitset initialActiveBits;
			FxArray<FxBitset> pvs;
			FxArray<float> defaultValues;
			FxArray<float> finalValues;
			FxHashTable<FxStringBase<char>, unsigned int, 11, char const*> _nodeHash;
			bool _containsCurrentTimeNodes;
		};

		class FxAnimGroup : public FxNamedObject
		{
		public:
			FxAVLTree<FxName, FxAnim*> _animations;
			FxAVLTree<FxName, FxAnimGroup*> _subgroups;
		};

		template<class T>
		class FxListNode
		{
		public:
			T element;
			FxListNode<T>* next;
			FxListNode<T>* prev;
		};

		template<class T>
		class FxList
		{
		public:
			FxListNode<T>* _head;
			unsigned int _size;
		};

		enum FxPhoneme : unsigned __int32
		{
			PHON_INVALID = 0xFFFFFFFF,
			PHON_FIRST = 0x0,
			PHON_SIL = 0x0,
			PHON_P = 0x1,
			PHON_B = 0x2,
			PHON_T = 0x3,
			PHON_D = 0x4,
			PHON_K = 0x5,
			PHON_G = 0x6,
			PHON_M = 0x7,
			PHON_N = 0x8,
			PHON_NG = 0x9,
			PHON_RA = 0xA,
			PHON_RU = 0xB,
			PHON_FLAP = 0xC,
			PHON_PH = 0xD,
			PHON_F = 0xE,
			PHON_V = 0xF,
			PHON_TH = 0x10,
			PHON_DH = 0x11,
			PHON_S = 0x12,
			PHON_Z = 0x13,
			PHON_SH = 0x14,
			PHON_ZH = 0x15,
			PHON_CX = 0x16,
			PHON_X = 0x17,
			PHON_GH = 0x18,
			PHON_HH = 0x19,
			PHON_R = 0x1A,
			PHON_Y = 0x1B,
			PHON_L = 0x1C,
			PHON_W = 0x1D,
			PHON_H = 0x1E,
			PHON_TS = 0x1F,
			PHON_CH = 0x20,
			PHON_JH = 0x21,
			PHON_IY = 0x22,
			PHON_E = 0x23,
			PHON_EN = 0x24,
			PHON_EH = 0x25,
			PHON_A = 0x26,
			PHON_AA = 0x27,
			PHON_AAN = 0x28,
			PHON_AO = 0x29,
			PHON_AON = 0x2A,
			PHON_O = 0x2B,
			PHON_ON = 0x2C,
			PHON_UW = 0x2D,
			PHON_UY = 0x2E,
			PHON_EU = 0x2F,
			PHON_OE = 0x30,
			PHON_OEN = 0x31,
			PHON_AH = 0x32,
			PHON_IH = 0x33,
			PHON_UU = 0x34,
			PHON_UH = 0x35,
			PHON_AX = 0x36,
			PHON_UX = 0x37,
			PHON_AE = 0x38,
			PHON_ER = 0x39,
			PHON_AXR = 0x3A,
			PHON_EXR = 0x3B,
			PHON_EY = 0x3C,
			PHON_AW = 0x3D,
			PHON_AY = 0x3E,
			PHON_OY = 0x3F,
			PHON_OW = 0x40,
			PHON_LAST = 0x40,
			NUM_PHONS = 0x41
		};

		class FxPhonToNameMap
		{
		public:
			FxPhoneme phoneme;
			FxName name;
			float amount;
		};

		enum FxTargetType : __int32
		{
			TargetBasic = 0x0,
			TargetJawOnly = 0x1,
			TargetTongueOnly = 0x2,
		};

		class FxMappingTarget
		{
		public:
			FxName name;
			FxTargetType type;
		};

		class FxPhonemeMap : public FxObject
		{
		public:
			FxArray<FxPhonToNameMap> _mapping;
			FxArray<FxMappingTarget> _targets;
		};

		class FxActor : public FxNamedObject
		{
		public:
			bool _shouldClientRelink;
			bool _isOpenInStudio;
			bool _isPublished;
			FxMasterBoneList _masterBoneList;
			FxFaceGraph _decompiledFaceGraph;
			FxCompiledFaceGraph _compiledFaceGraph;
			FxAnimGroup _defaultAnimGroup;
			FxArray<FxAnimGroup> _animGroups;
			FxList<FxAnimSet*> _mountedAnimSets;
			FxList<FxActorInstance*> _instanceList;
			FxPhonemeMap _phonemeMap;
			FxArray<unsigned char> _editorOnlyData;
		};

		class FxNodeChannelData
		{
		public:
			float persistentValue;
			float accumulatedTrackValue;
			unsigned int flags;
		};

		class FxNodeChannelBlendData
		{
		public:
			float persistentValueTarget;
			float blendStartTime;
			float inverseBlendDuration;
			float defaultValue;
		};

		class FxChannelWeight
		{
		public:
			float weight;
			unsigned int flags;
		};

		class FxChannelWeightBlendData
		{
		public:
			float weightTarget;
			float blendStartTime;
			float inverseBlendDuration;
		};

		class FxChannelBank
		{
		public:
			bool _paused;
			float _pauseTime;
			unsigned int _numNodes;
			unsigned int _numChannelsPerNode;
			FxArray<FxNodeChannelData> _nodeChannelData;
			FxArray<FxNodeChannelBlendData> _nodeChannelBlendData;
			FxArray<float> _nodeFinalValues;
			FxArray<FxChannelWeight> _channelWeights;
			FxArray<FxChannelWeightBlendData> _channelWeightBlendData;
			FxBitset _activePersistentBits;
			FxBitset _activeTrackBits;
			FxBitset _activeBits;
		};

		class FxGenericEvent
		{
		public:
			FxName _animGroupName;
			FxName _animationName;
			FxAnim* _pAnim;
			float _animStartTime;
			float _animEndTime;

			virtual ~FxGenericEvent();
			virtual const FxName* GetAnimGroupName();
			virtual const FxName* GetAnimationName();
			virtual FxRange* GetStartTimeRange(FxRange* result);
			virtual FxRange* GetMagnitudeRange(FxRange* result);
			virtual FxRange* GetDurationRange(FxRange* result);
			virtual FxRange* GetBlendInRange(FxRange* result);
			virtual FxRange* GetBlendOutRange(FxRange* result);
			virtual const FxName* GetCustomPayload();
			virtual float GetProbability();
			virtual FxRange* GetSpawnConditionDurationScale(FxRange* result);
			virtual FxRange* GetSpawnConditionMagnitudeScale(FxRange* result);
			virtual unsigned int GetEventID();
			virtual void SetEventID(unsigned int);
			virtual bool IsDurationScaledByParent();
			virtual bool IsMagnitudeScaledByParent();
			virtual bool IsBlendUnscaled();
			virtual bool UseParentBlendTimes();
			virtual bool ShouldPersistValues();
			virtual FxEventSubclassType GetType();
			virtual bool LinkToAnim(FxActor*);
		};

		class FxEvent : public FxGenericEvent
		{
		public:
			struct alignas(4) BoneWeightControl
			{
				unsigned int nodeIndex;
				unsigned int curveIndex;
				bool compressed;
			};

			struct alignas(4) AnimationCurveControl
			{
				unsigned int nodeIndex;
				unsigned int curveIndex;
				bool compressed;
			};

			float _startTime;
			float _magnitudeScale;
			float _invDurationScale;
			float _durationScale;
			float _blendInTime;
			float _invBlendInTime;
			float _blendOutTime;
			float _invBlendOutTime;
			float _actualStartTime;
			float _actualEndTime;
			float _scaledMagnitude;
			bool _shouldPersist;
			FxName _customEventPayload;
			unsigned int _id;
			unsigned int _parentID;
			unsigned int _templateRevisionID;
			unsigned int _templateParentID;
			FxArray<BoneWeightControl> _boneWeightControls;
			FxArray<AnimationCurveControl> _animationCurveControls;
		};

		enum FxClientEventState : unsigned __int32
		{
			CES_Invalid = 0xFFFFFFFF,
			CES_OneShot = 0x0,
			CES_FirstLoop = 0x1,
			CES_SubsequentLoop = 0x2
		};

		//OC3Ent::Face::FxEventManager::FxManagedEvent
		class FxManagedEvent
		{
		public:
			FxEvent event;
			float startTime;
			float lastTickTime;
			float eventStartOffset;
			bool loop;
			unsigned int channel;
			bool hasStartedAudio;
			FxClientEventState state;
			float forceBlendOutInvDuration;
			float forceBlendOutStartTime;
		};

		//OC3Ent::Face::FxEventList::FxTickControlInfo
		class alignas(4) FxTickControlInfo
		{
		public:
			unsigned int eventIndex;
			float time;
			bool shouldIngress;
		};

		class alignas(4) FxEventManager
		{
		public:
			bool _paused;
			float _pauseTime;
			unsigned int _uniqueID;
			unsigned int _numActive;
			FxArray<FxManagedEvent> _clientEvents;
			FxArray<bool> _clientEventActive;
			FxArray<FxTickControlInfo> _clientEventTickControl;
			bool _tickControlOutOfDate;
		};

		class FxActorInstance : public FxNamedObject
		{
			OC3Ent::Face::FxActor* _pActor;
			bool _isNoWorkFrame;
			bool _isOpenInStudio;
			OC3Ent::Face::FxChannelBank _channelBank;
			OC3Ent::Face::FxEventManager _eventManager;
			OC3Ent::Face::FxArray<float> _accumulatedBaseChannelTrackValues;

			virtual void BeginFrame();
			virtual void EndFrame();
		};

		class FxAnimSet : public FxNamedObject
		{
		public:
			bool _isPublished;
			FxName _owningActorName;
			FxAnimGroup _animGroup;
			FxList<OC3Ent::Face::FxActor*> _references;
		};

		class alignas(4) FxEventList
		{
		public:
			FxArray<FxEvent> _events;
			FxList<FxTickControlInfo> _tickControl;
			FxArray<FxName> _referencedAnimGroups;
			bool _metadataOutOfDate;
		};

		class FxChildEvent : public FxGenericEvent
		{
		public:
			unsigned int _uniqueID;
			FxRange _startTimeOffset;
			FxRange _magnitudeScale;
			FxRange _durationScale;
			FxRange _blendInTime;
			FxRange _blendOutTime;
			FxName _customEventPayload;
			unsigned __int8 _eventFlags;
			float _spawnConditionProbability;
			FxRange _spawnConditionDurationScale;
			FxRange _spawnConditionMagnitudeScale;
			FxRange _spawnConditionStartTimeOffset;
		};

		class FxChildEventGroup
		{
		public:
			FxArray<FxChildEvent> _childEvents;
			FxArray<float> _childEventWeights;
		};

		class FxEventTemplate
		{
		public:
			FxArray<FxChildEventGroup> _childEventGroups;
			unsigned int _templateRevisionID;
			unsigned int _currentChildID;
			int _recursionDepth;
		};

		class alignas(4) FxPhonInfo
		{
		public:
			FxPhoneme phoneme;
			float start;
			float end;
			bool selected;
		};

		class FxWordInfo
		{
		public:
			FxStringBase<wchar_t> text;
			unsigned int first;
			unsigned int last;
		};

		class alignas(4) FxPhonWordList : public FxObject
		{
		public:
			FxArray<FxPhonInfo> _phonemes;
			FxArray<FxWordInfo> _words;
			unsigned int _startWord;
			unsigned int _startPhon;
			float _minPhonLen;
			bool _isDirty;
		};

		class alignas(4) FxEditorOnlyCurveOwnerData
		{
		public:
			FxName curveName;
			bool ownedByAnalysis;
		};

		enum FxPreviewAnimationBlendMode : __int32
		{
			BM_FaceFX = 0x0,
			BM_Normal = 0x1
		};

		class alignas(4) FxPreviewAnimationSettings : public FxObject
		{
		public:
			FxPreviewAnimationBlendMode _blendMode;
			bool _blendModeIsSet;
			FxStringBase<char> _animationName;
			bool _animationNameIsSet;
			float _startTime;
			bool _startTimeIsSet;
			float _blendInTime;
			bool _blendInTimeIsSet;
			float _blendOutTime;
			bool _blendOutTimeIsSet;
			float _length;
			bool _lengthIsSet;
			bool _loop;
			bool _loopIsSet;
		};

		class FxAnimEditorOnlyData : public FxObject
		{
		public:
			FxStringBase<char> _language;
			FxStringBase<char> _analysisActor;
			FxStringBase<wchar_t> _analysisText;
			FxArray<FxEditorOnlyCurveOwnerData> _curveOwnerData;
			FxStringBase<char> _absoluteAudioPath;
			FxStringBase<char> _audioHash;
			FxEventTemplate _analysisActorTemplate;
			FxEventList _analysisActorTake;
			FxArray<unsigned char> _pythonDictionary;
			FxPreviewAnimationSettings _previewAnimationSettings;
			unsigned int _audioHandle;
		};

		class FxAnim : public FxNamedObject, public FxDataContainer
		{
		public:
			FxArray<FxAnimCurve> _animCurves;
			FxArray<FxCompressedAnimCurve> _compressedAnimCurves;
			float _startTime;
			float _endTime;
			float _curvesStartTime;
			float _curvesEndTime;
			FxEventList _eventTake;
			FxEventTemplate _eventTemplate;
			FxPhonWordList _phonWordList;
			FxAnimEditorOnlyData* _editorOnlyData;
			FxStringBase<char> _audioAssetPath;
			FxStringBase<char> _audioAssetName;
			unsigned int _audioAssetIndex;
			void* _audioAssetPointer;
			float _frameRate;
		};
	};
};