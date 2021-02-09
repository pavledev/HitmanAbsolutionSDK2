#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>

class ZStateManager
{
public:
    ID3D11DeviceContext* m_pDeviceContextImmediate;
    ID3D11Buffer* m_psConstantBuffers[14];
    unsigned int m_psConstantDirtyStart;
    unsigned int m_psConstantDirtyEnd;
    ID3D11Buffer* m_vsConstantBuffers[14];
    unsigned int m_vsConstantDirtyStart;
    unsigned int m_vsConstantDirtyEnd;
    ID3D11Buffer* m_hsConstantBuffers[14];
    unsigned int m_hsConstantDirtyStart;
    unsigned int m_hsConstantDirtyEnd;
    ID3D11Buffer* m_dsConstantBuffers[14];
    unsigned int m_dsConstantDirtyStart;
    unsigned int m_dsConstantDirtyEnd;
    ID3D11Buffer* m_gsConstantBuffers[14];
    unsigned int m_gsConstantDirtyStart;
    unsigned int m_gsConstantDirtyEnd;
    ID3D11PixelShader* m_psShader;
    ID3D11VertexShader* m_vsShader;
    ID3D11HullShader* m_hsShader;
    ID3D11DomainShader* m_dsShader;
    ID3D11GeometryShader* m_gsShader;
    ID3D11SamplerState* m_psSamplers[16];
    unsigned int m_psSamplersDirtyStart;
    unsigned int m_psSamplersDirtyEnd;
    ID3D11SamplerState* m_vsSamplers[16];
    unsigned int m_vsSamplersDirtyStart;
    unsigned int m_vsSamplersDirtyEnd;
    ID3D11SamplerState* m_gsSamplers[16];
    unsigned int m_gsSamplersDirtyStart;
    unsigned int m_gsSamplersDirtyEnd;
    ID3D11InputLayout* m_inputLayout;
    ID3D11Buffer* m_vertexBuffers[32];
    unsigned int m_vertexStrides[32];
    unsigned int m_vertexOffsets[32];
    ID3D11Buffer* m_indexBuffer;
    unsigned int m_indexOffset;
    DXGI_FORMAT m_indexFormat;
    D3D_PRIMITIVE_TOPOLOGY m_topology;
    ID3D11ShaderResourceView* m_psTextures[128];
    unsigned int m_psTextureDirtyStart;
    unsigned int m_psTextureDirtyEnd;
    ID3D11ShaderResourceView* m_vsTextures[128];
    unsigned int m_vsTextureDirtyStart;
    unsigned int m_vsTextureDirtyEnd;
    ID3D11BlendState* m_pBlendState;
    float m_fBlendFactor;
    ID3D11DepthStencilState* m_pDepthStencilState;
    unsigned int m_nStencilRef;
    ID3D11RasterizerState* m_pRasterizerState;
};
