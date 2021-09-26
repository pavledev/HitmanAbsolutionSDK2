#pragma once

#include "ZEntityImpl.h"
#include "IHM5OSD.h"
#include "TEntityRef.h"
#include "ZResourcePtr.h"
#include "TRefCountPtr.h"
#include "EHM5OSDSprite.h"
#include "SComponentMapEntry.h"
#include "SVector2.h"
#include "TArray.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"

struct SVertexGeneric;
class IHM5OSDDisplay;
class IRenderPrimitiveMesh;
class ZComponentCreateInfo;
class ZPrimitiveContainerEntity;
struct SGameUpdateEvent;
struct STypeID;
struct float4;

class ZHM5OSD : public ZEntityImpl, public IHM5OSD
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SSpriteInfo
	{
		float m_fTexU0;
		float m_fTexU1;
		float m_fTexV0;
		float m_fTexV1;
		float m_fScaleX;
		float m_fScaleY;

		SSpriteInfo(float fTexU0, float fTexU1, float fTexV0, float fTexV1, float fScaleX, float fScaleY);
		SSpriteInfo() = default;
		void Set(float fTexU0, float fTexU1, float fTexV0, float fTexV1, float fScaleX, float fScaleY);
	};

	struct SSpriteData
	{
		SVector2 m_aVertices[4];
		EHM5OSDSprite m_eSprite;
		unsigned char m_nPriority;
		unsigned int m_nColor;
	};

	struct SSpriteBuffer
	{
		SSpriteData* m_pSprites;
		unsigned int m_nSpritesAdded;

		SSpriteBuffer() = default;
		~SSpriteBuffer() = default;
		void AddSprite(EHM5OSDSprite eSprite, SVector2* aVertices, unsigned char nPriority, unsigned int nColor);
		void Render(SVertexGeneric* pVertices, unsigned int* pColors, const SSpriteInfo* pSpriteInfo);
	};

	TArray<TEntityRef<IHM5OSDDisplay>> m_Displays;
	ZEntityRef m_OSDCam;
	ZEntityRef m_PrimitiveContainerEntity;
	ZResourcePtr m_SBMaterial;
	TRefCountPtr<IRenderPrimitiveMesh> m_pSBMesh;
	TEntityRef<ZPrimitiveContainerEntity> m_rPrimCon;
	float m_fScaleX;
	float m_fScaleY;
	float m_fRotation;
	unsigned int m_nColor;
	SSpriteInfo m_aSpriteInfo[12];
	SSpriteBuffer m_SpriteBuffer[2];
	unsigned int m_nBufferIndex;
	bool m_bPrimAdded;
	float m_fAspect;
	unsigned int m_nViewPortWidth;
	unsigned int m_nViewPortHeight;

	static SComponentMapEntry s_componentMap[0];
	static const int MAX_NUM_SPRITES;
	static const unsigned int MAX_PRIO;

	~ZHM5OSD() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	virtual void FrameUpdate(const SGameUpdateEvent& updateEvent);

	void AddSprite(EHM5OSDSprite eSprite, float fPosX, float fPosY, unsigned char nPriority) override;
	void AddSpriteBar(EHM5OSDSprite eSprite, float fPosX1, float fPosY1, float fPosX2, float fPosY2, unsigned char nPriority) override;
	void AddCircle(float fPosX, float fPosY, float fRadius, float fWidth, unsigned char nPriority) override;
	void AddBox(float fPosX1, float fPosY1, float fPosX2, float fPosY2, float fWidth, unsigned char nPriority) override;
	void AddQuad(const float4& vCenter, const float4& v0, const float4& v1, const float4& v2, const float4& v3, unsigned char nPriority) override;
	void AddTriangle(float fPosX, float fPosY, unsigned char nPriority) override;
	void SetScale(float fScaleX, float fScaleY) override;
	void SetRotation(float fRotation) override;
	void SetColor(unsigned int nColor) override;
	SVector2 GetSize(EHM5OSDSprite eSprite) override;
	float GetAspectRatio() const override;

	ZHM5OSD() = default;
	static void RegisterType();
	ZHM5OSD(ZComponentCreateInfo& pInfo);
	void AddSprite(EHM5OSDSprite eSprite, SVector2* aVertices, unsigned char nPriority);
	void PushDisplay(TEntityRef<IHM5OSDDisplay>& rDisplay);
	void OnSBMaterialChanged();
	void RenderBuffer(SSpriteBuffer* pBuffer);
	void AddPrimitive(bool bAdd);
	void UpdateAspect();
};
