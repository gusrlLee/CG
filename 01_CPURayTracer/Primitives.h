#pragma once 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

typedef struct _Triangle {
    glm::vec3 v0, v1, v2;
    glm::vec3 centroid;
} Triangle;