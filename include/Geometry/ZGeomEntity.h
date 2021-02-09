#pragma once

#include "ZPrimitiveContainerEntity.h"
#include "ZPresenceState.h"
#include "ZResourcePtr.h"
#include "ZEvent.h"
#include "ZEventNull.h"
#include "TEnumerator.h"
#include "TRefCountPtr.h"
#include "IRenderPrimitive.h"

class alignas(4) ZGeomEntity : public ZPrimitiveContainerEntity, public ZPresenceState
{
public:
    ZResourcePtr m_pPrimitive;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* m_pResourceChanged;
    unsigned __int16 m_nRoomID;

    virtual ZResourcePtr* GetResourcePtr(ZResourcePtr* result);
    virtual ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetResourceChangedEvent();
    virtual ZResourcePtr* ChangePrimitiveResourcePtr(ZResourcePtr* result, const ZResourcePtr*);
    virtual TEnumerator<TRefCountPtr<IRenderPrimitive> const> GetResourcePrimitiveEnumerator();
    virtual TEnumerator<TRefCountPtr<IRenderPrimitive>>* GetResourcePrimitiveEnumerator(TEnumerator<TRefCountPtr<IRenderPrimitive> >* result);
    virtual unsigned int GetResourcePrimitivesCount();
    virtual void HandlePrimitiveChanged(const ZResourcePtr*);
};
