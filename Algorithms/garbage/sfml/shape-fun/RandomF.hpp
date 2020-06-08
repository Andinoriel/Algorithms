#pragma once
#ifndef __RANDOM_F_HPP__
#define __RANDOM_F_HPP__

#include <random>

extern std::mt19937 random;
extern std::random_device rd;

extern std::uniform_int_distribution<unsigned> rangeColor;
extern std::uniform_real_distribution<float> rangeSize;
extern std::uniform_real_distribution<float> rangeAngle;
extern std::uniform_real_distribution<float> rangeSpeed;

#endif // !__RANDOM_F_HPP__