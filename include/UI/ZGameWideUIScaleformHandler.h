#pragma once

#include "ZEntityImpl.h"
#include "IScaleformExternalInterfaceHandler.h"
#include "TEntityRef.h"
#include "EUIDialog.h"
#include "EControllerButton.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IScaleformExternalInterfaceArguments;
class IScaleformPlayer;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZGameWideUIScaleformHandler : public ZEntityImpl, public IScaleformExternalInterfaceHandler
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bCursorVisible;
	bool m_bLoadingVisible;
	bool m_bPcNewFeatures;
	bool m_bLoadSaveIndicatorShown;
	TEntityRef<IScaleformPlayer> m_pSystemMessagesMovie;

	static SComponentMapEntry s_componentMap[0];

	~ZGameWideUIScaleformHandler() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;

	ZGameWideUIScaleformHandler() = default;
	static void RegisterType();
	ZGameWideUIScaleformHandler(ZComponentCreateInfo& Info);
	void CreateAndShowDialog(EUIDialog eDialog, const ZString& sTitle, const ZString& sDescription, const ZString& sButtonOK, unsigned int iIconID, const ZString& sButtonCancel, const ZString& sButtonAlternative, unsigned int nDuration);
	void HideDialog();
	void OnButtonPressed(EControllerButton eButton);
	void DoShowLoadSaveIndicator(bool bShow);
	void UpdateLoadSaveIndicator(bool bHUDVisible);
	void SetBuildIDString(const ZString& sBuildID);
	void ShowUICursor(bool bShow);
	bool IsCursorVisible() const;
	void SetInputStates(bool bUsingMouse, bool bUsingGamepad);
	void ShowLoadingIcon(bool bShow, int x, int y);
	static void ShowLoadingIconCallBack(IScaleformExternalInterfaceArguments& params);
	static void HideLoadingIconCallBack(IScaleformExternalInterfaceArguments& params);
	void OnSystemMessagesMovieChanged();
	void SetSafeAreaXY(float fDummyUnused);
};
