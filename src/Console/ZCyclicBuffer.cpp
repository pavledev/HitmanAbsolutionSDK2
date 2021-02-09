#include "ZCyclicBuffer.h"
#include "Function.h"
#include "BaseAddresses.h"

void ZCyclicBuffer::FreeSpace()
{
	Function::CallMethod<ZCyclicBuffer*>(BaseAddresses::hitman5Dll + 0x629420, this);
}

void* ZCyclicBuffer::Alloc(int iSize)
{
	return Function::CallMethodAndReturn<void*, ZCyclicBuffer*, int>(BaseAddresses::hitman5Dll + 0x629AB0, this, iSize);
}

int ZCyclicBuffer::Count()
{
	return Function::CallMethodAndReturn<int, ZCyclicBuffer*>(BaseAddresses::hitman5Dll + 0x629330, this);
}

int ZCyclicBuffer::Last()
{
	return Function::CallMethodAndReturn<int, ZCyclicBuffer*>(BaseAddresses::hitman5Dll + 0x629310, this);
}

int ZCyclicBuffer::First()
{
	return Function::CallMethodAndReturn<int, ZCyclicBuffer*>(BaseAddresses::hitman5Dll + 0x629320, this);
}

void* ZCyclicBuffer::Get(int iNr)
{
	return Function::CallMethodAndReturn<void*, ZCyclicBuffer*, int>(BaseAddresses::hitman5Dll + 0x6293B0, this, iNr);
}

int ZCyclicBuffer::SpaceFree()
{
	return Function::CallMethodAndReturn<int, ZCyclicBuffer*>(BaseAddresses::hitman5Dll + 0x629470, this);
}
