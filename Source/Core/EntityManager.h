#pragma once 
#include "Entity.h"

namespace LE 
{
    class EntityManager
    {
        public:
            EntityManager();
            ~EntityManager() = default;

            Entity* CreateEntity(); 
            Entity* GetNextEntityID();

        private:
            unsigned int NextEntityID;
    }:
}