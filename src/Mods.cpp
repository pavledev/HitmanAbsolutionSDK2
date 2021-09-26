#pragma warning(disable : 26812)

#include "Mods.h"
#include "ZKnowledge.h"
#include "SInterfaceData.h"
#include "ZEntityType.h"
#include "ZHitman5.h"
#include "SSharedEntityKnowledge.h"
#include "IHM5Item.h"
#include "ZHM5CameraBaseFunc.h"
#include "ZHM5MainCamera.h"
#include "ZHM5Action.h"
#include "ZActor.h"
#include "IType.h"

void Mods::EnableGravityGun()
{
    static Moving entity = Moving::no;
    static int selected = -1;
    static TEntityRef<ZSpatialEntity> spatialEntity = {};
    static ZLevelManager* levelManager = Singletons::GetLevelManager();
    static ZUserFeedbackManager userFeedbackManager = {};

    if (!levelManager)
    {
        return;
    }

    userFeedbackManager.m_pHitman = levelManager->m_rHitman;

    ZHitman5* player = levelManager->GetHitman().GetRawPointer();

    if (!player)
    {
        return;
    }

    float dr = 0.1f;
    float dp = 0.1f;

    if (player->IsAiming())
    {
        bool isActorAimed = false;
        bool isItemAimed = false;
        bool isPropAimed = false;

        if (entity == Moving::no || entity == Moving::prop)
        {
            if (entity == Moving::no)
            {
                isPropAimed = ProcessProps(spatialEntity, player, entity, selected);

                if (isPropAimed)
                {
                    UpdateGravityGun(spatialEntity, player, true);
                }
            }
            else
            {
                UpdateGravityGun(spatialEntity, player, false);
            }
        }

        if (entity == Moving::no || entity == Moving::actor)
        {
            if (entity == Moving::no)
            {
                isActorAimed = ProcessActors(spatialEntity, player, entity, selected);

                if (isActorAimed)
                {
                    UpdateGravityGun(spatialEntity, player, true);
                }
            }
            else
            {
                UpdateGravityGun(spatialEntity, player, false);
            }
        }

        if (entity == Moving::no || entity == Moving::item)
        {
            if (entity == Moving::no)
            {
                isItemAimed = ProcessItems(spatialEntity, player, entity, selected);

                if (isItemAimed)
                {
                    UpdateGravityGun(spatialEntity, player, true);
                }
            }
            else
            {
                UpdateGravityGun(spatialEntity, player, false);
            }
        }
    }
    else
    {
        if ((GetAsyncKeyState(increasePowerLevel) & 0x8000) == 0x8000)
        {
            powerLevel += dp;
        }

        if ((GetAsyncKeyState(decreasePowerLevel) & 0x8000) == 0x8000 && powerLevel > dp)
        {
            powerLevel -= dp;
        }

        if ((GetAsyncKeyState(increaseRadiusKey) & 0x8000) == 0x8000)
        {
            detectRadius += dr;
        }

        if ((GetAsyncKeyState(decreaseRadiusKey) & 0x8000) == 0x8000 && detectRadius > 1.2)
        {
            detectRadius -= dr;
        }

        if (entity == Moving::item && item)
        {
			ZHM5CameraBaseFunc* currentCamera = player->m_rMainCamera.m_pInterfaceRef->m_pCurrentCamera;
			float camYaw = currentCamera->m_fAngleYaw;
			float camPitch = currentCamera->m_fAnglePitch;
            float4 velocity = { 0, 0, 0, 0 };

			velocity.x() = powerLevel * sin(camYaw) * cos(camPitch);
			velocity.y() = powerLevel * cos(camYaw) * cos(camPitch);
			velocity.z() = -powerLevel * sin(camPitch);

			float4 position = spatialEntity.m_pInterfaceRef->GetWorldPosition();

			item->OnReleaseItem(true);
			item->OnThrowItem(velocity, position);
        }

        if (entity != Moving::no)
        {
            entity = Moving::no;
            spatialEntity = {};
            selected = -1;
        }
    }
}

bool Mods::ProcessItems(TEntityRef<ZSpatialEntity>& spatialEntity, ZHitman5* player, Moving& entity, int& selected)
{
    bool isItemAimed = false;
    static ZHM5ActionManager* actionManager = Singletons::GetHM5ActionManager();
    float4 entityWorldPosition = {};

    if (!actionManager)
    {
        return false;
    }

    unsigned itemsSize = actionManager->m_Actions.m_nSize;

    ZHM5MainCamera* mainCamera = player->GetMainCamera();
    ZHM5CameraBaseFunc* currentCamera = mainCamera->GetCurrentCamera();
    ZHM53rdPersonCamera* thirdPersonCamera = mainCamera->Get3rdPersonCam();

    float yaw = 0;
    float pitch = 0;

    TSListIterator<ZHM5ActionManager::SActionTreeEntry> actionIterator = actionManager->m_Actions.Begin();

    for (unsigned i = 0; i < itemsSize; i++)
    {
        ZHM5Action* action = actionIterator.m_pCurrent->m_pNodeAction;
        EActionType actionType = action->GetActionType();

        if (actionType == EActionType::AT_PICKUP)
        {
            STypeID* typeID = TTypeIDHelper<IHM5Item>::GetTypeID();
            ZEntityType** type = reinterpret_cast<ZEntityType**>(action->m_Object.QueryInterfacePtr(typeID));
            item = reinterpret_cast<IHM5Item*>(type);
            item->RemoveItemFromPhysicsWorld();

            TEntityRef<ZSpatialEntity> itemSpatialEntity = item->GetSpatialEntity();

            entityWorldPosition = itemSpatialEntity.GetRawPointer()->GetWorldPosition();
            thirdPersonCamera->CalcYawPitchFromTargetPosition(yaw, pitch, entityWorldPosition);

            float camYaw = currentCamera->m_fAngleYaw;
            float camPitch = currentCamera->m_fAnglePitch;
            float angleDiff = sqrt((yaw - camYaw) * (yaw - camYaw) + (pitch - camPitch) * (pitch - camPitch));

            float4 playerWorldPosition = player->GetSpatialEntityPtr()->GetWorldPosition();

            float4 temp = entityWorldPosition - playerWorldPosition;
            float itemDistance = sqrt(temp.x() * temp.x() + temp.y() * temp.y() + temp.z() * temp.z());

            const ZEntityRef entityRef = item->GetOwner();
            string owner = {};

            if (entityRef.m_pEntityTypePtrPtr)
            {
                TArray<SInterfaceData>* interfaceDataArray = entityRef.m_pEntityTypePtrPtr[0]->m_pInterfaceData;

                owner = interfaceDataArray->operator[](0)->m_Type->pTypeInfo->pszTypeName;
            }

            if (angleDiff < 0.075f && itemDistance < detectRadius && owner != "ZLinkedEntity")
            {
                isItemAimed = true;
                spatialEntity = item->GetSpatialEntity();
                entity = Moving::item;
                selected = i;

                break;
            }
        }

        actionIterator.operator++();
    }

    return isItemAimed;
}

bool Mods::ProcessActors(TEntityRef<ZSpatialEntity>& spatialEntity, ZHitman5* player, Moving& entity, int& selected)
{
    bool isActorAimed = false;
    static ZActorManager* actorManager = Singletons::GetActorManager();

    if (!actorManager)
    {
        return false;
    }

    unsigned actorsSize = actorManager->m_aliveActors.Size();

    for (unsigned i = 0; i < actorsSize; i++)
    {
        ZActor* actor = actorManager->m_aliveActors[i]->GetRawPointer();
        ZKnowledge knowledge = actor->Knowledge();
        SSharedEntityKnowledge* sharedEntityKnowledge = knowledge.GetSelf().m_pObject->GetShared().m_pSharedEntityKnowledge;

        if (sharedEntityKnowledge && (sharedEntityKnowledge->IsCurrent(AISET_Dead) ||
            sharedEntityKnowledge->IsCurrent(AISET_DeadByAccident) ||
            sharedEntityKnowledge->IsCurrent(AISET_DeadByUnnoticed) ||
            sharedEntityKnowledge->IsCurrent(AISET_DeadBySniper) ||
            actor->GetDeathType() == EActorDeathType::eADT_INVISIBLE))
        {
            spatialEntity = actor->GetSpatialEntity();

            float4 actorWorldPosition = spatialEntity.m_pInterfaceRef->GetWorldPosition();
            ZHM5CameraBaseFunc* currentCamera = player->m_rMainCamera.m_pInterfaceRef->m_pCurrentCamera;
            ZHM53rdPersonCamera* thirdPersonCamera = player->m_rMainCamera.m_pInterfaceRef->Get3rdPersonCam();

            float yaw = 0;
            float pitch = 0;

            thirdPersonCamera->CalcYawPitchFromTargetPosition(yaw, pitch, actorWorldPosition);

            float camYaw = currentCamera->m_fAngleYaw;
            float camPitch = currentCamera->m_fAnglePitch;
            float angleDiff = sqrt((yaw - camYaw) * (yaw - camYaw) + (pitch - camPitch) * (pitch - camPitch));

            if (angleDiff < 0.075f)
            {
                isActorAimed = true;
                entity = Moving::actor;
                selected = i;

                break;
            }
        }

        if (sharedEntityKnowledge && sharedEntityKnowledge->IsCurrent(AISET_BeingAimedAt))
        {
            spatialEntity = actor->GetSpatialEntity();
            isActorAimed = true;
            entity = Moving::actor;
            selected = i;

            break;
        }
    }

    return isActorAimed;
}

bool Mods::ProcessProps(TEntityRef<ZSpatialEntity>& spatialEntity, ZHitman5* player, Moving& entity, int& selected)
{
    static ZHM5SBTargetPropManager* targetPropManager = Singletons::GetSBTargetPropManager();

    if (!targetPropManager)
    {
        return false;
    }

    int propsSize = targetPropManager->m_registeredProps.m_nSize;
    float4 entityWorldPosition = {};

	ZHM5MainCamera* mainCamera = player->GetMainCamera();
	ZHM5CameraBaseFunc* currentCamera = mainCamera->GetCurrentCamera();
	ZHM53rdPersonCamera* thirdPersonCamera = mainCamera->Get3rdPersonCam();

    float yaw = 0;
    float pitch = 0;
    bool isPropAimed = false;

    TBinaryTreeIterator<TEntityRef<ZSpatialEntity> const> propIterator = targetPropManager->m_registeredProps.Begin();
    TBinaryTreeNode<TEntityRef<ZSpatialEntity> const>* node;

    for (int i = 0; i < propsSize; i++)
    {
        node = &propIterator.Node();

        if (!node)
        {
            propIterator.operator++();

            continue;
        }

        TEntityRef<ZSpatialEntity> propSpatialEntity = node->m_data;

        entityWorldPosition = propSpatialEntity.m_pInterfaceRef->GetWorldPosition();
        thirdPersonCamera->CalcYawPitchFromTargetPosition(yaw, pitch, entityWorldPosition);

        float camYaw = currentCamera->m_fAngleYaw;
        float camPitch = currentCamera->m_fAnglePitch;
        float angleDiff = sqrt((yaw - camYaw) * (yaw - camYaw) + (pitch - camPitch) * (pitch - camPitch));

        float4 playerWorldPosition = player->GetSpatialEntityPtr()->GetWorldPosition();

        float4 temp = entityWorldPosition - playerWorldPosition;
        float propDistance = sqrt(temp.x() * temp.x() + temp.y() * temp.y() + temp.z() * temp.z());

        if (angleDiff < 0.1f && propDistance < detectRadius)
        {
            isPropAimed = true;
            spatialEntity = node->m_data;
            entity = Moving::prop;
            selected = i;

            break;
        }

        propIterator.operator++();
    }

    return isPropAimed;
}

void Mods::UpdateGravityGun(TEntityRef<ZSpatialEntity> spatialEntityRef, ZHitman5* player, bool firstRun)
{
    static float radius;

    float4 playerWorldPosition = player->GetSpatialEntityPtr()->GetWorldPosition();
    float4 entityWorldPosition = spatialEntityRef.GetRawPointer()->GetWorldPosition();
    float4 dist = entityWorldPosition - playerWorldPosition;

    if (firstRun)
    {
        radius = sqrt(dist.x() * dist.x() + dist.y() * dist.y() + dist.z() * dist.z());
    }

    float dr = 0;

    if (radius < 2.5f)
    {
        dr = 0.03f;
    }
    else
    {
        dr = 0.1f;
    }

    if ((GetAsyncKeyState(increaseRadiusKey) & 0x8000) == 0x8000)
    {
        radius += dr;
    }

    if ((GetAsyncKeyState(decreaseRadiusKey) & 0x8000) == 0x8000)
    {
        if (radius > 1.2)
        {
            radius -= dr;
        }
    }

	ZHM5MainCamera* mainCamera = player->GetMainCamera();
	ZHM5CameraBaseFunc* currentCamera = mainCamera->GetCurrentCamera();
	ZHM53rdPersonCamera* thirdPersonCamera = mainCamera->Get3rdPersonCam();

    float yaw = 0;
    float pitch = 0;

    thirdPersonCamera->CalcYawPitchFromTargetPosition(yaw, pitch, entityWorldPosition);

    float cameraYaw = currentCamera->m_fAngleYaw;
    float cameraPitch = currentCamera->m_fAnglePitch;

    static float dPitch;
    static float dYaw;

    if (firstRun)
    {
        dPitch = asin(dist.z() / radius + sin(cameraPitch));
        dYaw = yaw - ATan2_0To2Pi(dist.x(), dist.y());
    }

	cameraPitch -= dPitch;
	cameraYaw -= dYaw;

    float4 temp = {};

    temp.x() = radius * sin(cameraYaw) * cos(cameraPitch);
    temp.y() = radius * cos(cameraYaw) * cos(cameraPitch);
    temp.z() = -radius * sin(cameraPitch);

    if (temp.z() < 0.05f)
    {
        temp.z() = 0.05f;
    }

    entityWorldPosition = temp + playerWorldPosition;

    spatialEntityRef.GetRawPointer()->SetWorldPosition(entityWorldPosition);
}

void Mods::KillNearbyActors()
{
    static ZActorManager* actorManager = Singletons::GetActorManager();
    static ZLevelManager* levelManager = Singletons::GetLevelManager();

    if (!actorManager)
    {
        return;
    }

    ZHitman5* player = levelManager->GetHitman().GetRawPointer();
    ZActor* actor = nullptr;
    bool isActorAimed = false;

    if (!player || !player->GetCharacterController())
    {
        return;
    }

    float4 playerWorldPosition = player->GetSpatialEntityPtr()->GetWorldPosition();

    for (unsigned int i = 0; i < actorManager->m_aliveActors.Size(); i++)
    {
        actor = actorManager->m_aliveActors[i]->m_pInterfaceRef;

        float4 actorWorldPosition = actor->GetSpatialEntityPtr()->GetWorldPosition();

        float4 temp = actorWorldPosition - playerWorldPosition;
        float distance = sqrt(temp.x() * temp.x() + temp.y() * temp.y() + temp.z() * temp.z());

        if (distance <= 2.0f)
        {
            if (actor->IsAlive())
            {
                actor->KillActor(EActorDeathType::eADT_BLOODY_MURDER, true);
            }
        }
    }
}

const char* Mods::GetActorType(EActorType m_eActorType)
{
    const char* type{};

    switch (m_eActorType)
    {
    case eAT_Civilian:
        type = "Civilian";
        break;
    case eAT_Guard:
        type = "Guard";
        break;
    case eAT_Hitman:
        type = "Hitman";
        break;
    case eAT_Last:
        type = "Last";
        break;
    }

    return type;
}

void Mods::DisplayNearbyActorsInfo()
{
    static ZActorManager* actorManager = Singletons::GetActorManager();
    static ZHUDManager* hudManager = Singletons::GetHUDManager();
    static ZLevelManager* levelManager = Singletons::GetLevelManager();

    if (!actorManager || !hudManager)
    {
        return;
    }

    ZHitman5* player = levelManager->GetHitman().GetRawPointer();
    ZActor* actor = nullptr;
    bool isActorAimed = false;

    if (!player)
    {
        return;
    }

    static ZUserFeedbackManager userFeedbackManager = {};

    userFeedbackManager.m_pHitman = levelManager->m_rHitman;

    float4 playerWorldPosition = player->GetSpatialEntityPtr()->GetWorldPosition();

    for (unsigned int i = 0; i < actorManager->m_aliveActors.Size(); i++)
    {
        actor = actorManager->m_aliveActors[i]->m_pInterfaceRef;

        float4 actorWorldPosition = actor->GetSpatialEntityPtr()->GetWorldPosition();

        float4 temp = actorWorldPosition - playerWorldPosition;
        float distance = sqrt(temp.x() * temp.x() + temp.y() * temp.y() + temp.z() * temp.z());

        map<int, short>::iterator it = actorTextIDs.find(i);

        if (distance <= 4.0f)
        {
            SVector3 screenCoordinates = {};
            bool reject = false;

            screenCoordinates = userFeedbackManager.ConvToScreenSpace(actorWorldPosition, 0, 0, reject);

            string actorName = actor->GetActorName().ToCString();
            string actorType = GetActorType(actor->GetActorType());
            string txt = actorName + " (" + actorType + ")";
            ZString text = {};

            text.m_chars = txt.c_str();
            text.m_length = txt.size();

            int offsetX = static_cast<int>(screenCoordinates.x);
            int offsetY = static_cast<int>(screenCoordinates.y);

            if (it == actorTextIDs.end())
            {
                short actorTextID = hudManager->AddText(text, offsetX, offsetY, EScreenAnchor::SCREEN_ANCHOR_TOP_CENTER, 16, 0x0398fc, ETextAlignment::TEXT_ALIGN_LEFT, 0, false);
                
                actorTextIDs.insert(pair<int, short>(i, actorTextID));
            }
            else
            {
                hudManager->SetTextPosition(it->second, offsetX, offsetY, false);
            }
        }
        else
        {
            if (it != actorTextIDs.end())
            {
                hudManager->RemoveText(it->second);
                actorTextIDs.erase(it->first);
            }
        }
    }
}

float Mods::ATan2_0To2Pi(float y, float x)
{
    float answer = atan2(y, x);

    if (answer < 0.0)
    {
        return answer + 2.0f * (float)M_PI;
    }

    return answer;
}
