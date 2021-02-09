#pragma once

#include "THashMap.h"
#include "ZEvent.h"
#include "ZEventNull.h"
#include "_EUIOptionKey.h"
#include "ZHM5SaveData.h"
#include "TDefaultHashMapPolicy.h"

template<class T>
class Values
{
public:
    class ValueBase
    {
    public:
        ZEvent<T, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_Event;

        virtual ~ValueBase();
        virtual bool Get();
        virtual bool UnSet();
        virtual bool Set(T);
        virtual void Write(_EUIOptionKey, ZHM5SaveData*);
        virtual bool IsDefault();
    };

    THashMap<unsigned int, ValueBase*, TDefaultHashMapPolicy<unsigned int, ValueBase*>> m_values;
};
