#pragma once

#include "ZEntityImpl.h"
#include "EControlButtonName.h"
#include "TResourcePtr.h"
#include "EHintMessageType.h"
#include "EHintMessageSoundType.h"
#include "EMenuId.h"
#include "EControllerButton.h"
#include "SComponentMapEntry.h"
#include "ZResourcePtr.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZTextListData;
struct STypeID;

class ZHintMessageEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	EControlButtonName m_eButtonFirst;
	EControlButtonName m_eButtonSecond;
	ZString m_sTextHeadline;
	TResourcePtr<ZTextListData> m_pHeadlineTextListResource;
	ZString m_sCachedHeadlineString;
	ZString m_sText;
	TResourcePtr<ZTextListData> m_pTextListResource;
	ZString m_sCachedString;
	ZResourcePtr m_pTutorialImage;
	int m_iPriority;
	EHintMessageType m_eHintType;
	float m_fDuration;
	bool m_bWorksInContractsMode;
	bool m_bWorksInPuristDifficulty;
	EHintMessageSoundType m_eHintSound;
	bool m_bSlowDownTime;
	bool m_bTutorialNotebookPrompt;
	EMenuId m_eNotebookPage;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snTutorialStarted;
	static unsigned int m_snTutorialEnded;

	~ZHintMessageEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZHintMessageEntity() = default;
	static void RegisterType();
	ZHintMessageEntity(ZComponentCreateInfo& Info);
	void OnEnable();
	void OnDisable();
	const ZString& GetCachedText() const;
	void UpdateCachedStrings();
	const ZString& GetCachedHeadlineText() const;
	int GetPriority() const;
	float GetDuration() const;
	EHintMessageType GetHintType() const;
	EHintMessageSoundType GetHintSound() const;
	ZResourcePtr GetTutorialImage() const;
	EControllerButton GetFirstButton() const;
	EControllerButton GetSecondButton() const;
	void RemovedFromQueue();
	void TutorialStarted();
	void TutorialEnded();
	bool IsTutorialNotebookPrompt() const;
	EMenuId GetNotebookPage() const;
	void OnTextChange();
	void OnHeadlineTextChange();
	void DisplayText();
	EControllerButton GetButtonTypeFromName(EControlButtonName eButtonName) const;
};
