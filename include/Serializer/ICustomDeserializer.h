#pragma once

class __declspec(novtable) ICustomDeserializer
{
public:
	virtual void HandleCustomData(unsigned int param1, const void* param2, unsigned int param3, void* param4, unsigned int param5) = 0;
	virtual ~ICustomDeserializer() = default;

	ICustomDeserializer(const ICustomDeserializer& __that);
	ICustomDeserializer() = default;
	ICustomDeserializer& operator=(const ICustomDeserializer& __that);
};
