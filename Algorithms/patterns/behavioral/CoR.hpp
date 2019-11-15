#pragma once
#ifndef __COR_HPP__
#define __COR_HPP__

// for work demonstration
#include <iostream>
#include <string>

namespace CoR
{
	class IHandler
	{
	public:
		virtual ~IHandler(void) {};

		virtual void SetNext(IHandler* handler) = 0;
		virtual void Handle(std::string request) = 0;
	};

	class BaseHandler : public IHandler
	{
	public:
		virtual void SetNext(IHandler* handler) override final;
		virtual void Handle(std::string request) override;
	protected:
		IHandler* next;
	};

	class ConcreteHandler1 final : public BaseHandler
	{
	public:
		virtual void Handle(std::string request) override final;
	};
	class ConcreteHandler2 final : public BaseHandler
	{
	public:
		virtual void Handle(std::string request) override final;
	};
	class ConcreteHandler3 final : public BaseHandler
	{
	public:
		virtual void Handle(std::string request) override final;
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

#endif // !__COR_HPP__