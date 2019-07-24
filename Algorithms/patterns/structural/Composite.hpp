#pragma once
#ifndef __COMPOSITE_HPP__
#define __COMPOSITE_HPP__

// for work demonstration
#include <iostream>
#include <vector>
#include <algorithm>

namespace Composite
{
	class IComponent
	{
	public:
		virtual void Execute(void) = 0;
		virtual ~IComponent(void) = 0 {};
	};

	class Leaf : public IComponent
	{
	public:
		virtual void Execute(void) override final;
	};

	class Composite : public IComponent
	{
	public:
		void AddChild(IComponent* component);
		void RemoveChild(IComponent const* component);
		std::vector<IComponent*> GetChildren() const;

		virtual void Execute() override;
	private:
		std::vector<IComponent*> children;
	};

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__COMPOSITE_HPP__