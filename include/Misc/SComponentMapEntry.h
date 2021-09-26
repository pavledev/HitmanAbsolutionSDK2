#pragma once

struct STypeID;

struct SComponentMapEntry
{
	STypeID* type;
	int nOffset;

	SComponentMapEntry() = default;
	~SComponentMapEntry() = default;
};
