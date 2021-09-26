#pragma once

#include "ZSpatialEntity.h"
#include "SComponentMapEntry.h"
#include "TResourcePtr.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

class IEntityFactory;
class ZComponentCreateInfo;
class ZEntityImpl;
class ZString;
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;
template <class T> class TEntityRef;

class __declspec(novtable) ZTemplateFactoryBase : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZEntityRef m_pInstance;
	bool m_bStreamedIn : 1;
	bool m_bActivated : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZTemplateFactoryBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;
	void SetVisible(bool bVisible) override;
	virtual void OnInstanceChanged();
	virtual TResourcePtr<IEntityFactory> GetResource() const = 0;

	ZTemplateFactoryBase() = default;
	static void RegisterType();
	ZTemplateFactoryBase(ZComponentCreateInfo& info);
	ZEntityRef GetInstance(bool bCreate);
	void Create();
	static ZEntityRef Create(const TResourcePtr<IEntityFactory>& pResourcePtr, ZEntityImpl* pOwnerEntity, const TEntityRef<ZSpatialEntity>& pParent);
	void OnResourcePtrChanged();
	void Delete();
};
