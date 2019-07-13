// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Bridge.hpp"

#pragma region Implementations
void Bridge::ConcreteImplementation1::Method1(void) noexcept
{
	std::cout << "\nConcrete Impl1 - Method 1";
}
void Bridge::ConcreteImplementation1::Method2(void) noexcept
{
	std::cout << "\nConcrete Impl1 - Method 2";
}
void Bridge::ConcreteImplementation1::Method3(void) noexcept
{
	std::cout << "\nConcrete Impl1 - Method 3";
}

void Bridge::ConcreteImplementation2::Method1(void) noexcept
{
	std::cout << "\nConcrete Impl2 - Method 1";
}
void Bridge::ConcreteImplementation2::Method2(void) noexcept
{
	std::cout << "\nConcrete Impl2 - Method 2";
}
void Bridge::ConcreteImplementation2::Method3(void) noexcept
{
	std::cout << "\nConcrete Impl2 - Method 3";
}
#pragma endregion

#pragma region Abstraction
void Bridge::Abstraction::ChangeImplementation(IImplementation* implementation)
{
	this->current_implementation = implementation;
}
void Bridge::Abstraction::Feature1(void) noexcept
{
	this->current_implementation->Method1();
}
void Bridge::Abstraction::Feature2(void) noexcept
{
	this->current_implementation->Method2();
}
void Bridge::Abstraction::Feature3(void) noexcept
{
	this->current_implementation->Method3();
}
#pragma endregion

#pragma region Client
void Bridge::Client::ChangeImplementation(IImplementation* implementation)
{
	this->abtraction.ChangeImplementation(implementation);
}
void Bridge::Client::UseFeature1() noexcept
{
	this->abtraction.Feature1();
}
void Bridge::Client::UseFeature2() noexcept
{
	this->abtraction.Feature2();
}
void Bridge::Client::UseFeature3() noexcept
{
	this->abtraction.Feature3();
}
#pragma endregion

#pragma region TEST
void Bridge::TEST::DO_TEST(void)
{
	Abstraction abstraction;
	abstraction.ChangeImplementation(new ConcreteImplementation1());

	abstraction.Feature1();
	abstraction.Feature2();
	abstraction.Feature3();

	abstraction.ChangeImplementation(new ConcreteImplementation2());

	abstraction.Feature1();
	abstraction.Feature2();
	abstraction.Feature3();
};
#pragma endregion