#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "TMaxArray.h"
#include "EControllerButton.h"
#include "EUIDialog.h"
#include "EUIText.h"
#include "ZEvent.h"
#include "TArrayIterator.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZEventNull;
class ZGameWideUIScaleformHandler;
class ZInputAction;
struct SComponentMapEntry;
struct SGameUpdateEvent;
struct STypeID;
template <class T> class alignas(8) ZDelegate;

class ZGameWideUI : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EDialogOptions
	{
		DO_CONTINUE = 0,
		DO_OK = 1,
		DO_OK_CANCEL = 2,
		DO_YES_NO = 3,
		DO_CONTINUE_EXIT = 4,
		DO_REDEEM = 5,
		DO_WAIT = 6
	};

	enum EDialogResult
	{
		DR_CONFIRM = 0,
		DR_ALTERNATIVE = 1,
		DR_DENY = 2
	};

	enum EDialogContext
	{
		DC_FRONTEND = 0,
		DC_INGAME = 1
	};

	enum EDialogIcon
	{
		DI_DEFAULT = 0,
		DI_UNLOCK = 1,
		DI_WAITINGSERVER = 2,
		DI_AUTOSAVE = 3
	};

	struct SDialogData
	{
		EUIDialog m_eDialog;
		EDialogOptions m_eDialogOptions;
		EUIText m_eTitle;
		EUIText m_eMessage;
		ZString m_sMessage;
		EUIText m_eConfirmButton;
		EUIText m_eAlternativeButton;
		EUIText m_eDenyButton;
		EDialogIcon m_eIcon;
		ZEvent<EDialogContext, EUIDialog, EDialogResult, ZEventNull, ZEventNull> m_Callback;
		unsigned int m_nDuration;
		ZString m_sOverrideMessage;

		SDialogData(const SDialogData& __that);
		SDialogData() = default;
		~SDialogData() = default;
		SDialogData& operator=(const SDialogData& __that);
	};

	TEntityRef<ZGameWideUIScaleformHandler> m_rGameWideUI;
	TMaxArray<SDialogData, 10> m_DialogStack;
	bool m_bLoadSaveIndicatorRequested;
	bool m_bLoadSaveIndicatorShownLastFrame;
	int m_iTopDialog;
	bool m_bRequestedPause;
	int m_nTransitionCoolDown;
	long long m_tMinSaveIconShowTime;
	ZString m_sCachedBuildID;
	EControllerButton m_eClickedButton;
	bool m_bInGame;
	int m_nCursorFlag;
	bool mSelectedPositive;
	bool m_bPcNewFeatures;
	bool m_bIsFaded;

	static bool m_bInputBound;
	static ZInputAction s_GameWideUIInputControl;
	static ZInputAction s_GameWideUIInputControl_Cross;
	static ZInputAction s_GameWideUIInputControl_Circle;
	static ZInputAction s_GameWideUIInputControl_Square;
	static ZInputAction s_GameWideUIInputControl_Triangle;
	static ZInputAction s_GameWideUIInputControl_KB_Cross;
	static ZInputAction s_GameWideUIInputControl_KB_Circle;
	static ZInputAction s_GameWideUIInputControl_Left;
	static ZInputAction s_GameWideUIInputControl_Right;
	static unsigned int s_DialogOpen;
	static unsigned int s_DialogCloseYes;
	static unsigned int s_DialogCloseNo;

	~ZGameWideUI() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZGameWideUI() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void ShowDialog(EUIDialog eDialog, const EUIText eTitle, EUIText eMessage, const ZString& sMessage, EDialogOptions eDialogOptions, EDialogIcon eIcon, ZDelegate<void __cdecl(EDialogContext, EUIDialog, EDialogResult)> callback, unsigned int nDuration, const ZString& sOverrideMessage);
	void ShowDialog(EUIDialog eDialog, const EUIText eTitle, const ZString& sMessage, EDialogOptions eDialogOptions, EDialogIcon eIcon, ZDelegate<void __cdecl(EDialogContext, EUIDialog, EDialogResult)> callback, unsigned int nDuration, const ZString& sOverrideMessage);
	void ShowDialog(EUIDialog eDialog, const EUIText eTitle, EUIText eMessage, EDialogOptions eDialogOptions, EDialogIcon eIcon, ZDelegate<void __cdecl(EDialogContext, EUIDialog, EDialogResult)> callback, unsigned int nDuration, const ZString& sOverrideMessage);
	void RemoveAllDialogs();
	void ShowLoadSaveIndicator(bool bShow);
	bool IsShowingSaveIcon() const;
	void SetBuildIDString(const ZString& sBuildID);
	void SetGameWideUIScaleformHandler(TEntityRef<ZGameWideUIScaleformHandler> rMessages);
	ZGameWideUIScaleformHandler* GetGameWideUIScaleformHandler();
	void CloseDialog(EUIDialog eDialog, EDialogResult eResult);
	bool HasDialogs() const;
	void OnButtonClick(EControllerButton eButton);
	void SetInGame(bool enable);
	void ScheduleCursorChange(bool show);
	void SetSelectedPositive(bool positive);
	void CreateAndShowDialog(const SDialogData& data);
	static void DefaultDialogCallback(EDialogContext eContext, EUIDialog eDialog, EDialogResult eResult);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void OnGameStart(const ZString& sEvent, const ZVariantRef& val);
	void OnGameStop(const ZString& sEvent, const ZVariantRef& val);
	void OnTransitionStart(const ZString& sEvent, const ZVariantRef& val);
	void OnTransitionEnd(const ZString& sEvent, const ZVariantRef& val);
	void TriggerSoundEvent(const ZString& sPin, const ZVariantRef& data);
	void HandleDialogResult(EDialogResult iResult);
	void HideDialog();
	int FindMostImportantDialogIndex() const;
	TArrayIterator<SDialogData> FindDialogInStack(EUIDialog eDialog);
	bool PruneDialogStack(EUIDialog eNewDialog);
	bool DoesAOverrideB(EUIDialog eDialogA, EUIDialog eDialogB);
};
