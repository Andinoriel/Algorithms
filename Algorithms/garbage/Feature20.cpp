// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/*
*	$ vcvars64.bat when using cl.exe
*	**********************************************************************
*	** Visual Studio 2019 Developer Command Prompt v16.2.0
*	** Copyright (c) 2019 Microsoft Corporation
*	**********************************************************************
*	[vcvarsall.bat] Environment initialized for: 'x64'
*
*	Compiled with #see more precisely for each item#
*
*
*	Copyright(c) 2019 Mykola Symon. All rights reserved.
*	Assemble of some C++20 featuers
*/

// ==================================================================================================
// ==================================================================================================

#pragma region P0614R1
/*
*	P0614R1 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0614r1.html 
*	Test done
*	clang -std=c++2a -c filename
*/
//#define P0614R1
#ifdef P0614R1
#include <vector>
#include <cstddef>
#include <iostream>

static std::vector<std::size_t> vec;

void Check(void)
{
	// init
	for (std::size_t t = 0; t < 42; ++t)
		vec.push_back(t);

	for (std::size_t t = 0; auto const& elem : vec)
	{
		std::cout << t << "\t" << vec.at(t);
		++t;
	};
};
#endif // P0614R1
#pragma endregion // P0614R1

#pragma region P1301R4
/*
*	P1301R4 https://thephd.github.io/vendor/future_cxx/papers/d1301.html
*	Test failed: declared support in clang 9, but not implemented (?); need fix (?)
*	clang -std=c++2a -c filename
*/
//#define P1301R4
#ifdef P1301R4
#include <cstddef>

[[nodiscard("reason")]] std::size_t* Check(void)
{
	return new std::size_t;
};

#endif // P1301R4
#pragma endregion // P1301R4

#pragma region P1002R1
/*
*	P1002R1 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1002r1.pdf
*	Test done
*	clang -std=c++2a -c filename
*/
//#define P1002R1
#ifdef P1002R1
#include <cstddef>

constexpr std::size_t Check(std::size_t x)
{
	try
	{
		return std::size_t(x + 1);
	}
	catch (...)
	{
		return std::size_t(0);
	};
};

#endif // P1002R1
#pragma endregion // P1002R1

#pragma region P1009R2
/*
*	P1009R2 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1009r2.pdf
*	Test done
*	clang -std=c++2a -c filename
*/
//#define P1009R2
#ifdef P1009R2

double* Check(void)
{
	double* res = new double[] {1, 2, 3};
	return res;
};

#endif // P1009R2
#pragma endregion // P1009R2

/*
*	
*	
*	
*/


// ==================================================================================================
// ==================================================================================================

/*
*	Entry point
*/
#ifndef __EP_OFF__
int main(void)
{
	return 0;
};
#endif // !__EP_OFF__