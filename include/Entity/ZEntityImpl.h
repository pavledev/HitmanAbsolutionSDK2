#pragma once

#include "IEntity.h"
#include "SComponentMapEntry.h"
#include "ZEntityRef.h"
#include "ZString.h"
#include "ZVariantRef.h"

class IEntitySceneContext;
class ZComponentCreateInfo;
class ZEntityType;
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TArray;
template <class T> class TDefaultHashSetPolicy;
template <class T> class alignas(8) ZDelegate;

class ZEntityImpl : public IEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum
	{
		EDISALLOW_COMPONENTMAP = 1
	};

	ZEntityType* m_pEntityType;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int s_nActivatePinID;
	static unsigned int s_nDeactivatePinID;

	~ZEntityImpl() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	ZEntityRef GetID() const override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;
	virtual void Init();
	virtual void Start();

	ZEntityImpl() = default;
	static void RegisterType();
	ZEntityImpl(const ZEntityImpl& __that);
	ZEntityImpl(ZComponentCreateInfo& Info);
	ZEntityType* GetEntityType() const;
	bool SetProperty(unsigned int nPropertyID, const ZVariantRef& value);
	bool SetProperty(const ZString& sName, const ZVariantRef& value);
	void SignalOutputPin(unsigned int nPinID, const ZVariantRef& data);
	void SignalOutputPin(const ZString& sPin, const ZVariantRef& data);
	void SignalInputPin(unsigned int nPinID, const ZVariantRef& data);
	bool IsOutputPinConnected(unsigned int nPinID) const;
	bool IsRegisteredForDeletionListening(const ZDelegate<void __cdecl(ZEntityRef const&)>& fpCallback) const;
	void RegisterForDeletionListening(const ZDelegate<void __cdecl(ZEntityRef const&)>& fpCallback);
	void UnregisterForDeletionListening(const ZDelegate<void __cdecl(ZEntityRef const&)>& fpCallback);
	ZEntityImpl* GetExposedEntity(const ZString& sName);
	ZEntityImpl* GetOwnerEntity() const;
	void SetOwnerEntity(ZEntityImpl* pEntity);
	ZString GetDebugName() const;
	ZString GetDebugNameScenePath() const;
	static unsigned int GetLocalOffsetOfEntityTypeMember();
	void OnInputToOutputHandlerInternal(const ZVariantRef& data, unsigned int nExtraData);
	ZEntityType** GetEntityTypePtrPtr() const;
	static unsigned int GetActivatePinID();
	static unsigned int GetDeactivatePinID();
	ZEntityType* EnsureUniqueType(unsigned int nUniqueMapMask);
	IEntitySceneContext* GetContext() const;
	void FillSubsetArray(const ZString& subsetName, TArray<ZEntityRef>& entities, bool bChildSet) const;
	ZEntityImpl& operator=(const ZEntityImpl& __that);
};
