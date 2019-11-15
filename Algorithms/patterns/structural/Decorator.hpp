#pragma once
#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

// for work demonstration
#include <iostream>

namespace Decorator
{
#pragma region Components
	class IComponent
	{
	public:
		virtual ~IComponent(void) {};

		virtual void Execute(void) = 0;
	};

	class ConcreteComponent final : public IComponent
	{
	public:
		virtual void Execute(void) override final;
	};
#pragma endregion

#pragma region Decorators
	class BaseDecorator : public IComponent
	{
	public:
		BaseDecorator(void) = delete;
		BaseDecorator(IComponent* wrappee);
		~BaseDecorator(void) = default;

		virtual void Execute(void) override;
	private:
		IComponent* wrappee;
	};

	class ConcreteDecorator1 final : public BaseDecorator
	{
	public:
		ConcreteDecorator1(IComponent* wrappee);

		virtual void Execute(void) override final;
		void DoExtraThing(void);
	};

	class ConcreteDecorator2 final : public BaseDecorator
	{
	public:
		ConcreteDecorator2(IComponent* wrappee);

		virtual void Execute(void) override final;
		void DoExtraThing(void);
	};
#pragma endregion

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__DECORATOR_HPP__