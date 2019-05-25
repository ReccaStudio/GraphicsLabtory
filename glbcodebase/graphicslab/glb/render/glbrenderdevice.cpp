//--------------------------------------------------------------------
// Declaration: Copyright (c), by i_dovelemon, 2016. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2016 / 10 / 26
// Brief: Render device is used to render primitives
//--------------------------------------------------------------------
#include "glbrenderdevice.h"

#include "imp/dx11/glbrenderdeviceimp.h"
#include "imp/gl/glbrenderdeviceimp.h"

namespace glb {

namespace render {

//-----------------------------------------------------------------------------------
// CONSTANT VALUE
//----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// TYPE DECLARATION
//-----------------------------------------------------------------------------------
static DeviceImp* s_DeviceImp = nullptr;

//-----------------------------------------------------------------------------------
// Device DEFINITION
//-----------------------------------------------------------------------------------
void Device::Initialize() {
    if (s_DeviceImp == nullptr) {
        s_DeviceImp = new DeviceImp;
        if (s_DeviceImp != nullptr) {
            s_DeviceImp->Initialize();
        } else {
            GLB_SAFE_ASSERT(false);
        }
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::Destroy() {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->Destroy();
        GLB_SAFE_DELETE(s_DeviceImp);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetVertexBuffer(mesh::VertexBuffer* buf) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetVertexBuffer(buf);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetVertexLayout(VertexLayout layout) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetVertexLayout(layout);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetTexture(int32_t slot, texture::Texture* tex, int32_t tex_unit) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetTexture(slot, tex, tex_unit);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::ClearTexture() {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->ClearTexture();
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetShader(shader::Program* program) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetShader(program);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetShaderLayout(ShaderLayout layout) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetShaderLayout(layout);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform1i(int32_t location, int32_t v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform1i(location, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform1f(int32_t location, float v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform1f(location, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform3f(int32_t location, const math::Vector& v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform3f(location, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform4f(int32_t location, const math::Vector& v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform4f(location, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformMatrix(int32_t location, const math::Matrix& m) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformMatrix(location, const_cast<math::Matrix&>(m));
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformSampler2DMS(int32_t location, int32_t slot) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformSampler2DMS(location, slot);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformSampler2D(int32_t location, int32_t sampler) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformSampler2D(location, sampler);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformSampler3D(int32_t location, int32_t slot) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformSampler3D(location, slot);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformSamplerCube(int32_t location, int32_t sampler) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformSamplerCube(location, sampler);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform1i(const char* name, int32_t v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform1i(name, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform1f(const char* name, float v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform1f(name, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform3f(const char* name, const math::Vector& v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform3f(name, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniform4f(const char* name, const math::Vector& v) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniform4f(name, v);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformMatrix(const char* name, math::Matrix& m) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformMatrix(name, m);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformSampler2D(const char* name, texture::Texture* tex, int32_t texUnit) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformSampler2D(name, tex, texUnit);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformSampler3D(const char* name, texture::Texture* tex, int32_t texUnit) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformSampler3D(name, tex, texUnit);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetUniformSamplerCube(const char* name, texture::Texture* tex, int32_t texUnit) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetUniformSamplerCube(name, tex, texUnit);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetDepthTestEnable(bool enable) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetDepthTestEnable(enable);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetDepthWriteEnable(bool enable) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetDepthWriteEnable(enable);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetAlphaBlendEnable(bool enable) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetAlphaBlendEnable(enable);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetAlphaBlendFunc(AlphaBlendFactor factor, AlphaBlendFunc func) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetAlphaBlendFunc(factor, func);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetCullFaceEnable(bool enable) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetCullFaceEnable(enable);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetCullFaceMode(CullMode mode) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetCullFaceMode(mode);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetRenderTarget(RenderTarget* rt) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetRenderTarget(rt);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetViewport(x, y, width, height);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetDrawColorBuffer(DrawColorBuffer buffer) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetDrawColorBuffer(buffer);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetDrawMultiColorBuffer(DrawColorBuffer* buffers, int32_t num) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetDrawMultiColorBuffer(buffers, num);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetClearColor(float r, float g, float b, float alpha) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetClearColor(r, g, b, alpha);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetClearDepth(float depth) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetClearDepth(depth);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::Clear(int32_t flag) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->Clear(flag);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::Draw(PrimitiveType type, int32_t first, int32_t count) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->Draw(type, first, count);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::DrawInstance(PrimitiveType type, int32_t first, int32_t count, int32_t instance) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->DrawInstance(type, first, count, instance);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SetupVSync(bool enable) {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SetupVSync(enable);
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

void Device::SwapBuffer() {
    if (s_DeviceImp != nullptr) {
        s_DeviceImp->SwapBuffer();
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

};  // namespace render

};  // namespace glb