#include "HM5DebugConsole.h"

FILE* HM5DebugConsole::file;

void HM5DebugConsole::Initialize()
{
    if (AllocConsole())
    {
        freopen_s(&file, "CONOUT$", "w", stdout);
    }
}

void HM5DebugConsole::Close()
{
    if (file)
    {
        fclose(file);
    }

    FreeConsole();
}
