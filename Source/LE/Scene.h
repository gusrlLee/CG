#pragma once
#include "Core.h"
#include "stb_image.h"

namespace LE
{
    class Scene
    {
        public:
            Scene(const char* filepath);
            ~Scene();
            MTL::Texture* texture;
            int width, height, channels;
    };
}