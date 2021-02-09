#pragma once

#include "IComponentInterface.h"
#include "SMatrix.h"
#include "ZCollisionLayerColorGetter.h"

class ICollisionShape : public IComponentInterface
{
public:
    virtual void ApplyLocalTransformation(const SMatrix*);
    virtual void SetLocalTransformation(const SMatrix*);
    virtual void GetLocalTransformation(SMatrix*);
    virtual void DrawShape(const SMatrix*, const ZCollisionLayerColorGetter*, struct ZDebugRender*, const bool);
    virtual void DrawSubShape(const unsigned int, const SMatrix*, const ZCollisionLayerColorGetter*, struct ZDebugRender*, const bool);
    virtual void DrawCCDGeometry(const SMatrix*, ECCDUsage, struct ZDebugRender*);
    virtual bool IsCapsuleShape();
    virtual bool CanBeStatic();
    virtual bool CanBeDynamic();
    virtual unsigned int GetNumSubShapes();
    virtual unsigned __int16 GetDefaultCollisionLayer();
};
