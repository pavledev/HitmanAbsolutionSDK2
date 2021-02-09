#pragma once

#include "IComponentInterface.h"
#include "IIniFile.h"

class ZBenchmarkManager : public IComponentInterface
{
public:
    IIniFile* m_pIniFile;
    int m_iBenchmarkOldQualityProfile;
    bool m_bReturnToMainMenu;
    float m_fBenchmarkMinFPS;
    float m_fBenchmarkMaxFPS;
    long double m_fBenchmarkTotalFrametime;
    unsigned int m_fBenchmarkFrames;
    float m_fBenchmarkResultsTime;
    unsigned int m_benchmarkUpdateTotalTC;
    unsigned int m_benchmarkUpdateFrameCount;
    float m_benchmarkUpdateLastFps;
    unsigned int m_benchmarkUpdateLastFrameTC;
    int m_iBenchmarkSceneIndex;
    bool m_iBenchmarkSequencePlaying;
    bool m_bFinishedBenchmark;
    __int16 m_iBenchmarkSequence;
    __int16 m_iBenchmarkTextID;
    bool m_iBenchmarkTextIDMenu;
    TArray<ZString> m_aBenchmarkScenes;
    TArray<TArray<int>> m_aBenchmarkSceneCheckpoints;
    TArray<TArray<bool>> m_aBenchmarkSceneCheckpointsTriggered;
};
