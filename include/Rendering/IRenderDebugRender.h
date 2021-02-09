#pragma once

#include "SDebugRenderViewport.h"
#include "SMatrix43.h"
#include "SMatrix.h"
#include "SDebugVertex.h"
#include "SMatrix44.h"
#include "TResourcePtr.h"
#include "IRenderTextureResource.h"
#include "SDebugTextBox.h"

class IRenderDebugRender
{
public:
    enum UnkEnum : __int32
    {
        DEBUG_FONT_SIZE_X = 0x8,
        DEBUG_FONT_SIZE_Y = 0x9
    };

    enum TEXTURETYPE : unsigned __int32
    {
        TEXTURE_NONE = 0x0,
        TEXTURE_FONT = 0x80000000,
        TEXTURE_MOUSE = 0x80000001,
        TEXTURE_YELLOWWARNING = 0x80000002,
        TEXTURE_REDWARNING = 0x80000003,
        TEXTURE_CRYING = 0x80000004
    };

    enum PRIMTYPE : __int32
    {
        PT_LINES = 0x0,
        PT_TRIANGLES = 0x1,
        MAX_NUM_PRIMTYPES = 0x2
    };

    virtual ~IRenderDebugRender();
    virtual void Begin(const SDebugRenderViewport*, const SMatrix43*, const SMatrix*);
    virtual void End();
    virtual void Flush(IRenderDebugRender*);
    virtual void DrawLines(const SDebugVertex*, const SMatrix44*, unsigned int, unsigned int, bool);
    virtual void DrawTriangles(const SDebugVertex*, const SMatrix44*, unsigned int, unsigned int, bool);
    virtual void SetDrawMode(unsigned int);
    virtual void SetTexture(unsigned int);
    virtual void SetTexture(void*);
    virtual void AddDebugImage(float, float, float, float, const TResourcePtr<IRenderTextureResource>*);
    virtual void DrawTextBox(const SDebugTextBox*, const char*, unsigned int);
};
