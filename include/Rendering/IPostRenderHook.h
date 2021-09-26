#pragma once

class ZRenderDevice;

class __declspec(novtable) IPostRenderHook
{
public:
	virtual void OnPostRender(ZRenderDevice* renderDevice) = 0;
	virtual ~IPostRenderHook() = default;

	IPostRenderHook() = default;
};
