#pragma once

#include "IComponentInterface.h"

class ZEntityRef;
template <class T> class TArray;

class __declspec(novtable) IRoomEntity : public IComponentInterface
{
public:
	enum EReasoningGridImportance
	{
		RGI_NoGrid = 0,
		RGI_Low = 1,
		RGI_Normal = 2,
		RGI_High = 3,
		RGI_Extreme = 4
	};

	~IRoomEntity() override = default;
	virtual EReasoningGridImportance GetGridImportance() const = 0;
	virtual const TArray<ZEntityRef>& GetClientList() const = 0;

	static void RegisterType();
	IRoomEntity() = default;
};
