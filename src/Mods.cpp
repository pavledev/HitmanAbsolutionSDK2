#include "Mods.h"

map<int, __int16> Mods::actorTextIDs;

void Mods::EnableGravityGun()
{
    static ZActorManager* actorManager = reinterpret_cast<ZActorManager*>(Globals::g_pActorManagerSingleton);
    static ZLevelManager* levelManager = reinterpret_cast<ZLevelManager*>(Globals::g_pLevelManagerSingleton);

    if (!actorManager)
    {
        return;
    }

    ZHitman5* player = levelManager->m_rHitman.m_pInterfaceRef;
    ZActor* actor = nullptr;
    bool isActorAimed = false;

    if (!player)
    {
        return;
    }

    if (player->IsAiming())
    {
        for (unsigned int i = 0; i < actorManager->m_aliveActors.Size(); i++)
        {
            actor = actorManager->m_aliveActors[i]->m_pInterfaceRef;
            ZKnowledge* knowledge = actor->Knowledge();
            SSharedEntityKnowledge* sharedEntityKnowledge = knowledge->m_pSelfKnown.m_pObject->m_pSharedKnowledge.m_pSharedEntityKnowledge;

            if (sharedEntityKnowledge && sharedEntityKnowledge->IsCurrent(AISET_BeingAimedAt))
            {
                isActorAimed = true;
                break;
            }
        }

        if (isActorAimed)
        {
            ZHM5CameraBaseFunc* currentCamera = player->m_rMainCamera.m_pInterfaceRef->m_pCurrentCamera;

            float yaw = currentCamera->m_fAngleYaw;
            float pitch = currentCamera->m_fAnglePitch;
            float dr = 0.1f;

            const int increaseRadiusKey = VK_OEM_COMMA;
            const int decreaseRadiusKey = VK_OEM_PERIOD;

            float4 playerLocalPosition = {};
            player->GetSpatialEntityPtr()->GetLocalPosition(&playerLocalPosition);

            float4 actorLocalPosition = {};
            actor->GetSpatialEntityPtr()->GetLocalPosition(&actorLocalPosition);

            float4 temp = actorLocalPosition - playerLocalPosition;
            float radius = sqrt(temp.x() * temp.x() + temp.y() * temp.y() + temp.z() * temp.z());

            if ((GetAsyncKeyState(increaseRadiusKey) & 0x8000) == 0x8000)
            {
                radius += dr;
            }

            if ((GetAsyncKeyState(decreaseRadiusKey) & 0x8000) == 0x8000)
            {
                radius -= dr;
            }

            temp.x() = radius * sin(yaw) * cos(pitch);
            temp.y() = radius * cos(yaw) * cos(pitch);
            temp.z() = radius * sin(-pitch);

            actorLocalPosition = temp + playerLocalPosition;
            actor->GetSpatialEntityPtr()->SetLocalPosition(&actorLocalPosition);
        }
    }
}

void Mods::KillNearbyActors()
{
    static ZActorManager* actorManager = reinterpret_cast<ZActorManager*>(Globals::g_pActorManagerSingleton);
    static ZLevelManager* levelManager = reinterpret_cast<ZLevelManager*>(Globals::g_pLevelManagerSingleton);

    if (!actorManager)
    {
        return;
    }

    ZHitman5* player = levelManager->m_rHitman.m_pInterfaceRef;
    ZActor* actor = nullptr;
    bool isActorAimed = false;

    if (!player || !player->GetCharacterController())
    {
        return;
    }

    float4 playerWorldPosition = {};
    player->GetSpatialEntityPtr()->GetWorldPosition(&playerWorldPosition);

    for (unsigned int i = 0; i < actorManager->m_aliveActors.Size(); i++)
    {
        actor = actorManager->m_aliveActors[i]->m_pInterfaceRef;

        float4 actorWorldPosition = {};
        actor->GetSpatialEntityPtr()->GetWorldPosition(&actorWorldPosition);

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
    static ZActorManager* actorManager = reinterpret_cast<ZActorManager*>(Globals::g_pActorManagerSingleton);
    static ZHUDManager* hudManager = reinterpret_cast<ZHUDManager*>(Globals::g_pHUDManagerSingleton);
    static ZLevelManager* levelManager = reinterpret_cast<ZLevelManager*>(Globals::g_pLevelManagerSingleton);

    if (!actorManager || !hudManager)
    {
        return;
    }

    ZHitman5* player = levelManager->m_rHitman.m_pInterfaceRef;
    ZActor* actor = nullptr;
    bool isActorAimed = false;

    if (!player)
    {
        return;
    }

    static ZUserFeedbackManager userFeedbackManager;
    userFeedbackManager.m_pHitman = levelManager->m_rHitman;

    float4 playerWorldPosition = {};
    player->GetSpatialEntityPtr()->GetWorldPosition(&playerWorldPosition);

    for (unsigned int i = 0; i < actorManager->m_aliveActors.Size(); i++)
    {
        actor = actorManager->m_aliveActors[i]->m_pInterfaceRef;

        float4 actorWorldPosition = {};
        actor->GetSpatialEntityPtr()->GetWorldPosition(&actorWorldPosition);

        float4 temp = actorWorldPosition - playerWorldPosition;
        float distance = sqrt(temp.x() * temp.x() + temp.y() * temp.y() + temp.z() * temp.z());

        std::map<int, __int16>::iterator it = actorTextIDs.find(i);

        if (distance <= 4.0f)
        {
            SVector3 screenCoordinates;

            bool reject;
            userFeedbackManager.ConvToScreenSpace(&screenCoordinates, &actorWorldPosition, 0, 0, &reject);

            string actorName = actor->m_sActorName.m_chars;
            string actorType = GetActorType(actor->m_eActorType);
            string txt = actorName + " (" + actorType + ")";

            ZString text = {};
            text.m_chars = txt.c_str();
            text.m_length = txt.size();

            int offsetX = static_cast<int>(screenCoordinates.x);
            int offsetY = static_cast<int>(screenCoordinates.y);

            if (it == actorTextIDs.end())
            {
                __int16 actorTextID = hudManager->AddText(&text, offsetX, offsetY, EScreenAnchor::SCREEN_ANCHOR_TOP_CENTER, 16, 0x0398fc, ETextAlignment::TEXT_ALIGN_LEFT, 0, false);
                actorTextIDs.insert(pair<int, __int16>(i, actorTextID));
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
