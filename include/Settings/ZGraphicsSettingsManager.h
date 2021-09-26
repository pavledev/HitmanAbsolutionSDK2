#pragma once

#include <windef.h>

#include "IComponentInterface.h"
#include "TArray.h"
#include "ZMutex.h"
#include "EUIText.h"
#include "ZString.h"
#include "ZVariantRef.h"

struct SGameUpdateEvent;
class ZPCOptionsHelper;
struct SComponentMapEntry;
struct HKEY__;
struct STypeID;
template <class A, class B> class TPair;

class ZGraphicsSettingsManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EQualityProfile
	{
		QP_VERYLOW = 0,
		QP_LOW = 1,
		QP_MEDIUM = 2,
		QP_HIGH = 3,
		QP_ULTRA = 4,
		QP_CUSTOM = 5,
		QP_SIZE = 6
	};

	enum EDisplaySetting
	{
		DS_RESWIDTH = 0,
		DS_RESHEIGHT = 1,
		DS_REFRESHRATE = 2,
		DS_FULLSCREEN = 3,
		DS_EXCLUSIVEFULLSCREEN = 4,
		DS_VSYNC = 5,
		DS_MONITOR = 6,
		DS_ADAPTER = 7,
		DS_ASPECTRATIO = 8,
		DS_CLIENTRECT_LEFT = 9,
		DS_CLIENTRECT_TOP = 10,
		DS_CLIENTRECT_WIDTH = 11,
		DS_CLIENTRECT_HEIGHT = 12,
		DS_STEREOSCOPIC = 13,
		DS_STEREO_DEPTH = 14,
		DS_STEREO_STRENGTH = 15,
		DS_MAXIMIZED = 16,
		DS_FOCUSLOSS = 17,
		DS_DISABLEGDICURSOR = 18,
		DS_GAMMA = 19,
		DS_MSAA = 20,
		DS_SIZE = 21
	};

	enum EQualitySetting
	{
		QS_SHADOW_QUALITY = 0,
		QS_TEXTURE_RESOLUTION = 1,
		QS_TEXTURE_FILTER = 2,
		QS_SSAO = 3,
		QS_SSGI = 4,
		QS_LPV = 5,
		QS_TESSELLATION = 6,
		QS_MIRRORS = 7,
		QS_ANTI_ALIASING = 8,
		QS_LOD = 9,
		QS_BOKEH = 10,
		QS_BLOOM = 11,
		QS_PROFILE = 12,
		QS_SIZE = 13
	};

	class DisplaySetting
	{
	public:
		ZString m_sName;
		ZString m_sApplicationOption;

		union 
		{
			int m_nDesiredValue;
			float m_fDesiredValue;
		};

		union 
		{
			int m_nCurrentValue;
			float m_fCurrentValue;
		};

		union 
		{
			int m_nSavedValue;
			float m_fSavedValue;
		};

		bool DesiredEqualsCurrent() const;
		DisplaySetting() = default;
		~DisplaySetting() = default;
	};

	class QualitySetting
	{
	public:
		ZString m_sName;
		ZString m_sApplicationOption;
		ZString m_sConfigCommand;
		int m_nMinValue;
		int m_nMaxValue;
		int m_nDesiredValue;
		int m_nCurrentValue;

		QualitySetting() = default;
		~QualitySetting() = default;
	};

	class QualityOption
	{
	public:
		unsigned int m_nValue;
		EUIText m_eMenuItemText;
	};

	class Resolution
	{
	public:
		unsigned int m_nWidth;
		unsigned int m_nHeight;

		Resolution(unsigned int nWidth, unsigned int nHeight);
		Resolution() = default;
		bool operator==(const Resolution& rhs) const;
		ZString ToString() const;
	};

	class Aspectratio
	{
	public:
		unsigned int m_nX;
		unsigned int m_nY;

		Aspectratio(unsigned int nX, unsigned int nY);
		Aspectratio() = default;
		ZString ToString() const;
	};

	struct EyefinityInfo
	{
		bool m_bHasEyeifinty;
		int m_nGridWidth;
		int m_nGridHeight;
		int m_nPrimaryWidth;
		int m_nPrimaryHeight;
		int m_nDisplayWidth;
		int m_nDisplayHeight;
	};

	HWND__* m_hWnd;
	TArray<Resolution> m_Resolutions;
	TArray<unsigned int> m_RefreshRates;
	TArray<Aspectratio> m_AspectRatios;
	unsigned int m_nNumMonitors;
	tagRECT m_DesktopRect;
	ZMutex m_MessageThreadMutex;
	TArray<TPair<unsigned int, int>> m_MessageThreadSettings;
	TArray<TPair<unsigned int, float>> m_MessageThreadSettingsFloat;
	bool m_bScheduleApply;
	bool m_bScheduleSave;
	int m_nWindowWidthMessageThread;
	int m_nWindowHeightMessageThread;
	bool m_bDisableApplyAPIStereoValues;
	bool m_bWaitingForApply;
	bool m_bInitialized;
	bool m_bPCNewFeatures;
	bool m_bSupportsDX11;
	bool m_bSupportsDX10_1;
	bool m_bInitialWindowPlacement;

	static unsigned int m_nDefaultQualityProfile;
	static int m_QualityProfile[6][13];
	static QualityOption m_ShadowQuality[6];
	static QualityOption m_TextureFilter[5];
	static QualityOption m_TextureResolution[2];
	static QualityOption m_SSAO[3];
	static QualityOption m_SSGI[2];
	static QualityOption m_LPV[2];
	static QualityOption m_Tessellation[2];
	static QualityOption m_Mirror[4];
	static QualityOption m_AntiAliasing[2];
	static QualityOption m_LevelOfDetail[5];
	static QualityOption m_Bokeh[4];
	static QualityOption m_Bloom[3];
	static const ZString m_sRegisterySubkey;
	static DisplaySetting m_DisplaySettings[21];
	static QualitySetting m_QualitySettings[13];
	static bool m_bIgnoreQualitySetting[13];

	~ZGraphicsSettingsManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZGraphicsSettingsManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void Initialize();
	void Uninitialize();
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void SetWindowHandle(HWND__* handle);
	void SetResolution(int nResolutionIdx);
	void SetRefreshRate(int nRefreshRateIdx);
	void SetFullscreen(bool bFullscreen);
	void SetExlusiveFullscreen(bool bExclusiveFullscreen);
	void SetVSync(bool bEnabled);
	void SetMonitor(int nMonitorIdx);
	void SetStereoscopic(bool bStereoscopic);
	void SetStereoDepth(float fDepth);
	void SetStereoStrength(float fStrength);
	void SetAspectratio(int nAspectIdx);
	void SetGamma(float gamma);
	void SetMSAA(int nMSAAIndex);
	void SetQualityProfile(int nProfileIdx);
	void SetShadowQuality(int nQualityIdx);
	void SetTextureFilter(int nQualityIdx);
	void SetTextureResolution(int nQualityIdx);
	void SetSSAO(int nQualityIdx);
	void SetSSGI(bool bEnabled);
	void SetLPV(bool bEnabled);
	void SetTessellation(int nQualityIdx);
	void SetMirrorQuality(int nQualityIdx);
	void SetAntiAliasingQuality(int nQualityIdx);
	void SetLevelOfDetail(int nQualityIdx);
	void SetBokeh(int nType);
	void SetBloom(int nQualityIdx);
	Resolution GetDesiredResolution() const;
	unsigned int GetDesiredRefreshrate() const;
	unsigned int GetDesiredResolutionIndex() const;
	unsigned int GetDesiredRefreshrateIndex() const;
	tagRECT GetCurrentDesktopRect() const;
	void SyncWithRenderDestination();
	const DisplaySetting* GetDisplaySettings() const;
	const QualitySetting* GetQualitySettings() const;
	const TArray<Resolution>& GetResolutions() const;
	const TArray<unsigned int>& GetRefreshrates() const;
	unsigned int GetNumMonitors();
	TArray<Aspectratio>& GetAspectRatios();
	float GetCurrentAspectRatio();
	void SetWindowSize_MessageThread(int nWidth, int nHeight);
	void ScheduleApplyWindowSize_MessageThread();
	void SetDisplaySetting_MessageThread(EDisplaySetting setting, float fValue);
	void SetDisplaySetting_MessageThread(EDisplaySetting setting, int nValue);
	void ScheduleApplyDisplaySettings();
	void ScheduleSaveDisplaySettings();
	void ApplyDisplaySettings();
	void SaveDisplaySettings();
	void SaveDisplaySettingsToRegistry();
	void RestoreDisplaySettings();
	bool DisplaySettingsMatch();
	bool QualitySettingsMatch();
	void ApplyQualitySettings();
	void SaveQualitySettings();
	void RestoreQualitySettings();
	void ResetToDefaultQualitySettings();
	void GenerateSettingsOverview(ZString& overview);
	bool GetSupportsStereoscopic();
	float ConvertStereoStrength(float fSeparation, bool bToPercentage);
	void SetQualitySetting(int setting, int value);
	void DetectMonitorChange();
	void SetWaitingForApply(bool bDisable);
	ZPCOptionsHelper* GetPCOptionsHelper();
	void InitializeDisplaySettings();
	void InitializeQualitySettings();
	void DetectAdapterDefaults();
	bool GetDefaultAdapterSettings(const unsigned int& vendorID, const unsigned int& deviceID, EQualityProfile& profile, Resolution& resolution);
	void DeterminePossibleResolutions();
	void DeterminePossibleRefreshRates();
	void DeterminePossibleMonitors();
	void DeterminePossibleAspectratios();
	void UpdateDesktopRect();
	void OnResolutionChange();
	void OnDisplayOptionChange();
	void OnQualityOptionChange();
	static void GetValueFromApplicationOption(ZString sOption, bool& bOut);
	static void GetValueFromApplicationOption(ZString sOption, int& nOut);
	static void SetBoolValue(HKEY__* regKey, ZString sEntry, bool bValue);
	static void ReadBoolValue(HKEY__* regKey, ZString sEntry, bool& bOut);
	static void SetIntValue(HKEY__* regKey, ZString sEntry, int iValue);
	static void ReadIntValue(HKEY__* regKey, ZString sEntry, int& nOut);
	static void SetFloatValue(HKEY__* regKey, ZString sEntry, float fValue);
	static void ReadFloatValue(HKEY__* regKey, ZString sEntry, float& fValue);
	static void Clamp(int& nInOut, int nMinValue, int nMaxValue);
	void DetermineAspectRatio(float& fAspectRatio, float& fPrimaryAspectRatio);
	void FillEyefinityProperties(EyefinityInfo& info);
};
