#pragma once
#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

// for work demonstration
#include <iostream>

namespace Visitor
{
#pragma region Elements
	class IVisitor;
	class IElement
	{
	public:
		virtual ~IElement(void) = 0 {};

		virtual void Accept(IVisitor* visitor) = 0;
	};

	class ConcreteElementA final : public IElement
	{
	public:
		virtual void Accept(IVisitor* visitor) override final;

		void FeatureA(void);
	};
	class ConcreteElementB final : public IElement
	{
	public:
		virtual void Accept(IVisitor* visitor) override final;

		void FeatureB(void);
	};
#pragma endregion

	class IVisitor
	{
	public:
		virtual ~IVisitor(void) = 0 {};

		virtual void Visit(ConcreteElementA* elementA) = 0;
		virtual void Visit(ConcreteElementB* elementB) = 0;
	};

	class ConcreteVisitor final : public IVisitor
	{
	public:
		virtual void Visit(ConcreteElementA* elementA) override final;
		virtual void Visit(ConcreteElementB* elementB) override final;
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

#endif // !__VISITOR_HPP__