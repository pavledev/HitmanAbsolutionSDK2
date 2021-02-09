#include "Menu.h"

using namespace ImGui;

DebugConsole Menu::console;
PlayerInfo Menu::playerInfo;
ActorsInfo Menu::actorsInfo;
ItemsInfo Menu::itemsInfo;
HUDInfo Menu::hudInfo;
GameStatsInfo Menu::gameStatsInfo;
Cheats Menu::cheats;
UIOptions Menu::uiOptions;

void Menu::Render()
{
	ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowSize(ImVec2(450, 600));

	ImGui::GetIO().MouseDrawCursor = isOpen;

    if (showDebugConsole)
    {
        console.DrawWindow(&showDebugConsole);
    }

    if (showPlayerInfo)
    {
        playerInfo.DrawWindow(&showPlayerInfo);
    }

    if (showActorsInfo)
    {
        actorsInfo.DrawWindow(&showActorsInfo);
    }

    if (showItemsInfo)
    {
        itemsInfo.DrawWindow(&showItemsInfo);
    }

    if (showHUDInfo)
    {
        hudInfo.DrawWindow(&showHUDInfo);
    }

    if (showGameStatsInfo)
    {
        gameStatsInfo.DrawWindow(&showGameStatsInfo);
    }

    if (showCheats)
    {
        cheats.DrawWindow(&showCheats);
    }

    if (showUIOptions)
    {
        uiOptions.DrawWindow(&showUIOptions);
    }

	if (isOpen)
	{
        ImGui::Begin("Tools", &isOpen, ImGuiWindowFlags_MenuBar);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Options"))
            {
                ImGui::MenuItem("Debug Console", nullptr, &showDebugConsole);
                ImGui::MenuItem("Player Info", nullptr, &showPlayerInfo);
                ImGui::MenuItem("Actors Info", nullptr, &showActorsInfo);
                //ImGui::MenuItem("Items Info", nullptr, &showItemsInfo);
                ImGui::MenuItem("HUD Info", nullptr, &showHUDInfo);
                ImGui::MenuItem("Game Stats", nullptr, &showGameStatsInfo);
                ImGui::MenuItem("Cheats", nullptr, &showCheats);
                ImGui::MenuItem("UI Options", nullptr, &showUIOptions);
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        static ZInputActionManager* inputActionManager = *reinterpret_cast<ZInputActionManager**>(Globals::g_pInputActionManagerSingleton);
        static ZInputDeviceManager* inputDeviceManager = *reinterpret_cast<ZInputDeviceManager**>(Globals::g_pInputDeviceManagerSingleton);

        ImGui::Checkbox("Enable Input", &inputActionManager->m_bEnabled);
        ImGui::Checkbox("Enable Debug Keys", &inputDeviceManager->m_bDebugKeysEnabled);
        ImGui::Text("");

        ImGui::End();
	}

	ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
