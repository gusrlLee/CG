#pragma once 

namespace LE 
{
    class Mesh 
    {
        public: 
            int ID;

            void LoadOBJ(std::string objFilePath);
            void CreateBuffer();
            
    };
}