#pragma once

class ZHM5CamFovModifier
{
public:
	enum ECamFov
	{
		eCamFov_BlendIn1 = 0,
		eCamFov_BlendIn2 = 1,
		eCamFov_BlendOut = 2,
		eCamFov_CoolDown = 3,
		eCamFov_Num = 4
	};

	float m_fStateTime;
	float m_fFovOffset1;
	float m_fFovOffset2;
	float m_afStateTimes[4];
	ECamFov m_eState;

	ZHM5CamFovModifier() = default;
	~ZHM5CamFovModifier() = default;
	void Activate(float fFov1Max, float fFov1Min, float fFov2Max, float fFov2Min, float fBlendIn1, float fBlendIn2, float fBlendOut, float fCoolDown);
	float Update(const float fDeltaTime);
	void Reset();
};
