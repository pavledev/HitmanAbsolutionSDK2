#pragma once

#include "GFxResource.h"
#include "GFxStateBag.h"
#include "GRect.h"
#include "GMemoryHeap.h"
#include "GFxFileConstants.h"
#include "GRefCountBase.h"

struct GFxExporterInfo;
class GFxMovieView;
class GFxResourceId;

class __declspec(novtable) GFxMovieDef : public GFxResource, public GFxStateBag
{
public:
	enum FileAttrFlags
	{
		FileAttr_UseNetwork = 1,
		FileAttr_HasMetadata = 16
	};

	enum VisitResourceMask
	{
		ResVisit_NestedMovies = 32768,
		ResVisit_Fonts = 1,
		ResVisit_Bitmaps = 2,
		ResVisit_GradientImages = 4,
		ResVisit_EditTextFields = 8,
		ResVisit_Sounds = 16,
		ResVisit_Sprite = 32,
		ResVisit_AllLocalImages = 6,
		ResVisit_AllImages = 32774
	};

	struct MemoryParams
	{
		GMemoryHeap::HeapDesc Desc;
		float HeapLimitMultiplier;
		unsigned int MaxCollectionRoots;
		unsigned int FramesBetweenCollections;

		MemoryParams(unsigned int memoryArena);
	};

	class MemoryContext : public GRefCountBase<MemoryContext, 2>
	{
	public:
		~MemoryContext() override = default;

		MemoryContext() = default;
	};

	struct __declspec(novtable) ImportVisitor
	{
		virtual ~ImportVisitor() = default;
		virtual void Visit(GFxMovieDef* fxMovieDef, GFxMovieDef* fxMovieDef2, const char* param3) = 0;

		ImportVisitor() = default;
	};

	struct __declspec(novtable) ResourceVisitor : GFxFileConstants
	{
		virtual ~ResourceVisitor() = default;
		virtual void Visit(GFxMovieDef* fxMovieDef, GFxResource* fxResource, GFxResourceId fxResourceId, const char* param4) = 0;

		ResourceVisitor() = default;
	};

	~GFxMovieDef() override = default;
	virtual unsigned int GetVersion() const = 0;
	virtual unsigned int GetLoadingFrame() const = 0;
	virtual float GetWidth() const = 0;
	virtual float GetHeight() const = 0;
	virtual unsigned int GetFrameCount() const = 0;
	virtual float GetFrameRate() const = 0;
	virtual GRect<float> GetFrameRect() const = 0;
	virtual unsigned int GetSWFFlags() const = 0;
	virtual const char* GetFileURL() const = 0;
	virtual void WaitForLoadFinish(bool param1) const = 0;
	virtual void WaitForFrame(unsigned int param1) const = 0;
	virtual unsigned int GetFileAttributesW() const = 0;
	virtual unsigned int GetMetadata(char* param1, unsigned int param2) const = 0;
	virtual GMemoryHeap* GetLoadDataHeap() const = 0;
	virtual GMemoryHeap* GetBindDataHeap() const = 0;
	virtual GMemoryHeap* GetImageHeap() const = 0;
	virtual GFxResource* GetMovieDataResource() const = 0;
	virtual const GFxExporterInfo* GetExporterInfo() const = 0;
	virtual MemoryContext* CreateMemoryContext(const char* param1, const MemoryParams& memoryParams, bool param3) = 0;
	virtual GFxMovieView* CreateInstance(MemoryContext* memoryContext, bool param2) = 0;
	virtual GFxMovieView* CreateInstance(const MemoryParams& memoryParams, bool param2) = 0;
	virtual void VisitImportedMovies(ImportVisitor* importVisitor) = 0;
	virtual void VisitResources(ResourceVisitor* resourceVisitor, unsigned int param2) = 0;
	virtual GFxResource* GetResource(const char* param1) const = 0;

	GFxMovieView* CreateInstance(bool initFirstFrame, unsigned int memoryArena);
	GFxMovieDef() = default;
};
