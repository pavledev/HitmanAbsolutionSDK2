#pragma once

class __declspec(novtable) IListenerRegistrar
{
public:
	virtual ~IListenerRegistrar() = default;
	virtual void AddPositionListener(void* param1) = 0;
	virtual void RemovePositionListener(void* param1) = 0;

	IListenerRegistrar() = default;
};
