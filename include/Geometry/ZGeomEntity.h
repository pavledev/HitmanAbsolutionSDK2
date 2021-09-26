#pragma once

#include "ZPrimitiveContainerEntity.h"
#include "ZPresenceState.h"
#include "ZResourcePtr.h"
#include "TEnumerator.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class IRenderPrimitive;
class ZComponentCreateInfo;
class ZEventNull;
class ZString;
struct STypeID;
template <class A, class B, class C, class D, class E> class ZEvent;
template <class T> class TRefCountPtr;

class ZGeomEntity : public ZPrimitiveContainerEntity, public ZPresenceState
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZResourcePtr m_pPrimitive;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* m_pResourceChanged;
	unsigned short m_nRoomID;

	static SComponentMapEntry s_componentMap[0];

	~ZGeomEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;
	void Init() override;
	virtual ZResourcePtr GetResourcePtr() const;
	virtual ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetResourceChangedEvent() const;
	virtual ZResourcePtr ChangePrimitiveResourcePtr(const ZResourcePtr& resourcePtr);
	virtual TEnumerator<TRefCountPtr<IRenderPrimitive> const> GetResourcePrimitiveEnumerator() const;
	virtual TEnumerator<TRefCountPtr<IRenderPrimitive>> GetResourcePrimitiveEnumerator();
	virtual unsigned int GetResourcePrimitivesCount() const;
	virtual void HandlePrimitiveChanged(const ZResourcePtr& oldValue);

	void OnStreamActivateStateChanged() override;

	ZGeomEntity() = default;
	static void RegisterType();
	ZGeomEntity(const ZGeomEntity& __that);
	ZGeomEntity(ZComponentCreateInfo& Info);
	void SetRoomID(const unsigned short nRoomID);
	unsigned short GetRoomID() const;
	void OnPrimitiveChanged(const ZResourcePtr& oldValue);
	void InitPrimitives();
	void UninitPrimitives(const ZResourcePtr& oldValue);
	ZGeomEntity& operator=(const ZGeomEntity& __that);
};
