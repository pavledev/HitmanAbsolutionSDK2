#pragma once

struct SSharedEntityKnowledge;

class ZSharedKnowledgeRef
{
public:
	struct ZNull
	{
	};

	SSharedEntityKnowledge* m_pSharedEntityKnowledge;

	ZSharedKnowledgeRef(ZNull* pNull);
	ZSharedKnowledgeRef(SSharedEntityKnowledge* pKnownEntity);
	ZSharedKnowledgeRef(const ZSharedKnowledgeRef& other);
	ZSharedKnowledgeRef() = default;
	~ZSharedKnowledgeRef() = default;
	ZSharedKnowledgeRef& operator=(const ZSharedKnowledgeRef& other);
	bool operator==(const ZNull* pNull) const;
	bool operator==(const ZSharedKnowledgeRef& other) const;
	bool operator!=(const ZNull* pNull) const;
	bool operator!=(const ZSharedKnowledgeRef& other) const;
	SSharedEntityKnowledge* operator->() const;
	SSharedEntityKnowledge& operator*() const;
	bool Equals(const ZSharedKnowledgeRef& other) const;
	bool IsNull() const;
	int RefCount() const;
	void Retain();
	void Release();
	void FreeMe();
};
