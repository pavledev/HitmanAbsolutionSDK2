#pragma once

#include "ZRuntimeResourceID.h"
#include "ZString.h"

class ZDynamicResourceLibrary;

struct SHM5TransitionMovieData
{
	ZRuntimeResourceID ridIntroMovie;
	float fAttenuation;
	ZString sSubtitleID;
	bool bSkipable;
	bool bLooping;
	bool bMuteCustomMusic;
	ZRuntimeResourceID ridStreamedSubtitles;
	ZDynamicResourceLibrary* m_pSubtitlesLibrary;

	SHM5TransitionMovieData(const SHM5TransitionMovieData& __that);
	SHM5TransitionMovieData() = default;
	~SHM5TransitionMovieData() = default;
	SHM5TransitionMovieData& operator=(const SHM5TransitionMovieData& __that);
};
