#pragma once

#include "DataDesc.h"

class GString
{
    union DataDescUnion
    {
        DataDesc* pData;
        unsigned int HeapTypeBits;
    };

    enum HeapType : __int32
    {
        HT_Global = 0x0,
        HT_Local = 0x1,
        HT_Dynamic = 0x2,
        HT_Mask = 0x3
    };

    enum FlagConstants : __int32
    {
        Flag_LengthIsSizeShift = 0x1F
    };

    class NoConstructor
    {

    };

    class InitStruct
    {
    public:
        virtual ~InitStruct();
        virtual void InitString(char*, unsigned int);
    };

    class NoCaseKey
    {
    public:
        const GString* pStr;
    };

    class HashFunctor
    {
    };

    class NoCaseHashFunctor
    {
    };
};
