#include "ZUserFeedbackManager.h"
#include "Function.h"
#include "BaseAddresses.h"

ZHM5IngameMessageBarManager* ZUserFeedbackManager::GetMessageBarManager()
{
	return Function::CallMethodAndReturn<ZHM5IngameMessageBarManager*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x125710, this);
}

const SGameStateForUserFeedback* ZUserFeedbackManager::GetGameStateForUserFB()
{
	return Function::CallMethodAndReturn<const SGameStateForUserFeedback*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x1F3EA0, this);
}

const ZGameTime* ZUserFeedbackManager::GetLastDisplayWeaponGroupInfo()
{
	return Function::CallMethodAndReturn<const ZGameTime*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x2118A0, this);
}

const ZHM5TimerToOSDManager* ZUserFeedbackManager::GetTimerToOSDManager()
{
	return Function::CallMethodAndReturn<const ZHM5TimerToOSDManager*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x546780, this);
}

const TArray<SGameplayInputControlBind>* ZUserFeedbackManager::GetGameplayInputControlBinds()
{
	return Function::CallMethodAndReturn<const TArray<SGameplayInputControlBind>*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x5485A0, this);
}

TEntityRef<ZHitman5>* ZUserFeedbackManager::Hitman(TEntityRef<ZHitman5>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHitman5>*, ZUserFeedbackManager*, TEntityRef<ZHitman5>*>(BaseAddresses::hitman5Dll + 0x548B60, this, result);
}

bool ZUserFeedbackManager::GameplayInputControlBindsChanged()
{
	return Function::CallMethodAndReturn<bool, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x550E40, this);
}

void ZUserFeedbackManager::ClearGameplayInputControlBindsChanged()
{
	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x550E50, this);
}

float ZUserFeedbackManager::GetHoldsTimer()
{
	return Function::CallMethodAndReturn<float, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x550E60, this);
}

bool ZUserFeedbackManager::GetHUDInventoryInfo_IsDirty()
{
	return Function::CallMethodAndReturn<bool, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x558AF0, this);
}

bool ZUserFeedbackManager::GetHUDInventoryInfoMKB_IsDirty()
{
	return Function::CallMethodAndReturn<bool, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x558B00, this);
}

const UserFBInventoryInfoNamesp::SHUDInventoryInfo* ZUserFeedbackManager::GetHUDInventoryInfo()
{
	return Function::CallMethodAndReturn<const UserFBInventoryInfoNamesp::SHUDInventoryInfo*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x558B10, this);
}

const UserFBInventoryInfoNamesp::HUDInventoryInfoMKB* ZUserFeedbackManager::GetHUDInventoryInfoMKB()
{
	return Function::CallMethodAndReturn<const UserFBInventoryInfoNamesp::HUDInventoryInfoMKB*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x558B30, this);
}

//ZUserFeedbackManager::~ZUserFeedbackManager()
//{
//	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x65A0B0, this);
//}

void ZUserFeedbackManager::OnStop()
{
	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6D9320, this);
}

void ZUserFeedbackManager::AddActivatedAction(ZHM5Action* const pAction, bool bAlternativeActivated)
{
	Function::CallMethod<ZUserFeedbackManager*, ZHM5Action* const, bool>(BaseAddresses::hitman5Dll + 0x6D9330, this, pAction, bAlternativeActivated);
}

void ZUserFeedbackManager::UpdateActiveActions(int nActionCount, ZHM5Action** const pActionList)
{
	Function::CallMethod<ZUserFeedbackManager*, int, ZHM5Action** const>(BaseAddresses::hitman5Dll + 0x6D9340, this, nActionCount, pActionList);
}

void ZUserFeedbackManager::GetActivePrompts(unsigned __int8* iCount, SPromptToDisplay** pActivePrompts)
{
	Function::CallMethod<ZUserFeedbackManager*, unsigned __int8*, SPromptToDisplay**>(BaseAddresses::hitman5Dll + 0x6D9350, this, iCount, pActivePrompts);
}

void ZUserFeedbackManager::UpdateAIState(ZAIGameState* const pOldState, ZAIGameState* const pNewState)
{
	Function::CallMethod<ZUserFeedbackManager*, ZAIGameState* const, ZAIGameState* const>(BaseAddresses::hitman5Dll + 0x6D9380, this, pOldState, pNewState);
}

void ZUserFeedbackManager::HideAmmoPickup()
{
	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6D93A0, this);
}

void ZUserFeedbackManager::ChangeBindings(TArray<SGameplayInputControlBind>* bindingsToUpdate)
{
	Function::CallMethod<ZUserFeedbackManager*, TArray<SGameplayInputControlBind>*>(BaseAddresses::hitman5Dll + 0x6D99D0, this, bindingsToUpdate);
}

void ZUserFeedbackManager::ClearIcons()
{
	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6D9E80, this);
}

const UserFBInventoryInfoNamesp::SHUDWeaponInfo* ZUserFeedbackManager::GetCurrentWeaponInfo()
{
	return Function::CallMethodAndReturn<const UserFBInventoryInfoNamesp::SHUDWeaponInfo*, ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6D9F10, this);
}

SVector3* ZUserFeedbackManager::ConvToScreenSpace(SVector3* result, float4* vWorldTrans, float fCamSpaceOffsetX, float fCamSpaceOffsetY, bool* bReject)
{
	return Function::CallMethodAndReturn<SVector3*, ZUserFeedbackManager*, SVector3*, float4*, float, float, bool*>(BaseAddresses::hitman5Dll + 0x6DA080, this, result, vWorldTrans, fCamSpaceOffsetX, fCamSpaceOffsetY, bReject);
}

void ZUserFeedbackManager::UpdateWeaponDisplay(unsigned __int16 nNumLoadedAmmoLeft, unsigned __int16 nNumLoadedAmmoRight, unsigned __int16 nNumReserveAmmo)
{
	Function::CallMethod<ZUserFeedbackManager*, unsigned __int16, unsigned __int16, unsigned __int16>(BaseAddresses::hitman5Dll + 0x6DAC50, this, nNumLoadedAmmoLeft, nNumLoadedAmmoRight, nNumReserveAmmo);
}

void ZUserFeedbackManager::Initialize()
{
	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6DB070, this);
}

void ZUserFeedbackManager::ShowTopAmmoPickup()
{
	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6DB0E0, this);
}

void ZUserFeedbackManager::PushAmmoPickup(eAmmoType ammotype, ZString* sName, unsigned __int16 iAmmoPicked)
{
	Function::CallMethod<ZUserFeedbackManager*, eAmmoType, ZString*, unsigned __int16>(BaseAddresses::hitman5Dll + 0x6DB180, this, ammotype, sName, iAmmoPicked);
}

void ZUserFeedbackManager::Update(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZUserFeedbackManager*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x6DB320, this, updateEvent);
}

void ZUserFeedbackManager::ChangeHitmanInventoryInfo(bool bShowNoneSelected, bool bHolsterSelected, SInventoryChangeInfoMKB* pInventoryChangeInfoMKB)
{
	Function::CallMethod<ZUserFeedbackManager*, bool, bool, SInventoryChangeInfoMKB*>(BaseAddresses::hitman5Dll + 0x6DC180, this, bShowNoneSelected, bHolsterSelected, pInventoryChangeInfoMKB);
}

//ZUserFeedbackManager::ZUserFeedbackManager()
//{
//	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6DCB70, this);
//}

void ZUserFeedbackManager::Reset()
{
	Function::CallMethod<ZUserFeedbackManager*>(BaseAddresses::hitman5Dll + 0x6DCDD0, this);
}

void ZUserFeedbackManager::OnStart(TEntityRef<ZHitman5>* pHitman)
{
	Function::CallMethod<ZUserFeedbackManager*, TEntityRef<ZHitman5>*>(BaseAddresses::hitman5Dll + 0x6DCEC0, this, pHitman);
}
