#pragma once

struct STypeID;

class ZComponentCreateInfo
{
public:
	struct SArgumentInfo
	{
		STypeID* m_type;
		const void* m_pData;
	};

	int m_nCount;
	SArgumentInfo m_aArguments[5];

	static const int MAX_ARGUMENTS;

	ZComponentCreateInfo() = default;
	~ZComponentCreateInfo() = default;
	int ArgCount();
	void AddArgument(STypeID* type, const void* pData);
};
