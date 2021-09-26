#pragma once

#include "ZWin32ApplicationBase.h"
#include "ZEngineAppCommon.h"
#include "CCallback.h"
#include "ZString.h"
#include "ZThread.h"
#include "ZThreadEvent.h"

class IIniFile;
struct GameOverlayActivated_t;
struct HICON__;
struct HINSTANCE__;
struct HWND__;

class ZApplicationEngineWin32 : public ZWin32ApplicationBase
{
public:
	enum SteamInitResult
	{
		STEAM_INIT_OK = 0,
		STEAM_INIT_FAILED = 1,
		STEAM_INIT_NOTSUBSCRIBED = 2
	};

	struct WindowCreationParameters
	{
		HINSTANCE__* m_hInstance;
		HWND__* m_hParent;
		ZString m_sSceneFile;
		int m_nX;
		int m_nY;
		unsigned int m_nWidth;
		unsigned int m_nHeight;
		int m_nShowWindowCmd;
		bool m_bFullScreen;

		WindowCreationParameters() = default;
		~WindowCreationParameters() = default;
	};

	bool m_bUseSteam;
	SteamInitResult m_nSteamInitResult;
	bool m_bGSMBusy;
	ZEngineAppCommon m_common;
	WindowCreationParameters m_WindowCreationParameters;
	ZThread m_messageLoopThread;
	ZThreadEvent m_messageLoopThreadEvent;
	CCallback<ZApplicationEngineWin32, GameOverlayActivated_t, 0> m_overlayActivated;
	ZThreadEvent m_mainLoopDoneEvent;
	HWND__* m_hWnd;
	bool m_bTerminateApplication;
	bool m_bShowingCursor;
	bool m_bTempWindowed;
	bool m_bPauseGameLoop;
	bool m_bGameLoopPaused;
	int m_PreviousMasterVolume;
	bool m_bChangeMasterVolume;
	int m_TargetMasterVolume;
	bool m_bActive;
	HICON__* m_hDefaultCursor;
	static ZApplicationEngineWin32* m_pInstance;

	~ZApplicationEngineWin32() override = default;
	void OnAfterInitialize() override;
	void OnBeforeShutdown() override;
	void Exit() override;
	void Initialize(const ZString& sDefaultSettings) override;
	void AddApplicationSpecificOptions(IIniFile* pIniFile) override;
	bool Startup() override;
	void Shutdown() override;
	int Main(int argc, char** argv) override;

	ZApplicationEngineWin32() = default;
	ZApplicationEngineWin32(int argc, char** argv);
	void OnMainWindowActivated(bool bActive);
	void MainLoop();
	unsigned int MessageLoopThreadFunc(void* __formal);
	void InitSteam();
	bool HandleSteamInitResult();
	void OnOverlayActivated(GameOverlayActivated_t* param);
	long MainWindowProc(HWND__* hWnd, unsigned int uMsgId, unsigned int wParam, long lParam);
	void CreateMainWindow(HINSTANCE__* hInstance, HWND__* hParent, const ZString& sSceneFile, int nX, int nY, unsigned int nWidth, unsigned int nHeight, bool bFullScreen, int nShowWindowCmd);
	void UpdateMouseCursor();
	void UpdateClipState();
};
