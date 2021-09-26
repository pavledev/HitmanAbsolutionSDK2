#pragma once

class ZMutex
{
public:
	unsigned int m_impl[6];
	unsigned int m_nUniqueID;

	static const int IMPL_SIZE;

	ZMutex() = default;
	~ZMutex() = default;
	void Lock();
	void Unlock();
	bool TryLock();
	bool IsLockedByCurrentThread();
};
