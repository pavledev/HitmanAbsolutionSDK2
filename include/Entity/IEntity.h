#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"

class ZString;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;

class __declspec(novtable) IEntity : public IComponentInterface
{
public:
	~IEntity() override = default;
	virtual ZEntityRef GetID() const = 0;
	virtual void Activate(const ZString& string) = 0;
	virtual void Deactivate(const ZString& string) = 0;
	virtual void StreamIn() = 0;
	virtual void StreamOut() = 0;
	virtual bool IsStreamedIn() = 0;
	virtual void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& hashSet) const = 0;
	virtual void OnEnterEditMode() = 0;
	virtual void OnExitEditMode() = 0;

	static void RegisterType();
	IEntity(const IEntity& __that);
	IEntity() = default;
	IEntity& operator=(const IEntity& __that);
};
