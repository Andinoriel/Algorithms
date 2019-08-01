// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Strategy.hpp"

void Strategy::ConcreteStrategy1::Execute(void)
{
	std::cout << "Concrete Strategy 1: executing...\n";
}
void Strategy::ConcreteStrategy2::Execute(void)
{
	std::cout << "Concrete Strategy 2: executing...\n";
}

Strategy::Context::Context(IStrategy* strategy)
{
	this->strategy = strategy;
}
void Strategy::Context::SetStrategy(IStrategy* strategy)
{
	this->strategy = strategy;
}
void Strategy::Context::DoSomething(void)
{
	this->strategy->Execute();
}

#pragma region TEST
void Strategy::TEST::DO_TEST(void)
{
	ConcreteStrategy1 cc1; ConcreteStrategy2 cc2;
	Context ctx;

	ctx.SetStrategy(&cc1);
	ctx.DoSomething();
	ctx.SetStrategy(&cc2);
	ctx.DoSomething();
}
#pragma endregion