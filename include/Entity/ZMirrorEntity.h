#pragma once

#include "ZComponentCreateInfo.h"
#include "ZVariantRef.h"
#include "STypeID.h"
#include "ZCameraEntity.h"
#include "ZRenderableEntity.h"
#include "ZString.h"
#include "ZPresenceState.h"
#include "ZEntityRef.h"
#include "SRenderDestinationDesc.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "TArray.h"

class ZMirrorEntity : public ZRenderableEntity, public ZPresenceState
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EMirrorQuality
	{
		QUALITY_LOW = 0,
		QUALITY_MEDIUM = 1,
		QUALITY_HIGH = 2
	};

	enum EMirrorBlur
	{
		BLUR_DISABLED = 0,
		BLUR_LOW = 1,
		BLUR_HIGH = 2
	};

	TEntityRef<ZCameraEntity> m_linkedCamera;
	EMirrorQuality m_Quality;
	float m_fMirrorGaussScale;
	float m_fDrawDistance;
	int m_nGateTraversalDepth;
	EMirrorBlur m_Blur;
	bool m_bPCOnly;
	bool m_bEmissiveOnly;
	bool m_bCrowd;
	bool m_bScatter;
	TArray<ZEntityRef> m_Materials;
	int m_nOldPCMirrorSetting;
	unsigned int m_nWidth;
	unsigned int m_nHeight;

	static SComponentMapEntry s_componentMap[0];

	~ZMirrorEntity() override = default;
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

	void OnStreamActivateStateChanged() override;

	ZMirrorEntity() = default;
	static void RegisterType();
	ZMirrorEntity(const ZMirrorEntity& __that);
	ZMirrorEntity(ZComponentCreateInfo& Info);
	void MirrorReflectPre();
	void OnQualityChanged();
	void OnPCOnlyChanged();
	void ChangeHandler();
	TEntityRef<ZCameraEntity> GetCamera();
	EMirrorQuality GetQuality();
	EMirrorBlur GetBlur();
	bool IsPCOnly();
	void AddMaterial(ZEntityRef material);
	void RemoveMaterial(ZEntityRef material);
	TArray<ZEntityRef>& GetMaterials();
	void OnDeviceWillReset(const SRenderDestinationDesc& desc);
	void UpdateMirrorCamera();
	void InvalidateMaterials();
	ZMirrorEntity& operator=(const ZMirrorEntity& __that);
};
