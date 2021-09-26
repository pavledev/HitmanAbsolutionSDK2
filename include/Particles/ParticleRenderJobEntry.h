#pragma once

#include "SVector3.h"
#include "SVector4.h"

struct ParticleRenderJobEntry
{
	enum ERenderJobFlagShifts
	{
		TYPE_SPRITES_SHIFT = 0,
		TYPE_SPAWNER_SHIFT = 1,
		WRAP_TILE_INDEX_SHIFT = 2,
		IGNORE_ROTATION_SHIFT = 3,
		SCREEN_ALIGNED_SHIFT = 4,
		SHARED_WS_FEEDBACK_SHIFT = 5
	};

	enum ERenderJobFlags
	{
		TYPE_SPRITES = 1,
		TYPE_SPAWNER = 2,
		WRAP_TILE_INDEX = 4,
		IGNORE_ROTATION = 8,
		SCREEN_ALIGNED = 16,
		SHARED_WS_FEEDBACK = 32
	};

	unsigned int m_nConstEa;
	unsigned int m_nConstSize;
	unsigned int m_nSpriteBufferEa;
	unsigned int m_nEmitterFeedbacksEa;
	unsigned int m_nFlags;
	unsigned int m_nNumControllers;
	unsigned int m_nTilesX;
	unsigned int m_nTilesY;
	float m_fAspect;
	float m_fScaleRange;
	float m_fScaleFactor;
	float m_fAOBending;
	unsigned int m_nShaderMask;
	unsigned int m_nIADataSize;
	unsigned int m_nIADataEa;
	unsigned int m_nNumCollisionParticles;
	SVector3 m_vPosScalePrev;
	SVector3 m_vPosBiasPrev;
	SVector4 m_vDirScaleBiasPrev;
	SVector3 m_vVecScalePrev;
	SVector3 m_vVecBiasPrev;

	ParticleRenderJobEntry() = default;
	~ParticleRenderJobEntry() = default;
	unsigned int GetType();
	bool GetWrapTileIndex();
	bool GetIgnoreRotation();
	bool GetScreenAligned();
	bool GetSharedWSFeedback();
};
