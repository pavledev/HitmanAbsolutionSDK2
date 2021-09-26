#pragma once

class ZGridSearchIterator;
struct STypeID;

class __declspec(novtable) ZGridJob
{
public:
	enum EPriority
	{
		NORMAL = 0,
		HIGH = 1
	};

	int m_nRefCount;
	bool m_bCompleted;
	EPriority m_priority;
	STypeID* m_resultType;

	virtual ~ZGridJob() = default;
	virtual bool OnUpdate(ZGridSearchIterator& gridSearchIterator, bool param2) = 0;
	virtual const void* OnGetResult() const = 0;

	ZGridJob() = default;
	ZGridJob(const ZGridJob& __that);
	ZGridJob(STypeID* resultType);
	int GetRefCount() const;
	void AddRef();
	void Release();
	bool IsCompleted() const;
	EPriority GetPriority() const;
	void SetPriority(EPriority priority);
	bool Update(ZGridSearchIterator& iterator, bool bFirstUpdate);
	ZGridJob& operator=(const ZGridJob& __that);
};
