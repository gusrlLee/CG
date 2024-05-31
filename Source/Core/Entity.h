#pragma once 
#include <iostream>

namespace LE 
{
    class Entity
    {
        public:
            Entity(unsigned int id);
            {
                ID = id;
            }
            ~Entity() = default;

            unsigned int ID = 0;
    };
}