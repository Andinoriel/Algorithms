#include "RandomF.hpp"

#ifndef _WIN64
	std::mt19937 random;
#else
	std::mt19937_64 random;
#endif
std::random_device rd;

std::uniform_int_distribution<unsigned> rangeColor(10, 255);
std::uniform_real_distribution<float> rangeSize(10, 100);
std::uniform_real_distribution<float> rangeAngle(0.f, 360.f);
std::uniform_real_distribution<float> rangeSpeed(1.f, 10.f);