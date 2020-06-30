// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

// target: garbage-t-w-sfml

#include "./pch.hpp"

#pragma region sfml/shape_fun
inline namespace sfml_shape_fun 
{
    extern int demo1(void);
    extern int demo2(void);
};
#pragma endregion sfml/shape_fun

int main(int argc, char** argv)
{
    try
    {
        if (argc == 2)
            if (*argv[1] == '1')
                demo1();
            else if (*argv[1] == '2')
                demo2();
    }
    catch(std::exception const& ex)
    {
        std::cerr << ex.what() << '\n';
    };
    return 0;
};