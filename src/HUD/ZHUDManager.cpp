#include "ZHUDManager.h"
#include "Function.h"
#include "BaseAddresses.h"

ZAttentionHUD* ZHUDManager::GetAttentionHUD()
{
	return Function::CallMethodAndReturn<ZAttentionHUD*, ZHUDManager*>(BaseAddresses::hitman5Dll + 0xC83D0, this);
}

bool ZHUDManager::ShouldCutsceneStop()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x1605D0, this);
}

ZHUDMenuSystem* ZHUDManager::GetMenuSystem()
{
	return Function::CallMethodAndReturn<ZHUDMenuSystem*, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x1F3F10, this);
}

bool ZHUDManager::IsNotebookActive()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x34B0B0, this);
}

bool ZHUDManager::IsPauseMenuActive()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x558CF0, this);
}

ZUIButtonMapper_Windows* ZHUDManager::GetButtonMapper()
{
	return Function::CallMethodAndReturn<ZUIButtonMapper_Windows*, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x558D00, this);
}

bool ZHUDManager::IsNotebookOff()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x558F70, this);
}

bool ZHUDManager::IsNotebookWaitingForDisguiseRelease()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x558F80, this);
}

unsigned __int16 ZHUDManager::GetNotbookState()
{
	return Function::CallMethodAndReturn<unsigned __int16, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x558FA0, this);
}

void ZHUDManager::CallHUD(ZString* sFunction, ZVariant* arg0)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZVariant*>(BaseAddresses::hitman5Dll + 0x558FB0, this, sFunction, arg0);
}

void ZHUDManager::UpdateWaitForAsyncSaveState()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x559080, this);
}

void ZHUDManager::ShowScoreComparison(ZString sId)
{
	Function::CallMethod<ZHUDManager*, ZString>(BaseAddresses::hitman5Dll + 0x559150, this, sId);
}

void ZHUDManager::InitMenuMovieClip()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x559180, this);
}

void ZHUDManager::DisplayCustomButton(EControllerButton nButton, ZString* sButtonText, bool bShow)
{
	Function::CallMethod<ZHUDManager*, EControllerButton, ZString*, bool>(BaseAddresses::hitman5Dll + 0x5591D0, this, nButton, sButtonText, bShow);
}

void ZHUDManager::SetupMenu()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5591E0, this);
}

void ZHUDManager::ShutdownMenu()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x559200, this);
}

void ZHUDManager::MenuAction(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559240, params);
}

void ZHUDManager::PCEvent(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559260, params);
}

void ZHUDManager::StopRumble()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x559280, this);
}

void ZHUDManager::HideLevelCompleteScreen()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5592E0, this);
}

void ZHUDManager::SetNotebookPage(EMenuId ePageId, int nItemId)
{
	Function::CallMethod<ZHUDManager*, EMenuId, int>(BaseAddresses::hitman5Dll + 0x559340, this, ePageId, nItemId);
}

void ZHUDManager::SetCrossHair(ECrossHairType eCrossHair)
{
	Function::CallMethod<ZHUDManager*, ECrossHairType>(BaseAddresses::hitman5Dll + 0x559360, this, eCrossHair);
}

void ZHUDManager::FocusCrossHair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x559380, this);
}

void ZHUDManager::UnfocusCrossHair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5593A0, this);
}

void ZHUDManager::SetFocusTargetCrossHair(bool bOnTarget)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x5593C0, this, bOnTarget);
}

void ZHUDManager::ShootCrossHair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5593D0, this);
}

void ZHUDManager::SetDisguiseHealth(float fDisguiseLevel)
{
	Function::CallMethod<ZHUDManager*, float>(BaseAddresses::hitman5Dll + 0x5593E0, this, fDisguiseLevel);
}

void ZHUDManager::ClearDisguise()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x559420, this);
}

ZString* ZHUDManager::GetText(ZString* result, EUIText nTextId)
{
	return Function::CallMethodAndReturn<ZString*, ZHUDManager*, ZString*, EUIText>(BaseAddresses::hitman5Dll + 0x559430, this, result, nTextId);
}

void ZHUDManager::TriggerSoundEvent(ZString* sPin, ZVariantRef* data)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZVariantRef*>(BaseAddresses::hitman5Dll + 0x559460, this, sPin, data);
}

void ZHUDManager::SoundEvent(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559480, params);
}

void ZHUDManager::HUDEvent(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559520, params);
}

void ZHUDManager::GetFriendsList(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559560, params);
}

void ZHUDManager::GetUserWalletAmount(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559570, params);
}

void ZHUDManager::UpdateLikesDislikes(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559580, params);
}

void ZHUDManager::LeaderboardGetScores(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x5595E0, params);
}

void ZHUDManager::LeaderboardGetAverageScores(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559620, params);
}

void ZHUDManager::FetchNotificationMessages(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559660, params);
}

void ZHUDManager::GetChallengeInfo(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559670, params);
}

void ZHUDManager::GetChallengeSentInfo(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559680, params);
}

void ZHUDManager::SetContractTargetOutfit(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559690, params);
}

void ZHUDManager::SetContractTargetWeapon(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559700, params);
}

void ZHUDManager::SetContractRestriction(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559770, params);
}

void ZHUDManager::ShowGamerCard(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x5597D0, params);
}

void ZHUDManager::GetIconPathForResourceID_Async(ZRuntimeResourceID rID, ZDynamicResourceLibrary** lib)
{
	Function::CallMethod<ZHUDManager*, ZRuntimeResourceID, ZDynamicResourceLibrary**>(BaseAddresses::hitman5Dll + 0x5597E0, this, rID, lib);
}

void ZHUDManager::ItemPickedUp(TEntityRef<IHM5Item>* rItem)
{
	Function::CallMethod<ZHUDManager*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x559840, this, rItem);
}

void ZHUDManager::ItemUnlocked(ZString* sItemName)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x559850, this, sItemName);
}

void ZHUDManager::AmmoSuckedUp(TEntityRef<IHM5ItemWeapon>* rWeapon, int nBullets)
{
	Function::CallMethod<ZHUDManager*, TEntityRef<IHM5ItemWeapon>*, int>(BaseAddresses::hitman5Dll + 0x559860, this, rWeapon, nBullets);
}

void ZHUDManager::SetWaitForAsyncSaveState(EMenuActionId eAction)
{
	Function::CallMethod<ZHUDManager*, EMenuActionId>(BaseAddresses::hitman5Dll + 0x559870, this, eAction);
}

void ZHUDManager::ShowAmmoPickup(ZString* ammoName, unsigned __int16 iAmmoPicked)
{
	Function::CallMethod<ZHUDManager*, ZString*, unsigned __int16>(BaseAddresses::hitman5Dll + 0x559990, this, ammoName, iAmmoPicked);
}

void ZHUDManager::OnClosedDisplayOptionsMenu()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5599E0, this);
}

void ZHUDManager::QueryButtonMapCallback(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559A10, params);
}

void ZHUDManager::CancelButtonMapCallback(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559A30, params);
}

void ZHUDManager::StartButtonMapCallback(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559A50, params);
}

void ZHUDManager::RequestButtonMapCallback(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559A70, params);
}

void ZHUDManager::ResetButtonMapCallback(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x559A90, params);
}

void ZHUDManager::SetPauseMenuActive(bool bActive)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x559AB0, this, bActive);
}

void ZHUDManager::SetHUDManagerEntity(ZHUDManagerEntity* pHUDManagerEntity)
{
	Function::CallMethod<ZHUDManager*, ZHUDManagerEntity*>(BaseAddresses::hitman5Dll + 0x55B300, this, pHUDManagerEntity);
}

void ZHUDManager::SetUserNotebookPage(EMenuId ePageId)
{
	Function::CallMethod<ZHUDManager*, EMenuId>(BaseAddresses::hitman5Dll + 0x55B350, this, ePageId);
}

void ZHUDManager::ScaleformShowWeaponDisplay(bool bShow)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x55B430, this, bShow);
}

void ZHUDManager::ScaleformUpdateWeaponDisplayAnimations()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55B4E0, this);
}

void ZHUDManager::HideCrossHair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55B6C0, this);
}

void ZHUDManager::ShowCrossHair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55B6D0, this);
}

void ZHUDManager::AnimateCrosshair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55B6E0, this);
}

void ZHUDManager::DisguiseChanged(ZResourcePtr* pDisguiseMovie, bool bDisguiseIsBroken)
{
	Function::CallMethod<ZHUDManager*, ZResourcePtr*, bool>(BaseAddresses::hitman5Dll + 0x55B980, this, pDisguiseMovie, bDisguiseIsBroken);
}

void ZHUDManager::RemoveIcon(SHUDIconInfo* iconInfo)
{
	Function::CallMethod<ZHUDManager*, SHUDIconInfo*>(BaseAddresses::hitman5Dll + 0x55BB00, this, iconInfo);
}

void ZHUDManager::ShowTrespassingIcon(bool bShow)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x55BBD0, this, bShow);
}

void ZHUDManager::ResetContractScoring()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55BD30, this);
}

void ZHUDManager::SetContractsScore(int iScore)
{
	Function::CallMethod<ZHUDManager*, int>(BaseAddresses::hitman5Dll + 0x55BE50, this, iScore);
}

void ZHUDManager::ExpandContractScoringCountdown()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55BED0, this);
}

void ZHUDManager::HideContractInfo()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55BFE0, this);
}

bool ZHUDManager::InitTargetTrackerTimer()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55C0B0, this);
}

void ZHUDManager::ClearTargetTracker()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55C1B0, this);
}

void ZHUDManager::HideRatingProgress()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55C2B0, this);
}

void ZHUDManager::ShowThreatRadar(bool bShow)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x55C7F0, this, bShow);
}

void ZHUDManager::HideHint()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55C820, this);
}

void ZHUDManager::HideTutorial()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55C930, this);
}

TEntityRef<ZHitman5>* ZHUDManager::Hitman(TEntityRef<ZHitman5>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHitman5>*, ZHUDManager*, TEntityRef<ZHitman5>*>(BaseAddresses::hitman5Dll + 0x55CA40, this, result);
}

void ZHUDManager::HideLevelIntroScreen()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55CA80, this);
}

void ZHUDManager::UpdateAnimatedScoreForRatingTracker()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55CE00, this);
}

void ZHUDManager::ScaleformUpdateContractsTracker()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55CFF0, this);
}

void ZHUDManager::ScaleformUpdateRatingTracker()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55D010, this);
}

void ZHUDManager::HideRatingTracker()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55D030, this);
}

void ZHUDManager::HideAmmoPickup()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55D100, this);
}

void ZHUDManager::ScaleformGetStageScale(float* fScaleX, float* fScaleY)
{
	Function::CallMethod<ZHUDManager*, float*, float*>(BaseAddresses::hitman5Dll + 0x55D280, this, fScaleX, fScaleY);
}

void ZHUDManager::CompetitionClearSelectedFriends()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55D350, this);
}

void ZHUDManager::ScaleformUpdateEyefinityHUDPosition()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55ECF0, this);
}

bool ZHUDManager::DoShowLoadSaveIndicator(bool bShow)
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x55EEC0, this, bShow);
}

void ZHUDManager::GetLocalizedText(IScaleformExternalInterfaceArguments* params)
{
	Function::CallMethod<ZHUDManager*, IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x55EFD0, this, params);
}

void ZHUDManager::FadeHUDElements(unsigned int nElements, EHUDFadeReason eReason, bool bFadeIn, float fTime)
{
	Function::CallMethod<ZHUDManager*, unsigned int, EHUDFadeReason, bool, float>(BaseAddresses::hitman5Dll + 0x55F080, this, nElements, eReason, bFadeIn, fTime);
}

void ZHUDManager::SetDifficultyLevelHUDElementMask(unsigned int nElements)
{
	Function::CallMethod<ZHUDManager*, unsigned int>(BaseAddresses::hitman5Dll + 0x55F2C0, this, nElements);
}

void ZHUDManager::StoreLastOutfitParameters()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55F310, this);
}

void ZHUDManager::FadePauseMenuToBlack(EMenuActionId eAction)
{
	Function::CallMethod<ZHUDManager*, EMenuActionId>(BaseAddresses::hitman5Dll + 0x55F420, this, eAction);
}

void ZHUDManager::InitWeaponSelectionMKB()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55F670, this);
}

void ZHUDManager::UpdateAmmoCountsMKB()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x55FCC0, this);
}

void ZHUDManager::DeSelectCurrentWeapon()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x560130, this);
}

void ZHUDManager::SetSelectedWeapon(unsigned int nDirection, unsigned int nSlot, GFxValue* mcMain, GFxValue* mcWeapon)
{
	Function::CallMethod<ZHUDManager*, unsigned int, unsigned int, GFxValue*, GFxValue*>(BaseAddresses::hitman5Dll + 0x5601A0, this, nDirection, nSlot, mcMain, mcWeapon);
}

void ZHUDManager::ScaleformUpdateCrossHair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5614E0, this);
}

void ZHUDManager::ScaleformUpdateFocusBar()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5618D0, this);
}

void ZHUDManager::SetFocusBarValue(float fFocusFraction, bool bIsBurning)
{
	Function::CallMethod<ZHUDManager*, float, bool>(BaseAddresses::hitman5Dll + 0x561AF0, this, fFocusFraction, bIsBurning);
}

void ZHUDManager::ShowFocusBar(bool bShow)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x561C10, this, bShow);
}

void ZHUDManager::ScaleformUpdateDisguiseLevel()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x561C70, this);
}

void ZHUDManager::ScaleformUpdateIcon(SHUDIconInfo* iconInfo)
{
	Function::CallMethod<ZHUDManager*, SHUDIconInfo*>(BaseAddresses::hitman5Dll + 0x561FC0, this, iconInfo);
}

void ZHUDManager::InitIcons()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5622A0, this);
}

void ZHUDManager::ReleaseIcons()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5623C0, this);
}

void ZHUDManager::ShowAIStateIcon(int nState)
{
	Function::CallMethod<ZHUDManager*, int>(BaseAddresses::hitman5Dll + 0x562410, this, nState);
}

void ZHUDManager::ShowAchievementNotification(ZString* sTitle, ZString* sDescription)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZString*>(BaseAddresses::hitman5Dll + 0x562590, this, sTitle, sDescription);
}

void ZHUDManager::ContractUpdateTimerScore(TMap<ZString, ZVariant>* info)
{
	Function::CallMethod<ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x5626F0, this, info);
}

bool ZHUDManager::InitTargetTrackerCampaign(TMap<ZString, ZVariant>* info)
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x562840, this, info);
}

bool ZHUDManager::InitTargetTrackerContractPlayer(TMap<ZString, ZVariant>* info)
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x562950, this, info);
}

bool ZHUDManager::InitTargetTrackerContractCreator(TMap<ZString, ZVariant>* info)
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x562A60, this, info);
}

void ZHUDManager::UpdateTargetTrackerState(TMap<ZString, ZVariant>* info)
{
	Function::CallMethod<ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x562B70, this, info);
}

void ZHUDManager::UpdateTargetTrackerTime(TMap<ZString, ZVariant>* info)
{
	Function::CallMethod<ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x562C70, this, info);
}

void ZHUDManager::InitRadarBlips()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x562D70, this);
}

void ZHUDManager::ScaleformUpdateThreatRadar()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x562E10, this);
}

void ZHUDManager::UpdateHealth()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x563040, this);
}

void ZHUDManager::ScaleformUpdateHealth()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x563180, this);
}

void ZHUDManager::ShowCommunicationBar(ZString* sHeadline, ZString* sSubline, ECommunicationBarState eState)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZString*, ECommunicationBarState>(BaseAddresses::hitman5Dll + 0x5632E0, this, sHeadline, sSubline, eState);
}

void ZHUDManager::HideCommunicationBar()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x563440, this);
}

void ZHUDManager::ShowMeBar(ZString* sHeadline, ZString* sSubline, EMeBarState eState)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZString*, EMeBarState>(BaseAddresses::hitman5Dll + 0x563590, this, sHeadline, sSubline, eState);
}

void ZHUDManager::HideMeBar()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5636F0, this);
}

__int16 ZHUDManager::AddText(ZString* sText, int nOffsetX, int nOffsetY, EScreenAnchor eScreenAnchor, float nSize, unsigned int nColor, ETextAlignment eTextAlign, float nDuration, bool bForce)
{
	return Function::CallMethodAndReturn<__int16, ZHUDManager*, ZString*, int, int, EScreenAnchor, float, unsigned int, ETextAlignment, float, bool>(BaseAddresses::hitman5Dll + 0x563840, this, sText, nOffsetX, nOffsetY, eScreenAnchor, nSize, nColor, eTextAlign, nDuration, bForce);
}

void ZHUDManager::SetText(__int16 nTextID, ZString* sText, bool bForce)
{
	Function::CallMethod<ZHUDManager*, __int16, ZString*, bool>(BaseAddresses::hitman5Dll + 0x563D10, this, nTextID, sText, bForce);
}

void ZHUDManager::SetTextPosition(__int16 nTextID, int nOffsetX, int nOffsetY, bool bForce)
{
	Function::CallMethod<ZHUDManager*, __int16, int, int, bool>(BaseAddresses::hitman5Dll + 0x563E20, this, nTextID, nOffsetX, nOffsetY, bForce);
}

void ZHUDManager::SetTextScale(__int16 nTextID, float fScale, bool bForce)
{
	Function::CallMethod<ZHUDManager*, __int16, float, bool>(BaseAddresses::hitman5Dll + 0x563F20, this, nTextID, fScale, bForce);
}

void ZHUDManager::SetTextAlpha(__int16 nTextID, __int16 nAlpha, bool bForce)
{
	Function::CallMethod<ZHUDManager*, __int16, __int16, bool>(BaseAddresses::hitman5Dll + 0x564020, this, nTextID, nAlpha, bForce);
}

void ZHUDManager::RemoveText(__int16 nTextID)
{
	Function::CallMethod<ZHUDManager*, __int16>(BaseAddresses::hitman5Dll + 0x564120, this, nTextID);
}

void ZHUDManager::ShowHint(ZString* text, int iType, int iFirstButton, int iSecondButton, ZString* buttonText)
{
	Function::CallMethod<ZHUDManager*, ZString*, int, int, int, ZString*>(BaseAddresses::hitman5Dll + 0x564200, this, text, iType, iFirstButton, iSecondButton, buttonText);
}

void ZHUDManager::HideHintAndTutorialAndReset()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x564310, this);
}

void ZHUDManager::ControlLayoutChanged()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5643B0, this);
}

void ZHUDManager::ShowTutorial(ZString* headline, ZString* text, ZString* resourcePath, int iButton, ZString* buttonText, ZString* keyText)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZString*, ZString*, int, ZString*, ZString*>(BaseAddresses::hitman5Dll + 0x564400, this, headline, text, resourcePath, iButton, buttonText, keyText);
}

void ZHUDManager::BaconShot(ZString* sText)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x564510, this, sText);
}

__int16 ZHUDManager::AddQuad(int nOffsetX, int nOffsetY, int nWidth, int nHeight, EScreenAnchor eScreenAnchor, unsigned int nColor, unsigned __int16 nAlpha, float nDuration)
{
	return Function::CallMethodAndReturn<__int16, ZHUDManager*, int, int, int, int, EScreenAnchor, unsigned int, unsigned __int16, float>(BaseAddresses::hitman5Dll + 0x5645F0, this, nOffsetX, nOffsetY, nWidth, nHeight, eScreenAnchor, nColor, nAlpha, nDuration);
}

void ZHUDManager::SetQuadSize(__int16 nQuadID, int nWidth, int nHeight)
{
	Function::CallMethod<ZHUDManager*, __int16, int, int>(BaseAddresses::hitman5Dll + 0x564960, this, nQuadID, nWidth, nHeight);
}

void ZHUDManager::SetQuadPositionAndSize(__int16 nQuadID, int nOffsetX, int nOffsetY, int nWidth, int nHeight)
{
	Function::CallMethod<ZHUDManager*, __int16, int, int, int, int>(BaseAddresses::hitman5Dll + 0x564A50, this, nQuadID, nOffsetX, nOffsetY, nWidth, nHeight);
}

void ZHUDManager::RemoveQuad(__int16 nQuadID)
{
	Function::CallMethod<ZHUDManager*, __int16>(BaseAddresses::hitman5Dll + 0x564B50, this, nQuadID);
}

void ZHUDManager::LeaderboardDisplayScores(TMap<ZString, ZVariant>* info)
{
	Function::CallMethod<ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x564C30, this, info);
}

void ZHUDManager::LeaderboardDisplayAverageScores(TMap<ZString, ZVariant>* info)
{
	Function::CallMethod<ZHUDManager*, TMap<ZString, ZVariant>*>(BaseAddresses::hitman5Dll + 0x564E10, this, info);
}

void ZHUDManager::IsContractsTutorial(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x564FF0, params);
}

void ZHUDManager::GetImageFromResourceID(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x565080, params);
}

bool ZHUDManager::HitmanExists()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x565180, this);
}

ZString* ZHUDManager::GetButtonTag(ZString* result, EControllerButton eButton, EButtonPressType ePressType)
{
	return Function::CallMethodAndReturn<ZString*, ZHUDManager*, ZString*, EControllerButton, EButtonPressType>(BaseAddresses::hitman5Dll + 0x565190, this, result, eButton, ePressType);
}

void ZHUDManager::SetSceneOverlayVisible(bool bVisible)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x565410, this, bVisible);
}

void ZHUDManager::UpdatePcInput()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5657C0, this);
}

void ZHUDManager::ShowLevelIntroScreen(ZString* sLevelName, ZString* sSubString)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZString*>(BaseAddresses::hitman5Dll + 0x565A20, this, sLevelName, sSubString);
}

void ZHUDManager::ResetRatingTracker(ZString* portrait)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x565B50, this, portrait);
}

void ZHUDManager::ScaleformShowAmmoPickup()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x565C90, this);
}

void ZHUDManager::SetDialogActive(bool bActive)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x565F80, this, bActive);
}

void ZHUDManager::HideTutorialFromScaleform()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x566040, this);
}

void ZHUDManager::HideTutorialCallback(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x566070, params);
}

void ZHUDManager::RestoreDifficultySelection(int nIndex)
{
	Function::CallMethod<ZHUDManager*, int>(BaseAddresses::hitman5Dll + 0x5660A0, this, nIndex);
}

bool ZHUDManager::UpdateBreadcrumbIcon(TEntityRef<ZShowBreadcrumbIcon>* ent, SHUDIconInfo* info)
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*, TEntityRef<ZShowBreadcrumbIcon>*, SHUDIconInfo*>(BaseAddresses::hitman5Dll + 0x5662B0, this, ent, info);
}

void ZHUDManager::ScaleformUpdateContractsReportEnabled(bool bState)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x566510, this, bState);
}

void ZHUDManager::CheckpointLoadingFinished()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x566720, this);
}

void ZHUDManager::ShowHUD(bool bShow)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x567380, this, bShow);
}

void ZHUDManager::InitMovieClips()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x567560, this);
}

void ZHUDManager::UpdatePrompts(unsigned __int8 iCount, SPromptToDisplay* const pActivePrompts)
{
	Function::CallMethod<ZHUDManager*, unsigned __int8, SPromptToDisplay* const>(BaseAddresses::hitman5Dll + 0x5676E0, this, iCount, pActivePrompts);
}

void ZHUDManager::ReleaseNotebook()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x567710, this);
}

void ZHUDManager::ScaleformUpdateWeaponDisplay()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x567D40, this);
}

void ZHUDManager::AddIcon(SHUDIconInfo* iconInfo)
{
	Function::CallMethod<ZHUDManager*, SHUDIconInfo*>(BaseAddresses::hitman5Dll + 0x567FF0, this, iconInfo);
}

void ZHUDManager::UpdateIcon(SHUDIconInfo* iconInfo, unsigned int changedFlags)
{
	Function::CallMethod<ZHUDManager*, SHUDIconInfo*, unsigned int>(BaseAddresses::hitman5Dll + 0x5681B0, this, iconInfo, changedFlags);
}

void ZHUDManager::ShowContractTargets(TArray<ZVariant> aTargets)
{
	Function::CallMethod<ZHUDManager*, TArray<ZVariant>>(BaseAddresses::hitman5Dll + 0x568200, this, aTargets);
}

void ZHUDManager::ShowContractExitPoints(TArray<ZVariant> aTargets)
{
	Function::CallMethod<ZHUDManager*, TArray<ZVariant>>(BaseAddresses::hitman5Dll + 0x568380, this, aTargets);
}

void ZHUDManager::UpdateThreatRadar()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x568500, this);
}

void ZHUDManager::ScaleformUpdateAttentionHUD()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x568680, this);
}

void ZHUDManager::GetControllerLayout(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x568BE0, params);
}

ZString* ZHUDManager::GetIconPathForResourceID(ZString* result, ZRuntimeResourceID rID, ZDynamicResourceLibrary** lib, bool bWait)
{
	return Function::CallMethodAndReturn<ZString*, ZHUDManager*, ZString*, ZRuntimeResourceID, ZDynamicResourceLibrary**, bool>(BaseAddresses::hitman5Dll + 0x568CA0, this, result, rID, lib, bWait);
}

void ZHUDManager::GetObjectiveImage(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x568E40, params);
}

ZString* ZHUDManager::GetRatingPortraitImage(ZString* result, int titleIndex)
{
	return Function::CallMethodAndReturn<ZString*, ZHUDManager*, ZString*, int>(BaseAddresses::hitman5Dll + 0x568F50, this, result, titleIndex);
}

ZRuntimeResourceID* ZHUDManager::GetRatingPortraitImageRID(ZRuntimeResourceID* result, int titleIndex)
{
	return Function::CallMethodAndReturn<ZRuntimeResourceID*, ZHUDManager*, ZRuntimeResourceID*, int>(BaseAddresses::hitman5Dll + 0x569160, this, result, titleIndex);
}

void ZHUDManager::SetNotebookLibID(ZRuntimeResourceID* notebookLibID)
{
	Function::CallMethod<ZHUDManager*, ZRuntimeResourceID*>(BaseAddresses::hitman5Dll + 0x5691E0, this, notebookLibID);
}

void ZHUDManager::SetContractLibID(ZRuntimeResourceID* contractLibID)
{
	Function::CallMethod<ZHUDManager*, ZRuntimeResourceID*>(BaseAddresses::hitman5Dll + 0x569210, this, contractLibID);
}

void ZHUDManager::UpdateBreadcrumbIcons()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x569240, this);
}

void ZHUDManager::ScaleformUpdateBreadcrumbIcons()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x569300, this);
}

void ZHUDManager::ShowNextScreen()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x569F70, this);
}

void ZHUDManager::UpdateCrossHair()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56A190, this);
}

void ZHUDManager::ReleaseWeapons()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56A7C0, this);
}

void ZHUDManager::ReleaseRadarBlips()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56A900, this);
}

void ZHUDManager::CancelHintEntity(TEntityRef<ZHintMessageEntity> pEntity)
{
	Function::CallMethod<ZHUDManager*, TEntityRef<ZHintMessageEntity>>(BaseAddresses::hitman5Dll + 0x56A9B0, this, pEntity);
}

void ZHUDManager::GetChallengeIcon(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x56AC10, params);
}

void ZHUDManager::ReleaseMovieClips()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56AD90, this);
}

void ZHUDManager::RemoveBreadcrumbIcon(TEntityRef<ZShowBreadcrumbIcon>* ent)
{
	Function::CallMethod<ZHUDManager*, TEntityRef<ZShowBreadcrumbIcon>*>(BaseAddresses::hitman5Dll + 0x56ADB0, this, ent);
}

void ZHUDManager::OnDisplayScreen(EMenuId nMenuId, TMap<ZString, ZVariant> info)
{
	Function::CallMethod<ZHUDManager*, EMenuId, TMap<ZString, ZVariant>>(BaseAddresses::hitman5Dll + 0x56B390, this, nMenuId, info);
}

void ZHUDManager::ContractsSetTargetRestriction(TMap<ZString, ZVariant> info)
{
	Function::CallMethod<ZHUDManager*, TMap<ZString, ZVariant>>(BaseAddresses::hitman5Dll + 0x56B660, this, info);
}

void ZHUDManager::PushHintEntity(TEntityRef<ZHintMessageEntity> pEntity)
{
	Function::CallMethod<ZHUDManager*, TEntityRef<ZHintMessageEntity>>(BaseAddresses::hitman5Dll + 0x56B880, this, pEntity);
}

void ZHUDManager::UpdateHints()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56B9A0, this);
}

void ZHUDManager::AddBreadcrumbIcon(TEntityRef<ZShowBreadcrumbIcon>* ent)
{
	Function::CallMethod<ZHUDManager*, TEntityRef<ZShowBreadcrumbIcon>*>(BaseAddresses::hitman5Dll + 0x56C640, this, ent);
}

void ZHUDManager::SetHUDMovieClip(IScaleformPlayer* pFlashMovie)
{
	Function::CallMethod<ZHUDManager*, IScaleformPlayer*>(BaseAddresses::hitman5Dll + 0x56C9B0, this, pFlashMovie);
}

void ZHUDManager::SetPauseMenuMovieClip(IScaleformPlayer* pFlashMovie)
{
	Function::CallMethod<ZHUDManager*, IScaleformPlayer*>(BaseAddresses::hitman5Dll + 0x56CAC0, this, pFlashMovie);
}

void ZHUDManager::StartPauseMode()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56CB70, this);
}

void ZHUDManager::ResumeGame()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56CEB0, this);
}

void ZHUDManager::ContractScoreUpdate(int iScore, ZString* sScoreReason)
{
	Function::CallMethod<ZHUDManager*, int, ZString*>(BaseAddresses::hitman5Dll + 0x56E1F0, this, iScore, sScoreReason);
}

void ZHUDManager::ContractSetTitleText(ZString sTitle)
{
	Function::CallMethod<ZHUDManager*, ZString>(BaseAddresses::hitman5Dll + 0x56E430, this, sTitle);
}

void ZHUDManager::ContractSetDescriptionText(ZString sDescription)
{
	Function::CallMethod<ZHUDManager*, ZString>(BaseAddresses::hitman5Dll + 0x56E6A0, this, sDescription);
}

void ZHUDManager::ShowRatingProgress(SRatingProgress* actionProgress, SRatingProgress* stealthProgress)
{
	Function::CallMethod<ZHUDManager*, SRatingProgress*, SRatingProgress*>(BaseAddresses::hitman5Dll + 0x56E910, this, actionProgress, stealthProgress);
}

void ZHUDManager::ShowFinalCheckPointRating(float fActionRatingFraction, float fStealthRatingFraction, float fDuration)
{
	Function::CallMethod<ZHUDManager*, float, float, float>(BaseAddresses::hitman5Dll + 0x56ED80, this, fActionRatingFraction, fStealthRatingFraction, fDuration);
}

void ZHUDManager::GetLikeDislikeInfo(IScaleformExternalInterfaceArguments* params)
{
	Function::Call<IScaleformExternalInterfaceArguments*>(BaseAddresses::hitman5Dll + 0x56EF90, params);
}

void ZHUDManager::SetGlobalTexts()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x56FB00, this);
}

void ZHUDManager::SetHUDConstants()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x570170, this);
}

void ZHUDManager::UpdateRatingTracker(ZString* title, ZString* portrait, int totalscore, bool titlechanged, bool totalscorechanged)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZString*, int, bool, bool>(BaseAddresses::hitman5Dll + 0x5705D0, this, title, portrait, totalscore, titlechanged, totalscorechanged);
}

void ZHUDManager::RatingScoreAdded(int score, ZString* scoreReason)
{
	Function::CallMethod<ZHUDManager*, int, ZString*>(BaseAddresses::hitman5Dll + 0x570A80, this, score, scoreReason);
}

void ZHUDManager::LevelFailed(ZString* sReason)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x570D40, this, sReason);
}

void ZHUDManager::ScaleformUpdateContractTargets()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x571050, this);
}

void ZHUDManager::ScaleformUpdateContractExits()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x571B40, this);
}

void ZHUDManager::OnFontChanged()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5729B0, this);
}

void ZHUDManager::ShowPauseMenu(bool bShow)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x572B90, this, bShow);
}

void ZHUDManager::TogglePauseMenu()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x572FE0, this);
}

void ZHUDManager::ScaleformUpdateWeaponSelection()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5730C0, this);
}

void ZHUDManager::SetMenuConstants()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5733C0, this);
}

void ZHUDManager::RenderThreadUpdate()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x573B30, this);
}

void ZHUDManager::Reset()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5740D0, this);
}

void ZHUDManager::ShowContractFailed()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x574600, this);
}

void ZHUDManager::HandleNotebookTransition()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x574670, this);
}

void ZHUDManager::ShowNotebook(bool bShow)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x5759B0, this, bShow);
}

void ZHUDManager::OnContinueAction()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x575C40, this);
}

void ZHUDManager::ShowNotebookScreen(EMenuId nNotebookScreenID)
{
	Function::CallMethod<ZHUDManager*, EMenuId>(BaseAddresses::hitman5Dll + 0x575C80, this, nNotebookScreenID);
}

void ZHUDManager::ContractCreatorEnded(bool bSuccess)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x575CB0, this, bSuccess);
}

void ZHUDManager::ContractPlayerEnded(bool bSuccess)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x575D40, this, bSuccess);
}

void ZHUDManager::ShowLevelCompleteScreen()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x575DD0, this);
}

void ZHUDManager::UpdatePushNotifications()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x575EE0, this);
}

void ZHUDManager::ResetScorePreviewPushNotifications()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x576500, this);
}

bool ZHUDManager::OnClosedGraphicsOptionsMenu()
{
	return Function::CallMethodAndReturn<bool, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5767A0, this);
}

void ZHUDManager::ToggleNotebook()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5768C0, this);
}

void ZHUDManager::LevelEnded(ZString* sNextLevelPath)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x576910, this, sNextLevelPath);
}

void ZHUDManager::ShowPushNotification(EPushNotificationType ePushNotificationType, float fDisplayTime, TMap<ZString, ZVariant>* data, int nItemID)
{
	Function::CallMethod<ZHUDManager*, EPushNotificationType, float, TMap<ZString, ZVariant>*, int>(BaseAddresses::hitman5Dll + 0x576940, this, ePushNotificationType, fDisplayTime, data, nItemID);
}

void ZHUDManager::ShowObjective(ZString* sText, bool bTertiaryObjective, bool bObjectiveUpdated)
{
	Function::CallMethod<ZHUDManager*, ZString*, bool, bool>(BaseAddresses::hitman5Dll + 0x576BC0, this, sText, bTertiaryObjective, bObjectiveUpdated);
}

void ZHUDManager::ShowScoreUpdate()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x577040, this);
}

void ZHUDManager::OutfitUnlocked(ZString* sOutfitName)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x5774A0, this, sOutfitName);
}

void ZHUDManager::TechniqueUnlocked(ZString* sTechniqueName)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x577910, this, sTechniqueName);
}

void ZHUDManager::SpecialRatingUnlocked(ZString* sTitle)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x577C70, this, sTitle);
}

void ZHUDManager::ContractPickedUp(ZString* sTitle)
{
	Function::CallMethod<ZHUDManager*, ZString*>(BaseAddresses::hitman5Dll + 0x577F90, this, sTitle);
}

void ZHUDManager::CheckpointLoadingStarted()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x5782B0, this);
}

void ZHUDManager::OnPauseUpdate(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZHUDManager*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x5783E0, this, updateEvent);
}

void ZHUDManager::ShowScoreComparisonCallback(bool bSuccess, ZScoreComparisonData* data)
{
	Function::CallMethod<ZHUDManager*, bool, ZScoreComparisonData*>(BaseAddresses::hitman5Dll + 0x578C30, this, bSuccess, data);
}

void ZHUDManager::ShowContractNotification(ZString* sUser, ZString* sText, unsigned __int16 nIcon, float fDuration)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZString*, unsigned __int16, float>(BaseAddresses::hitman5Dll + 0x579290, this, sUser, sText, nIcon, fDuration);
}

void ZHUDManager::UpdateScoreComparison()
{
	Function::CallMethod<ZHUDManager*>(BaseAddresses::hitman5Dll + 0x579560, this);
}

void ZHUDManager::OnFrameUpdate(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZHUDManager*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x579670, this, updateEvent);
}

void ZHUDManager::OnGameStop(ZString* sEvent, ZVariantRef* val)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZVariantRef*>(BaseAddresses::hitman5Dll + 0x579D10, this, sEvent, val);
}

void ZHUDManager::OnGameStart(ZString* sEvent, ZVariantRef* val)
{
	Function::CallMethod<ZHUDManager*, ZString*, ZVariantRef*>(BaseAddresses::hitman5Dll + 0x579F30, this, sEvent, val);
}

const SComponentMapEntry* ZHUDManager::GetComponentInterfacesInternal()
{
	return Function::CallMethodAndReturn<const SComponentMapEntry*, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x57B6D0, this);
}

TEntityRef<ZNotebookEntity>* ZHUDManager::GetNotebook()
{
	return Function::CallMethodAndReturn<TEntityRef<ZNotebookEntity>*, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x57C7F0, this);
}

const ZString* ZHUDManager::GetLastOutfitTitle()
{
	return Function::CallMethodAndReturn<const ZString*, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x57C800, this);
}

const ZString* ZHUDManager::GetLastOutfitDescription()
{
	return Function::CallMethodAndReturn<const ZString*, ZHUDManager*>(BaseAddresses::hitman5Dll + 0x57C810, this);
}

ZRuntimeResourceID* ZHUDManager::GetLastOutfitImage(ZRuntimeResourceID* result)
{
	return Function::CallMethodAndReturn<ZRuntimeResourceID*, ZHUDManager*, ZRuntimeResourceID*>(BaseAddresses::hitman5Dll + 0x57C820, this, result);
}

void ZHUDManager::SetNotebookBlocked(bool bVal)
{
	Function::CallMethod<ZHUDManager*, bool>(BaseAddresses::hitman5Dll + 0x6DCF90, this, bVal);
}
