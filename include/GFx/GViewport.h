#pragma once

class GViewport
{
public:
	enum
	{
		View_IsRenderTexture = 1,
		View_AlphaComposite = 2,
		View_UseScissorRect = 4,
		View_NoSetState = 8,
		View_RenderTextureAlpha = 3
	};

	int BufferWidth;
	int BufferHeight;
	int Left;
	int Top;
	int Width;
	int Height;
	int ScissorLeft;
	int ScissorTop;
	int ScissorWidth;
	int ScissorHeight;
	float Scale;
	float AspectRatio;
	unsigned int Flags;

	GViewport() = default;
	~GViewport() = default;
};
