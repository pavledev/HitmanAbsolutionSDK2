#pragma once

struct SQV;
template <class A, class B, class C> class THashMap;
template <class A, class B> class TDefaultHashMapPolicy;
template <class T> class TArrayRef;

class ZAimBuffer
{
public:
	SQV* m_qvBones;
	int* m_nBoneIDMap;
	bool m_bMapped;
	unsigned int m_nSize;
	bool m_bAimWasMirrored;

	ZAimBuffer() = default;
	~ZAimBuffer() = default;
	void Reset();
	void ResetBones();
	bool MapBones(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& charboneMap);
	void StoreBonesFromBoneCache(TArrayRef<SQV> BoneCache);
	void BlendBonesToBoneCache(TArrayRef<SQV> BoneCache, float fWeight);
	bool IsBonesMapped();
	void ResetBonesMapped();
};
