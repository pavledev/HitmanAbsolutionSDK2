#pragma once

struct STypeID;

struct STypeIDStorage
{
	STypeID* id;

	STypeIDStorage() = default;
	~STypeIDStorage() = default;
	STypeID* operator&();
};
