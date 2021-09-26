#pragma once

struct SUIOptionValue
{
	unsigned int key;
	unsigned char type;

	union 
	{
		int intValue;
		float floatValue;
		bool boolValue;
	};

	SUIOptionValue() = default;
	SUIOptionValue(unsigned int key, bool b);
	SUIOptionValue(unsigned int key, float f);
	SUIOptionValue(unsigned int key, int i);
	~SUIOptionValue() = default;
};
