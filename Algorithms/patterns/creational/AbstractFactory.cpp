// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "AbstractFactory.hpp"

#pragma region Products
void ConcreteProductA1::SomeOperation(void)
{
	std::cout << "\nConcrete Product A1: doing something...";
}
void ConcreteProductA2::SomeOperation(void)
{
	std::cout << "\nConcrete Product A2: doing something...";
}
void ConcreteProductB1::SomeOperation(void)
{
	std::cout << "\nConcrete Product B1: doing something...";
}
void ConcreteProductB2::SomeOperation(void)
{
	std::cout << "\nConcrete Product B2: doing something...";
}
#pragma endregion

#pragma region Factories
IProduct* ConcreteFactory1::CreateProduct1(void)
{
	return new ConcreteProductA1();
}
IProduct* ConcreteFactory1::CreateProduct2(void)
{
	return new ConcreteProductA2();
}
IProduct* ConcreteFactory2::CreateProduct1(void)
{
	return new ConcreteProductB1();
}
IProduct* ConcreteFactory2::CreateProduct2(void)
{
	return new ConcreteProductB2();
}
#pragma endregion

#pragma region Client
Client::Client(IAbstractFactory& factory)
{
	this->current_factory = &factory;
}
void Client::ChangeFactory(IAbstractFactory& factory)
{
	this->current_factory = &factory;
}
IProduct* Client::CreateProduct1(void) noexcept
{
	return this->current_factory->CreateProduct1();
}
IProduct* Client::CreateProduct2(void) noexcept
{
	return this->current_factory->CreateProduct2();
}
#pragma endregion

#pragma region TEST
void TEST::DO_TEST(void)
{
	ConcreteFactory1 cf1; ConcreteFactory2 cf2;
	Client client(cf1);

	client.CreateProduct1()->SomeOperation();
	client.CreateProduct2()->SomeOperation();

	client.ChangeFactory(cf2);

	client.CreateProduct1()->SomeOperation();
	client.CreateProduct2()->SomeOperation();
};
#pragma endregion