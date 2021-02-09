#pragma once

#include "ZEntityImpl.h"
#include "SMatrix.h"

class ZCameraBlendNodeInterface : public ZEntityImpl
{
public:
    virtual SMatrix* GetObjectToWorldMatrix(SMatrix* result);
    virtual float GetFieldOfView();
};
