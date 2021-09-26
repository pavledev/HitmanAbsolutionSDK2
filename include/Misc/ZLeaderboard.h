#pragma once

#include "ZDelegate.h"

class ZLeaderboardEntry;
class ZScoreComparisonData;
class ZString;
namespace OSuite {
class ZWebServiceClient;
struct SCallbackData;
}  // namespace OSuite
template <class T> class TArray;

class ZLeaderboard
{
public:
	unsigned int m_iPendingUploadScoreId;
	unsigned int m_iPendingGetScoresId;
	unsigned int m_iPendingGetScoresFilter;
	ZDelegate<void __cdecl(bool, int, TArray<ZLeaderboardEntry> const&, int)> m_fnGetScoresCallback;
	ZDelegate<void __cdecl(bool, int)> m_fnUploadScoreCallback;
	unsigned int m_iPendingGetAverageScoresId;
	ZDelegate<void __cdecl(bool, TArray<int> const&)> m_fnGetAverageScoresCallback;
	unsigned int m_iPendingGetScoreComparisonId;
	ZDelegate<void __cdecl(bool, ZScoreComparisonData const&)> m_fnGetScoreComparisonCallback;
	int m_iType;

	ZLeaderboard() = default;
	ZLeaderboard(int iType);
	~ZLeaderboard() = default;
	int GetTypeId() const;
	void UploadScore(const ZString& sId, int iScore, int iRating, ZDelegate<void __cdecl(bool, int)> cb);
	void GetScores(const ZString& sId, int iFilter, int iStart, int iRange, ZDelegate<void __cdecl(bool, int, TArray<ZLeaderboardEntry> const&, int)> cb);
	void GetAverageScores(const ZString& sId, ZDelegate<void __cdecl(bool, TArray<int> const&)> cb);
	void GetSpecialDeadliest(int iFilter, int iStart, int iRange, ZDelegate<void __cdecl(bool, int, TArray<ZLeaderboardEntry> const&, int)> cb);
	void GetSpecialRichest(int iFilter, int iStart, int iRange, ZDelegate<void __cdecl(bool, int, TArray<ZLeaderboardEntry> const&, int)> cb);
	void GetSpecialPopular(int iFilter, int iStart, int iRange, ZDelegate<void __cdecl(bool, int, TArray<ZLeaderboardEntry> const&, int)> cb);
	void GetSpecialAverageDeadliest(ZDelegate<void __cdecl(bool, TArray<int> const&)> cb);
	void GetSpecialAverageRichest(ZDelegate<void __cdecl(bool, TArray<int> const&)> cb);
	void GetSpecialAveragePopular(ZDelegate<void __cdecl(bool, TArray<int> const&)> cb);
	void GetScoreComparison(const ZString& sId, ZDelegate<void __cdecl(bool, ZScoreComparisonData const&)> cb);
	void UploadScoreCallback(unsigned int iId, OSuite::SCallbackData* pData, OSuite::ZWebServiceClient* pWebService, void* pUserData);
	void GetScoresCallback(unsigned int iId, OSuite::SCallbackData* pData, OSuite::ZWebServiceClient* pWebService, void* pUserData);
	void GetAverageScoresCallback(unsigned int iId, OSuite::SCallbackData* pData, OSuite::ZWebServiceClient* pWebService, void* pUserData);
	void GetScoreComparisonCallback(unsigned int iId, OSuite::SCallbackData* pData, OSuite::ZWebServiceClient* pWebService, void* pUserData);
	void GetScoresTranslatorCallback(int nStart, const TArray<ZString>& aGamerTags, void* pData, unsigned long dwStatus);
	void GetScoreComparisonTranslatorCallback(int nStart, const TArray<ZString>& aGamerTags, void* pData, unsigned long dwStatus);
};
