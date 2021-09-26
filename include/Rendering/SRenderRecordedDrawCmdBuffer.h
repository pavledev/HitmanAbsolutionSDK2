#pragma once

#include "ZRenderBlendState.h"
#include "ZRenderDepthStencilState.h"
#include "ZRenderIndexBuffer.h"
#include "SRenderRecordRingBufferHeader.h"
#include "ZRenderRasterizerState.h"
#include "ZRenderVertexBuffer.h"
#include "SRenderRecordRingBuffer.h"
#include "ZRenderInputLayout.h"
#include "ZRenderShader.h"
#include "SRenderRecordRingBufferReservation.h"
#include "ZRenderConstBufferRef.h"
#include "SQV.h"

class ZRenderShaderResourceView;

struct SRenderRecordedDrawCmdBuffer
{
	enum
	{
		CMD_ENUM_SIZE = 4
	};

	enum
	{
		CMD_TYPE_BLENDSTATE = 0,
		CMD_TYPE_RASTERIZERSTATE = 1,
		CMD_TYPE_DEPTHSTENCILSTATE = 2,
		CMD_TYPE_INPUTLAYOUT = 3,
		CMD_TYPE_SHAREDCONSTBUFFER = 4,
		CMD_TYPE_TEXTURE = 5,
		CMD_TYPE_VERTEXBUFFERS = 6,
		CMD_TYPE_INDEXBUFFER = 7,
		CMD_TYPE_CONSTBUFFERV = 8,
		CMD_TYPE_CONSTBUFFERF = 9,
		CMD_TYPE_VERTEXSHADER = 10,
		CMD_TYPE_FRAGMENTSHADER = 11,
		CMD_TYPE_CONSTBUFFERH = 12,
		CMD_TYPE_HULLSHADER = 13,
		CMD_TYPE_DOMAINSHADER = 14,
		CMD_TYPE_DRAWINDEXED = 15,
		CMD_TYPE_CONSTBUFFERBONES = 16,
		CMD_TYPE_PS3_SETUP_EDGE_LINKED_SEGMENT = 17,
		CMD_TYPE_PS3_DRAW_EDGE_LINKED_SEGMENT = 18,
		CMD_TYPE_PS3_SETUP_EDGE_WEIGHTED_SEGMENT = 19,
		CMD_TYPE_PS3_DRAW_EDGE_WEIGHTED_SEGMENT = 20,
		CMD_TYPE_PS3_SETUP_EDGE_SEGMENT = 21,
		CMD_TYPE_PS3_DRAW_EDGE_SEGMENT = 22,
		CMD_TYPE_PS3_DRAW_DECAL = 23,
		CMD_TYPE_360_DRAW_DECAL = 24,
		CMD_TYPE_PS3_DRAW_EDGE_SCATTER = 25,
		NUM_CMD_TYPES = 26
	};

	ZRenderConstBufferRef m_ConstBufferV;
	ZRenderConstBufferRef m_ConstBufferF;
	ZRenderConstBufferRef m_ConstBufferH;
	ZRenderShader* m_pShaderV;
	ZRenderShader* m_pShaderF;
	ZRenderShader* m_pShaderH;
	ZRenderShader* m_pShaderD;
	unsigned int m_nNumIndices;
	unsigned int m_nNumDrawCalls;
	unsigned char* m_pPut;
	unsigned char* m_pPutEnd;
	SRenderRecordRingBufferReservation m_Reservation;
	SRenderRecordRingBufferHeader* m_pHeader;

	SRenderRecordedDrawCmdBuffer() = default;
	~SRenderRecordedDrawCmdBuffer() = default;
	void SetBlendState(ZRenderBlendState* pBlendState, float fFactor);
	void SetRasterizerState(ZRenderRasterizerState* pRasterizerState);
	void SetDepthStencilState(ZRenderDepthStencilState* pDepthStencilState, unsigned int nStencilRef);
	void SetInputLayout(ZRenderInputLayout* pInputLayout);
	void SetSharedConstBuffer(unsigned int nCBuffer, unsigned int nCBufferSlot, ZRenderConstBufferRef SharedConstBuffer);
	void SetTextureInternal(unsigned int nTexUnit, ZRenderShaderResourceView* pShaderResourceView);
	void SetTexture(unsigned int nTexUnit, ZRenderShaderResourceView* pShaderResourceView);
	void SetVertexBuffers(unsigned int nStartSlot, unsigned int nNumBuffers, ZRenderVertexBuffer** pVertexBuffers, unsigned char* pStrides);
	void SetIndexBuffer(ZRenderIndexBuffer* pIndexBuffer, unsigned int nOffset);
	void SetConstBufferV(ZRenderConstBufferRef ConstBufferV);
	void SetConstBufferF(ZRenderConstBufferRef ConstBufferF);
	void SetConstBufferH(ZRenderConstBufferRef ConstBufferH);
	void SetVertexShader(ZRenderShader* pShader);
	void SetFragmentShader(ZRenderShader* pShader);
	void SetHullShader(ZRenderShader* pShader);
	void SetDomainShader(ZRenderShader* pShader);
	void SetDrawIndexed(unsigned int nStartIndex, unsigned int nNumIndices, int nBaseVertex, unsigned int nNumVertices);
	void SetConstBufferBones(SQV* pSQV, unsigned int nConstBufferSlot, unsigned int* pCopyBones, unsigned int nNumCopyBones);
	static void SetConstBufferBonesImmediate(const SQV* pSQV, unsigned int nConstBufferSlot, const unsigned int* pCopyBones, unsigned int nNumCopyBones);
	unsigned char* CondExpand(unsigned int nCmdSize);
	void GetMoreSpace(unsigned int nNewSize);
	void SetBlendStateImmediate(ZRenderBlendState* pBlendState, float fFactor) const;
	void SetBlendStateImmediate(ZRenderBlendState* pBlendState) const;
	void SetRasterizerStateImmediate(ZRenderRasterizerState* pRasterizerState) const;
	void SetDepthStencilStateImmediate(ZRenderDepthStencilState* pDepthStencilState, unsigned int nStencilRef) const;
	void SetInputLayoutImmediate(ZRenderInputLayout* pInputLayout) const;
	void SetSharedConstBufferImmediate(unsigned int nCBuffer, unsigned int nCBufferSlot, ZRenderConstBufferRef SharedConstBuffer) const;
	void SetTextureImmediate(unsigned int nTexUnit, ZRenderShaderResourceView* pShaderResourceView) const;
	void SetVertexBuffersImmediate(unsigned int nStartSlot, unsigned int nNumBuffers, ZRenderVertexBuffer** pVertexBuffers, unsigned char* pStrides) const;
	void SetIndexBufferImmediate(ZRenderIndexBuffer* pIndexBuffer, unsigned int nOffset) const;
	void SetDrawIndexedImmediate(unsigned int nStartIndex, unsigned int nNumIndices, int nBaseVertex, unsigned int nNumVertices) const;
	void Begin(SRenderRecordRingBuffer* pRingBuffer, unsigned int nExtraHeaderSize);
	bool End();
};
