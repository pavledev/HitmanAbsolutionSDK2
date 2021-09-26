#pragma warning(disable : 26812)

#include <vector>
#include "PropsInfo.h"
#include "ZHM5SBTargetPropManager.h"
#include "TBinaryTreeNode.h"
#include "TEntityRef.h"
#include "ZLevelManager.h"
#include "ZHitman5.h"

PropsInfo::PropsInfo()
{
	flags = ImGuiInputTextFlags_EnterReturnsTrue;
	color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f);
}

void PropsInfo::DrawWindow(bool* showItemsInfo)
{
	ImGui::SetNextWindowSize(ImVec2(766, 440), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Props Info", showItemsInfo))
	{
		ImGui::End();

		return;
	}

	static ZHM5SBTargetPropManager* targetPropManager = Singletons::GetSBTargetPropManager();
	int propsSize = targetPropManager->m_registeredProps.m_nSize;

	if (propsSize == 0)
	{
		ImGui::End();

		return;
	}

	TBinaryTreeIterator<TEntityRef<ZSpatialEntity> const> propIterator = targetPropManager->m_registeredProps.Begin();
	TBinaryTreeNode<TEntityRef<ZSpatialEntity> const>* node;
	vector<TEntityRef<ZSpatialEntity>> props;

	for (int i = 0; i < propsSize; i++)
	{
		node = &propIterator.Node();

		if (!node)
		{
			propIterator.operator++();

			continue;
		}

		TEntityRef<ZSpatialEntity> propSpatialEntity = node->m_data;

		props.push_back(propSpatialEntity);

		propIterator.operator++();
	}

	static int selected = 0;

	ImGui::BeginChild("left pane", ImVec2(150, 0), true);

	for (int i = 0; i < propsSize; i++)
	{
		char label[128];
		
		sprintf_s(label, "Prop %d", i);

		if (ImGui::Selectable(label, selected == i))
		{
			selected = i;
		}
	}

	ImGui::EndChild();
	ImGui::SameLine();

	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

	ImGui::AlignTextToFramePadding();
	ImGui::PushItemWidth(100);

	AddPropInfo(props[selected].GetRawPointer(), selected);

	ImGui::PopItemWidth();

	ImGui::EndChild();
	ImGui::EndGroup();
	ImGui::End();
}

void PropsInfo::AddPropInfo(ZSpatialEntity* spatialEntity, int propIndex)
{
	AddLocalPositionInputs(spatialEntity, propIndex);
	AddWorldPositionInputs(spatialEntity, propIndex);

	if (ImGui::Button("Teleport Prop To Player"))
	{
		static ZLevelManager* levelManager = Singletons::GetLevelManager();
		ZHitman5* player = levelManager->GetHitman().GetRawPointer();

		if (player)
		{
			float4 playerLocalPosition = player->GetSpatialEntityPtr()->GetWorldPosition();
			float4 correct = { 1, -5, 0, 0 };

			SetWorldPositionOfProp(playerLocalPosition + correct, propIndex);
		}
	}
}

void PropsInfo::AddLocalPositionInputs(ZSpatialEntity* spatialEntity, int propIndex)
{
	ImGui::TextColored(color, "Local Position");

	float4 localPosition = spatialEntity->GetLocalPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	static string label1 = "##localPositionX" + to_string(propIndex);

	if (ImGui::InputFloat(label1.c_str(), &localPosition.x(), 0, 0, "%.3f", flags))
	{
		SetLocalPositionOfProp(localPosition, propIndex);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	static string label2 = "##localPositionY" + to_string(propIndex);

	if (ImGui::InputFloat(label2.c_str(), &localPosition.y(), 0, 0, "%.3f", flags))
	{
		SetLocalPositionOfProp(localPosition, propIndex);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	static string label3 = "##localPositionZ" + to_string(propIndex);

	if (ImGui::InputFloat(label3.c_str(), &localPosition.z(), 0, 0, "%.3f", flags))
	{
		SetLocalPositionOfProp(localPosition, propIndex);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	static string label4 = "##localPositionW" + to_string(propIndex);

	if (ImGui::InputFloat(label4.c_str(), &localPosition.w(), 0, 0, "%.3f", flags))
	{
		SetLocalPositionOfProp(localPosition, propIndex);
	}
}

void PropsInfo::AddWorldPositionInputs(ZSpatialEntity* spatialEntity, int propIndex)
{
	ImGui::TextColored(color, "World Position");

	float4 worldPosition = spatialEntity->GetWorldPosition();

	ImGui::Text("X");
	ImGui::SameLine();

	static string label1 = "##wordPositionX" + to_string(propIndex);

	if (ImGui::InputFloat(label1.c_str(), &worldPosition.x(), 0, 0, "%.3f", flags))
	{
		SetWorldPositionOfProp(worldPosition, propIndex);
	}

	ImGui::SameLine();
	ImGui::Text("Y");
	ImGui::SameLine();

	static string label2 = "##wordPositionY" + to_string(propIndex);

	if (ImGui::InputFloat(label2.c_str(), &worldPosition.y(), 0, 0, "%.3f", flags))
	{
		SetWorldPositionOfProp(worldPosition, propIndex);
	}

	ImGui::SameLine();
	ImGui::Text("Z");
	ImGui::SameLine();

	static string label3 = "##wordPositionZ" + to_string(propIndex);

	if (ImGui::InputFloat(label3.c_str(), &worldPosition.z(), 0, 0, "%.3f", flags))
	{
		SetWorldPositionOfProp(worldPosition, propIndex);
	}

	ImGui::SameLine();
	ImGui::Text("W");
	ImGui::SameLine();

	static string label4 = "##wordPositionW" + to_string(propIndex);

	if (ImGui::InputFloat(label4.c_str(), &worldPosition.w(), 0, 0, "%.3f", flags))
	{
		SetWorldPositionOfProp(worldPosition, propIndex);
	}
}

void PropsInfo::SetLocalPositionOfProp(float4 localPosition, int propIndex)
{
	static ZHM5SBTargetPropManager* targetPropManager = Singletons::GetSBTargetPropManager();
	int propsSize = targetPropManager->m_registeredProps.m_nSize;

	TBinaryTreeIterator<TEntityRef<ZSpatialEntity> const> propIterator = targetPropManager->m_registeredProps.Begin();
	TBinaryTreeNode<TEntityRef<ZSpatialEntity> const>* node;

	for (int i = 0; i < propsSize; i++)
	{
		node = &propIterator.Node();

		if (i == propIndex)
		{
			node->m_data->SetLocalPosition(localPosition);
		}

		propIterator.operator++();
	}
}

void PropsInfo::SetWorldPositionOfProp(float4 worldPosition, int propIndex)
{
	static ZHM5SBTargetPropManager* targetPropManager = Singletons::GetSBTargetPropManager();
	int propsSize = targetPropManager->m_registeredProps.m_nSize;

	TBinaryTreeIterator<TEntityRef<ZSpatialEntity> const> propIterator = targetPropManager->m_registeredProps.Begin();
	TBinaryTreeNode<TEntityRef<ZSpatialEntity> const>* node;

	for (int i = 0; i < propsSize; i++)
	{
		node = &propIterator.Node();

		if (i == propIndex)
		{
			node->m_data->SetWorldPosition(worldPosition);
		}

		propIterator.operator++();
	}
}
