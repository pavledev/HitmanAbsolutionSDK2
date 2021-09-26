#pragma once

#include "ZEntityImpl.h"
#include "IParticleRenderEntity.h"
#include "IParticleControllerEntity.h"
#include "SESEntry.h"

class ZParticleRenderEntityBase : public ZEntityImpl, public IParticleRenderEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SESEntry
	{
		TEntityRef<ZSpatialEntity> parentEntity;
		ZParticleContainerEntity* m_pParticleContainer;
		bool bInUse;

		SESEntry(const SESEntry& __that);
		SESEntry() = default;
		~SESEntry() = default;
	};

	TArray<IParticleControllerEntity*> m_ParticleControllers;
	TArray<unsigned int> m_nControllerOffsets;
	ParticleRenderListEntry m_JobEntry;
	unsigned int m_nNumParticles;
	char* m_pBuffer;
	unsigned int m_nBufferSize;
	unsigned int m_nSize;
	unsigned int m_nShaderMask;
	unsigned int m_nMaxEmitters;
	unsigned int m_nAllEmitters;
	bool m_bSizeDirty : 1;
	bool m_bIsStreamedIn : 1;
	TArray<SESEntry> m_ESEntries;
	unsigned int m_nFreeESEntries;

	static SComponentMapEntry s_componentMap[0];

	~ZParticleRenderEntityBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	virtual void OnESEntriesChanged();

	void AssignEmitterSpaceEntry(ZParticleEmitterBaseEntity* pParticleEmitter) override;
	void ReleaseEmitterSpaceEntry(ZParticleEmitterBaseEntity* pParticleEmitter) override;

	ZParticleRenderEntityBase() = default;
	static void RegisterType();
	void SetSizeDirty();
	void RegisterController(IParticleControllerEntity* pParticleController);
	void UnregisterController(IParticleControllerEntity* pParticleController);
	const TArray<SESEntry>& GetESEntries() const;
	ZParticleRenderEntityBase(const ZParticleRenderEntityBase& __that);
	ZParticleRenderEntityBase(ZComponentCreateInfo& Info);
	unsigned int BeginUpdate_Pre(ParticleRenderJobEntry* pOut, float fDeltaTime, const float4& vCameraPosition, float4* avCameraCullPlanes);
	void EndUpdate(ParticleRenderJobFeedback* pFeedback);
	unsigned int GetParticleCntThisFrame() const;
	unsigned int GetUsedESEntriesCnt() const;
	ZParticleRenderEntityBase& operator=(const ZParticleRenderEntityBase& __that);
};
