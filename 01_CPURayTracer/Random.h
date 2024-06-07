#pragma once 
#include <random>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// inline double random_double() {
//     static std::uniform_real_distribution<double> distribution(0.0, 1.0);
//     static std::mt19937 generator;
//     return distribution(generator);
// }

static inline uint32_t RandomUint32() {
    static std::uniform_real_distribution<uint32_t> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

static uint32_t PCG_Hash(uint32_t input)
{
    uint32_t state = input * 747796405u + 2891336453u;
    uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
    return (word >> 22u) ^ word;
}

// static float RandomFloat(uint32_t& seed)
// {
//     seed = PCG_Hash(seed);
//     return (float)seed / (float) std:: numeric_limits<uint32_t>::max();
// }

static float RandomFloat()
{
    uint32_t seed = RandomUint32();
    seed = PCG_Hash(seed);
    return (float)seed / (float) std:: numeric_limits<uint32_t>::max();
}

// inline double random_double() {
//     // Returns a random real in [0,1).
//     return rand() / (RAND_MAX + 1.0);
// }

// inline double random_double(double min, double max) {
//     // Returns a random real in [min,max).
//     return min + (max-min)*random_double();
// }

// inline float random_float() {
//     // Returns a random real in [0,1).
//     return static_cast<float>(rand() / (RAND_MAX + 1.0));
// }

// inline float random_float(double min, double max) {
//     // Returns a random real in [min,max).
//     return static_cast<float>(min + (max-min)*random_double());
// }

// inline int random_int(int min, int max) {
//     // Returns a random integer in [min,max].
//     return static_cast<int>(random_double(min, max+1));
// }
