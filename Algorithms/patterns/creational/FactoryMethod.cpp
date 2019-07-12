// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "FactoryMethod.hpp"

#pragma region Products
void FactoryMethod::DefaultProduct::DoStuff(void)
{
	std::cout << "\nDefault Product: doing stuff...";
}
void FactoryMethod::ConcreteProduct1::DoStuff(void)
{
	std::cout << "\nConcrete Product 1: doing stuff...";
}
void FactoryMethod::ConcreteProduct2::DoStuff(void)
{
	std::cout << "\nConcrete Product 2: doing stuff...";
}
#pragma endregion

#pragma region Creators
FactoryMethod::IProduct* FactoryMethod::Creator::CreateProduct(void)
{
	return new DefaultProduct();
}
FactoryMethod::ConcreteProduct1* FactoryMethod::ConcreteCreator1::CreateProduct(void)
{
	return new ConcreteProduct1();
}
FactoryMethod::ConcreteProduct2* FactoryMethod::ConcreteCreator2::CreateProduct(void)
{
	return new ConcreteProduct2();
}
#pragma endregion

#pragma region TEST
void FactoryMethod::TEST::DO_TEST(void)
{
	auto SomeOperation = [](Creator* creator) -> void
	{
		std::cout << "\nCreator undefined, but: ";
		creator->CreateProduct()->DoStuff();
	};
	SomeOperation(new Creator());
	SomeOperation(new ConcreteCreator1());
	SomeOperation(new ConcreteCreator2());
}
#pragma endregion