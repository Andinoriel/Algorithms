#pragma once
#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

// for work demonstration
#include <iostream>

namespace Command
{
	class ICommand
	{
	public:
		virtual ~ICommand(void) {};

		virtual void Execute(/* Params params // if need */) = 0;
	};

	class Receiver1
	{
	public:
		void SomeOperation(void);
	};
	class Receiver2
	{
	public:
		void SomeOperation(void);
	};

	class ConcreteCommand1 final : public ICommand
	{
	public:
		ConcreteCommand1(Receiver1* receiver /* ,Params params // if need */);
		virtual void Execute(void) override final;
	private:
		Receiver1* receiver;
	};

	class ConcreteCommand2 final : public ICommand
	{
	public:
		ConcreteCommand2(Receiver2* receiver /* ,Params params // if need */);
		virtual void Execute(void) override final;
	private:
		Receiver2* receiver;
	};

	class Invoker
	{
	public:
		Invoker(ICommand* command);

		void ChangeCommand(ICommand* command);
		void ExecuteCommand(/*Params params // if need */);
	private:
		ICommand* command;
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

#endif // !__COMMAND_HPP__