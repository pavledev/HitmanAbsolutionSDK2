#pragma once

#include "ZEntityImpl.h"
#include "SVector4.h"
#include "SVector3.h"
#include "SMatrix43.h"
#include "float4.h"
#include "TEntityRef.h"
#include "SMatrix.h"
#include "ZComponentCreateInfo.h"
#include "Function.h"
#include "BaseAddresses.h"

class ZBoundedEntity;

class ZSpatialEntity : public ZEntityImpl
{
public:
    ZSpatialEntity* m_pTransformParent;
    ZSpatialEntity* m_pTransformChildren;
    ZSpatialEntity* m_pTransformNext;
    ZSpatialEntity* m_pTransformPrev;
    ZEntityRef m_transformParentID;
    SVector4 m_vObjectToParentRotation;
    SVector3 m_vObjectToParentTranslation;
    bool m_bVisible;
    bool m_bIsPrivate;
    __int8 m_bDisplayBounds : 1;
    __int8 m_bDisplayPivot : 1;
    __int8 m_bDisplayHelpers : 1;
    __int8 m_bDisplayHelperPrimitive : 1;
    __int8 m_bEditorSelected : 1;
    __int8 m_bEditorVisible : 1;
    __int8 m_bParentHidden : 1;
    __int8 m_bSceneChild : 1;
    __int8 m_bFPSDrawMode : 1;
    __int8 m_bNotifyChange : 1;
    __int8 m_bRoomDynamicAlways : 1;
    __int8 m_bRoomDynamic : 1;
    __int8 m_bParentDynamic : 1;
    __int8 m_bIsDynamic : 1;
    __int8 m_bIncludeInParentsBounds : 1;
    __int8 m_bUpdateBoundsPending : 1;
    ZEvent<ZEntityRef const&, SMatrix43 const&, ZEventNull, ZEventNull, ZEventNull>* m_pTransformChangeCallBackEvent;

    virtual void SetVisible(bool);
    virtual const ZBoundedEntity* QueryBoundedEntityConst(); //original name is QueryBoundedEntity
    virtual ZBoundedEntity* QueryBoundedEntity();
    virtual void SetPrivate(bool);
    virtual bool IsPrivate();
    virtual void SetFPSDrawMode(bool);
    virtual void SetEditorSelected(bool);
    virtual bool GetEditorSelected();
    virtual void SetEditorVisible(bool);
    virtual bool GetEditorVisible();
    virtual void SetTransformParent(TEntityRef<ZSpatialEntity>);
    virtual TEntityRef<ZSpatialEntity>* GetTransformParentEntityPtr(TEntityRef<ZSpatialEntity>* result);
    virtual ZSpatialEntity* GetScene();
    virtual void CalculateBounds(float4*, float4*, const unsigned int, const unsigned int);
    virtual float4* GetLocalCenter(float4* result);
    virtual float4* GetLocalHalfSize(float4* result);
    virtual void OnObjectToParentChanged();
    virtual void OnTransformParentIDChanged();
    virtual void OnVisibleChanged(const bool*);
    virtual void OnSpatialChange();

    SMatrix* GetObjectToWorldMatrix(SMatrix* retstr);
    void SetObjectToWorldMatrix(SMatrix*);
    float4* GetWorldPosition(float4* retstr);
    float4* GetWorldDirection(float4* retstr, float4*);
    ZSpatialEntity(ZComponentCreateInfo*);
    ~ZSpatialEntity();
    void UnregisterObjectToWorldChangeCallBack(ZDelegate<void __cdecl (ZEntityRef const&, SMatrix43 const&)> const&);
    void RegisterObjectToWorldChangeCallBack(ZDelegate<void __cdecl (ZEntityRef const&, SMatrix43 const&)> const&);
    float4* GetWorldPosition(float4* retstr, float4*);
    void SetWorldPosition(float4*);
    float4* GetLocalPosition(float4* retstr, float4*);
    ZSpatialEntity* GetTransformParent();
    void Detach();
    SMatrix* GetObjectToParentMatrix(SMatrix* retstr);
    float4* GetLocalPosition(float4* retstr);
    void SetObjectToParentMatrix(SMatrix*);
    float4* GetLocalDirection(float4* retstr, float4*);
    void AttachChild(ZSpatialEntity*);
    void SetObjectToWorldMatrixNoChangeHandlers(SMatrix*);
    void SetLocalPosition(float4*);
    void AttachTo(ZSpatialEntity*);
};
