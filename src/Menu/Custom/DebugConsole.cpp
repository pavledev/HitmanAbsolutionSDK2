#include "DebugConsole.h"
#include <imgui_internal.h>

static ImVector<const char*> commands;

DebugConsole::DebugConsole()
{
    ClearLog();
}

DebugConsole::~DebugConsole()
{
    ClearLog();
}

int DebugConsole::Stricmp(const char* s1, const char* s2)
{ 
    int d;

    while ((d = toupper(*s2) - toupper(*s1)) == 0 && *s1)
    { 
        s1++;
        s2++;
    }

    return d;
}

int DebugConsole::Strnicmp(const char* s1, const char* s2, int n)
{ 
    int d = 0;

    while (n > 0 && (d = toupper(*s2) - toupper(*s1)) == 0 && *s1)
    { 
        s1++;
        s2++;
        n--;
    }

    return d;
}

char* DebugConsole::Strdup(const char* s)
{ 
    IM_ASSERT(s);
    size_t length = strlen(s) + 1;
    void* buffer = malloc(length);
    IM_ASSERT(buffer);

    return (char*)memcpy(buffer, (const void*)s, length);
}

void DebugConsole::Strtrim(char* s)
{ 
    char* strEnd = s + strlen(s);

    while (strEnd > s && strEnd[-1] == ' ')
    {
        strEnd--;
    }

    *strEnd = 0;
}

void DebugConsole::ClearLog()
{
    for (int i = 0; i < items.Size; i++)
    {
        free(items[i]);
    }

    items.clear();
}

void DebugConsole::AddLog(const char* fmt, ...) IM_FMTARGS(2)
{
    char buffer[256];

    va_list args;
    va_start(args, fmt);

    vsprintf_s(buffer, IM_ARRAYSIZE(buffer), fmt, args);
    buffer[IM_ARRAYSIZE(buffer) - 1] = 0;

    va_end(args);

    items.push_back(Strdup(buffer));
}

static int TextEditCallbackStub(ImGuiInputTextCallbackData* data)
{
    DebugConsole* console = (DebugConsole*)data->UserData;
    return console->TextEditCallback(data);
}

int DebugConsole::TextEditCallback(ImGuiInputTextCallbackData* data)
{
    State& state = *reinterpret_cast<State*>(data->UserData);

    switch (data->EventFlag)
    {
    case ImGuiInputTextFlags_CallbackAlways:
        if (state.activeIndex != -1)
        {
            data->DeleteChars(0, data->BufTextLen);
            data->InsertChars(0, commands[state.activeIndex]);

            state.activeIndex = -1;
        }

        break;
    }

    return 0;
}

void DebugConsole::DrawWindow(bool* showDebugConsole)
{
    static State state =
    {
        false,
        -1
    };

    /// Begin main window
    ImGui::SetNextWindowSize(ImVec2(640, 480), ImGuiCond_FirstUseEver);

    if (!ImGui::Begin("Debug Console", showDebugConsole))
    {
        ImGui::End();
        return;
    }

    ImGui::TextWrapped("Debug console for entering game debug variables");
    ImGui::TextWrapped("Enter 'HELP' for help.");

    if (ImGui::SmallButton("Clear")) 
    { 
        ClearLog();
    }

    ImGui::SameLine();
    bool copyToClipboard = ImGui::SmallButton("Copy");
    //static float t = 0.0f; if (ImGui::GetTime() - t > 0.02f) { t = ImGui::GetTime(); AddLog("Spam %f", t); }

    ImGui::Separator();

    /// Draw any window content here
    {
        const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();

        ImGui::BeginChild("scrollRegion", ImVec2(0, -footer_height_to_reserve),
            true, ImGuiWindowFlags_HorizontalScrollbar
        );

        if (copyToClipboard)
        {
            ImGui::LogToClipboard();
        }

        for (int i = 0; i < items.Size; i++)
        {
            const char* item = items[i];

            // Normally you would store more information in your item than just a string.
            // (e.g. make Items[] an array of structure, store color/type etc.)
            ImVec4 color;
            bool hasColor = false;

            if (strstr(item, "not found") || strstr(item, "Invalid ") || strstr(item, "Unknown"))
            {
                color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f);
                hasColor = true;
            }
            else if (strstr(item, ">") || strstr(item, "- "))
            {
                color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);
                hasColor = true;
            }

            if (hasColor)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, color);
            }

            ImGui::TextUnformatted(item);

            if (hasColor)
            {
                ImGui::PopStyleColor();
            }
        }

        if (copyToClipboard)
        {
            ImGui::LogFinish();
        }

        if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
        {
            ImGui::SetScrollHereY(1.0f);
        }

        ImGui::EndChild();
    }

    bool reclaimFocus = false;
    ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackAlways;

    if (ImGui::InputText("Command", inputBuffer, IM_ARRAYSIZE(inputBuffer), flags, &TextEditCallbackStub, &state))
    {
        char* s = inputBuffer;
        Strtrim(s);

        if (s[0])
        {
            ExecuteCommand(s);
        }

        inputBuffer[0] = '\0';
        reclaimFocus = true;
    }

    ImGui::SameLine();
    state.isPopupOpen = inputBuffer[0] != '\0' && !ContainsCommand();

    if (state.isPopupOpen)
    {
        ImGui::SetNextWindowPos({ ImGui::GetItemRectMin().x, ImGui::GetItemRectMax().y });
        ImGui::SetNextWindowSize({ ImGui::GetItemRectSize().x, ImGui::GetFrameHeightWithSpacing() * 4 });

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_Tooltip;

        if (ImGui::Begin("popup", &state.isPopupOpen, windowFlags))
        {
            ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());

            for (int i = 0; i < commands.Size; i++)
            {
                if (!strstr(commands[i], inputBuffer))
                {
                    continue;
                }

                if (ImGui::Selectable(commands[i]) || (ImGui::IsItemFocused() && ImGui::IsKeyPressedMap(ImGuiKey_Enter)))
                {
                    state.isPopupOpen = false;
                    state.activeIndex = i;
                    reclaimFocus = true;
                }
            }
        }

        ImGui::End();
    }

    // Auto-focus on window apparition
    ImGui::SetItemDefaultFocus();

    if (reclaimFocus)
    {
        ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget
    }

    ImGui::End();

    if (commands.Size == 0)
    {
        GetCommands();
    }
}

void DebugConsole::ExecuteCommand(const char* command)
{
    if (Stricmp(command, "CLEAR") == 0)
    {
        ClearLog();
    }
    else if (Stricmp(command, "HELP") == 0)
    {
        AddLog("Commands:");

        for (int i = 0; i < commands.Size; i++)
        {
            AddLog("- %s", commands[i]);
        }
    }
    else
    {
        ZDebugConsole* debugConsole = (ZDebugConsole*)(BaseAddresses::hitman5Dll + 0xCA54F0);

        if (debugConsole)
        {
            debugConsole->ExecuteCommand(command);
        }
    }
}

void DebugConsole::GetCommands()
{
    ZConfigFloat* zConfigCommand = reinterpret_cast<ZConfigFloat*>(ZConfigCommand::First());

    if (zConfigCommand)
    {
        string name = zConfigCommand->m_pszName;

        ostringstream ss;
        ss << zConfigCommand->m_Value;
        string value(ss.str());

        value.insert(0, " ");

        string command = name + " " + value;

        commands.push_back(Strdup(command.c_str()));

        while ((zConfigCommand = reinterpret_cast<ZConfigFloat*>(zConfigCommand->Next())) != nullptr)
        {
            string name = zConfigCommand->m_pszName;

            ostringstream ss;
            ss << zConfigCommand->m_Value;
            string value(ss.str());

            value.insert(0, " ");

            string command = name + " " + value;

            commands.push_back(Strdup(command.c_str()));
        }
    }
}

bool DebugConsole::ContainsCommand()
{
    for (int i = 0; i < commands.Size; i++)
    {
        if (strcmp(commands[i], inputBuffer) == 0)
        {
            return true;
        }
    }

    return false;
}
