#pragma once

struct STypeFunctions
{
    void placementConstruct(void*);
    void placementCopyConstruct(void*, const void*);
    void destruct(void*);
    void assign(void*, const void*);
};
