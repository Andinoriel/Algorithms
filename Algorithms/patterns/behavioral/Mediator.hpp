#pragma once
#ifndef __MEDIATOR_HPP__
#define __MEDIATOR_HPP__

// for work demonstration
#include <iostream>

namespace Mediator
{
	class IComponent
	{
	public:
		virtual ~IComponent(void) {};
		
		virtual void React(void) = 0;
	};

	class IMediator
	{
	public:
		virtual ~IMediator(void) {};

		virtual void Notify(IComponent* component) = 0;
	};
#pragma region Components
	class ConcreteComponentA final : public IComponent
	{
	public:
		ConcreteComponentA(IMediator* mediator);

		virtual void React(void) override final;
		void OperationA(void);
	private:
		IMediator* mediator;
	};
	class ConcreteComponentB final : public IComponent
	{
	public:
		ConcreteComponentB(IMediator* mediator);

		virtual void React(void) override final;
		void OperationB(void);
	private:
		IMediator* mediator;
	};
	class ConcreteComponentC final : public IComponent
	{
	public:
		ConcreteComponentC(IMediator* mediator);

		virtual void React(void) override final;
		void OperationC(void);
	private:
		IMediator* mediator;
	};
#pragma endregion

	class ConcreteMediator final : public IMediator
	{
	public:
		void SetComponents(ConcreteComponentA* cca, ConcreteComponentB* ccb, ConcreteComponentC* ccc);

		virtual void Notify(IComponent* component) override final;
	private:
		ConcreteComponentA* cca;
		ConcreteComponentB* ccb;
		ConcreteComponentC* ccc;
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

#endif // !__MEDIATOR_HPP__