#pragma once

#include "TEntityRef.h"
#include "ZRenderDynamicMesh.h"
#include "float4.h"

class ZPrimitiveContainerEntity;
class ZTossConfigurationEntity;
template <class T> class TArray;

class ZTossGeometry
{
public:
	TEntityRef<ZPrimitiveContainerEntity> m_primitiveContainer;
	TEntityRef<ZPrimitiveContainerEntity> m_primitiveContainerDisc;
	ZTossConfigurationEntity* m_pConfigurator;
	ZRenderDynamicMesh m_Mesh;
	ZRenderDynamicMesh m_MeshDisc;
	int m_cOldArch;
	float4 m_rgOldArch[64];
	bool m_bIsFloor;
	bool m_bLastWasDeadly;
	float m_discAlpha;
	float m_discRadius;
	float m_targetAnimTime;
	float m_targetAnimParam;
	float m_targetArchAnimParam;
	float m_discAnimTime;
	float m_wallBlend;
	float m_floorBlend;
	float m_targetBlend;
	float m_fCamRotation;
	bool m_bTossGeometryAllowedForDifficulty;

	virtual ~ZTossGeometry() = default;

	ZTossGeometry() = default;
	bool Init(int nMaxPoints);
	void Show(TArray<float4>& points, float4& intersectionNormal, bool bIsDeadlyThrow, bool bNewTarget, bool bApplyRotationOffset, bool bShowRedicule);
	void Hide();
	void RegisterConfigurator(ZTossConfigurationEntity* pConfigurator);
	void UnregisterConfigurator(ZTossConfigurationEntity* pConfigurator);
	void OnGameStarted();
	void OnGameStopped();
	void BuildGeometry3D(TArray<float4>& points, float4& intersectionNormal, bool bDeadly, float animTime, bool bApplyRotationOffset);
};
