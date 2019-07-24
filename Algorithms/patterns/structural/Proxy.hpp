#pragma once
#ifndef __PROXY_HPP__
#define __PROXY_HPP__

// for work demonstration
#include <iostream>

namespace Proxy
{
	class IServiceInterface
	{
	public:
		virtual void SomeOperation(void) = 0;
		virtual ~IServiceInterface(void) = 0 {};
	};
	
	class Service : public IServiceInterface
	{
	public:
		virtual void SomeOperation(void) override final;
	};

	class Proxy : public IServiceInterface
	{
	public:
		Proxy(void);
		Proxy(Service* service);
		~Proxy(void);

		virtual void SomeOperation(void) override final;
		void SomeAnotherOperation(void);
	private:
		Service* service; bool is_alloc;
	};

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__PROXY_HPP__