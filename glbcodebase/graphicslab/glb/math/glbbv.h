//-----------------------------------------------------------------------------------------
// Declaration: Copyright (c), by i_dovelemon, 2016. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2017 / 04 / 03
// Brief: Bounding Volume and intersection test
//-----------------------------------------------------------------------------------------
#ifndef GLB_GLBBV_H_
#define GLB_GLBBV_H_

#include "glbvector.h"

#include <stdint.h>

namespace glb {

namespace math {

//-----------------------------------------------------------------------------------
// CONSTANT VALUE
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// TYPE DECLARATION
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// CLASS DECLARATION
//----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// AABB DECLARATION
//----------------------------------------------------------------------------------
class AABB {
public:
    AABB();
    AABB(Vector* points);
    ~AABB();

public:
    bool HasIntersect(const AABB& other);

public:
    Vector m_Max;
    Vector m_Min;
};

//-----------------------------------------------------------------------------------
// Sphere DECLARATION
//----------------------------------------------------------------------------------
class Sphere {
public:
    Sphere();
    Sphere(Vector* points, int32_t num);
    ~Sphere();

public:
    bool HasIntersect(const Sphere& other);

public:
    Vector m_Center;
    float m_Radius;
};

};  // namespace math

};  // namespace glb

#endif  // GLB_GLBBV_H_