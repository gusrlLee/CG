#pragma once
#include <simd/simd.h>

using namespace simd;

namespace LE
{
    struct VertexData {
        float4 position;
        float2 textureCoordinate;
    };
}