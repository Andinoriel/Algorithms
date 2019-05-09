#pragma once
#include <random>
#include <Windows.h>

#ifndef _WIN64
	extern std::mt19937 random;
#else
	extern std::mt19937_64 random;
#endif
extern std::random_device rd;

extern std::uniform_int_distribution<unsigned> rangeColor;
extern std::uniform_real_distribution<float> rangeSize;
extern std::uniform_real_distribution<float> rangeAngle;
extern std::uniform_real_distribution<float> rangeSpeed;