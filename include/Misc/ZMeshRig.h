#pragma once

#include "TArrayRef.h"

struct SQV;

struct ZMeshRig
{
	TArrayRef<int> m_meshIDToRigID;
	TArrayRef<int> m_meshHierarchy;
	TArrayRef<SQV const> m_meshBindPose;
	TArrayRef<unsigned short> m_globalIDToMeshID;
	TArrayRef<SQV> m_aObjectSpaceToBindPoseSpace;
	TArrayRef<SQV> m_aBindPoseSpaceToObjectSpace;

	ZMeshRig(const ZMeshRig& __that);
	ZMeshRig() = default;
	~ZMeshRig() = default;
};
