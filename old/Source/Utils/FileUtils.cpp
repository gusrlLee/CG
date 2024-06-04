#include "FileUtils.h"

namespace LE
{
    std::string LoadShaderSourceCodeFromFile(const char* file_path)
    {
        std::string shaderSrc;
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try 
        {
            shaderFile.open(file_path);
            std::stringstream shaderStream;
            shaderStream << shaderFile.rdbuf();
            shaderFile.close();
            shaderSrc = shaderStream.str();
        } 
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }

        return shaderSrc;
    }
}