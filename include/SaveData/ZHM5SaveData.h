#pragma once

#include "SChallengeData.h"
#include "SUIOptionsData.h"
#include "SRatingData.h"
#include "SRatingHighScoreData.h"
#include "SContractSaveData.h"
#include "SLevelProgressionData.h"
#include "SCheatData.h"
#include "STechniquesSaveData.h"
#include "SGameStatsSaveData.h"
#include "SMiscSaveData.h"
#include "TArray.h"

struct SDLCItemSaveData;
struct SFireArmKitSaveData;
struct SLevelCPProgressionData;
struct SLevelSaveData;
struct SOutfitKitSaveData;
struct SPropKitSaveData;

class ZHM5SaveData
{
public:
	unsigned int m_nVersion;
	SChallengeData m_ChallengeData;
	SUIOptionsData m_UIOptionsData;
	SRatingData m_RatingData;
	SRatingHighScoreData m_RatingHighScoreData;
	SContractSaveData m_ContractsData;
	SLevelProgressionData m_LevelProgression;
	TArray<SFireArmKitSaveData> m_FireArmContentKits;
	TArray<SOutfitKitSaveData> m_OutfitContentKits;
	TArray<SPropKitSaveData> m_PropContentKits;
	TArray<SLevelSaveData> m_Levels;
	SCheatData m_Cheats;
	STechniquesSaveData m_Techniques;
	SGameStatsSaveData m_GameStats;
	TArray<SDLCItemSaveData> m_DLCData;
	SMiscSaveData m_MiscData;
	TArray<SLevelCPProgressionData> m_LevelCPProgression;

	static void RegisterType();
	ZHM5SaveData(const ZHM5SaveData& __that);
	ZHM5SaveData() = default;
	void GetFromBuffer(TArray<unsigned char>& buffer);
	void ToBuffer(TArray<unsigned char>& buffer);
	unsigned int GetCurrentVersion() const;
	~ZHM5SaveData() = default;
	ZHM5SaveData& operator=(const ZHM5SaveData& __that);
};
