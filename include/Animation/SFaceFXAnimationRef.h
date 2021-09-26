#pragma once

#include "TResourcePtr.h"
#include "ZString.h"

class ZRuntimeResourceID;
namespace OC3Ent {
namespace Face {
class FxAnimSet;
}  // namespace Face
}  // namespace OC3Ent

struct SFaceFXAnimationRef
{
	TResourcePtr<OC3Ent::Face::FxAnimSet> m_AnimationSetResource;
	ZString m_sAnimationName;

	SFaceFXAnimationRef(ZRuntimeResourceID animationSetResourceID, const ZString& sAnimationName);
	SFaceFXAnimationRef(const SFaceFXAnimationRef& rhs);
	SFaceFXAnimationRef() = default;
	~SFaceFXAnimationRef() = default;
	void OnResourceChanged(const ZRuntimeResourceID& id);
	SFaceFXAnimationRef& operator=(const SFaceFXAnimationRef& __that);
};
