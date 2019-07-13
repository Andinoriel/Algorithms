#pragma once 
#ifndef __ADAPTER_HPP__
#define __ADAPTER_HPP__

// for work demonstration
#include <iostream>

namespace Adapter
{
	class IClientInterface
	{
	public:
		virtual void DoSomeThings(void) noexcept = 0;
	};

	class Service
	{
	public:
		void DoSomeThingsDifferently(void);
	};

	class Adapter : public IClientInterface, Service
	{
	public:
		virtual void DoSomeThings(void) noexcept override final;
	};

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__ADAPTER_HPP__