#pragma once

#include <Windows.h>

class GLock
{
public:
	class Locker
	{
	public:
		GLock* pLock;

		~Locker() = default;
	};

	_RTL_CRITICAL_SECTION cs;

	GLock() = default;
	~GLock() = default;
};
