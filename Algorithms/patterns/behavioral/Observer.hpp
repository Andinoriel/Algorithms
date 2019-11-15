#pragma once
#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

// for work demonstration
#include <iostream>
#include <vector>
#include <algorithm>

namespace Observer
{
	class ISubscriber
	{
	public:
		virtual ~ISubscriber(void) {};
		virtual void Update(void) = 0;
	};

	class Publisher
	{
	public:
		void Subscribe(ISubscriber* subscriber);
		void Unsubscribe(ISubscriber* subscriber);
		void Notify(void) const;
		void SomeBusinessLogic(void);
	private:
		std::vector<ISubscriber*> subscribers;
		std::ptrdiff_t SomeMainState;
	};

	class ConcreteSubscriber final : public ISubscriber
	{
	public:
		virtual void Update(void) override final; // do smth when notify come
	};

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__OBSERVER_HPP__