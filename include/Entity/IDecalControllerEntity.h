#pragma once

#include "IComponentInterface.h"
#include "SDecalIntersectionInfo.h"
#include "SDecalCreationContext.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "SMatrix.h"

class IDecalControllerEntity : public IComponentInterface
{
public:
    virtual bool GenerateDecal(const SDecalIntersectionInfo*, SDecalCreationContext*, TEntityRef<ZSpatialEntity>, const SMatrix*);
    virtual SMatrix* GetMatrixFromRotation(SMatrix* result, const SDecalIntersectionInfo*, SDecalCreationContext*);
};
