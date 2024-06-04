#pragma once 

namespace LE 
{
    class Vec3f 
    {
        float e[3];

        Vec3f() : e{0.0f, 0.0f, 0.0f} {}
        Vec3f(float e1, float e2, float e3) : e{e1, e2, e3} {}

        

    };
}