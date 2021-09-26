#pragma once

class ZSimpleModuleBase;

class ZConfiguration
{
public:
	bool m_bUseGameController;
	bool m_bDefaultInvertVertical;
	bool m_bDefaultInvertHorizontal;
	bool m_bFastTargetSelection;
	bool m_bAutoInsertHM;
	bool m_bMouseInvertVertical;
	bool m_bMouseInvertHorizontal;
	ZSimpleModuleBase* m_pModuleBase;

	ZConfiguration() = default;
	~ZConfiguration() = default;
	bool IsUsingGameController();
	bool IsInvertVertical();
	bool IsDefaultInvertVertical();
	bool IsInvertHorizontal();
	bool IsDefaultInvertHorizontal();
	bool IsFastTargetSelection();
	void SetFastTargetSelection(bool bSet);
	void CollectIniFileOptions();
	bool IsMouseInvertVertical();
	bool IsMouseInvertHorizontal();
	void SetMouseInvertVertical(bool bInvert);
	void SetMouseInvertHorizontal(bool bInvert);
};
