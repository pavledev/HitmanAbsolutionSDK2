#pragma once

#include "ZEntityImpl.h"
#include "TResourcePtr.h"
#include "EObjectiveType.h"
#include "SComponentMapEntry.h"
#include "ZRuntimeResourceID.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTextListData;
struct STypeID;

class ZObjectiveEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZString m_sObjectiveString;
	ZString m_sDescriptionString;
	ZString m_sCompletedString;
	bool m_bActive;
	bool m_bCompleted;
	EObjectiveType m_objectiveType;
	ZString m_ObjectiveStringID;
	ZString m_DescriptionStringID;
	ZString m_CompletedStringID;
	TResourcePtr<ZTextListData> m_pTextListResource;
	TResourcePtr<ZTextListData> m_pCompletedTextListResource;
	int m_nTally;
	int m_nTallyRequired;
	ZRuntimeResourceID m_sIconResourceID;
	bool m_bShowInHUD;
	bool m_bRegisterInNotebook;
	bool m_bIsCompletable;
	ZString m_sCustomSaveTitle;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snOnActivated;
	static unsigned int m_snOnCompleted;
	static unsigned int m_snOnTallyChanged;
	static unsigned int m_snOnGetTally;
	static unsigned int m_snOnGetTallyRemaining;
	static unsigned int m_snOnActivatedByForwardSpawn;
	static unsigned int m_snOnCompletedByForwardSpawn;

	~ZObjectiveEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZObjectiveEntity() = default;
	static void RegisterType();
	void Activate(bool bSilent);
	ZObjectiveEntity(ZComponentCreateInfo& info);
	bool IsPrimary() const;
	bool IsSecondary() const;
	bool IsTertiary() const;
	bool IsActive() const;
	bool IsCompleted() const;
	const ZString& GetTitle() const;
	const ZString& GetDescription() const;
	ZRuntimeResourceID GetIconResourceID() const;
	unsigned int GetTally() const;
	unsigned int GetTallyRequired() const;
	void OnPushObjectiveText();
	void OnIncrementTally();
	void OnSetTally(int nTally);
	void OnSetTallyF(float nTally);
	void OnSetTallyRequired(int nTotal);
	void OnSetTallyRequiredF(float nTotal);
	void DeactivateObjective();
	void ForwardSpawnActivate();
	void ForwardSpawnComplete();
	bool IsCompletable() const;
	const ZString& GetCustomSaveTitle() const;
	void MarkCompleted(bool bSilent);
	void UpdateCachedString();
	void OnActivate();
	void OnDeactivate();
	void OnSetCompleted();
	void OnTallyChanged();
	void OnGetTally();
	void OnGetTallyRemaining();
	void OnObjectiveStringIDChanged();
	void OnDescriptionStringIDChanged();
	void OnCompletedStringIDChanged();
	void OnTextListResourceChanged();
	void OnCompletedTextListResourceChanged();
};
