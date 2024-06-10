#pragma once 

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

inline float fminf( float a, float b ) { return a < b ? a : b; }
inline float fmaxf( float a, float b ) { return a > b ? a : b; }

inline glm::vec3 fminf( const glm::vec3& a, const glm::vec3& b ) 
{
    return glm::vec3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
}
inline glm::vec3 fmaxf( const glm::vec3& a, const glm::vec3& b ) 
{ 
    
    return glm::vec3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
}