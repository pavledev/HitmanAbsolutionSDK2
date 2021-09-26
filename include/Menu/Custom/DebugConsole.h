#pragma once

#include <ctype.h>
#include <cstdlib>
#include <iostream>
#include "imgui.h"
#include "Singletons.h"
#include "ZDebugConsole.h"
#include "ZConfigFloat.h"
#include <sstream>

using namespace std;

struct DebugConsole
{
    char inputBuffer[256] = { 0 };
    ImVector<char*> items;

    struct State
    {
        bool isPopupOpen;
        int  activeIndex;
    };

    DebugConsole();
    ~DebugConsole();

    static int Stricmp(const char* s1, const char* s2);
    static int Strnicmp(const char* s1, const char* s2, int n);
    static char* Strdup(const char* s);
    static void Strtrim(char* s);

    void ClearLog();
    void AddLog(const char* fmt, ...) IM_FMTARGS(2);
    void DrawWindow(bool* showDebugConsole);
    void ExecuteCommand(const char* command_line);
    void GetCommands();
    bool ContainsCommand();
    int TextEditCallback(ImGuiInputTextCallbackData* data);
};