//-----------------------------------------------------------
// Declaration: Copyright (c), by i_dovelemon, 2016. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2016 / 10 / 24
// Brief: Manage uniforms
// Update[2019-05-29]: Add build-in time
//-----------------------------------------------------------
#ifndef GLB_GLBUNIFORM_H_
#define GLB_GLBUNIFORM_H_

#include <stdint.h>

#include "math/glbmatrix.h"
#include "math/glbvector.h"

#include "scene/glbscene.h"

namespace glb {

class Object;

namespace render {

namespace uniform {

// Uniform enum
enum {
    GLB_PROJM = 0,
    GLB_VIEWM,
    GLB_WORLDM,
    GLB_SHADOWM0,
    GLB_SHADOWM1,
    GLB_SHADOWM2,
    GLB_SHADOWM3,
    GLB_SHADOWSPLIT0,
    GLB_SHADOWSPLIT1,
    GLB_SHADOWSPLIT2,
    GLB_SHADOWMINDEX,
    GLB_SHADOWMAP_WIDTH,
    GLB_SHADOWMAP_HEIGHT,
    GLB_TRANS_INV_WORLDM,
    GLB_DECAL_VIEWM,
    GLB_DECAL_PROJM,
    GLB_SHADOWTEX0,
    GLB_SHADOWTEX1,
    GLB_SHADOWTEX2,
    GLB_SHADOWTEX3,
    GLB_BRDFPFTTEX,
    GLB_LIGHT0TEX,
    GLB_LIGHT1TEX,
    GLB_LIGHT2TEX,
    GLB_DECALTEX,
    GLB_EYEPOS,
    GLB_LOOKAT,
    GLB_GLOBALLIGHT_AMBIENT,
    GLB_PARALLELLIGHT_DIR,
    GLB_PARALLELLIGHT,
    GLB_SKYLIGHT_DIFFUSE,
    GLB_SKYLIGHT_SPECULAR,
    GLB_SKYLIGHT,
    GLB_SKYLIGHT_SPECULAR_LOD,
    GLB_FAR_CLIP,
    GLB_SCREEN_WIDTH,
    GLB_SCREEN_HEIGHT,
    GLB_TIMER,
    GLB_MAX,
};

// Uniform table
static const struct {
    char        name[64];
    int32_t     id;
    int32_t     flag; // 1: Scene uniform 0: Object uniform
} kEngineUniforms[] = {
    {"glb_unif_ProjM",                           GLB_PROJM,                          1},
    {"glb_unif_ViewM",                           GLB_VIEWM,                          1},
    {"glb_unif_WorldM",                          GLB_WORLDM,                         0},
    {"glb_unif_ShadowM0",                        GLB_SHADOWM0,                       1},
    {"glb_unif_ShadowM1",                        GLB_SHADOWM1,                       1},
    {"glb_unif_ShadowM2",                        GLB_SHADOWM2,                       1},
    {"glb_unif_ShadowM3",                        GLB_SHADOWM3,                       1},
    {"glb_unif_ShadowSplit0",                    GLB_SHADOWSPLIT0,                   1},
    {"glb_unif_ShadowSplit1",                    GLB_SHADOWSPLIT1,                   1},
    {"glb_unif_ShadowSplit2",                    GLB_SHADOWSPLIT2,                   1},
    {"glb_unif_ShadowMIndex",                    GLB_SHADOWMINDEX,                   1},
    {"glb_unif_ShadowMapWidth",                  GLB_SHADOWMAP_WIDTH,                1},
    {"glb_unif_ShadowMapHeight",                 GLB_SHADOWMAP_HEIGHT,               1},
    {"glb_unif_Trans_Inv_WorldM",                GLB_TRANS_INV_WORLDM,               0},
    {"glb_unif_DecalViewM",                      GLB_DECAL_VIEWM,                    1},
    {"glb_unif_DecalProjM",                      GLB_DECAL_PROJM,                    1},
    {"glb_unif_ShadowTex0",                      GLB_SHADOWTEX0,                     0},
    {"glb_unif_ShadowTex1",                      GLB_SHADOWTEX1,                     0},
    {"glb_unif_ShadowTex2",                      GLB_SHADOWTEX2,                     0},
    {"glb_unif_ShadowTex3",                      GLB_SHADOWTEX3,                     0},
    {"glb_unif_BRDFPFTTex",                      GLB_BRDFPFTTEX,                     1},
    {"glb_unif_Light0Tex",                       GLB_LIGHT0TEX,                      0},
    {"glb_unif_Light1Tex",                       GLB_LIGHT1TEX,                      0},
    {"glb_unif_Light2Tex",                       GLB_LIGHT2TEX,                      0},
    {"glb_unif_DecalTex",                        GLB_DECALTEX,                       1},
    {"glb_unif_EyePos",                          GLB_EYEPOS,                         1},
    {"glb_unif_LookAt",                          GLB_LOOKAT,                         1},
    {"glb_unif_GlobalLight_Ambient",             GLB_GLOBALLIGHT_AMBIENT,            1},
    {"glb_unif_ParallelLight_Dir",               GLB_PARALLELLIGHT_DIR,              1},
    {"glb_unif_ParallelLight",                   GLB_PARALLELLIGHT,                  1},
    {"glb_unif_DiffuseSkyCubeMap",               GLB_SKYLIGHT_DIFFUSE,               1},
    {"glb_unif_SpecularSkyCubeMap",              GLB_SKYLIGHT_SPECULAR,              1},
    {"glb_unif_SkyLight",                        GLB_SKYLIGHT,                       1},
    {"glb_unif_SpecularSkyPFCLOD",               GLB_SKYLIGHT_SPECULAR_LOD,          1},
    {"glb_unif_FarClip",                         GLB_FAR_CLIP,                       1},
    {"glb_unif_ScreenWidth",                     GLB_SCREEN_WIDTH,                   1},
    {"glb_unif_ScreenHeight",                    GLB_SCREEN_HEIGHT,                  1},
    {"glb_unif_Timer",                           GLB_TIMER,                          1},
};

static_assert(sizeof(kEngineUniforms) / sizeof(kEngineUniforms[0]) == GLB_MAX, "Must match");

// Uniform wrapper
class Wrapper {
public:
    enum {
        FMT_INT,
        FMT_FLOAT,
        FMT_FLOAT3,
        FMT_MATRIX,
        FMT_SAMPLER2D,
        FMT_SAMPLERCUBE,
    };

public:
    Wrapper();
    virtual ~Wrapper();

public:
    void SetFloat(float v);
    float GetFloat();

    void SetVector(math::Vector v);
    math::Vector& GetVector();

    void SetInt(int v);
    int GetInt();

    void SetSampler2D(int32_t sampler);
    int32_t GetSampler2D();

    void SetSampler3D(int32_t sampler);
    int32_t GetSampler3D();

    void SetSamplerCube(int32_t sampler);
    int32_t GetSamplerCube();

    void SetMatrix(math::Matrix m);
    math::Matrix& GetMatrix();

    void SetFormat(int32_t format);
    int32_t GetFormat();

private:
    int32_t                 m_Int;
    int32_t                 m_Sampler2D;
    int32_t                 m_Sampler3D;
    int32_t                 m_SamplerCube;
    float                   m_Float;
    math::Vector            m_Vector;
    math::Matrix            m_Matrix;
    int32_t                 m_Format;
};


// Uniform picker
typedef Wrapper (*Uniform_Picker)(scene::Object*);

Wrapper uniform_projm_picker(scene::Object*);                     // Pick glb_ProjM
Wrapper uniform_viewm_picker(scene::Object*);                     // Pick glb_ViewM
Wrapper uniform_worldm_picker(scene::Object*);                    // Pick glb_WorldM
Wrapper uniform_shadowm0_picker(scene::Object*);                  // Pick glb_ShadowM0
Wrapper uniform_shadowm1_picker(scene::Object*);                  // Pick glb_ShadowM1
Wrapper uniform_shadowm2_picker(scene::Object*);                  // Pick glb_ShadowM2
Wrapper uniform_shadowm3_picker(scene::Object*);                  // Pick glb_ShadowM3
Wrapper uniform_shadowsplit0_picker(scene::Object*);              // Pick glb_ShadowSplit0
Wrapper uniform_shadowsplit1_picker(scene::Object*);              // Pick glb_ShadowSplit1
Wrapper uniform_shadowsplit2_picker(scene::Object*);              // Pick glb_ShadowSplit2
Wrapper uniform_shadowmindex_picker(scene::Object*);              // Pick glb_ShadowMIndex
Wrapper uniform_shadowmap_width_picker(scene::Object*);           // Pick glb_ShadowMapWidth
Wrapper uniform_shadowmap_height_picker(scene::Object*);          // Pick glb_ShadowMapHeight
Wrapper uniform_trans_inv_worldm_picker(scene::Object*);          // Pick glb_Trans_Inv_WorldM
Wrapper uniform_decal_viewm_picker(scene::Object*);               // Pick glb_DecalViewM
Wrapper uniform_decal_projm_picker(scene::Object*);               // Pick glb_DecalProjM
Wrapper uniform_shadow0_texslot_picker(scene::Object*);           // Pick glb_ShadowTex0
Wrapper uniform_shadow1_texslot_picker(scene::Object*);           // Pick glb_ShadowTex1
Wrapper uniform_shadow2_texslot_picker(scene::Object*);           // Pick glb_ShadowTex2
Wrapper uniform_shadow3_texslot_picker(scene::Object*);           // Pick glb_ShadowTex3
Wrapper uniform_brdf_pft_texslot_picker(scene::Object* obj);      // Pick glb_BRDFPFT
Wrapper uniform_light0_texslot_picker(scene::Object* obj);        // Pick glb_Light0Tex
Wrapper uniform_light1_texslot_picker(scene::Object* obj);        // Pick glb_Light1Tex
Wrapper uniform_light2_texslot_picker(scene::Object* obj);        // Pick glb_Light2Tex
Wrapper uniform_decal_texslot_picker(scene::Object* obj);         // Pick glb_DecalTex
Wrapper uniform_eye_pos_picker(scene::Object*);                   // Pick glb_EyePos
Wrapper uniform_look_at_picker(scene::Object*);                   // Pick glb_LookAt
Wrapper uniform_global_light_ambient_picker(scene::Object*);      // Pick glb_GlobalLight_Ambient
Wrapper uniform_parallel_light_dir_picker(scene::Object*);        // Pick glb_ParallelLight_Dir
Wrapper uniform_parallel_light_picker(scene::Object*);            // Pick glb_ParallelLight
Wrapper uniform_skylight_diffuse_picker(scene::Object*);          // Pick glb_unif_DiffuseSkyCubeMap
Wrapper uniform_skylight_specular_picker(scene::Object*);         // Pick glb_unif_SpecularSkyCubeMap
Wrapper uniform_skylight_picker(scene::Object*);                  // Pick glb_unif_SkyLight
Wrapper uniform_skylight_lod_picker(scene::Object*);              // Pick glb_unif_SpecularSkyPFCLOD
Wrapper uniform_far_clip_picker(scene::Object*);                  // Pick glb_FarClip
Wrapper uniform_screen_width_picker(scene::Object*);              // Pick glb_ScreenWidth
Wrapper uniform_screen_height_picker(scene::Object*);             // Pick glb_ScreenHeight
Wrapper uniform_timer_picker(scene::Object*);                     // Pick glb_unif_Timer;

// Uniform picker table
static const struct {
    Uniform_Picker      picker;
    int                 id;
} kUniformPickers[] = {
    {uniform_projm_picker,                      GLB_PROJM},
    {uniform_viewm_picker,                      GLB_VIEWM},
    {uniform_worldm_picker,                     GLB_WORLDM},
    {uniform_shadowm0_picker,                   GLB_SHADOWM0},
    {uniform_shadowm1_picker,                   GLB_SHADOWM1},
    {uniform_shadowm2_picker,                   GLB_SHADOWM2},
    {uniform_shadowm3_picker,                   GLB_SHADOWM3},
    {uniform_shadowsplit0_picker,               GLB_SHADOWSPLIT0},
    {uniform_shadowsplit1_picker,               GLB_SHADOWSPLIT1},
    {uniform_shadowsplit2_picker,               GLB_SHADOWSPLIT2},
    {uniform_shadowmindex_picker,               GLB_SHADOWMINDEX},
    {uniform_shadowmap_width_picker,            GLB_SHADOWMAP_WIDTH},
    {uniform_shadowmap_height_picker,           GLB_SHADOWMAP_HEIGHT},
    {uniform_trans_inv_worldm_picker,           GLB_TRANS_INV_WORLDM},
    {uniform_decal_viewm_picker,                GLB_DECAL_VIEWM},
    {uniform_decal_projm_picker,                GLB_DECAL_PROJM},
    {uniform_shadow0_texslot_picker,            GLB_SHADOWTEX0},
    {uniform_shadow1_texslot_picker,            GLB_SHADOWTEX1},
    {uniform_shadow2_texslot_picker,            GLB_SHADOWTEX2},
    {uniform_shadow3_texslot_picker,            GLB_SHADOWTEX3},
    {uniform_brdf_pft_texslot_picker,           GLB_BRDFPFTTEX},
    {uniform_light0_texslot_picker,             GLB_LIGHT0TEX},
    {uniform_light1_texslot_picker,             GLB_LIGHT1TEX},
    {uniform_light2_texslot_picker,             GLB_LIGHT2TEX},
    {uniform_decal_texslot_picker,              GLB_DECALTEX},
    {uniform_eye_pos_picker,                    GLB_EYEPOS},
    {uniform_look_at_picker,                    GLB_LOOKAT},
    {uniform_global_light_ambient_picker,       GLB_GLOBALLIGHT_AMBIENT},
    {uniform_parallel_light_dir_picker,         GLB_PARALLELLIGHT_DIR},
    {uniform_parallel_light_picker,             GLB_PARALLELLIGHT},
    {uniform_skylight_diffuse_picker,           GLB_SKYLIGHT_DIFFUSE},
    {uniform_skylight_specular_picker,          GLB_SKYLIGHT_SPECULAR},
    {uniform_skylight_picker,                   GLB_SKYLIGHT},
    {uniform_skylight_lod_picker,               GLB_SKYLIGHT_SPECULAR_LOD},
    {uniform_far_clip_picker,                   GLB_FAR_CLIP},
    {uniform_screen_width_picker,               GLB_SCREEN_WIDTH},
    {uniform_screen_height_picker,              GLB_SCREEN_HEIGHT},
    {uniform_timer_picker,                      GLB_TIMER},
};
static_assert(sizeof(kUniformPickers) / sizeof(kUniformPickers[0]) == GLB_MAX, "Must match");

// Uniform entry
struct UniformEntry {
    uint32_t            location;
    int                 id;
    int32_t             flag;  // 0:Scene Uniforms 1:Object Uniforms
};

//---------------------------------------------------------------------

bool IsInternalParameter(const char* name);

};  // namespace uniform

};  // namespace render

};  // namespace glb

#endif  // GLB_GLBUNIFORM_H_
