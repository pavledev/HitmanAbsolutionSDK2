#pragma once

#include "float4.h"
#include "SPromptToDisplay.h"
#include "TEntityRef.h"
#include "BoneId.h"
#include "EButtonDisplay.h"

class ZUserFeedbackManager;
class ZHM5Action;
class IHM5Item;
class ZActor;
class ZHM5GuideLedge;
class ZHM5GuideWindow;
class ZHitman5;
class ZLinkedEntity;

class ZHM5IngamePromptsManager
{
public:
	enum
	{
		MAXACTIVE = 8
	};

	enum EOFFSETBUTTON
	{
		eOFFSETFACE_DOWN = 0,
		eOFFSETFACE_LEFT = 1,
		eOFFSETFACE_RIGHT = 2,
		eOFFSETFACE_UP = 3,
		OFFSETBUTTONS = 4
	};

	enum
	{
		OFFSET2D_X = 0,
		OFFSET2D_Y = 1,
		OFFSETDIMENSIONS = 2
	};

	float4 m_vClipPlanesOuter[6];
	float4 m_vClipPlanesInner[6];
	SPromptToDisplay m_ActivePrompts[8];
	SPromptToDisplay m_LastPrompts[8];
	SPromptToDisplay m_ActivatedActionPrompt;
	const ZUserFeedbackManager* const m_pUserFBManager = {};
	unsigned char m_iActPromptsCount;
	unsigned char m_iLastPromptsCount;
	bool m_bHasPrimaryLedgePromptActive;
	TEntityRef<ZActor> m_pPreviousCandidate;

	static float s_fPromptOffsets[8];

	ZHM5IngamePromptsManager() = default;
	ZHM5IngamePromptsManager(ZUserFeedbackManager* pUserFBMan);
	~ZHM5IngamePromptsManager() = default;
	void OnStart();
	void Reset();
	void Update(int nActionCount, ZHM5Action** const pActionList);
	void GetActivePrompts(unsigned char& iCount, const SPromptToDisplay*& pActivePrompts);
	void AddActivatedAction(ZHM5Action* const pAction, bool bAlternativeActivated);
	bool HasPrimaryLedgePromptActive() const;
	void UpdateClipPlanes();
	void UpdateFromActionClient(int nActionCount, ZHM5Action** const pActionList);
	void UpdateGenericPrompts();
	void UpdateAgilityPrompts();
	void UpdateCloseCombatPrompts();
	void UpdateContractPrompts();
	void UpdateFarPrompts();
	void FinalizePrompts();
	void RemovePromptsForDifficulty();
	bool TestPromptForDifficulty(EButtonDisplay eButtonDisplay);
	void FillIn3dPrompt(SPromptToDisplay& prompt, const TEntityRef<IHM5Item>& rItem, float fCamSpaceOffsetX);
	void FillIn3dPrompt(SPromptToDisplay& prompt, const float4& vWorldTrans, float fCamSpaceOffsetX, float fCamSpaceOffsetY);
	void FillIn3dPrompt(SPromptToDisplay& prompt, ZLinkedEntity* pLE, BoneId::Enum boneid, const float4& vOffset, float fCamSpaceOffsetX);
	void FillIn3dPrompt(SPromptToDisplay& prompt, TEntityRef<ZActor> pActor, BoneId::Enum boneid, const float4& vOffset, float fCamSpaceOffsetX, float fCamSpaceOffsetY);
	float4 CalculateLedgePromptPos(const ZHM5GuideLedge* pLedgeGuide, const TEntityRef<ZHitman5> pHitman) const;
	void GetButtonOffset(const SPromptToDisplay& prompt, float& fOffsetX, float& fOffsetY) const;
	void PushCustomPrompt(const SPromptToDisplay& parameters);
	void Push3dPrompt(EButtonDisplay eButton, const float4& vPos, float fCamSpaceOffsetX, float fCamSpaceOffsetY);
	void PushStandardPrompt(EButtonDisplay buttonDisplay);
	void PushWindowEnterPrompt(const ZHM5GuideWindow* pGuide, bool bGreyed);
	void FillInVentPrompt(SPromptToDisplay& prompt, EButtonDisplay buttonDisplay, const ZHM5Action* pAction);
	void EvaluateAction(const ZHM5Action* action, bool bActivated, bool bAlternativeActivated, bool bFarAction);
	bool IsButtonDisplayActivating(EButtonDisplay buttonDisplay);
	bool IsInsidePlanes(const float4& vWorldTrans, const float4* pPlanes) const;
	bool PromptCanBeConsideredFor2D(const SPromptToDisplay& prompt) const;
	int FindCachedPrompt(EButtonDisplay button, unsigned int paramHash);
};
