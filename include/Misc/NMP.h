#pragma once

namespace NMP
{
    namespace Memory
    {
        enum EAllocationColor
        {
            ALLOCCOLOR_UNKNOWN = 0,
            ALLOCCOLOR_FREELIST = 1,
            ALLOCCOLOR_OBJECT_POOL = 2,
            ALLOCCOLOR_NETWORK_INSTANCE = 3,
            ALLOCCOLOR_ANIM_QSA = 4,
            ALLOCCOLOR_NM_FIBER = 5,
            ALLOCCOLOR_ANIM_PLAYER_BUFFER = 6
        };

        enum eAllocationType
        {
            kUnknown = 0,
            kPermanent = 1,
            kTemporary = 2
        };

        struct Format
        {
            unsigned int size;
            unsigned int alignment;

            Format() = default;
            ~Format() = default;
        };

        struct Resource
        {
            void* ptr;
            Format format;

            Resource() = default;
            ~Resource() = default;
        };

        struct Config
        {
            void* (*allocator)(unsigned int param1, eAllocationType param2, EAllocationColor allocationColor);
            void* (*alignedAllocator)(unsigned int param1, unsigned int param2, eAllocationType param3, EAllocationColor allocationColor);
            void* (*callocator)(unsigned int param1, eAllocationType param2, EAllocationColor allocationColor);
            void (*deallocator)(void* param1);
            void (*memcpy)(void* param1, const void* param2, unsigned int param3);

            Config() = default;
            ~Config() = default;
        };
    };

    class BitArray
    {
    public:
        unsigned int m_numBits;
        unsigned int m_numUInts;
        unsigned int m_data[1];

        static const unsigned int INVALID_INDEX;

        BitArray() = default;
        ~BitArray() = default;
    };

    class DataBuffer
    {
    public:
        enum ElementType
        {
            NMP_ELEMENT_TYPE_INT = 0,
            NMP_ELEMENT_TYPE_FLOAT = 1,
            NMP_ELEMENT_TYPE_VEC3 = 2,
            NMP_ELEMENT_TYPE_VEC4 = 3,
            NMP_ELEMENT_TYPE_QUAT = 4,
            NMP_ELEMENT_TYPE_QUAT_COMP = 5,
            NMP_ELEMENT_TYPE_POS_COMP = 6,
            NMP_ELEMENT_TYPE_MATRIX = 7,
            NMP_ELEMENT_TYPE_MAX = 8,
            NMP_ELEMENT_TYPE_VEL = 9,
            NMP_ELEMENT_TYPE_ANGVEL = 10,
            NMP_ELEMENT_TYPE_USER = 4294901760
        };

        struct ElementDescriptor
        {
            ElementType type;
            unsigned int size;
            unsigned int alignment;
        };

        Memory::Format m_memoryReqs;
        unsigned int m_length;
        unsigned int m_numElements;
        ElementDescriptor* m_elements;
        void** m_data;
        BitArray* m_usedFlags;

        static ElementDescriptor PosQuatDescriptor[2];

        DataBuffer() = default;
        ~DataBuffer() = default;
    };

    class Hierarchy
    {
    public:
        unsigned int m_NumEntries;
        int* m_HierarchyArray;

        Hierarchy() = default;
        ~Hierarchy() = default;
    };

    class Vector3
    {
    public:
        enum InitZeroType
        {
            InitZero = 0
        };

        enum InitOneType
        {
            InitOne = 0
        };

        enum InitOneXType
        {
            InitOneX = 0
        };

        enum InitOneYType
        {
            InitOneY = 0
        };

        enum InitOneZType
        {
            InitOneZ = 0
        };

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
        };

        ~Vector3() = default;
        Vector3() = default;
    };

    class StringTable
    {
    public:
        unsigned int m_NumEntrys;
        unsigned int m_DataLength;
        unsigned int* m_IDs;
        unsigned int* m_Offsets;
        const char* m_Data;

        StringTable() = default;
        ~StringTable() = default;
    };

    class Quat
    {
    public:
        enum QuatConstruction
        {
            kIdentity = 0
        };

        float x;
        float y;
        float z;
        float w;

        ~Quat() = default;
        Quat() = default;
    };

    class Pool
    {
    public:
        BitArray* m_usedEntries;
        unsigned char* m_entries;
        unsigned int m_maxNumEntries;
        unsigned int m_numRemainingEntries;
        unsigned int m_entryStride;

        Pool() = default;
        ~Pool() = default;
    };

    class SequentialFitAllocator
    {
    public:
        struct Chunk
        {
            unsigned int size;
            Chunk* next;
        };

        struct Heap
        {
            Chunk* _free;
            unsigned int pad;
        };

        struct MemoryBlock
        {
            unsigned int size;
            MemoryBlock* next;
        };

        unsigned int m_defaultBlockSize;
        MemoryBlock* m_memoryBlock;
        unsigned int m_numBytesAllocated;

        SequentialFitAllocator() = default;
        ~SequentialFitAllocator() = default;
    };

    template <class T>
    class Flags
    {
    public:
        T m_flags;

        Flags() = default;
        ~Flags() = default;
    };
};