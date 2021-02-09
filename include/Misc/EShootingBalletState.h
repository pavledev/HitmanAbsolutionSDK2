#pragma once

enum EShootingBalletState : __int32
{
    eNotInShootingBallet = 0x0,
    eEnteringFromCover = 0x1,
    eTagging = 0x2,
    eExecuting = 0x3,
    eWaitOutroAnim = 0x4,
    eTerminateControl = 0x5
};
