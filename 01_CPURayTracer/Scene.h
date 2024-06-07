#pragma once 


#include <stb/stb_image.h>

#include "glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Shader.h"

class Scene 
{
    public: 
        Scene() = default;
        ~Scene() = default;

        void Init();
        void Update();
        void Draw();
        void Release();

    private:
        Shader* m_Shader;
        unsigned int m_VAO, m_EBO, m_VBO;
        unsigned int m_Texture;
};