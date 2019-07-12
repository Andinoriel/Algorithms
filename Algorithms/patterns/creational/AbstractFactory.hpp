#pragma once
#ifndef __ABSTRACT_FACTORY_HPP__
#define __ABSTRACT_FACTORY_HPP__

// for work demonstration
#include <iostream>

#pragma region Products
class IProduct
{
public:
	virtual void SomeOperation(void) = 0;
};
class ConcreteProductA1 : public IProduct
{
public:
	virtual void SomeOperation(void) override final;
};
class ConcreteProductA2 : public IProduct
{
public:
	virtual void SomeOperation(void) override final;
};
class ConcreteProductB1 : public IProduct
{
public:
	virtual void SomeOperation(void) override final;
};
class ConcreteProductB2 : public IProduct
{
public:
	virtual void SomeOperation(void) override final;
};
#pragma endregion

#pragma region Factories
class IAbstractFactory
{
public:
	virtual IProduct* CreateProduct1(void) = 0;
	virtual IProduct* CreateProduct2(void) = 0;
};
class ConcreteFactory1 : public IAbstractFactory
{
public:
	virtual IProduct* CreateProduct1(void) override final;
	virtual IProduct* CreateProduct2(void) override final;
};
class ConcreteFactory2 : public IAbstractFactory
{
public:
	virtual IProduct* CreateProduct1(void) override final;
	virtual IProduct* CreateProduct2(void) override final;
};
#pragma endregion

#pragma region Client
class Client
{
public:
	Client(void) = default;
	Client(IAbstractFactory& factory);
	~Client(void) = default;

	void ChangeFactory(IAbstractFactory& factory);

	IProduct* CreateProduct1(void) noexcept;
	IProduct* CreateProduct2(void) noexcept;
private:
	IAbstractFactory* current_factory;
};
#pragma endregion

#pragma region TEST
class TEST
{
public:
	// use TEST::DO_TEST() for test
	static void DO_TEST(void);
};
#pragma endregion

#endif // !__ABSTRACT_FACTORY_HPP__