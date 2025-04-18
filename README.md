# Hitman Absolution SDK

## Requirements
 1. DirectX SDK
 2. NVIDIA PhysX SDK
 3. FMOD SDK
 4. MinHook

## Usage
 1. Create Debug folder in main directory of Hitman Absolution and copy files from this link https://debugging.games/_files/Windows/[WIN]%20Hitman%20Absolution%20[2012-12-18]%20(PDB).7z to it
 2. Copy HitmanAbsolutionSDK.dll to Debug folder
 3. For injecting DLL copy dinput8.dll (https://github.com/pavledev/DInput8Proxy) to Debug folder or use any DLL injector
 4. Run RelocateExportTable.exe (https://github.com/pavledev/RelocateExportTable) and export classes listed here https://github.com/pavledev/HitmanAbsolutionSDK/wiki
 5. Convert dll files to lib files
 6. Run engine.exe

## Mods
- F4 - Gravity Gun - move actors, items and props while aiming at them (they can be launched with arbitrary force and direction)\
While aiming use . and , keys to move actor, item, or prop back and forth
- F5 - Kill Nearby Actors - kill actors by walking near them
- F6 - Display Nearby Actors Info - displays actor's name and type
- F7 - Grappling Hook
- F8 - Fly
- F9 - Menu
  - Debug Console
  - Actors Info (Change actors positions, kill actors, teleport to player, ...)
  - Player Info (Modify health, modify ammo, change outfit, teleport, ...)
  - Items Info (Modify ammo, change position, teleport items, add items to inventory)
  - Props Info (Modify position)
  - HUD Info (Modify weapons ammo, create text)
  - Game Stats Info (Kill count, ...)
  - Cheats (Infinite health, infinite ammo, invisibility, refill instinct bar)
  - UI Options (Change graphics settings)
