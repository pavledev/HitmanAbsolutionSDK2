#pragma once

#include "ZSimpleModuleBase.h"
#include "ZConfiguration.h"
#include "ZHM5OSD.h"
#include "ZEntitySceneContext.h"
#include "ZUserFeedbackManager.h"
#include "SInfoText.h"

class ZHitman5Module : public ZSimpleModuleBase, public ZConfiguration
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZHM5OSD* m_pOSD;
	ZEntitySceneContext* m_pSceneContext;
	ZUserFeedbackManager* m_pUserFeedbackManager;
	bool m_bVideoExportMode;
	float m_fInfoUpdate;
	bool m_bShowInfoUpdateWarning;
	ZString m_sBuildVersion;
	bool m_bBuildIdSetup;
	bool m_bShowWorstCaseMemoryStats;
	SInfoText m_FpsText;
	SInfoText m_BuildVersionAndFingerPrintText;
	SInfoText m_PageMemoryText;
	SInfoText m_GPUMemoryText;
	SInfoText m_SubAllocatorHeadline;
	SInfoText m_SubAllocText[15];
	bool m_bFirstRun;

	static const int m_nMaxNumSuballocators;

	~ZHitman5Module() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	bool Initialize() override;
	void Shutdown() override;
	void Activate() override;
	void Deactivate() override;
	void OnRegisterComponents() override;

	ZHitman5Module() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void RegisterOSD(ZHM5OSD* pOSD);
	ZHM5OSD* GetOSD();
	ZUserFeedbackManager* GetUserFeedbackManager();
	bool IsInVideoExportMode();
	void SetupPhysicsWorldCollisionFilter();
	void SetupPhysicsRayLayers();
	void SetupPhysicsCollisionLayers();
	void VideoExportSettingsCallback(bool bEnableExport);
	static void InitInfoText(SInfoText* pText, int xOffset, int yOffset, int anchor, int align);
	static void ShowInfoText(SInfoText* pText, bool bIsVisible);
	static void SetInfoText(SInfoText* pText, const ZString& sText);
	void UpdateBuildIdString();
	void UpdateInfoDisplay(const SGameUpdateEvent& ev);
	void ReadBuildVersionFile();
};
