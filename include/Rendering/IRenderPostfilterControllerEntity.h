#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"

class IRenderPostfilterParametersEntity;
struct SRenderPostfilterParameters;
struct SRenderPostfilterPerScreenDecalParametersInternal;

class __declspec(novtable) IRenderPostfilterControllerEntity : public IComponentInterface
{
public:
	~IRenderPostfilterControllerEntity() override = default;
	virtual TEntityRef<IRenderPostfilterParametersEntity> GetCurrentParametersEntity() const = 0;
	virtual TEntityRef<IRenderPostfilterParametersEntity> GetParametersEntity() const = 0;
	virtual void UpdateParameters(SRenderPostfilterParameters& renderPostfilterParameters) = 0;
	virtual void LerpParameters(ZEntityRef entityRef) = 0;
	virtual void ReportParametersChanged() = 0;
	virtual void RestartLerp(const float param1) = 0;
	virtual void SetRoomLerp(const bool param1) = 0;
	virtual bool GetRoomLerp() const = 0;
	virtual float GetLuminance() const = 0;
	virtual unsigned int GetScreenDecals(SRenderPostfilterPerScreenDecalParametersInternal** renderPostfilterPerScreenDecalParametersInternal) = 0;
	virtual void ClearScreenDecals() = 0;

	static void RegisterType();
	IRenderPostfilterControllerEntity() = default;
};
