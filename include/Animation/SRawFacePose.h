#pragma once

struct SPoseBone;
struct SQV;

struct SRawFacePose
{
	SQV* m_pBones;
	int* m_pBoneToMeshIDs;
	char* m_pName;
	short m_nCount;
	short m_nBlockCount;

	SRawFacePose() = default;
	~SRawFacePose() = default;
	static SRawFacePose* Create(const char* pName, const SPoseBone* pFirst, const int* pMeshIDs, int nCount);
	static SRawFacePose* Create(const SRawFacePose& rhs);
	static void Destroy(SRawFacePose* pRawFacePose);
	unsigned int GetMemoryRequirements() const;
	static unsigned int GetBlockSize();
	void Relocate();
};
