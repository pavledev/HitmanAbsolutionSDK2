#pragma once

#include "ZRenderTexture2D.h"
#include "ZRenderTargetView.h"
#include "ERainPuddleSimulationType.h"

class ZRenderRainPuddleSimulator
{
public:
	enum ERainPuddleSimulationType
	{
		eRipple = 0,
		eRunning = 1,
		eRunningHead = 2
	};

	enum
	{
		RAIN_PUDDLE_TEXTURE_SIZE = 256
	};

	enum
	{
		RAIN_PUDDLE_TEXTURE_MIPLEVELS = 4
	};

	ZRenderTexture2D* m_pRainPuddleTexture[2];
	ZRenderShaderResourceView* m_pRainPuddleSRV[2];
	ZRenderTargetView* m_pRainPuddleRTV[2];
	ZRenderTexture2D* m_pRainPuddleNormalTexture[2];
	ZRenderShaderResourceView* m_pRainPuddleNormalSRV[2];
	ZRenderTargetView* m_pRainPuddleNormalRTV[2];
	ZRenderShaderResourceView* m_pCurrentRainPuddleNormalSRV;
	ZRenderTexture2D* m_pRainPuddleInterpolatedNormalTexture[4];
	ZRenderShaderResourceView* m_pRainPuddleInterpolatedNormalSRV[4];
	ZRenderTargetView* m_pRainPuddleInterpolatedNormalRTV[4];
	ZRenderTexture2D* m_pRainPuddleInterpolatedNormalTexture2;
	ZRenderShaderResourceView* m_pRainPuddleInterpolatedNormalSRV2;
	ZRenderTargetView* m_pRainPuddleInterpolatedNormalRTV2[4];
	ZRenderTexture2D* m_pRainPuddleNoiseMap;
	ZRenderShaderResourceView* m_pRainPuddleNoiseMapSRV;
	int m_nIndex;
	int m_nOldFrames;
	float m_fLastLerpFactor;
	int m_nRainPuddleNoiseRes;
	float m_fOldNoiseMultiplier;
	float m_fTimeMultiplier;
	float m_fHeight;
	float m_fDamping;
	float m_fDelta;
	int m_nMinStrength;
	int m_nMaxStrength;
	bool m_bInitialized;
	bool m_bIsFirstTime;
	ERainPuddleSimulationType m_eType;

	ZRenderRainPuddleSimulator() = default;
	ZRenderRainPuddleSimulator(unsigned int nType);
	~ZRenderRainPuddleSimulator() = default;
	void Init(int nRainPuddleNoiseRes);
	void Simulate(bool bClear);
	void ReallocateSeedMap(float fNoiseMultiplier, int nMinStrength, int nMaxStrength);
	void SetParameters(float fTimeMultiplier, float fNoiseMultiplier, int nMinStrength, int nMaxStrength, float fHeight, float fDamping, float fDelta);
	ZRenderShaderResourceView* GetRainPuddleNormalSRV() const;
	void InterpolateNormalMaps(float fLerpFactor);
	ZRenderShaderResourceView* DownSampleNormalMaps(ZRenderShaderResourceView* pSrc);
};
