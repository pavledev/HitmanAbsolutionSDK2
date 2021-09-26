#pragma once

class IRenderTextureResource;
struct SDebugRenderViewport;
struct SDebugTextBox;
struct SDebugVertex;
struct SMatrix43;
struct SMatrix44;
struct SMatrix;
template <class T> class TResourcePtr;

class __declspec(novtable) IRenderDebugRender
{
public:
	enum
	{
		DEBUG_FONT_SIZE_X = 8,
		DEBUG_FONT_SIZE_Y = 9
	};

	enum TEXTURETYPE
	{
		TEXTURE_NONE = 0,
		TEXTURE_FONT = 2147483648,
		TEXTURE_MOUSE = 2147483649,
		TEXTURE_YELLOWWARNING = 2147483650,
		TEXTURE_REDWARNING = 2147483651,
		TEXTURE_CRYING = 2147483652
	};

	enum PRIMTYPE
	{
		PT_LINES = 0,
		PT_TRIANGLES = 1,
		MAX_NUM_PRIMTYPES = 2
	};

	enum
	{
		MAX_NUM_VERTICES = 512
	};

	virtual ~IRenderDebugRender() = default;
	virtual void Begin(const SDebugRenderViewport& debugRenderViewport, const SMatrix43& matrix43, const SMatrix& matrix) = 0;
	virtual void End() = 0;
	virtual void Flush(IRenderDebugRender* renderDebugRender) = 0;
	virtual void DrawLines(const SDebugVertex* debugVertex, const SMatrix44* matrix44, unsigned int param3, unsigned int param4, bool param5) = 0;
	virtual void DrawTriangles(const SDebugVertex* debugVertex, const SMatrix44* matrix44, unsigned int param3, unsigned int param4, bool param5) = 0;
	virtual void SetDrawMode(unsigned int param1) = 0;
	virtual void SetTexture(unsigned int param1) = 0;
	virtual void SetTexture(void* param1) = 0;
	virtual void AddDebugImage(float param1, float param2, float param3, float param4, const TResourcePtr<IRenderTextureResource>& resourcePtr) = 0;
	virtual void DrawTextBox(const SDebugTextBox& debugTextBox, const char* param2, unsigned int param3) = 0;

	IRenderDebugRender() = default;
};
