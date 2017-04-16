//----------------------------------------------------------------------
// Declaration: Copyright (c), by i_dovelemon, 2016. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2016 / 09 / 11
// Brief: Model manage all the meshes,materials and textures.
//----------------------------------------------------------------------
#ifndef GLB_GLBMODEL_H_
#define GLB_GLBMODEL_H_

#include "render/glbmesh.h"
#include "scene/glbmodelfile.h"

namespace glb {

namespace scene {

class Model {
public:
    enum {
        MT_DIFFUSE = 0,
        MT_ALPHA,
        MT_NORMAL,
        MT_REFLECT,
        MT_MAX,
    };
public:
    Model();
    virtual~Model();

public:
    static Model* Create(const char* file_name);

public:
    std::string GetName();
    int32_t GetMeshId();
    int32_t GetTexId(int32_t slot);
    int32_t GetMaterial();
    math::Vector GetBoundBoxMax();
    math::Vector GetBoundBoxMin();

    bool HasDiffuseTexture();
    bool HasAlphaTexture();
    bool HasNormalTexture();
    bool HasReflectTexture();
    bool HasTexCoord();
    bool HasNormal();
    bool HasTangent();
    bool HasBinormal();
    bool IsAcceptLight();
    void SetAcceptLight(bool accept);
    bool IsAcceptShadow();
    void SetAcceptShadow(bool accept);
    bool IsCastShadow();
    void SetCastShadow(bool cast);
    bool IsUseAO();

    void SetTexWithId(int32_t slot, int32_t tex_id);

private:
    std::string         m_Name;
    int32_t             m_Mesh;
    int32_t             m_Tex[MT_MAX];
    int32_t             m_Material;
    math::Vector        m_BoundBoxMax;
    math::Vector        m_BoundBoxMin;
    ModelEffectParam    m_ModelEffectParam;
};

class ModelMgr {
public:
    static void Initialize();
    static void Destroy();
    static Model* AddModel(const char* file_name);
    static Model* GetModelByName(const char* file_name);
};

};  // namespace scene

};  // namespace glb

#endif  // GLB_GLBMODEL_H_