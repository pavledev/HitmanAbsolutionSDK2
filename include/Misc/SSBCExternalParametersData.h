#pragma once

#include "TArray.h"
#include "SSBCExternalParametersProperties.h"

class SSBCExternalParametersData
{
public:
    unsigned int m_nNumParameters;
    unsigned int m_nOffsetToParameters;
    TArray<unsigned int> m_aParameterIDs;
    TArray<SSBCExternalParametersProperties> m_aMinMaxDefaultValues;
};
