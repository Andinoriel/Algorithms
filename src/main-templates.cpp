// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

// target: patterns-t

#include "./pch.hpp"

#include "../Algorithms/garbage/__oth/templates.hpp"

int main(void)
{
    try
    {
        std::size_t count = 0;
		AlmostReflectionTypeTraits::pod_reflection::detect_fields_count<AlmostReflectionTypeTraits::POD>(count);
		std::cout << "<AlmostReflectionTypeTraits::POD> fields count: " << count << "\n";

    	struct has_foo { inline void foo() const noexcept { std::cout << "foo\n"; } } foo;
		struct has_bar { inline void bar() const noexcept { std::cout << "bar\n"; } } bar;
		AlmostReflectionTypeTraits::call_foo_or_bar(foo);
		AlmostReflectionTypeTraits::call_foo_or_bar(bar);

		std::cout << "10! = " << TemplateMagic::factorial<10>::result << "\n";

		TemplateMagic::deep_switch::calc(1, 2);
    }
    catch(std::exception const& ex)
    {
        std::cerr << ex.what() << '\n';
    };
    return 0;
};
