#pragma once

#include "ZEntityImpl.h"
#include "SMatrix.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class __declspec(novtable) ZCameraBlendNodeInterface : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	static SComponentMapEntry s_componentMap[0];

	~ZCameraBlendNodeInterface() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	virtual SMatrix GetObjectToWorldMatrix() const = 0;
	virtual float GetFieldOfView() const = 0;

	ZCameraBlendNodeInterface() = default;
	static void RegisterType();
	ZCameraBlendNodeInterface(ZComponentCreateInfo& info);
};
