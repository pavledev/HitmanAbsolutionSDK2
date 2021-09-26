#pragma once

#include "IComponentInterface.h"
#include "IIniFile.h"

class ZBenchmarkManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	IIniFile* m_pIniFile;
	int m_iBenchmarkOldQualityProfile;
	bool m_bReturnToMainMenu;
	float m_fBenchmarkMinFPS;
	float m_fBenchmarkMaxFPS;
	double m_fBenchmarkTotalFrametime;
	unsigned int m_fBenchmarkFrames;
	float m_fBenchmarkResultsTime;
	unsigned int m_benchmarkUpdateTotalTC;
	unsigned int m_benchmarkUpdateFrameCount;
	float m_benchmarkUpdateLastFps;
	unsigned int m_benchmarkUpdateLastFrameTC;
	int m_iBenchmarkSceneIndex;
	bool m_iBenchmarkSequencePlaying;
	bool m_bFinishedBenchmark;
	short m_iBenchmarkSequence;
	short m_iBenchmarkTextID;
	bool m_iBenchmarkTextIDMenu;
	TArray<ZString> m_aBenchmarkScenes;
	TArray<TArray<int>> m_aBenchmarkSceneCheckpoints;
	TArray<TArray<bool>> m_aBenchmarkSceneCheckpointsTriggered;

	~ZBenchmarkManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZBenchmarkManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void DialogCallback(ZGameWideUI::EDialogContext eContext, EUIDialog eDialog, ZGameWideUI::EDialogResult eResult);
	void LoadBenchmarkIni(const ZString& sFileName, TArray<unsigned char>& aBuffer);
	ZString GetBenchmarkOption(const ZString& name) const;
	bool GetBenchmarkOptionBool(const ZString& name, bool bDefault) const;
	int GetBenchmarkOptionInt(const ZString& name, int iDefault) const;
	void LoadBenchmarkSettings();
	void OnFrameUpdate(const SGameUpdateEvent& updateEvent);
	bool UpdateBenchmark(bool bQuit);
	void StartBenchmarking();
	void SetBenchmarkText(const ZString& str, bool bVisible);
	float GetBenchmarkResultsTime() const;
	void SetBenchmarkResultsTime(float fTime);
	void UpdateBenchmarkingStatistics();
	float GetBenchmarkMinFPS() const;
	float GetBenchmarkMaxFPS() const;
	float GetBenchmarkFPS() const;
	bool IsBenchmarking() const;
	bool HasFinishedBenchmark() const;
	void SetFinishedBenchmark(bool bFinished);
	void ReturnToMainMenuAfterBenchmark(bool enable);
};
