#pragma once

struct SRenderDrawMode
{
	bool m_bDisableShadow;
	bool m_bWireFrameOverlay;
	bool m_bOcclusionOverlay;

	SRenderDrawMode() = default;
	~SRenderDrawMode() = default;
};
