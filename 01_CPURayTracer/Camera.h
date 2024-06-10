#pragma once 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


struct Camera {
    glm::vec3 pos;
    glm::vec3 p0, p1, p2;

    glm::vec3 GetRay()
    {
        
    }
};