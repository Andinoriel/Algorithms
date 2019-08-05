#pragma once
#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

// for work demonstration
#include <iostream>

namespace Strategy
{
	class IStrategy
	{
	public:
		virtual ~IStrategy(void) = 0 {};

		virtual void Execute(void) = 0;
	};

	class ConcreteStrategy1 final : public IStrategy
	{
	public:
		virtual void Execute(void) override final;
	};

	class ConcreteStrategy2 final : public IStrategy
	{
	public:
		virtual void Execute(void) override final;
	};

	class Context
	{
	public:
		Context(void) = default;
		Context(IStrategy* strategy);
		~Context(void) = default;

		void SetStrategy(IStrategy* strategy);
		void DoSomething(void);
	private:
		IStrategy* strategy;
	};

#pragma region TEST
	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
#pragma endregion
};

#endif // !__STRATEGY_HPP__