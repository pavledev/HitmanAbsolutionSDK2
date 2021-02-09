#pragma once

#include "GFxResource.h"
#include "GFxStateBag.h"
#include "HeapDesc.h"
#include "GFxResourceId.h"

class GFxMovieDef : public GFxResource, public GFxStateBag
{
public:
    enum VisitResourceMask : __int32
    {
        ResVisit_NestedMovies = 0x8000,
        ResVisit_Fonts = 0x1,
        ResVisit_Bitmaps = 0x2,
        ResVisit_GradientImages = 0x4,
        ResVisit_EditTextFields = 0x8,
        ResVisit_Sounds = 0x10,
        ResVisit_Sprite = 0x20,
        ResVisit_AllLocalImages = 0x6,
        ResVisit_AllImages = 0x8006
    };

    enum FileAttrFlags : __int32
    {
        FileAttr_UseNetwork = 0x1,
        FileAttr_HasMetadata = 0x10,
    };

    class MemoryContext : public GRefCountBase<GFxMovieDef::MemoryContext, 2>
    {

    };

    class MemoryParams
    {
    public:
        HeapDesc Desc;
        float HeapLimitMultiplier;
        unsigned int MaxCollectionRoots;
        unsigned int FramesBetweenCollections;
    };

    class ImportVisitor
    {
    public:
        virtual ~ImportVisitor();
        virtual void Visit(GFxMovieDef*, GFxMovieDef*, const char*);
    };

    class ResourceVisitor : public GFxFileConstants
    {
    public:
        virtual ~ResourceVisitor();
        virtual void Visit(GFxMovieDef*, GFxResource*, GFxResourceId, const char*);
    };
};
