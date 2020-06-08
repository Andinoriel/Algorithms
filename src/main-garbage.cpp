// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

// target: garbage-t

#define __GARBAGE_EXTERN__
#include "./pch.hpp"
#undef __GARBAGE_EXTERN__

int main(void)
{
    try
    {
        garbage_test::run();
    }
    catch(std::exception const& ex)
    {
        std::cerr << ex.what() << '\n';
    };
    return 0;
};