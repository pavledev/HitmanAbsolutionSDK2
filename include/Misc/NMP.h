#pragma once

struct NMP
{
    struct Memory
    {
        enum EAllocationColor : __int32
        {
            ALLOCCOLOR_UNKNOWN = 0x0,
            ALLOCCOLOR_FREELIST = 0x1,
            ALLOCCOLOR_OBJECT_POOL = 0x2,
            ALLOCCOLOR_NETWORK_INSTANCE = 0x3,
            ALLOCCOLOR_ANIM_QSA = 0x4,
            ALLOCCOLOR_NM_FIBER = 0x5,
            ALLOCCOLOR_ANIM_PLAYER_BUFFER = 0x6,
        };

        enum eAllocationType : __int32
        {
            kUnknown = 0x0,
            kPermanent = 0x1,
            kTemporary = 0x2,
        };

        class Format
        {
        public:
            unsigned int size;
            unsigned int alignment;
        };

        class Resource
        {
        public:
            void* ptr;
            Format format;
        };

        struct Config
        {
            void* (__cdecl* allocator)(unsigned int, eAllocationType, EAllocationColor);
            void* (__cdecl* alignedAllocator)(unsigned int, unsigned int, eAllocationType, EAllocationColor);
            void* (__cdecl* callocator)(unsigned int, eAllocationType, EAllocationColor);
            void(__cdecl* deallocator)(void*);
            void(__cdecl* memcpy)(void*, const void*, unsigned int);
        };
    };

    class BitArray
    {
    public:
        unsigned int m_numBits;
        unsigned int m_numUInts;
        unsigned int m_data[1];
    };

    class DataBuffer
    {
    public:
        enum ElementType : unsigned __int32
        {
            NMP_ELEMENT_TYPE_INT = 0x0,
            NMP_ELEMENT_TYPE_FLOAT = 0x1,
            NMP_ELEMENT_TYPE_VEC3 = 0x2,
            NMP_ELEMENT_TYPE_VEC4 = 0x3,
            NMP_ELEMENT_TYPE_QUAT = 0x4,
            NMP_ELEMENT_TYPE_QUAT_COMP = 0x5,
            NMP_ELEMENT_TYPE_POS_COMP = 0x6,
            NMP_ELEMENT_TYPE_MATRIX = 0x7,
            NMP_ELEMENT_TYPE_MAX = 0x8,
            NMP_ELEMENT_TYPE_VEL = 0x9,
            NMP_ELEMENT_TYPE_ANGVEL = 0xA,
            NMP_ELEMENT_TYPE_USER = 0xFFFF0000,
        };

        struct ElementDescriptor
        {
            DataBuffer::ElementType type;
            unsigned int size;
            unsigned int alignment;
        };

        Memory::Format m_memoryReqs;
        unsigned int m_length;
        unsigned int m_numElements;
        DataBuffer::ElementDescriptor* m_elements;
        void** m_data;
        BitArray* m_usedFlags;
    };

    class Hierarchy
    {
    public:
        unsigned int m_NumEntries;
        int* m_HierarchyArray;
    };

    class Vector3
    {
    public:
        union
        {
            struct
            {
                float x;
                float y;
                float z;
                float w;
            };

            float f[4];

            enum InitZeroType
            {
                InitZero = 0x0
            };

            enum InitOneType
            {
                InitOne = 0x0
            };

            enum InitOneXType
            {
                InitOneX = 0x0
            };

            enum InitOneYType
            {
                InitOneY = 0x0
            };

            enum InitOneZType
            {
                InitOneZ = 0x0
            };
        };
    };

    struct StringTable
    {
        unsigned int m_NumEntrys;
        unsigned int m_DataLength;
        unsigned int* m_IDs;
        unsigned int* m_Offsets;
        const char* m_Data;
    };

    class Quat
    {
    public:
        float x;
        float y;
        float z;
        float w;
    };

    class Pool
    {
    public:
        BitArray* m_usedEntries;
        unsigned __int8* m_entries;
        unsigned int m_maxNumEntries;
        unsigned int m_numRemainingEntries;
        unsigned int m_entryStride;
    };

    class SequentialFitAllocator
    {
    public:
        unsigned int m_defaultBlockSize;

        struct MemoryBlock
        {
            unsigned int size;
            MemoryBlock* next;
        } * m_memoryBlock;

        unsigned int m_numBytesAllocated;
    };
};