#include "EntityManager.h"

namespace LE 
{
    EntityManager::EntityManager()
    {
        NextEntityID = 0;
    }


    Entity* EntityManager::CreateEntity()
    {
        Entity* pEntity = new Entity(NextEntityID);
        NextEntityID++;
        return pEntity;
    }

    Entity* EntityManager::GetNextEntityID()
    {
        return NextEntityID;
    }
}