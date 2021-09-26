#pragma once

class ZAnimationBoneData;
class ZAnimationBonePose;
struct SBoneAnimatorInfo;
struct SMatrix;
struct float4;

class __declspec(novtable) IBoneAnimator
{
public:
	virtual ~IBoneAnimator() = default;
	virtual void UpdateBones(const ZAnimationBoneData* animationBoneData, ZAnimationBonePose* animationBonePose, const SMatrix& matrix, const SMatrix* matrix4) = 0;
	virtual bool TryCalculateBounds(float4& param1, float4& param2, const float4& param3, const float4& param4, const ZAnimationBoneData* animationBoneData) const = 0;
	virtual void SetBoneAnimatorInfo(const SBoneAnimatorInfo& boneAnimatorInfo) = 0;

	static void RegisterType();
	IBoneAnimator() = default;
};
