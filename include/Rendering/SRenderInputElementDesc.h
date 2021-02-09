#pragma once

struct SRenderInputElementDesc
{
    unsigned __int8 nOffset;
    __int32 eFormat : 8;
    __int32 eElement : 8;
    unsigned __int8 nElementIndex;
    unsigned __int8 nStreamIndex;
    __int32 eClassification : 8;
    unsigned __int16 nInstanceDataStepRate;
};
