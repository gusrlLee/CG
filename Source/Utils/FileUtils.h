#pragma once 
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace LE 
{
     std::string LoadShaderSourceCodeFromFile(const char* file_path);
}