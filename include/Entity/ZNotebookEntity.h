#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "ZString.h"
#include "ZVariantRef.h"

class IScaleformPlayer;
class ZComponentCreateInfo;
class ZDynamicResourceLibrary;
class ZScaleformResourceEntity;
struct STypeID;

class ZNotebookEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZDynamicResourceLibrary* m_pCheckpointImageLib;
	TEntityRef<ZScaleformResourceEntity> m_pCheckpointImageEntity;
	TEntityRef<IScaleformPlayer> m_mcNotebook;

	static SComponentMapEntry s_componentMap[0];

	~ZNotebookEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZNotebookEntity() = default;
	static void RegisterType();
	ZNotebookEntity(ZComponentCreateInfo& Info);
	TEntityRef<IScaleformPlayer> GetNotebookMovie();
	ZString GetCheckpointImagePath();
	void OnNotebookChanged();
	void LoadCheckpointImage();
};
