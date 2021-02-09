#pragma warning(disable : 4005)

#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdarg>
#include <Psapi.h>
#include <TlHelp32.h>
#include <mutex>
#include "MinHook.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include "InputHook.h"
#include "ZRenderManager.h"
#include "ZRenderDevice.h"
#include "ApplicationHooks.h"
#include "ZDebugConsoleHooks.h"
#include "ZInputActionManager.h"
#include "Menu.h"
#include "Globals.h"
#include "BaseAddresses.h"
#include "Mods.h"
#include "HM5DebugConsole.h"

using namespace std;

Menu menu;
InputHook inputHook;
Mods mods;

typedef void(__thiscall* ZRenderDevicePresent)(ZRenderDevice* pThis);

ZRenderDevicePresent pOriginalZRenderDevicePresent;

const int openMenuKey = VK_F9;
static once_flag isInitialized;

static bool gravityGunEnabled;
static bool killNearbyActors;
static bool displayNearbyActorsInfo;

void __fastcall ZRenderDevicePresentHook(ZRenderDevice* pThis)
{
    call_once(isInitialized, [&]()
    {
        ImGui::CreateContext();

        ImGui_ImplWin32_Init(ApplicationHooks::hwnd);
        ImGui_ImplDX11_Init(pThis->m_pDirect3DDevice, pThis->m_pDeviceContextImmediate);

        inputHook.Init(ApplicationHooks::hwnd);
    });

    if (GetAsyncKeyState(openMenuKey) & 0x1)
    {
        menu.isOpen = !menu.isOpen;

        static ZInputActionManager* inputActionManager = *reinterpret_cast<ZInputActionManager**>(Globals::g_pInputActionManagerSingleton);
        
        if (inputActionManager)
        {
            if (!menu.isOpen && !inputActionManager->m_bEnabled)
            {
                inputActionManager->m_bEnabled = true;
            }
            else
            {
                inputActionManager->m_bEnabled = !menu.isOpen;
            }
        }
    }

    menu.Render();

    pOriginalZRenderDevicePresent(pThis);
}

typedef void(__thiscall* InitPatchReader)(void* pThis, ZString* sPatchPath);
InitPatchReader pOriginalInitPatchReader;

void __fastcall InitPatchReaderHook(void* pThis, int padding, ZString* sPatchPath)
{
    pOriginalInitPatchReader(pThis, sPatchPath);
}

typedef void(__thiscall* ResourceReady)(void* pThis, ZRuntimeResourceID id, ZResourceStub* pStub, int nPriority, ZString sFileName, unsigned int nFileOffset);
ResourceReady pOriginalResourceReady;

void __fastcall ResourceReadyHook(void* pThis, int padding, ZRuntimeResourceID id, ZResourceStub* pStub, int nPriority, ZString sFileName, unsigned int nFileOffset)
{
    pOriginalResourceReady(pThis, id, pStub, nPriority, sFileName, nFileOffset);
}

void InitializeGlobalVariables()
{
    Globals::g_pSystemEventHandlerSingleton = BaseAddresses::hitman5Dll + 0xBDAC60;
    Globals::g_pBenchmarkManagerSingleton = BaseAddresses::hitman5Dll + 0xBDAC90;
    Globals::g_pGraphicsSettingsManagerSingleton = BaseAddresses::hitman5Dll + 0xBDAD00;
    Globals::g_pHM5IconLoaderSingleton = BaseAddresses::hitman5Dll + 0xBDAD90;
    Globals::g_pDialogueSubtitleManagerSingleton = BaseAddresses::hitman5Dll + 0xBDC7A0;
    Globals::g_pUniqueIDUtilSingleton = BaseAddresses::hitman5Dll + 0xBDC7B0;
    Globals::g_pSocialNetworkManagerSingleton = BaseAddresses::hitman5Dll + 0xBDC7C0;
    Globals::g_pHM5SaveGameManagerSingleton = BaseAddresses::hitman5Dll + 0xBDC7D0;
    Globals::g_pContentKitManagerSingleton = BaseAddresses::hitman5Dll + 0xBDCAA0;
    Globals::g_pTechniquesManagerSingleton = BaseAddresses::hitman5Dll + 0xBDCB70;
    Globals::g_pDifficultyLevelManagerSingleton = BaseAddresses::hitman5Dll + 0xBDD1E0;
    Globals::g_pFireVolumeManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4B10;
    Globals::g_pVolumeTriggerManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4B30;
    Globals::g_pHM5TimeMultiplierManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4BD0;
    Globals::g_pDecalsSpawnEntityManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4C20;
    Globals::g_pSequenceSkipManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4C30;
    Globals::g_pBulletImpactManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4C40;
    Globals::g_pHM5AimAssistPropManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4C60;
    Globals::g_pContractManagerSingleton = BaseAddresses::hitman5Dll + 0xBE4C70;
    Globals::g_pContractFileInstallerSingleton = BaseAddresses::hitman5Dll + 0xBE5110;
    Globals::g_pOSQueryManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5120;
    Globals::g_pOnlineManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5190;
    Globals::g_pHitmanEventEmitterManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5270;
    Globals::g_pHM5RatingManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5280;
    Globals::g_pChallengeManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5330;
    Globals::g_pHM5IndicatorManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5370;
    Globals::g_pUISoundHandlerSingleton = BaseAddresses::hitman5Dll + 0xBE5390;
    Globals::g_pUIOptionsSingleton = BaseAddresses::hitman5Dll + 0xBE53D0;
    Globals::g_pUITextSingleton = BaseAddresses::hitman5Dll + 0xBE5420;
    Globals::g_pMenuManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5440;
    Globals::g_pHUDManagerSingleton = BaseAddresses::hitman5Dll + 0xBE5770;
    Globals::g_pHM5LocalizationManagerSingleton = BaseAddresses::hitman5Dll + 0xBE86C0;
    Globals::g_pGlobalRumbleManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8700;
    Globals::g_pRigidBodyPoolManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8710;
    Globals::g_pGameContextSingleton = BaseAddresses::hitman5Dll + 0xBE8750;
    Globals::g_pHM5ActionManagerSingleton = BaseAddresses::hitman5Dll + 0xBE87A0;
    Globals::g_pLookAtTriggerManagerSingleton = BaseAddresses::hitman5Dll + 0xBE87C0;
    Globals::g_pBloodSplatCreatorSingleton = BaseAddresses::hitman5Dll + 0xBE87F0;
    Globals::g_pHMStateSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8800;
    Globals::g_pLookAtAimSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8830;
    Globals::g_pThrowSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8840;
    Globals::g_pExplosionSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8850;
    Globals::g_pAgilitySoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8860;
    Globals::g_pWeaponSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8870;
    Globals::g_pKillSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8880;
    Globals::g_pCCPostFilterManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8890;
    Globals::g_pCCSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE88A0;
    Globals::g_pSBTargetPropManagerSingleton = BaseAddresses::hitman5Dll + 0xBE88B0;
    Globals::g_pSBSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xBE88E0;
    Globals::g_pHM5SoundGlobalDataSingleton = BaseAddresses::hitman5Dll + 0xBE88F0;
    Globals::g_pHM5GridManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8910;
    Globals::g_pInstinctManagerSingleton = BaseAddresses::hitman5Dll + 0xBE8BF0;
    Globals::g_pNPCAvoidanceManagerSingleton = BaseAddresses::hitman5Dll + 0xBE9020;
    Globals::g_pAIStateSingleton = BaseAddresses::hitman5Dll + 0xBE9040;
    Globals::g_pActorManagerSingleton = BaseAddresses::hitman5Dll + 0xC819E0;
    Globals::g_pGameStatsManagerSingleton = BaseAddresses::hitman5Dll + 0xCA49B0;
    Globals::g_pBehaviorTreeEntityBlueprintInstallerSingleton = BaseAddresses::hitman5Dll + 0xCA4D20;
    Globals::g_pBehaviorTreeEntityTypeInstallerSingleton = BaseAddresses::hitman5Dll + 0xCA4D30;
    Globals::g_pCompiledBehaviorTreeResourceInstallerSingleton = BaseAddresses::hitman5Dll + 0xCA4D40;
    Globals::g_pHM5CollisionManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4D50;
    Globals::g_pGuideManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4D60;
    Globals::g_pHM5RagdollManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4DC0;
    Globals::g_pZoneManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4DE0;
    Globals::g_pAreaManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4E30;
    Globals::g_pLevelSelectManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4E50;
    Globals::g_pLevelManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4E80;
    Globals::g_pCoverManagerSingleton = BaseAddresses::hitman5Dll + 0xCA4FC0;
    Globals::g_pActivatableManagerSingleton = BaseAddresses::hitman5Dll + 0xCA5030;
    Globals::g_pMemoryReportingManagerSingleton = BaseAddresses::hitman5Dll + 0xCA50D0;
    Globals::g_pCheckPointManagerSingleton = BaseAddresses::hitman5Dll + 0xCA50F0;
    Globals::g_pGameWideUISingleton = BaseAddresses::hitman5Dll + 0xCA5200;
    Globals::g_pDebugConsoleSingleton = BaseAddresses::hitman5Dll + 0xCA54F0;
    Globals::g_pHitman5Module = BaseAddresses::hitman5Dll + 0xCA5618;
    Globals::g_pGlobalBoneRegistrySingleton = BaseAddresses::hitman5Dll + 0xD9DB18;
    Globals::g_pGameTimeManagerSingleton = BaseAddresses::hitman5Dll + 0xD9DBCC;
    Globals::g_pLoadTimeStatisticsSingleton = BaseAddresses::hitman5Dll + 0xD9DC40;
    Globals::g_pGameLoopManagerSingleton = BaseAddresses::hitman5Dll + 0xD9DC48;
    Globals::g_ThreadIdMainThread = BaseAddresses::hitman5Dll + 0xD9DE04;
    Globals::g_pEntitySingletonManagerSingleton = BaseAddresses::hitman5Dll + 0xD9DED8;
    Globals::g_pStreamingStateManagerSingleton = BaseAddresses::hitman5Dll + 0xD9DEF0;
    Globals::g_pEntityManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E028;
    Globals::g_pShatterManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E1E0;
    Globals::g_pInputActionManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E220;
    Globals::g_pInputDeviceManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E230;
    Globals::g_pLocalizationManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E2D0;
    Globals::g_pSubtitleManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E2E0;
    Globals::g_pMorphemeMediatorSingleton = BaseAddresses::hitman5Dll + 0xD9E450;
    Globals::g_pPathfinder2Singleton = BaseAddresses::hitman5Dll + 0xD9E5D8;
    Globals::g_pCollisionManagerSingletonInterface = BaseAddresses::hitman5Dll + 0x10D9E644;
    Globals::g_pPhysicsManagerSingletonInterface = BaseAddresses::hitman5Dll + 0x10D9E64C;
    Globals::g_pRagdollManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E650;
    Globals::g_pClothManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E67C;
    Globals::g_pUserProfileManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E75C;
    Globals::g_pDLCManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E760;
    Globals::g_pSaveGameManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E76C;
    Globals::g_pEncryptedAllocatorSingleton = BaseAddresses::hitman5Dll + 0xD9E770;
    Globals::g_pContractsCodeRedemptionManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E774;
    Globals::g_pCommerceBrowserSingleton = BaseAddresses::hitman5Dll + 0xD9E778;
    Globals::g_pGridManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E7AC;
    Globals::g_pParticleManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E890;
    Globals::g_pVideoPlaybackStatusSingleton = BaseAddresses::hitman5Dll + 0xD9E8BC;
    Globals::g_nEnableDOFOverride = BaseAddresses::hitman5Dll + 0xD9E97C;
    Globals::g_pRenderGraphManagerSingleton = BaseAddresses::hitman5Dll + 0xD9E98C;
    Globals::g_pRoomManagerCreatorSingleton = BaseAddresses::hitman5Dll + 0xD9EA9C;
    Globals::g_pRenderManagerSingleton = BaseAddresses::hitman5Dll + 0xD9EAB0;
    Globals::g_pResourceManagerSingleton = BaseAddresses::hitman5Dll + 0xD9EB84;
    Globals::g_pResourceStreamerSingleton = BaseAddresses::hitman5Dll + 0xD9EC24;
    Globals::g_pResourceLibraryManagerSingleton = BaseAddresses::hitman5Dll + 0xD9EC2C;
    Globals::g_pScaleformManagerSingleton = BaseAddresses::hitman5Dll + 0xD9ECC8;
    Globals::g_pScatterManagerSingleton = BaseAddresses::hitman5Dll + 0xD9ECF8;
    Globals::g_pSequenceManagerSingleton = BaseAddresses::hitman5Dll + 0xD9ED5C;
    Globals::g_pSoundManagerSingleton = BaseAddresses::hitman5Dll + 0xD9ED8C;
    Globals::g_pSoundGateManagerSingleton = BaseAddresses::hitman5Dll + 0xD9EDA0;
    Globals::g_pSoundAmbienceManagerSingleton = BaseAddresses::hitman5Dll + 0xD9EDA8;
    Globals::g_pSoundBlendManagerSingleton = BaseAddresses::hitman5Dll + 0xD9EDC8;
    Globals::g_pLoadingScreenVideoPlayerSingleton = BaseAddresses::hitman5Dll + 0xD9EE30;
}

void GetDLLAddresses()
{
    uintptr_t engine = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
    uintptr_t hitman5Dll = reinterpret_cast<uintptr_t>(GetModuleHandle(L"hitman5Dll.dll"));
    uintptr_t runtimeRenderDll = reinterpret_cast<uintptr_t>(GetModuleHandle(L"runtime.render.dll"));
    uintptr_t runtimeInputDll = reinterpret_cast<uintptr_t>(GetModuleHandle(L"runtime.input.dll"));
    uintptr_t runtimePathFinder = reinterpret_cast<uintptr_t>(GetModuleHandle(L"runtime.pathfinder.dll"));
    uintptr_t runtimeEntity = reinterpret_cast<uintptr_t>(GetModuleHandle(L"runtime.entity.dll"));
    uintptr_t runtimeResource = reinterpret_cast<uintptr_t>(GetModuleHandle(L"runtime.resource.dll"));

    BaseAddresses::engine = engine;
    BaseAddresses::hitman5Dll = hitman5Dll;
    BaseAddresses::runtimeRenderDll = runtimeRenderDll;
    BaseAddresses::runtimeInputDll = runtimeInputDll;
    BaseAddresses::runtimePathFinder = runtimePathFinder;
    BaseAddresses::runtimeEntity = runtimeEntity;
    BaseAddresses::runtimeResource = runtimeResource;
}

DWORD WINAPI MainThread(HMODULE hModule)
{
    HM5DebugConsole::Initialize();

    if (MH_Initialize() != MH_OK)
    {
        HM5_LOG("Initialize failed\n");

        return 0;
    }

    GetDLLAddresses();
    InitializeGlobalVariables();

    ZRenderDevicePresent pZRenderDevicePresent = reinterpret_cast<ZRenderDevicePresent>(BaseAddresses::runtimeRenderDll + 0xBB5A0);

    if (MH_CreateHook(reinterpret_cast<LPVOID>(pZRenderDevicePresent), reinterpret_cast<LPVOID>(ZRenderDevicePresentHook), reinterpret_cast<LPVOID*>(&pOriginalZRenderDevicePresent)) != MH_OK)
    {
        HM5_LOG("IFailed to create ZRenderDevicePresent hook.\n");

        return 1;
    }

    if (MH_EnableHook(reinterpret_cast<LPVOID>(pZRenderDevicePresent)) != MH_OK)
    {
        HM5_LOG("Failed to enable ZRenderDevicePresent hook.\n");

        return 1;
    }

    InitPatchReader pInitPatchReader = reinterpret_cast<InitPatchReader>(BaseAddresses::runtimeResource + 0x374F0);

    if (MH_CreateHook(reinterpret_cast<LPVOID>(pInitPatchReader), reinterpret_cast<LPVOID>(InitPatchReaderHook), reinterpret_cast<LPVOID*>(&pOriginalInitPatchReader)) != MH_OK)
    {
        HM5_LOG("IFailed to create InitPatchReader hook.\n");

        return 1;
    }

    if (MH_EnableHook(reinterpret_cast<LPVOID>(pInitPatchReader)) != MH_OK)
    {
        HM5_LOG("Failed to enable InitPatchReader hook.\n");

        return 1;
    }

    ResourceReady pResourceReady = reinterpret_cast<ResourceReady>(BaseAddresses::runtimeResource + 0x212B0);

    if (MH_CreateHook(reinterpret_cast<LPVOID>(pResourceReady), reinterpret_cast<LPVOID>(ResourceReadyHook), reinterpret_cast<LPVOID*>(&pOriginalResourceReady)) != MH_OK)
    {
        HM5_LOG("IFailed to create ResourceReady hook.\n");

        return 1;
    }

    if (MH_EnableHook(reinterpret_cast<LPVOID>(pResourceReady)) != MH_OK)
    {
        HM5_LOG("Failed to enable ResourceReady hook.\n");

        return 1;
    }

    ApplicationHooks::CreateAndEnableHooks();
    ZDebugConsoleHooks::CreateAndEnableHooks();

    while (true)
    {
        if (GetAsyncKeyState(VK_F3) & 1)
        {
            break;
        }

        if (GetAsyncKeyState(VK_F4) & 1)
        {
            gravityGunEnabled = !gravityGunEnabled;
        }

        if (GetAsyncKeyState(VK_F5) & 1)
        {
            killNearbyActors = !killNearbyActors;
        }

        if (GetAsyncKeyState(VK_F6) & 1)
        {
            displayNearbyActorsInfo = !displayNearbyActorsInfo;
        }

        if (gravityGunEnabled)
        {
            mods.EnableGravityGun();
        }

        if (killNearbyActors)
        {
            mods.KillNearbyActors();
        }

        if (displayNearbyActorsInfo)
        {
            mods.DisplayNearbyActorsInfo();
        }

        Sleep(5);
    }

    if (MH_DisableHook(MH_ALL_HOOKS) != MH_OK)
    {
        HM5_LOG("Failed to disable.\n");

        return 1;
    }

    if (MH_Uninitialize() != MH_OK)
    { 
        HM5_LOG("MH_Uninitialize failed.\n");

        return 1;
    }

    inputHook.Remove(ApplicationHooks::hwnd);

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    HM5DebugConsole::Close();
    FreeLibraryAndExitThread(hModule, 0);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
        HANDLE hdl = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr);

        if (hdl)
        {
            CloseHandle(hdl);
        }

        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}
