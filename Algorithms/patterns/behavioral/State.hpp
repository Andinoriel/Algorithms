#pragma once
#ifndef __STATE_HPP__
#define __STATE_HPP__

// for work demonstration
#include <iostream>

namespace State
{
	class Context;
	class IState
	{
	public:
		virtual ~IState(void) = 0 {};

		virtual void SomeOperation(void) = 0;
		virtual void ChangeContext(Context* context) = 0;
	};

	class Context
	{
	public:
		Context(IState* state);

		void ChangeState(IState* state);
		void SomeOperation(void);
	private:
		IState* state;
	};

#pragma region States
	class ConcreteState1 final : public IState
	{
	public:
		virtual void SomeOperation(void) override final;
		virtual void ChangeContext(Context* context) override final;
	private:
		Context* context;
	};
	class ConcreteState2 final : public IState
	{
	public:
		virtual void SomeOperation(void) override final;
		virtual void ChangeContext(Context* context) override final;
	private:
		Context* context;
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
};

#endif // !__STATE_HPP__