#pragma once

#include "TEntityRef.h"

class ZSpatialEntity;

struct SBoneAttachment
{
	unsigned int m_nBoneID;
	TEntityRef<ZSpatialEntity> m_Attachment;

	SBoneAttachment() = default;
	SBoneAttachment(const SBoneAttachment& __that);
	SBoneAttachment(unsigned int nBoneID, TEntityRef<ZSpatialEntity> Attachment);
	bool operator==(const SBoneAttachment& rhs);
	~SBoneAttachment() = default;
	SBoneAttachment& operator=(const SBoneAttachment& __that);
};
