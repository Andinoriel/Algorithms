// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "RandomF.hpp"

#ifndef _WIN64
	std::mt19937 random;
#else
	std::mt19937_64 random;
#endif
std::random_device rd;

std::uniform_int_distribution<unsigned> rangeColor(10, 255);
std::uniform_real_distribution<float> rangeCoordX(0, GetSystemMetrics(SM_CXSCREEN) - 100.f);
std::uniform_real_distribution<float> rangeCoordY(0, GetSystemMetrics(SM_CYSCREEN) - 100.f);
std::uniform_real_distribution<float> rangeSize(10.f, 100.f);