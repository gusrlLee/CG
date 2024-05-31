#pragma once
#include "Component.h"
#include <>

namespace LE 
{
    class ComponentMananger
    {
        public:
            template<typename T>
            void AddComponent(Entity entity, T component);
            template<typename T>
            T* GetComponent(Entity entity, T component);
            
            unsigned int GetNextEntityID();


        private:
            std::unordered_map<std::type_index, std::unordered_map<Entity, std::shared_ptr<IComponent>>> components;
            unsigned int NextEntityID;
    };
}