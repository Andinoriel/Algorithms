// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

// target: patterns-t

#define __PATTERNS_INCLUDES__
#include "./pch.hpp"
#undef __PATTERNS_INCLUDES__

int main(void)
{
    try
    {
        patterns_test::run();
    }
    catch(std::exception const& ex)
    {
        std::cerr << ex.what() << '\n';
    };
    return 0;
};