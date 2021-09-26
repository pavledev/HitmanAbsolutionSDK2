#pragma once

struct SRawFacePose;
template <class A, class B> class TMap;

struct SRawFacePoseCollection
{
	struct SFacePoseDescriptor
	{
		unsigned int m_uid;
		SRawFacePose* m_pRawFacePose;
		unsigned short m_nBlockCount;
	};

	SFacePoseDescriptor* m_pCollection;
	int* m_pFaceBonesIndexes;
	unsigned short m_nCollectionSize;
	unsigned short m_nNumFaceBones;
	unsigned short m_nBlockCount;

	SRawFacePoseCollection() = default;
	~SRawFacePoseCollection() = default;
	static SRawFacePoseCollection* Create(const TMap<unsigned int, SRawFacePose*>& facePoseMap, const int* pBoneIDs, int nBoneCount);
	static SRawFacePoseCollection* Create(const SRawFacePoseCollection& facePoseCollection);
	static void Destroy(SRawFacePoseCollection* pFacePoseCollection);
	const SFacePoseDescriptor* GetFacePose(unsigned int nUid) const;
	const SFacePoseDescriptor* GetFacePose(const char* pName) const;
	unsigned int GetMemoryRequirements() const;
	static unsigned int GetBlockSize();
	void Relocate();
};
