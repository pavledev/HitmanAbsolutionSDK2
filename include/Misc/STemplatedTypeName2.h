#pragma once

struct STypeID;

struct STemplatedTypeName2
{
	STypeID* arg0;
	STypeID* arg1;
	char argCount;
	char name[255];

	STemplatedTypeName2() = default;
	~STemplatedTypeName2() = default;
};
