#pragma once

#include "GRefCountBase.h"
#include "GTexture.h"
#include "GMatrix2D.h"
#include "GColor.h"
#include "GList.h"
#include "GRendererEventHandler.h"
#include "GRenderTarget.h"
#include "GViewport.h"
#include "GStatBag.h"

class __declspec(novtable) GRenderer : public GRefCountBase<GRenderer, 65>
{
public:
	enum BlendType
	{
		Blend_None = 0,
		Blend_Normal = 1,
		Blend_Layer = 2,
		Blend_Multiply = 3,
		Blend_Screen = 4,
		Blend_Lighten = 5,
		Blend_Darken = 6,
		Blend_Difference = 7,
		Blend_Add = 8,
		Blend_Subtract = 9,
		Blend_Invert = 10,
		Blend_Alpha = 11,
		Blend_Erase = 12,
		Blend_Overlay = 13,
		Blend_HardLight = 14
	};

	enum ResizeImageType
	{
		ResizeRgbToRgb = 0,
		ResizeRgbaToRgba = 1,
		ResizeRgbToRgba = 2,
		ResizeGray = 3
	};

	enum VertexFormat
	{
		Vertex_None = 0,
		Vertex_XY16i = 1,
		Vertex_XY32f = 2,
		Vertex_XY16iC32 = 3,
		Vertex_XY16iCF32 = 4
	};

	enum IndexFormat
	{
		Index_None = 0,
		Index_16 = 1,
		Index_32 = 2
	};

	enum RenderCapBits
	{
		Cap_CacheDataUse = 1,
		Cap_Index16 = 4,
		Cap_Index32 = 8,
		Cap_RenderStats = 16,
		Cap_FillGouraud = 256,
		Cap_FillGouraudTex = 512,
		Cap_CxformAdd = 4096,
		Cap_NestedMasks = 8192,
		Cap_TexNonPower2 = 16384,
		Cap_TexNonPower2Wrap = 32768,
		Cap_TexNonPower2Mip = 524288,
		Cap_CanLoseData = 65536,
		Cap_KeepVertexData = 131072,
		Cap_NoTexOverwrite = 262144,
		Cap_ThreadedTextureCreation = 1048576,
		Cap_RenderTargets = 32,
		Cap_RenderTargetPrePass = 64,
		Cap_RenderTargetNonPow2 = 128,
		Cap_RenderTargetMip = 2097152,
		Cap_Filter_Blurs = 4194304,
		Cap_Filter_ColorMatrix = 8388608
	};

	enum StereoDisplay
	{
		StereoCenter = 0,
		StereoLeft = 1,
		StereoRight = 2
	};

	enum CachedDataType
	{
		Cached_Vertex = 1,
		Cached_Index = 2,
		Cached_BitmapList = 3
	};

	enum UserDataPropertyFlag
	{
		UD_None = 0,
		UD_HasString = 1,
		UD_HasFloat = 2,
		UD_HasMatrix = 3
	};

	enum BitmapWrapMode
	{
		Wrap_Repeat = 0,
		Wrap_Clamp = 1
	};

	enum BitmapSampleMode
	{
		Sample_Point = 0,
		Sample_Linear = 1
	};

	enum GouraudFillType
	{
		GFill_Color = 0,
		GFill_1Texture = 1,
		GFill_1TextureColor = 2,
		GFill_2Texture = 3,
		GFill_2TextureColor = 4,
		GFill_3Texture = 5
	};

	enum SubmitMaskMode
	{
		Mask_Clear = 0,
		Mask_Increment = 1,
		Mask_Decrement = 2
	};

	enum FilterModes
	{
		Filter_Blur = 1,
		Filter_Shadow = 2,
		Filter_Highlight = 4,
		Filter_Knockout = 256,
		Filter_Inner = 512,
		Filter_HideObject = 1024,
		Filter_UserModes = 65535,
		Filter_SkipLastPass = 65536,
		Filter_LastPassOnly = 131072
	};

	enum FilterSupport
	{
		FilterSupport_None = 0,
		FilterSupport_Ok = 1,
		FilterSupport_Multipass = 2,
		FilterSupport_Slow = 4
	};

	struct StereoParams
	{
		float DisplayWidthCm;
		float Distortion;
		float DisplayDiagInches;
		float DisplayAspectRatio;
		float EyeSeparationCm;

		StereoParams() = default;
	};

	struct RenderCaps
	{
		unsigned long CapBits;
		unsigned long VertexFormats;
		unsigned long BlendModes;
		unsigned long MaxTextureSize;
	};

	class Stats
	{
	public:
		unsigned int Triangles;
		unsigned int Lines;
		unsigned int Primitives;
		unsigned int Masks;
		unsigned int Filters;

		Stats() = default;
	};

	class CachedData
	{
	public:
		GRenderer* pRenderer;
		void* hData;

		CachedData() = default;
		~CachedData() = default;
	};

	class CacheProvider
	{
	public:
		CachedData* pData;
		bool DiscardSharedData;

		~CacheProvider() = default;
	};

	class Cxform
	{
	public:
		float M_[4][2];

		static Cxform Identity;

		Cxform() = default;
	};

	struct UserData
	{
		const char* pString;
		float* pFloat;
		float* pMatrix;
		unsigned int MatrixSize;
		unsigned char PropFlags;

		UserData() = default;
	};

	struct FillTexture
	{
		GTexture* pTexture;
		GMatrix2D TextureMatrix;
		BitmapWrapMode WrapMode;
		BitmapSampleMode SampleMode;

		FillTexture() = default;
	};

	struct VertexXY16i
	{
		short x;
		short y;
	};

	struct VertexXY16iC32
	{
		enum
		{
			VFormat = 3
		};

		short x;
		short y;
		unsigned long Color;
	};

	struct VertexXY16iCF32
	{
		enum
		{
			VFormat = 4
		};

		short x;
		short y;
		unsigned long Color;
		unsigned long Factors;
	};

	struct BitmapDesc
	{
		GRect<float> Coords;
		GRect<float> TextureCoords;
		GColor Color;

		BitmapDesc() = default;
	};

	struct DistanceFieldParams
	{
		float Width;
		float ShadowWidth;
		GColor ShadowColor;
		GPoint<float> ShadowOffset;
		GColor GlowColor;
		float GlowSize[4];

		DistanceFieldParams() = default;
	};

	struct BlurFilterParams
	{
		unsigned int Mode;
		float BlurX;
		float BlurY;
		unsigned int Passes;
		GPoint<float> Offset;
		GColor Color;
		GColor Color2;
		float Strength;
		Cxform cxform;

		BlurFilterParams() = default;
	};

	GList<GRendererEventHandler> Handlers;

	~GRenderer() override = default;
	virtual bool GetRenderCaps(RenderCaps* renderCaps) = 0;
	virtual GTexture* CreateTexture() = 0;
	virtual GTexture* CreateTextureYUV() = 0;
	virtual GRenderTarget* CreateRenderTarget() = 0;
	virtual void SetDisplayRenderTarget(GRenderTarget* renderTarget, bool param2) = 0;
	virtual void PushRenderTarget(const GRect<float>& rect, GRenderTarget* renderTarget) = 0;
	virtual void PopRenderTarget() = 0;
	virtual GTexture* PushTempRenderTarget(const GRect<float>& rect, unsigned int param2, unsigned int param3, bool param4) = 0;
	virtual void BeginDisplay(GColor color, const GViewport& viewport, float param3, float param4, float param5, float param6) = 0;
	virtual void EndDisplay() = 0;
	virtual void SetMatrix(const GMatrix2D& matrix2D) = 0;
	virtual void SetUserMatrix(const GMatrix2D& matrix2D) = 0;
	virtual void SetCxform(const Cxform& cxform) = 0;
	virtual void PushBlendMode(BlendType blendType) = 0;
	virtual void PopBlendMode() = 0;
	virtual void SetVertexData(const void* param1, int param2, VertexFormat vertexFormat, CacheProvider* cacheProvider) = 0;
	virtual void SetIndexData(const void* param1, int param2, IndexFormat indexFormat, CacheProvider* cacheProvider) = 0;
	virtual void ReleaseCachedData(CachedData* cachedData, CachedDataType cachedDataType) = 0;
	virtual void DrawIndexedTriList(int param1, int param2, int param3, int param4, int param5) = 0;
	virtual void DrawLineStrip(int param1, int param2) = 0;
	virtual void LineStyleDisable() = 0;
	virtual void LineStyleColor(GColor color) = 0;
	virtual void FillStyleDisable() = 0;
	virtual void FillStyleColor(GColor color) = 0;
	virtual void FillStyleBitmap(const FillTexture* fillTexture) = 0;
	virtual void FillStyleGouraud(GouraudFillType gouraudFillType, const FillTexture* fillTexture, const FillTexture* fillTexture3, const FillTexture* fillTexture4) = 0;
	virtual void DrawBitmaps(BitmapDesc* bitmapDesc, int param2, int param3, int param4, const GTexture* texture, const GMatrix2D& matrix2D, CacheProvider* cacheProvider) = 0;
	virtual void BeginSubmitMask(SubmitMaskMode submitMaskMode) = 0;
	virtual void EndSubmitMask() = 0;
	virtual void DisableMask() = 0;
	virtual unsigned int CheckFilterSupport(const BlurFilterParams& blurFilterParams) = 0;
	virtual void DrawBlurRect(GTexture* texture, const GRect<float>& rect, const GRect<float>& rect3, const BlurFilterParams& blurFilterParams) = 0;
	virtual void DrawColorMatrixRect(GTexture* texture, const GRect<float>& rect, const GRect<float>& rect3, const float* param4) = 0;
	virtual void GetRenderStats(Stats* stats, bool param2) = 0;
	virtual void GetStats(GStatBag* statBag, bool param2) = 0;
	virtual void ReleaseResources() = 0;

	GRenderer() = default;
};
