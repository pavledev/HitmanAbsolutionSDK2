#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZRuntimeResourceID.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IScaleformPlayer;
class ZComponentCreateInfo;
class ZString;
struct STypeID;

class ZHUDManagerEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<IScaleformPlayer> m_mcHUD;
	ZRuntimeResourceID m_NotebookLibID;
	ZRuntimeResourceID m_ContractLibID;
	float m_ObjectiveTimeMin;
	float m_ObjectiveTimeMax;
	float m_ObjectiveTimeFactor;
	ZResourcePtr m_pDisguiseOSDResource;

	static SComponentMapEntry s_componentMap[0];

	~ZHUDManagerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;

	ZHUDManagerEntity() = default;
	static void RegisterType();
	ZHUDManagerEntity(ZComponentCreateInfo& Info);
	float GetObjectiveTextTimeMin() const;
	float GetObjectiveTextTimeMax() const;
	float GetObjectiveTextTimeFactor() const;
	void OnShowObjective(const ZString& sText);
	void OnSetObjectiveTimeMin(float seconds);
	void OnSetObjectiveTimeMax(float seconds);
	void OnSetObjectiveTimeFactor(float nFactor);
	const ZResourcePtr& GetDisguiseOSDResource();
	void OnHUDMovieClipChanged();
	void OnNotebookLibIDChanged();
	void OnContractLibIDChanged();
};
