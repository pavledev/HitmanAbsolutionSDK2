#pragma once

struct STypeID;

struct STemplatedTypeName1
{
	STypeID* arg0;
	char argCount;
	char name[255];

	STemplatedTypeName1() = default;
	~STemplatedTypeName1() = default;
};
