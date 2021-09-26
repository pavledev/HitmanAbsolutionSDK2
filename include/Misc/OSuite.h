#pragma once

namespace OSuite
{
	struct SCallbackData
	{

	};

	class ZWebServiceClient
	{

	};

	/*enum EServerError
	{
		SERVERERROR_OK = 0,
		SERVERERROR_INVALID_TICKET = 1,
		SERVERERROR_EXPIRED_TICKET = 2,
		SERVERERROR_BAD_ENVIRONMENT = 3,
		SERVERERROR_COUNT = 4
	};

	class ZHttp
	{
	public:
		enum
		{
			CONTENTLENGTH_UNKNOWN = -1
		};

		enum EMethod
		{
			METHOD_GET = 0,
			METHOD_PUT = 1,
			METHOD_POST = 2,
			METHOD_DELETE = 3,
			METHOD_UPDATE = 4
		};

		enum EError
		{
			HTTPERROR_OK = 0,
			HTTPERROR_REQUESTSENDFAILED = 1,
			HTTPERROR_RESPONSERECEIVEFAILED = 2,
			HTTPERROR_DATAPROCESSINGFAILED = 3,
			HTTPERROR_DATASENDFAILED = 4,
			HTTPERROR_DATARECEIVEFAILED = 5,
			HTTPERROR_SOCKETCONNECTIONFAILED = 6,
			HTTPERROR_SOCKETCONNECTIONLOST = 7,
			HTTPERROR_CONNECTIONCREATIONFAILED = 8,
			HTTPERROR_SERVERCLOSEDCONNECTION = 9,
			HTTPERROR_RESPONSESTATUSCODE = 10,
			HTTPERROR_ABORTED = 11,
			HTTPERROR_CLOSED = 12,
			HTTPERROR_INVALID = 13,
			HTTPERROR_FAILED = 14,
			HTTPERROR_BAD_CERTIFICATE = 15,
			HTTPERROR_TIMEOUT = 16,
			HTTPERROR_UNKNOWN = 17,
			HTTPERROR_NUM = 18
		};

		static const int HttpOperationTimeoutSec;
		static const unsigned int PrefetchSize;

		ZHttp() = default;
		~ZHttp() = default;
	};

	struct SHttpStatus
	{
		int nHttpStatus;
		EServerError eServerError;
		ZHttp::EError eError;

		SHttpStatus() = default;
		~SHttpStatus() = default;
		bool Success();
		void Reset();
	};

	enum EDownloadEvent
	{
		EVENT_NONE = 0,
		EVENT_UNAUTHORIZED_ERROR = 1,
		EVENT_RESOURCE_ERROR = 2,
		EVENT_SERVER_ERROR = 3,
		EVENT_FINISHED = 4,
		EVENT_ABORTED = 5
	};

	class __declspec(novtable) IAllocator
	{
	public:
		virtual void* malloc(unsigned int param1, char* param2) = 0;
		virtual void* realloc(void* param1, unsigned int param2, char* param3) = 0;
		virtual void free(void* param1) = 0;
		virtual ~IAllocator() = default;

		IAllocator() = default;
	};

	class ZObject
	{
	public:
		static IAllocator* m_allocator;

		virtual ~ZObject() = default;

		static IAllocator* GetAllocator();
		static void SetAllocator(IAllocator* allocator);
		static void* operator new(unsigned int nSize, char* pTag);
		static void* operator new(unsigned int nSize);
		static void operator delete(void* pMemory, char* __formal);
		static void operator delete(void* pMemory);
		static void* operator new[](unsigned int nSize, char* pTag);
		static void* operator new[](unsigned int nSize);
		static void operator delete[](void* pMemory, char* __formal);
		static void operator delete[](void* pMemory);
		void* malloc(unsigned int size, char* pTag) const;
		void* malloc(unsigned int size, char* pTag);
		void* realloc(void* ptr, unsigned int size, char* pTag) const;
		void* realloc(void* ptr, unsigned int size, char* pTag);
		void free(void* ptr) const;
		void free(void* ptr);
		ZObject(const ZObject& __formal);
		ZObject() = default;
		ZObject& operator=(const ZObject& __formal);
	};

	class __declspec(novtable) IHashable
	{
	public:
		virtual ~IHashable() = default;
		virtual unsigned int ComputeHash() const = 0;

		IHashable() = default;
	};

	class __declspec(novtable) ZListBase : public ZObject
	{
	public:
		class ZListIteratorBase : public ZObject
		{
		public:
			ZListBase* m_pListBase;
			unsigned int m_nIndex;

			~ZListIteratorBase() override = default;

			bool AtEnd() const;
			operator bool() const;
			void Next();
			void Previous();
			void Remove();
			ZListIteratorBase(const ZListIteratorBase& that);
			ZListIteratorBase(ZListBase* pList);
			ZListIteratorBase() = default;
			ZListIteratorBase& operator=(const ZListIteratorBase& that);
		};

		unsigned int m_nSize;
		unsigned int m_nTop;

		~ZListBase() override = default;
		virtual void RemoveIndex(unsigned int param1) = 0;

		ZListBase() = default;
		ZListBase(const ZListBase& that);
		ZListBase& operator=(const ZListBase& that);
		unsigned int Count() const;
	};

	template <class A, class B, class C>
	class TConstIterator : public ZObject
	{
	public:
		A m_iterator;

		~TConstIterator() override = default;

		TConstIterator(const A& it);
		TConstIterator() = default;
		bool AtEnd() const;
		const B& Value() const;
		void Next();
	};

	template <class T>
	class TList : public ZListBase, public IHashable
	{
	public:
		enum
		{
			INITIALSIZE = 16
		};

		class ZIterator : public ZListIteratorBase
		{
		public:
			~ZIterator() override = default;

			ZIterator(const ZIterator& other);
			ZIterator(TList* pList);
			ZIterator() = default;
			T& Value();
			TList* List();
		};

		T* m_pList;

		~TList() override = default;
		void RemoveIndex(unsigned int nIndex) override;

		unsigned int ComputeHash() const override;

		TList() = default;
		TList(unsigned int nInitialSize);
		TList& operator=(const TList& that);
		TConstIterator<ZIterator, T, int> Iterator() const;
		ZIterator Iterator();
		void Clear(unsigned int nInitialSize);
		void Append(const T* pElements, unsigned int nCount);
		T& Append(const T& element);
		const T& operator[](unsigned int nElement) const;
		T& operator[](unsigned int nElement);
		const T& ElementAt(unsigned int nElement) const;
		T& ElementAt(unsigned int nElement);
		T* AllocList(void* __formal, unsigned int nElements);
		void FreeList(void* __formal);
		void Grow(unsigned int nNewSize);
	};

	class ZString : public ZObject, public IHashable
	{
	public:
		struct InternalString
		{
			int m_nRefCount;
			unsigned int m_nLength;
			unsigned int m_nHash;
			char m_szString[0];

			unsigned int ComputeHash() const;
		};

		InternalString* m_pString;

		~ZString() override = default;

		unsigned int ComputeHash() const override;

		ZString(InternalString* pString);
		ZString(double nNumber);
		ZString(float nNumber);
		ZString(unsigned long long nNumber);
		ZString(long long nNumber);
		ZString(unsigned int nNumber);
		ZString(int nNumber);
		ZString(char nChar);
		ZString(const ZString& that);
		ZString(const char* pszString, unsigned int nLength);
		ZString(const char* pszString);
		ZString(const TList<ZString>& stringList, const ZString& sDelimiter);
		ZString(const TList<char>& charList);
		ZString() = default;
		static ZString FromUtf8(const char* pszUtf8, unsigned int nLength);
		static ZString FromUtf8(const char* pszUtf8);
		static void FOutputDebugStringList(const char* pszFormat, char* __formal);
		static void FOutputDebugString(const char* pszFormat, ...);
		static void FOutputHexDump(const void* pMem, unsigned int nSize);
		operator bool() const;
		ZString& operator=(const ZString& that);
		bool operator==(const char* pszThat) const;
		bool operator==(const ZString& that) const;
		bool operator<(const char* pszThat) const;
		bool operator<(const ZString& that) const;
		bool operator<=(const char* pszThat) const;
		bool operator<=(const ZString& that) const;
		bool EqualsCaseInsensitive(const char* that) const;
		bool EqualsCaseInsensitive(const ZString& that) const;
		bool LessThanCaseInsensitive(const char* that) const;
		bool LessThanCaseInsensitive(const ZString& that) const;
		ZString operator+(char nThat) const;
		ZString operator+(int nThat) const;
		ZString operator+(const char* pszThat) const;
		ZString operator+(const ZString& that) const;
		void operator+=(const char* pszThat);
		void operator+=(const ZString& that);
		char CharAt(unsigned int nIndex) const;
		unsigned int Count() const;
		bool Empty() const;
		int IndexOf(const ZString& InternalString, unsigned int nStartFrom) const;
		int IndexOf(char ch, unsigned int nStartFrom) const;
		int LastIndexOf(char ch) const;
		ZString Slice(unsigned int nStart) const;
		ZString Slice(unsigned int nStart, unsigned int nLength) const;
		ZString ToLower() const;
		ZString Trim() const;
		long long ToInt() const;
		double ToDouble() const;
		float ToFloat() const;
		const char* c_str() const;
		static ZString Format(const char* pszFormat, ...);
		bool StartsWith(const ZString& sStr) const;
		bool StartsWith(const char* pszStr) const;
		bool EndsWith(const ZString& sStr) const;
		bool EndsWith(const char* pszStr) const;
		void Split(TList<ZString>* pList, char nChar) const;
		bool IsNull() const;
		ZString Scramble() const;
		ZString Unscramble() const;
		void InstantiateFrom(const char* pszString, unsigned int nLength);
		void DecreaseRefCount();
		static InternalString* AllocateInternalString(unsigned int length);
	};

	template <class A, class B>
	class TPair : public ZObject
	{
	public:
		A m_First;
		B m_Second;

		~TPair() override = default;

		TPair(const TPair& that);
		TPair(const A& v1);
		TPair(const A& v1, const B& v2);
		TPair() = default;
		TPair& operator=(const TPair& that);
		A& First();
		const A& First() const;
		B& Second();
		const B& Second() const;
	};

	class __declspec(novtable) ZRedBlackTreeBase : public ZObject
	{
	public:
		enum EColour
		{
			COLOUR_RED = 0,
			COLOUR_BLACK = 1
		};

		class __declspec(novtable) ZElementBase : public ZObject
		{
		public:
			ZElementBase* m_pLeft;
			ZElementBase* m_pRight;
			EColour m_eColour;

			~ZElementBase() override = default;
			virtual void CopyValueFrom(const ZElementBase& elementBase) = 0;
			virtual ZElementBase* DeepClone() = 0;

			ZElementBase() = default;
			ZElementBase(const ZElementBase& that);
			ZElementBase& operator=(const ZElementBase& that);
			void DeepCloneFrom(const ZElementBase* pElement);
		};

		template <class T>
		class TStack : public ZObject, public IHashable
		{
		public:
			enum
			{
				STATIC_ELEMENTS = 9
			};

			unsigned int m_nFree;
			T m_staticList[9];
			TList<T>* m_pList;

			~TStack() override = default;

			unsigned int ComputeHash() const override;

			TStack() = default;
			TStack& operator=(const TStack& that);
			void Push(const T& element);
			T Pop();
			T& const Peek(unsigned int nIndex) const;
			unsigned int Count() const;
			void Clear();
		};

		class ZIteratorBase : public ZObject
		{
		public:
			ZRedBlackTreeBase* m_pList;
			ZElementBase* m_pElement;
			TStack<ZElementBase*> m_parents;

			~ZIteratorBase() override = default;

			bool AtEnd() const;
			operator bool() const;
			void Next();
			void Previous();
			void Remove();
			ZIteratorBase(ZRedBlackTreeBase* pList);
			ZIteratorBase(ZRedBlackTreeBase* pList, ZElementBase* pElement, TStack<ZElementBase*>* pParents);
			ZIteratorBase(const ZIteratorBase& other);
			ZIteratorBase() = default;
			ZIteratorBase& operator=(const ZIteratorBase& that);
			ZElementBase* Left() const;
			ZElementBase* Right() const;
			ZElementBase* Parent(int nAncestor) const;
			void MoveToFirst();
			void MoveToLast();
		};

		template <class T>
		class TElement : public ZElementBase
		{
		public:
			T m_data;

			~TElement() override = default;
			void CopyValueFrom(const ZElementBase& that) override;
			ZElementBase* DeepClone() override;

			TElement(const T& data);
			TElement() = default;
		};

		template <class T>
		class TIterator : public ZIteratorBase
		{
		public:
			~TIterator() override = default;

			TIterator(ZRedBlackTreeBase* pList);
			TIterator(ZRedBlackTreeBase* pList, ZElementBase* pElement, TStack<ZElementBase*>* pParents);
			TIterator(const TIterator& other);
			TIterator() = default;
			TIterator& operator=(const TIterator& that);
			T& Value();
		};

		ZElementBase* m_pTop;
		unsigned int m_nTotalElements;

		~ZRedBlackTreeBase() override = default;
		virtual bool ElementsEqual(const ZElementBase* elementBase, const ZElementBase* elementBase2) const = 0;
		virtual bool ElementKeysEqual(const ZElementBase* elementBase, const ZElementBase* elementBase2) const = 0;
		virtual bool ElementKeysLessThan(const ZElementBase* elementBase, const ZElementBase* elementBase2) const = 0;

		ZRedBlackTreeBase() = default;
		void Clear();
		unsigned int Count() const;
		bool IsEmpty() const;
		ZRedBlackTreeBase& operator=(const ZRedBlackTreeBase& that);
		bool operator==(const ZRedBlackTreeBase& that) const;
		bool operator!=(const ZRedBlackTreeBase& that) const;
		void DeleteFixUp(ZElementBase* pX, TStack<ZElementBase*>* pXParents);
		void InsertFixUp(ZElementBase* pZ, TStack<ZElementBase*>& zParents);
		void RotateLeft(ZElementBase* pX, ZElementBase* pXParent);
		void RotateRight(ZElementBase* pY, ZElementBase* pYParent);
		void DeleteSubTree(ZElementBase* pNode);
		void CopyFrom(const ZRedBlackTreeBase& that);
		ZElementBase* DeleteElement(ZIteratorBase* pY);
		bool FindExactElement(const ZElementBase* pElement, TStack<ZElementBase*>* pParents) const;
		TStack<ZElementBase*>* FindExactElement(const ZElementBase* pElement) const;
		TPair<ZElementBase*, TStack<ZElementBase*>*> FindKeyElement(const ZElementBase& dataElement) const;
		TPair<ZElementBase*, TStack<ZElementBase*>*> FindKeyElementLessThanOrEqual(const ZElementBase& dataElement) const;
		void InsertElement(ZElementBase* pData);
		void InsertElementSet(ZElementBase* pData);
	};

	template <class A, class B>
	class TKeyValueElement : public TPair<A, B>
	{
	public:
		~TKeyValueElement() override = default;

		TKeyValueElement(const TKeyValueElement& that);
		TKeyValueElement(const A& key);
		TKeyValueElement(const A& key, const B& value);
		TKeyValueElement() = default;
		TKeyValueElement& operator=(const TKeyValueElement& that);
		bool operator==(const TKeyValueElement& that) const;
		const A& Key() const;
		A& Key();
		B& Value();
	};

	template <class A, int B, class C>
	class TRedBlackTree : public ZRedBlackTreeBase
	{
	public:
		C m_Comparer;

		~TRedBlackTree() override = default;
		bool ElementsEqual(const ZElementBase* p1, const ZElementBase* p2) const override;
		bool ElementKeysEqual(const ZElementBase* p1, const ZElementBase* p2) const override;
		bool ElementKeysLessThan(const ZElementBase* p1, const ZElementBase* p2) const override;

		TRedBlackTree(const TRedBlackTree& that);
		TRedBlackTree() = default;
		TRedBlackTree& operator=(const TRedBlackTree& that);
		ZRedBlackTreeBase::TIterator<A> IteratorEnd();
		void Insert(const A& data);
		bool Remove(const A& data);
		ZRedBlackTreeBase::TIterator<A> Find(const A& data);
	};

	template <class T>
	class __declspec(novtable) IComparer
	{
	public:
		virtual ~IComparer() = default;
		virtual bool Equals(const T& param1, const T& const param2) const = 0;
		virtual bool LessThan(const T& param1, const T& param2) const = 0;

		IComparer() = default;
	};

	template <class T>
	class TOperatorComparer : public IComparer<T>, public ZObject
	{
	public:
		~TOperatorComparer() override = default;
		bool Equals(const T& v1, const T& v2) const override;
		bool LessThan(const T& v1, const T& v2) const override;

		TOperatorComparer() = default;
	};

	template <class A, class B, class C>
	class TKeyValueElementComparer : public TOperatorComparer<A>
	{
	public:
		~TKeyValueElementComparer() override = default;
		virtual bool Equals(const TKeyValueElement<A, B>& v1, const TKeyValueElement<A, B>& v2) const;
		virtual bool LessThan(const TKeyValueElement<ZString, ZString>& v1, const TKeyValueElement<ZString, ZString>& v2) const;

		TKeyValueElementComparer() = default;
	};

	template <class A, class B, class C>
	class TOrderedMap : public TRedBlackTree<TKeyValueElement<A, B>, 1, TKeyValueElementComparer<A, B, C>>
	{
	public:
		class ZIterator
		{
		public:
			ZRedBlackTreeBase::TIterator<TKeyValueElement<A, B>> m_iterator;

			virtual ~ZIterator() = default;

			ZIterator(const ZIterator& that);
			ZIterator(TOrderedMap < TList<TOperatorComparer<A>>* pList);
			ZIterator(const ZRedBlackTreeBase::TIterator<TKeyValueElement<A, B>>& iterator);
			ZIterator() = default;
			bool AtEnd() const;
			operator bool() const;
			void Next();
			A& Key();
			B& Value();
		};

		~TOrderedMap() override = default;

		TOrderedMap(const TOrderedMap& that);
		TOrderedMap() = default;
		TOrderedMap& operator=(const TOrderedMap& that);
		bool operator==(const TOrderedMap& that) const;
		bool operator<(const TOrderedMap& that) const;
		bool operator!=(const TOrderedMap& that) const;
		void Insert(const A& key, const B& value);
		TConstIterator<TOrderedMap<A, B, C>::ZIterator, B, A> Find(const A& key) const;
		ZIterator Find(const A& key);
		bool Remove(const A& key);
		ZIterator Iterator();
		TConstIterator<TOrderedMap<A, B, TOperatorComparer<A>>::ZIterator, B, A> Iterator() const;
	};

	class ZUrlParameters : public ZObject, public IHashable
	{
	public:
		TOrderedMap<ZString, ZString, TOperatorComparer<ZString>> m_parameters;
		TOrderedMap<ZString, TList<ZString>, TOperatorComparer<ZString>> m_arrayParameters;

		~ZUrlParameters() override = default;

		unsigned int ComputeHash() const override;

		ZUrlParameters(const ZUrlParameters& that);
		ZUrlParameters() = default;
		ZUrlParameters& operator=(const ZUrlParameters& that);
		bool operator==(const ZUrlParameters& that) const;
		bool operator!=(const ZUrlParameters& that) const;
		bool operator<(const ZUrlParameters& that) const;
		void Clear();
		void Set(const ZString& sKey, const TList<ZString>& valueList);
		void Set(const ZString& sKey, const ZString& sValue);
		void Set(const char* sKey, const char** aValue, unsigned int aSize);
		void Set(const char* sKey, const char* sValue);
		ZString Get(const ZString& sKey, const ZString& sDefaultValue) const;
		TList<ZString> GetArray(const ZString& sKey) const;
		ZString ToString() const;
		void Parse(const char* pszParams);
	};

	class ZUrl : public ZObject, public IHashable
	{
	public:
		ZString m_sProtocol;
		ZString m_sHost;
		ZString m_sFakeHost;
		ZString m_sPath;
		ZUrlParameters m_urlParameters;
		int m_nPort;
		unsigned int m_nHash;

		~ZUrl() override = default;

		unsigned int ComputeHash() const override;

		ZUrl(const ZString& sPath);
		ZUrl(const ZUrl& other);
		ZUrl() = default;
		ZUrl(const ZUrl& that, const ZString& sPath);
		operator bool() const;
		ZUrl& operator=(const ZUrl& other);
		bool operator==(const ZUrl& other) const;
		bool operator<(const ZUrl& other) const;
		const ZString& GetProtocol() const;
		const ZString& GetHost() const;
		const ZString& GetFakeHost() const;
		const ZString& GetPath() const;
		ZString GetPathAndParameters() const;
		int GetPort() const;
		void OverwriteParameters(const ZUrlParameters& params);
		void SetParameter(const ZString& sKey, const TList<ZString>& valueList);
		void SetParameter(const ZString& sKey, const ZString& sValue);
		ZString GetParameter(const ZString& sKey, const ZString& sDefaultValue) const;
		TList<ZString> GetArrayParameter(const ZString& sKey) const;
		ZString ToString(bool bIncludeFakeHost) const;
		bool IsBaseOf(const ZUrl& that) const;
		static ZUrl Parse(const ZString& sUrl);
		static ZUrl Parse(const char* pszUrl);
		static ZString UrlEncode(const ZString& sString);
		void ParseUrl(const char* pszUrl);
		void ParsePath(const char* pszUrl);
	};

	struct SCallbackData
	{
		SHttpStatus Status;
		EDownloadEvent eEvent;
		ZUrl URL;

		SCallbackData(const SCallbackData& that);
		SCallbackData() = default;
		~SCallbackData() = default;
		SCallbackData& operator=(const SCallbackData& that);
		bool Success();
		void Reset();
	};

	class ZEvent : public ZObject
	{
	public:
		void* m_event;
		bool m_bManualReset;
		~ZEvent() override = default;

		ZEvent() = default;
		ZEvent(bool bManualReset);
		ZEvent(const ZEvent& __formal);
		ZEvent& operator=(const ZEvent& __formal);
		void Signal();
		void Reset();
		void SetState(bool bSignal);
		void Wait(int nTimeout);
		bool IsSignalled() const;
	};

	class ZDoublyLinkedListBase : public ZObject
	{
	public:
		class ZElementBase : public ZObject
		{
		public:
			ZElementBase* m_pNext;
			ZElementBase* m_pPrev;

			~ZElementBase() override = default;

			ZElementBase() = default;
			ZElementBase(const ZElementBase& that);
			ZElementBase& operator=(const ZElementBase& that);
		};

		class ZIteratorBase : public ZObject
		{
		public:
			ZDoublyLinkedListBase* m_pList;
			ZElementBase* m_pElement;

			~ZIteratorBase() override = default;

			ZIteratorBase& operator=(const ZIteratorBase& that);
			void Next();
			void Previous();
			void Remove();
			bool AtEnd() const;
			operator bool() const;
			ZIteratorBase(const ZIteratorBase& that);
			ZIteratorBase(ZDoublyLinkedListBase* pList, ZElementBase* pElement);
			ZIteratorBase() = default;
			void InsertAfter(ZElementBase* pData);
			void InsertBefore(ZElementBase* pData);
		};

		ZElementBase* m_pHead;
		unsigned int m_nTotalElements;

		~ZDoublyLinkedListBase() override = default;

		ZDoublyLinkedListBase& operator=(const ZDoublyLinkedListBase& that);
		unsigned int Count() const;
		bool IsEmpty() const;
		void Clear();
		ZDoublyLinkedListBase() = default;
		void AppendElement(ZElementBase* el);
		void InsertElement(ZElementBase* el);
		void DeleteElement(ZElementBase* pElem);
		void InsertAfter(ZElementBase* tail, ZElementBase* el);
		void InsertBefore(ZElementBase* tail, ZElementBase* el);
		ZElementBase* TailElement() const;
	};

	template <class T>
	class TDoublyLinkedList : public ZDoublyLinkedListBase
	{
	public:
		class ZElement : public ZElementBase
		{
		public:
			T m_data;

			~ZElement() override = default;

			ZElement(const T& data);
		};

		class ZIterator : public ZIteratorBase
		{
		public:
			~ZIterator() override = default;

			ZIterator(TDoublyLinkedList<T>* pList, ZElement* pElement);
			ZIterator() = default;
			T& Value();
		};

		~TDoublyLinkedList() override = default;

		TDoublyLinkedList() = default;
		ZIterator Iterator();
		ZIterator IteratorEnd();
		ZElement* Insert(const T& data);
		ZIterator Find(const T& data);
		ZElement* FindElement(const T& data) const;
	};

	template <class T>
	class TDelegateList : public ZObject
	{
	public:
		TDoublyLinkedList<T> m_delegates;

		~TDelegateList() override = default;

		TDelegateList() = default;
		TDelegateList& operator+=(const T& _delegate);
		TConstIterator<TDoublyLinkedList<T>::FastDelegate1<SCallbackData*, void>, int> Iterator() const;
		void Clear();
	};

	template <class A, class B>
	class TMap : public ZObject
	{
	public:
		class ZIterator : public ZObject
		{
		public:
			TMap* m_pMap;
			int m_iCurrentHash;
			TOrderedMap<A, B, TOperatorComparer<A>>::ZIterator m_iterator;

			~ZIterator() override = default;

			ZIterator(TMap* pMap, int iHash, const TOrderedMap<A, B, TOperatorComparer<A>>::ZIterator& Iterator);
			ZIterator() = default;
			ZIterator& operator=(const ZIterator& other);
			bool AtEnd() const;
			A& Key();
			B& Value();
			void Next();
		};

		TOrderedMap<A, B, TOperatorComparer<A>>* m_pLists;
		int m_nHashSize;
		unsigned int m_nCount;

		~TMap() override = default;

		TMap() = default;
		TMap(A nHashSize);
		void Clear();
		void Insert(const A& key, const B& value);
		ZIterator Find(const A& key);
		ZIterator Iterator();
	};

	class ZJsonObject : public ZObject
	{
	public:
		TMap<ZString, ZJsonValue*> m_Pairs;

		~ZJsonObject() override = default;

		ZJsonObject(const ZJsonObject& that);
		ZJsonObject() = default;
		ZJsonObject& operator=(const ZJsonObject& that);
		ZJsonValue* Value(const ZString& sName);
		TMap<ZString, ZJsonValue*>::ZIterator PairIterator();
		bool HasPairs() const;
		void Add(const ZString& sName, ZJsonValue* vValue);
		ZJsonValue* Create(const ZString& sName);
		bool DeleteValue(const ZString& sName);
		void Clear();
	};

	class ZJsonValue : public ZObject
	{
	public:
		enum ZJsonValueType
		{
			JSONTYPE_STRING = 0,
			JSONTYPE_OBJECT = 1,
			JSONTYPE_ARRAY = 2
		};

		ZJsonValueType m_Type;
		ZString m_literal;
		TList<ZJsonValue*> m_array;
		ZJsonObject* m_object;
		bool m_quotes;
		~ZJsonValue() override = default;

		ZJsonValue(ZJsonObject* pElement);
		ZJsonValue(const ZString& sValue, bool hasQuotes);
		ZJsonValue(const ZJsonValue& that);
		ZJsonValue() = default;
		ZJsonValue& operator=(const ZJsonValue& that);
		void Add(ZJsonValue* pValue);
		ZJsonValueType Type() const;
		const ZString& GetAsString() const;
		ZString GetForSerialization() const;
		ZJsonObject* GetAsObject();
		TList<ZJsonValue*>& GetAsArray();
		void Clear();
	};

	class ZAtomBase : public ZObject
	{
	public:
		ZString m_sAuthorName;
		ZString m_sIdentifier;
		ZString m_sTitle;
		ZString m_sEditURL;
		ZString m_sBaseURL;
		bool m_bHasValidSource;
		static const int s_nClassId;

		~ZAtomBase() override = default;
		virtual bool ClassMatch(int nClassId) const;
		virtual void ParseJsonValue(const ZString& __formal, ZJsonValue* __formal1);

		void SetTitle(const ZString& sTitle);
		const ZString& Title() const;
		const ZString& AuthorName() const;
		ZUrl EditURL() const;
		ZUrl BaseURL() const;
		const ZString& Identifier() const;
		bool HasValidSource();
		ZAtomBase(const ZAtomBase& that);
		ZAtomBase(const ZString& baseUrl);
		ZAtomBase() = default;
		ZAtomBase& operator=(const ZAtomBase& that);
		ZUrl GetUrlFromString(const ZString& sUrlString) const;
		void ParseJson(ZJsonObject* pJson);
		static void Parse(ZAtomBase* pAtom, ZJsonObject* pJson);
		static int GenerateClassId();
	};

	namespace fastdelegate
	{
		namespace detail
		{
			class GenericClass
			{
			public:
				GenericClass() = default;
				~GenericClass() = default;
			};

			struct GenericVirtualClass : virtual GenericClass
			{
				GenericVirtualClass() = default;
				~GenericVirtualClass() = default;
			};

			template <class A, class B, class C>
			class ClosurePtr<void(__thiscall GenericClass::TPair<OSuite::ZString> const&), void(__cdeclTPair<OSuite::ZString> const&), void(__cdeclTPair<OSuite::ZString> const&)> : public DelegateMemento
			{
			public:
				union WarningHackMemFuncUnion
				{
					void (*fPtr)(unsigned int param1, const TPair<OSuite::ZString>& pair);
					void (*fPtrType)();
				};

				ClosurePtr() = default;
				~ClosurePtr() = default;
				GenericClass* GetClosureThis() const;
				auto GetClosureMemPtr() const -> void (*)(unsigned int param1, const TPair<OSuite::ZString>& pair);
				auto GetStaticFunction() const -> void (*)(unsigned int param1, const TPair<OSuite::ZString>& pair);
			};
		}

		template <class A, class B>
		class FastDelegate1
		{
		public:
			struct SafeBoolStruct
			{
			};

			struct UselessTypedef
			{
			};

			fastdelegate::detail::ClosurePtr<void(__thiscall fastdelegate::detail::GenericClass::*)(SCallbackData*), void(__cdecl*)(SCallbackData*), void(__cdecl*)(SCallbackData*)> m_Closure;

			~FastDelegate1() = default;
			FastDelegate1(const FastDelegate1& x);
			FastDelegate1() = default;
			void operator=(const FastDelegate1& x);
			//void operator()(SCallbackData* p1) const;
			bool empty() const;
			void clear();
		};
	}

	class __declspec(novtable) IHttpRequest : public ZObject
	{
	public:
		enum AsynchState
		{
			ASYNCHSTATE_NONE = 0,
			ASYNCHSTATE_READY = 1,
			ASYNCHSTATE_CONNECTION = 2,
			ASYNCHSTATE_CONNECTWAIT = 4,
			ASYNCHSTATE_SEND = 8,
			ASYNCHSTATE_SENDWAIT = 16,
			ASYNCHSTATE_RECEIVE = 32,
			ASYNCHSTATE_RECEIVEWAIT = 64,
			ASYNCHSTATE_WAIT = 128,
			ASYNCHSTATE_FINISHED = 256,
			ASYNCHSTATE_ABORTED = 512,
			ASYNCHSTATE_LYMBO = 1024,
			ASYNCHSTATE_SHUTDOWN = 2048
		};

		struct AsynchCallback
		{
			OSuite::fastdelegate::FastDelegate1<OSuite::IHttpRequest*, bool> m_OnStarted;
			OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, OSuite::IBufferedReader*, bool> m_OnDataAvailable;
			OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, unsigned int, bool> m_OnDataNeeded;
			OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, OSuite::ZHttp::EError, bool> m_OnFinished;
			bool m_bClientCallback;
			AsynchCallback(OSuite::fastdelegate::FastDelegate1<OSuite::IHttpRequest*, bool> onStarted, OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, OSuite::IBufferedReader*, bool> onDataAvailable, OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, unsigned int, bool> onDataNeeded, OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, OSuite::ZHttp::EError, bool> onFinished, bool bClientCallback);
			AsynchCallback() = default;
		};

		~IHttpRequest() override = default;
		virtual OSuite::fastdelegate::FastDelegate1<OSuite::IHttpRequest*, bool> GetOnStartedCB() = 0;
		virtual OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, OSuite::IBufferedReader*, bool> GetOnDataAvailableCB() = 0;
		virtual OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, unsigned int, bool> GetOnDataNeededCB() = 0;
		virtual OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest*, OSuite::ZHttp::EError, bool> GetOnFinishedCB() = 0;
		virtual void Update() = 0;
		virtual void Execute(const AsynchCallback& asynchCallback) = 0;
		virtual void Abort() = 0;
		virtual bool Ready() = 0;
		virtual bool Busy() = 0;
		virtual bool HandleResponse() = 0;
		virtual unsigned int HandleData() = 0;
		virtual bool HandleDataCompleted() = 0;
		virtual bool SendBuffer(IReader* reader) = 0;
		virtual bool SendBuffer(const void* param1, unsigned int param2) = 0;
		virtual bool SendMemoryBuffer() = 0;
		virtual bool FinishChunkedTransfer() = 0;
		virtual bool CheckAsynchState(int param1) = 0;
		virtual bool HasFatalError() const = 0;
		virtual bool IsConnected() const = 0;
		virtual bool IsConnecting() const = 0;
		virtual unsigned int ReadyToWrite() const = 0;
		virtual bool WriterEof() const = 0;
		virtual bool PendingWrite() const = 0;
		virtual AsynchState GetAsynchState() const = 0;
		virtual unsigned int GetBytesReceived() const = 0;
		virtual unsigned int GetBytesSent() const = 0;
		virtual TOrderedMap<ZString, ZString, TOperatorComparer<ZString>>& GetHeaders() = 0;
		virtual ZHttp::EError GetLastError() const = 0;
		virtual unsigned int GetLengthToSend() const = 0;
		virtual void* GetLinkedObject() = 0;
		virtual ZMemoryBufferChain& GetMemoryBuffer() = 0;
		virtual void* GetParent() const = 0;
		virtual IHttpResponse* GetResponse() = 0;
		virtual const ZUrl& GetUrl() const = 0;
		virtual bool GetRecordUsage() const = 0;
		virtual void SetAcceptType(ZString string) = 0;
		virtual void SetAsynchState(AsynchState asynchState) = 0;
		virtual void SetChunkedTransfer(bool param1) = 0;
		virtual void SetRecordUsage(bool param1) = 0;
		virtual void SetLastError(ZHttp::EError error) = 0;
		virtual void SetContentType(ZString string) = 0;
		virtual void SetLengthToSend(unsigned int param1) = 0;
		virtual void SetLinkedObject(void* param1) = 0;
		virtual void SetMethod(ZString string) = 0;
		virtual void SetUrl(ZUrl& url) = 0;
		virtual void ThrottleBandwidth(unsigned int param1) = 0;
		virtual bool Release() = 0;
		virtual bool Shutdown() = 0;
		virtual bool AssociateWithResources() = 0;
		virtual void CloseHttpRequest(bool param1) = 0;
		virtual bool IsClientCallback() const = 0;
		virtual bool InternalMakeRequest() = 0;
		virtual void BuildHeaders() = 0;

		IHttpRequest() = default;
	};

	class __declspec(novtable) ZCachedObject : public ZObject
	{
	public:
		ZEvent m_UpdatedEvent;
		TDelegateList<fastdelegate::FastDelegate1<SCallbackData*, void>> m_Callbacks;
		SCallbackData m_cbData;
		ZString m_Format;
		ZString m_HttpMethod;
		ZAtomBase* m_pAtomObject;
		ZAtomBase* m_pNewAtomObject;
		IHttpRequest* m_pHttpRequest;

		~ZCachedObject() override = default;
		virtual ZAtomBase* Read(IReader* reader) = 0;

		ZCachedObject() = default;
		ZCachedObject(const ZUrl& url, const ZString& format, const ZString& httpMethod);
		void ProcessData(IBufferedReader* pBufferedReader);
		void CallCallbacks();
		void AddCallback(const OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData*, void>& callback);
		void FetchAsync();
		void Fetch();
		void Abort();
		ZAtomBase* GetAtomObject(SCallbackData* pStatus);
		SCallbackData GetAtomObjectState() const;
		const SCallbackData& GetStatus() const;
	};

	class ZAtomCache : public ZObject
	{
	public:
		TOrderedMap<ZUrl, ZCachedObject*, TOperatorComparer<ZUrl>> m_Objects;
		ZMutex m_Mutex;

		~ZAtomCache() override = default;

		ZAtomCache() = default;
		bool GetState(const ZUrl& url, SCallbackData& pStatus);
		void Close(const ZUrl& sBaseUrl);
		void CloseObject(ZAtomBase* obj);
		void ReFetch(const ZUrl& url);
	};

	class ZWebServiceClient : public ZObject
	{
	public:
		enum EState
		{
			INIT_STATE = 0,
			READY_STATE = 1,
			ERROR_STATE = 2,
			SHUTDOWN_STATE = 3
		};

		EState m_eState;
		ZAtomCache* m_pCache;
		ZMetricAppender* m_pMetricAppender;
		ZMetricAppender* m_pUsageStatisticsMetricAppender;
		ZMetricAppender* m_pPriorityMetricAppender;
		ZUsageTracker* m_pUsageTracker;
		ZOMetadata* m_pMetadata;
		IHttpRequest* m_pProbeRequest;
		long long m_LastProbeTime;
		ZUrl m_baseUrl;
		ZMutex m_requestDelegatesMutex;
		TMap<ZString, fastdelegate::FastDelegate2<SCallbackData*, ZWebServiceClient*, void>> m_clientRequestDelegates;
		OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData*, char const*, void> m_clientProbeDelegate;

		static const char* METADATA_PATH;

		~ZWebServiceClient() override = default;

		bool Initialize(const OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData*, OSuite::ZWebServiceClient*, void>& cb);
		ZOMetadata* Metadata();
		bool ExecuteQuery(ZOQuery& query, const OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData*, OSuite::ZWebServiceClient*, void>& cb);
		ZMetricAppender* MetricAppender();
		ZMetricAppender* PriorityMetricAppender();
		bool GetRequestState(const ZUrl& url, SCallbackData& pStatus);
		bool GetRequestState(const char* path, SCallbackData& pStatus);
		void CloseRequest(ZAtomBase* obj);
		ZOEntry* CreateEntry(const char* entitySetName);
		void ReleaseEntry(ZOEntry* pEntry);
		const ZUrl& GetBaseUrl() const;
		ZString GetRelativePath(const ZUrl& url) const;
		bool ProbeAvailability(const OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData*, char const*, void>& cb);
		bool Navigate(ZOEntry* entry, const char* navigationPropertyName, const OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData*, OSuite::ZWebServiceClient*, void>& callback);
		bool Navigate(ZONavigationProperty* navigationProperty, const OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData*, OSuite::ZWebServiceClient*, void>& callback);
		void Release();
		ZWebServiceClient() = default;
		ZWebServiceClient(const ZUrl& baseUrl);
		void InternalMetadataCallback(SCallbackData* pData);
		void InternalRequestCallback(SCallbackData* pData);
		void InvokeExternalRequestCallback(SCallbackData* pData);
		void ProcessPath(ZUrl& url, ZString& path);
		void InternalProbeResultCallback(SCallbackData* pData, const char* ipAddress);
	};*/
}
