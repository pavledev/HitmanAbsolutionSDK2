#pragma once

namespace OC3Ent
{
	namespace Face
	{
		class FxClass;
		class FxArchive;
		class FxAnim;
		class FxFaceGraphNodeLink;
		class FxAnimSet;
		class FxActorInstance;
		class FxNameTableInternalData;
		
		template<class T>
		class FxTreeBase;

		class FxLazyLoader;

		class FxUseAllocator
		{
		public:
			FxUseAllocator() = default;
			~FxUseAllocator() = default;
			static void* operator new(unsigned int size);
			static void operator delete(void* ptr, unsigned int size);
		};

		class FxObject : public FxUseAllocator
		{
		public:
			static FxClass* _pClassDesc;

			virtual const FxClass* GetClassDesc() const;
			virtual unsigned short GetCurrentVersion() const;
			virtual ~FxObject() = default;
			virtual void Serialize(FxArchive & arc);
		};

		class __declspec(novtable) FxArchiveStore : public FxUseAllocator
		{
		public:
			virtual bool OpenRead() = 0;
			virtual bool OpenWrite() = 0;
			virtual bool Close() = 0;
			virtual bool Read(unsigned char* param1, unsigned int param2) = 0;
			virtual bool Write(const unsigned char* param1, unsigned int param2) = 0;
			virtual int Tell() const = 0;
			virtual void Seek(const int param1) = 0;
			virtual int Length() const = 0;
			virtual ~FxArchiveStore() = default;
			virtual void Destroy() = 0;
			virtual unsigned int GetClassSize() = 0;

			FxArchiveStore() = default;
		};

		namespace PrivateImpl
		{
			template <class T>
			class FxNoBase
			{

			};
		};

		template <class T>
		class FxSafeBool : public PrivateImpl::FxNoBase<T>
		{

		};

		template <class A, class B, class C>
		class FxTreeNodeBase : public FxObject
		{
		public:
			A key;
			B item;
			unsigned int height;
			C* parent;
			C* children[2];
		};

		template <class A, class B>
		class FxAVLNode : public FxTreeNodeBase<A, B, FxAVLNode<A, B>>
		{
		public:
			short balance;
		};

		template <class A, class B>
		class FxAVLTree : public FxTreeBase<FxAVLNode<A, B>>
		{

		};

		template <class T>
		class FxTreeBase
		{
		public:
			class IteratorBase : public FxSafeBool<IteratorBase>
			{
			public:
				FxTreeBase* _tree;
				T* _node;
			};

			class ConstIteratorBase : public FxSafeBool<ConstIteratorBase>
			{
			public:
				FxTreeBase* _tree;
				T* _node;
			};

			class Iterator : public IteratorBase
			{

			};

			class ConstIterator : public ConstIteratorBase
			{

			};

			class ReverseIterator
			{
			};

			class ConstReverseIterator
			{
			};

			/*class Item
			{
			public:
				const FxStringBase<char>& key;
				unsigned int& item;
			};

			class ConstItem
			{
			public:
				const FxStringBase<char>& key;
				const unsigned int& item;
			};*/

			T* _root;
			unsigned int _numNodes;
		};

		template <class T>
		class FxArrayBase
		{
		public:
			T* _v;
			unsigned int _allocatedCount;
			unsigned int _usedCount;
		};

		template <class T>
		class FxArray
		{
		public:
			FxArrayBase<T> _container;
		};

		template <class T>
		class FxShortStringOptimizationBase
		{
		public:
			T _sv[16];
			T* _v;
			unsigned int _allocatedCount;
			unsigned int _usedCount;
		};

		template <class T>
		class FxStringBase
		{
		public:
			FxShortStringOptimizationBase<T> _container;
		};

		class FxRefObject : public FxObject
		{
		public:
			unsigned int _referenceCount;

			static FxClass* _pClassDesc;
		};

		class FxNameEntry : public FxRefObject
		{
		public:
			const FxStringBase<char>* _pString;

			static FxClass* _pClassDesc;
		};

		class FxName
		{
		public:
			FxNameEntry* _pNameEntry;

			static FxName NullName;
			static FxNameTableInternalData* _internal;
		};

		class FxArchiveNameEntry
		{
		public:
			FxStringBase<char> NameStr;
			FxName Name;
		};

		template <class A, class B, int C, class D>
		class FxHashTable
		{
		public:
			class HashBinType : public FxAVLTree<A, B>
			{

			};

			class ConstIterator : public FxSafeBool<ConstIterator>
			{
			public:
				FxHashTable* _table;
				unsigned int _numBins;
				unsigned int _binIndex;
				typename FxTreeBase<FxAVLNode<A, B>>::Iterator _binIter;
			};

			class ConstItem
			{
			public:
				const A& key;
				const B& item;
			};

			unsigned int _numItems;
			unsigned int _numInsertions;
			unsigned int _numRemovals;
			unsigned int _numCollisions;
			unsigned int _numProbes;
			HashBinType _hashBins[1 << C];
		};

		class FxNameTableInternalData
		{
		public:
			FxHashTable<FxStringBase<char>, FxNameEntry*, 12, char const*> NameHash;
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
			FxArchiveDirectory Directory;
		};

		class FxArchive : public FxUseAllocator
		{
		public:
			enum FxArchiveMode
			{
				AM_LinearLoad = 0,
				AM_LazyLoad = 1,
				AM_CreateDirectory = 2,
				AM_ApproximateMemoryUsage = 3,
				AM_Save = 4,
				AM_Load = 0
			};

			enum FxArchiveByteOrder
			{
				ABO_LittleEndian = 0,
				ABO_BigEndian = 1
			};

			FxArchiveStore* _store;
			FxArchiveMode _mode;
			FxArchiveByteOrder _byteOrder;
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
			void (*_progressCallback)(float param1);
			float _updateFrequency;
			int _numBytesProcessed;
			float _numBytesTotal;
			float _progress;
			float _lastProgress;
		};

		class __declspec(novtable) FxLazyLoader
		{
		public:
			FxArchive* _archive;
			int _pos;
			bool _isLoaded;
		};

		class FxNamedObject : public FxObject
		{
		public:
			FxName _name;

			static FxClass* _pClassDesc;
		};

		class FxClass : public FxUseAllocator
		{
		public:
			FxName _name;
			unsigned short _currentVersion;
			const FxClass* _pBaseClassDesc;
			unsigned int _numChildren;
			unsigned int _size;
			FxObject* (*_constructObjectFn)();

			static FxArray<FxClass*>* _classTable;
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

			static FxClass* _pClassDesc;
		};

		class FxCompressedAnimCurve : public FxNamedObject
		{
		public:
			float _min_value;
			float _max_value;
			int _start_frame;
			unsigned char* _keys;
			int _cached_segment_start_key_frame;
			float _cached_segment_start_key_time;
			float _cached_segment_start_key_value;
			float _cached_segment_start_key_slope_out;
			float _cached_segment_end_key_time;
			float _cached_segment_end_key_value;
			float _cached_segment_end_key_slope_in;
			float _cached_segment_delta_time;
			float _cached_segment_one_over_delta_time;
			unsigned char* _cached_segment_end_key_control_byte;

			static FxClass* _pClassDesc;
		};

		struct FxRange
		{
			float rangeMin;
			float rangeMax;
		};

		enum FxEventSubclassType
		{
			EST_None = 0,
			EST_FxChildEvent = 1,
			EST_FxEvent = 2
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

		struct FxBoneTransform
		{
			FxVec3 position;
			FxQuat rotation;
			FxVec3 scale;
		};

		class FxBone : public FxNamedObject
		{
		public:
			FxBoneTransform _transform;

			static FxClass* _pClassDesc;
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

					FxBoneLink(unsigned int iNodeIndex, FxBoneTransform transform);
					FxBoneLink() = default;
					~FxBoneLink() = default;
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
		};

		enum FxInputOp
		{
			IO_Invalid = -1,
			IO_Sum = 0,
			IO_Multiply = 1,
			IO_Max = 2,
			IO_Min = 3
		};

		enum FxFaceGraphNodeUserPropertyType
		{
			UPT_Integer = 0,
			UPT_Bool = 1,
			UPT_Real = 2,
			UPT_String = 3,
			UPT_Choice = 4
		};

		class FxFaceGraphNodeUserProperty : public FxNamedObject
		{
		public:
			FxFaceGraphNodeUserPropertyType _propertyType;
			int _integerProperty;
			float _realProperty;
			FxArray<FxStringBase<char>> _choices;

			static FxClass* _pClassDesc;
		};

		enum FxLinkFnType
		{
			LFT_Invalid = -1,
			LFT_Null = 0,
			LFT_Linear = 1,
			LFT_Quadratic = 2,
			LFT_Cubic = 3,
			LFT_Sqrt = 4,
			LFT_Negate = 5,
			LFT_Inverse = 6,
			LFT_OneClamp = 7,
			LFT_Constant = 8,
			LFT_Corrective = 9,
			LFT_ClampedLinear = 10,
			LFT_TrueQuadratic = 11,
			LFT_First = 0,
			LFT_Last = 11,
			LFT_NumLinkFnTypes = 12
		};

		struct FxLinkFnParameters
		{
			FxArray<float> parameters;

			FxLinkFnParameters(const FxLinkFnParameters& __that);
			FxLinkFnParameters() = default;
			~FxLinkFnParameters() = default;
			FxLinkFnParameters& operator=(const FxLinkFnParameters& __that);
		};

		class __declspec(novtable) FxFaceGraphNode : public FxNamedObject, public FxDataContainer
		{
		public:
			bool _hasBeenVisited;
			float _min;
			float _max;
			FxInputOp _inputOperation;
			FxArray<FxFaceGraphNodeLink> _inputs;
			FxArray<FxFaceGraphNode*> _outputs;
			FxArray<FxFaceGraphNodeUserProperty> _userProperties;

			static FxClass* _pClassDesc;
		};

		class FxFaceGraphNodeLink : public FxObject, public FxDataContainer
		{
		public:
			FxName _inputName;
			FxFaceGraphNode* _input;
			FxName _linkFnName;
			FxLinkFnType _linkFnType;
			FxLinkFnParameters _linkFnParams;

			static FxClass* _pClassDesc;
		};

		class FxFaceGraph : public FxObject
		{
		public:
			class Iterator
			{
			public:
				FxFaceGraphNode** _fgNodeListIter;

				Iterator(FxFaceGraphNode** fgNodeListIter);
				Iterator& operator++();
				FxFaceGraphNode* GetNode();
				bool operator!=(const Iterator& other);
			};

			class FxFaceGraphNodeJumpList
			{
			public:
				const FxClass* _nodeType;
				FxArray<FxFaceGraphNode*> _jumpList;

				FxFaceGraphNodeJumpList(const FxFaceGraphNodeJumpList& __that);
				FxFaceGraphNodeJumpList(const FxClass* nodeType, FxFaceGraphNode* pNode);
				~FxFaceGraphNodeJumpList() = default;
				const FxClass* GetNodeType() const;
				void SetNodeType(const FxClass* nodeType);
				unsigned int GetNumNodes() const;
				bool FindNode(FxFaceGraphNode* pNode) const;
				bool AddNode(FxFaceGraphNode* pNode);
				bool RemoveNode(FxFaceGraphNode* pNode);
				FxFaceGraphNode** Begin() const;
				FxFaceGraphNode** End() const;
				void Reserve(unsigned int numNodes);
				FxFaceGraphNodeJumpList& operator=(const FxFaceGraphNodeJumpList& __that);
			};

			FxArray<FxFaceGraphNode*> _nodes;
			FxHashTable<FxStringBase<char>, FxFaceGraphNode*, 11, char const*>* _pNodeHash;
			FxArray<FxFaceGraphNodeJumpList> _jumpLists;

			static FxClass* _pClassDesc;
		};

		enum FxCompiledFaceGraphNodeType
		{
			NT_Invalid = -1,
			NT_Combiner = 0,
			NT_Delta = 1,
			NT_CurrentTime = 2,
			NT_GenericTarget = 3,
			NT_BonePose = 4,
			NT_MorphTarget = 5,
			NT_MaterialParameter = 6,
			NT_MaterialParameterUE3 = 7,
			NT_MorphTargetUE3 = 8,
			NT_BoneWeight = 9,
			NT_First = 0,
			NT_Last = 9,
			NT_NumNodeTypes = 10
		};

		struct FxCompiledFaceGraphLink
		{
			unsigned int nodeIndex;
			float defaultValue;
			FxLinkFnType linkFnType;
			float linkFnParams[4];
		};

		struct FxCompiledFaceGraphNode
		{
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

			static const unsigned int kNumBitsInStorageType;
			static const unsigned int kStorageTypePowerOfTwo;
		};

		struct FxCompiledFaceGraph
		{
			FxArray<FxCompiledFaceGraphNode> nodes;
			FxArray<FxName> nodeNames;
			FxArray<FxArray<FxFaceGraphNodeUserProperty>> nodeUserProperties;
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

			static FxClass* _pClassDesc;
			static FxName Default;
			static bool _logErrorOnAnimationNotFound;
		};

		template <class T>
		class FxList
		{
		public:
			class FxListNode
			{
			public:
				T element;
				FxListNode* next;
				FxListNode* prev;

				FxListNode(const FxListNode& __that);
				FxListNode(const T& iElement, FxListNode* iNext, FxListNode* iPrev);
				FxListNode() = default;
				~FxListNode() = default;
			};

			class Iterator
			{
			public:
				FxListNode* _pNode;

				Iterator(FxListNode* pNode);
				Iterator& operator++();
				T& operator*();
				T* operator->();
				bool operator==(const Iterator& other);
				bool operator!=(const Iterator& other);
				FxListNode* GetNode();
			};

			class ConstIterator
			{
			public:
				const FxListNode* _pNode;

				ConstIterator(FxListNode* pNode);
				ConstIterator& operator++();
				T& operator*();
				bool operator!=(const ConstIterator& other);
			};

			class ReverseIterator
			{
			};

			FxListNode* _head;
			unsigned int _size;
		};

		enum FxPhoneme
		{
			PHON_INVALID = -1,
			PHON_FIRST = 0,
			PHON_SIL = 0,
			PHON_P = 1,
			PHON_B = 2,
			PHON_T = 3,
			PHON_D = 4,
			PHON_K = 5,
			PHON_G = 6,
			PHON_M = 7,
			PHON_N = 8,
			PHON_NG = 9,
			PHON_RA = 10,
			PHON_RU = 11,
			PHON_FLAP = 12,
			PHON_PH = 13,
			PHON_F = 14,
			PHON_V = 15,
			PHON_TH = 16,
			PHON_DH = 17,
			PHON_S = 18,
			PHON_Z = 19,
			PHON_SH = 20,
			PHON_ZH = 21,
			PHON_CX = 22,
			PHON_X = 23,
			PHON_GH = 24,
			PHON_HH = 25,
			PHON_R = 26,
			PHON_Y = 27,
			PHON_L = 28,
			PHON_W = 29,
			PHON_H = 30,
			PHON_TS = 31,
			PHON_CH = 32,
			PHON_JH = 33,
			PHON_IY = 34,
			PHON_E = 35,
			PHON_EN = 36,
			PHON_EH = 37,
			PHON_A = 38,
			PHON_AA = 39,
			PHON_AAN = 40,
			PHON_AO = 41,
			PHON_AON = 42,
			PHON_O = 43,
			PHON_ON = 44,
			PHON_UW = 45,
			PHON_UY = 46,
			PHON_EU = 47,
			PHON_OE = 48,
			PHON_OEN = 49,
			PHON_AH = 50,
			PHON_IH = 51,
			PHON_UU = 52,
			PHON_UH = 53,
			PHON_AX = 54,
			PHON_UX = 55,
			PHON_AE = 56,
			PHON_ER = 57,
			PHON_AXR = 58,
			PHON_EXR = 59,
			PHON_EY = 60,
			PHON_AW = 61,
			PHON_AY = 62,
			PHON_OY = 63,
			PHON_OW = 64,
			PHON_LAST = 64,
			NUM_PHONS = 65
		};

		class FxPhonToNameMap
		{
		public:
			FxPhoneme phoneme;
			FxName name;
			float amount;
		};

		enum FxTargetType
		{
			TargetBasic = 0,
			TargetJawOnly = 1,
			TargetTongueOnly = 2
		};

		struct FxMappingTarget
		{
			FxName name;
			FxTargetType type;
		};

		class FxPhonemeMap : public FxObject
		{
		public:
			FxArray<FxPhonToNameMap> _mapping;
			FxArray<FxMappingTarget> _targets;

			static FxClass* _pClassDesc;
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

			static FxClass* _pClassDesc;
			static FxName NewActor;
		};

		struct FxNodeChannelData
		{
			float persistentValue;
			float accumulatedTrackValue;
			unsigned int flags;

			FxNodeChannelData() = default;
			~FxNodeChannelData() = default;
		};

		struct FxNodeChannelBlendData
		{
			float persistentValueTarget;
			float blendStartTime;
			float inverseBlendDuration;
			float defaultValue;

			FxNodeChannelBlendData() = default;
			~FxNodeChannelBlendData() = default;
		};

		struct FxChannelWeight
		{
			float weight;
			unsigned int flags;

			FxChannelWeight() = default;
			~FxChannelWeight() = default;
		};

		struct FxChannelWeightBlendData
		{
			float weightTarget;
			float blendStartTime;
			float inverseBlendDuration;

			FxChannelWeightBlendData() = default;
			~FxChannelWeightBlendData() = default;
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

		class __declspec(novtable) FxGenericEvent
		{
		public:
			FxName _animGroupName;
			FxName _animationName;
			FxAnim* _pAnim;
			float _animStartTime;
			float _animEndTime;

			virtual ~FxGenericEvent() = default;
			virtual const FxName& GetAnimGroupName() const;
			virtual const FxName& GetAnimationName() const;
			virtual FxRange GetStartTimeRange() const = 0;
			virtual FxRange GetMagnitudeRange() const = 0;
			virtual FxRange GetDurationRange() const = 0;
			virtual FxRange GetBlendInRange() const = 0;
			virtual FxRange GetBlendOutRange() const = 0;
			virtual const FxName& GetCustomPayload() const = 0;
			virtual float GetProbability() const = 0;
			virtual FxRange GetSpawnConditionDurationScale() const = 0;
			virtual FxRange GetSpawnConditionMagnitudeScale() const = 0;
			virtual unsigned int GetEventID() const = 0;
			virtual void SetEventID(unsigned int param1) = 0;
			virtual bool IsDurationScaledByParent() const = 0;
			virtual bool IsMagnitudeScaledByParent() const = 0;
			virtual bool IsBlendUnscaled() const = 0;
			virtual bool UseParentBlendTimes() const = 0;
			virtual bool ShouldPersistValues() const = 0;
			virtual FxEventSubclassType GetType() const;
			virtual bool LinkToAnim(FxActor * pActor) const;
		};

		class FxEvent : public FxGenericEvent
		{
		public:
			struct BoneWeightControl
			{
				unsigned int nodeIndex;
				unsigned int curveIndex;
				bool compressed;
			};

			struct AnimationCurveControl
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

			~FxEvent() override = default;
			FxRange GetStartTimeRange() const override;
			FxRange GetMagnitudeRange() const override;
			FxRange GetDurationRange() const override;
			FxRange GetBlendInRange() const override;
			FxRange GetBlendOutRange() const override;
			const FxName& GetCustomPayload() const override;
			float GetProbability() const override;
			FxRange GetSpawnConditionDurationScale() const override;
			FxRange GetSpawnConditionMagnitudeScale() const override;
			unsigned int GetEventID() const override;
			void SetEventID(unsigned int eventID) override;
			bool IsDurationScaledByParent() const override;
			bool IsMagnitudeScaledByParent() const override;
			bool IsBlendUnscaled() const override;
			bool UseParentBlendTimes() const override;
			bool ShouldPersistValues() const override;
			FxEventSubclassType GetType() const override;
			bool LinkToAnim(FxActor * pActor) const override;
		};

		enum FxClientEventState
		{
			CES_Invalid = -1,
			CES_OneShot = 0,
			CES_FirstLoop = 1,
			CES_SubsequentLoop = 2
		};

		class FxEventList
		{
		public:
			struct FxTickControlInfo
			{
				unsigned int eventIndex;
				float time;
				bool shouldIngress;

				FxTickControlInfo(unsigned int index, float t, bool ingress);
				FxTickControlInfo() = default;
				bool operator==(const FxTickControlInfo& other) const;
				bool operator!=(const FxTickControlInfo& other) const;
				bool operator<(const FxTickControlInfo& other) const;
				void Reset();
			};

			FxArray<FxEvent> _events;
			FxList<FxTickControlInfo> _tickControl;
			FxArray<FxName> _referencedAnimGroups;
			bool _metadataOutOfDate;
		};

		class FxEventManager
		{
		public:
			struct FxManagedEvent
			{
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

				FxManagedEvent(const FxManagedEvent& __that);
				FxManagedEvent() = default;
				~FxManagedEvent() = default;
			};

			bool _paused;
			float _pauseTime;
			unsigned int _uniqueID;
			unsigned int _numActive;
			FxArray<FxManagedEvent> _clientEvents;
			FxArray<bool> _clientEventActive;
			FxArray<FxEventList::FxTickControlInfo> _clientEventTickControl;
			bool _tickControlOutOfDate;
		};

		class FxActorInstance : public FxNamedObject
		{
		public:
			FxActor* _pActor;
			bool _isNoWorkFrame;
			bool _isOpenInStudio;
			FxChannelBank _channelBank;
			FxEventManager _eventManager;
			FxArray<float> _accumulatedBaseChannelTrackValues;

			static FxClass* _pClassDesc;
		};

		class FxAnimSet : public FxNamedObject
		{
		public:
			bool _isPublished;
			FxName _owningActorName;
			FxAnimGroup _animGroup;
			FxList<FxActor*> _references;

			static FxClass* _pClassDesc;
		};

		class FxChildEvent : public FxGenericEvent
		{
		public:
			enum FxEventFlags
			{
				EF_None = 0,
				EF_DurationScaledByParent = 1,
				EF_MagnitudeScaledByParent = 2,
				EF_ShouldPersistValues = 4,
				EF_BlendUnscaled = 8,
				EF_UseParentBlend = 16
			};

			unsigned int _uniqueID;
			FxRange _startTimeOffset;
			FxRange _magnitudeScale;
			FxRange _durationScale;
			FxRange _blendInTime;
			FxRange _blendOutTime;
			FxName _customEventPayload;
			unsigned char _eventFlags;
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

		struct FxPhonInfo
		{
			FxPhoneme phoneme;
			float start;
			float end;
			bool selected;
		};

		struct FxWordInfo
		{
			FxStringBase<wchar_t> text;
			unsigned int first;
			unsigned int last;
		};

		class FxPhonWordList : public FxObject
		{
		public:
			enum InsertionMethod
			{
				SPLIT_TIME = 1,
				PUSH_OUT = 2
			};

			FxArray<FxPhonInfo> _phonemes;
			FxArray<FxWordInfo> _words;
			unsigned int _startWord;
			unsigned int _startPhon;
			float _minPhonLen;
			bool _isDirty;

			static FxClass* _pClassDesc;
		};

		struct FxEditorOnlyCurveOwnerData
		{
			FxName curveName;
			bool ownedByAnalysis;
		};

		enum FxPreviewAnimationBlendMode
		{
			BM_FaceFX = 0,
			BM_Normal = 1
		};

		class FxPreviewAnimationSettings : public FxObject
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

			static FxClass* _pClassDesc;
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

			static FxClass* _pClassDesc;
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

			static FxClass* _pClassDesc;
			static const float MINIMUM_FRAME_RATE;
			static const float MAXIMUM_FRAME_RATE;
			static const float DEFAULT_FRAME_RATE;
		};
	};
};