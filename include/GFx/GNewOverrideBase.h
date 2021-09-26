#pragma once

template <int T>
class GNewOverrideBase
{
public:
	enum
	{
		StatType = T
	};

	GNewOverrideBase() = default;
	~GNewOverrideBase() = default;
};
