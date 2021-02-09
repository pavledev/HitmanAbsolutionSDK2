#pragma once

#include "ZRuntimeResourceID.h"
#include "ZString.h"
#include "ZDynamicResourceLibrary.h"

class SHM5TransitionMovieData
{
public:
    ZRuntimeResourceID ridIntroMovie;
    float fAttenuation;
    ZString sSubtitleID;
    bool bSkipable;
    bool bLooping;
    bool bMuteCustomMusic;
    ZRuntimeResourceID ridStreamedSubtitles;
    ZDynamicResourceLibrary* m_pSubtitlesLibrary;
};
