#pragma once
#ifndef __FACTORY_METHOD_HPP__
#define __FACTORY_METHOD_HPP__

// for work demonstration
#include <iostream>
#include <string>

#pragma region IProduct
class IProduct
{
public:
	virtual void DoStuff(void) = 0;
};
#pragma endregion

#pragma region Products
class DefaultProduct : public IProduct
{
public:
	virtual void DoStuff(void) override final;
};
class ConcreteProduct1 : public IProduct
{
public:
	virtual void DoStuff(void) override final;
};
class ConcreteProduct2 : public IProduct
{
public:
	virtual void DoStuff(void) override final;
};
#pragma endregion

#pragma region Creators
class Creator
{
public:
	Creator(void) = default;
	~Creator(void) = default;

	//void SomeOperation(void);
	virtual IProduct* CreateProduct(void);
};

class ConcreteCreator1 : public Creator
{
public:
	virtual ConcreteProduct1* CreateProduct(void) override final;
};
class ConcreteCreator2 : public Creator
{
public:
	virtual ConcreteProduct2* CreateProduct(void) override final;
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

#endif // !__FACTORY_METHOD_HPP__