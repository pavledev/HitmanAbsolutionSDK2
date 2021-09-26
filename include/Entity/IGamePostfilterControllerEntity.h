#pragma once

#include "IComponentInterface.h"
#include "ZEntityRef.h"

struct SRenderPostfilterParameters;
struct SRenderPostfilterPerScreenDecalParametersInternal;

class __declspec(novtable) IGamePostfilterControllerEntity : public IComponentInterface
{
public:
	~IGamePostfilterControllerEntity() override = default;
	virtual void UpdateParameters(SRenderPostfilterParameters& renderPostfilterParameters) = 0;
	virtual void SetDefaultParameters(const SRenderPostfilterParameters& renderPostfilterParameters, float param2) = 0;
	virtual void SetRenderPostfilterControllerEntity(ZEntityRef entityRef) = 0;
	virtual unsigned int GetGameLerpMask() = 0;
	virtual unsigned int UpdateScreenDecals(SRenderPostfilterPerScreenDecalParametersInternal* renderPostfilterPerScreenDecalParametersInternal, unsigned int param2) = 0;

	static void RegisterType();
	IGamePostfilterControllerEntity() = default;
};
