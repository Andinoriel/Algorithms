// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

// #define __GARBAGE_EXTERN__
// #define __PATTERNS_INCLUDES__
#include "../Algorithms/pch.hpp"

// inside part that use rttr
#define __RTTR_TEST_OFF__
#include "..//Algorithms/garbage/templates.hpp"

int main(void)
{
#ifndef __RTTR_TEST_OFF__

	RTTR_Test::DO_TEST();

#endif

#pragma region COMMENT_ME_IF_RTTR_USE

	#pragma region templates
	std::size_t count = 0;
	AlmostReflectionTypeTraits::pod_reflection::detect_fields_count<AlmostReflectionTypeTraits::POD>(count);
	std::cout << "AlmostReflectionTypeTraits::POD fields count: " << count << "\n";
	

	std::cout << "10! = " << TemplateMagic::factorial<10>::result << "\n";
	TemplateMagic::deep_switch::calc(1, 2, 3); // ...


	struct has_foo { inline void foo() const noexcept { std::cout << "foo\n"; } } foo;
	struct has_bar { inline void bar() const noexcept { std::cout << "bar\n"; } } bar;
	AlmostReflectionTypeTraits::call_foo_or_bar(foo);
	AlmostReflectionTypeTraits::call_foo_or_bar(bar);
	#pragma endregion // templates

	// garbage_test::run();
	// patterns_test::run();


#pragma endregion

	return ([]() -> int { return 0; })();
};

#pragma region EMPTY_ENTRY_POINT
#define EMPTY_ENTRY_POINT
#ifndef EMPTY_ENTRY_POINT

int __cdecl main(void)
{
	return 0;
};

#endif // !EMPTY_ENTRY_POINT
#pragma endregion // EMPTY_ENTRY_POINT
