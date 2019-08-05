#pragma once
#ifndef __BRIDGE_HPP__
#define __BRIDGE_HPP__

// for work demonstration
#include <iostream>

namespace Bridge
{
#pragma region Implementations
	class IImplementation
	{
	public:
		virtual ~IImplementation(void) = 0 {};

		virtual void Method1(void) noexcept = 0;
		virtual void Method2(void) noexcept = 0;
		virtual void Method3(void) noexcept = 0;
	};
	class ConcreteImplementation1 final : public IImplementation
	{
	public:
		virtual void Method1(void) noexcept override final;
		virtual void Method2(void) noexcept override final;
		virtual void Method3(void) noexcept override final;
	};
	class ConcreteImplementation2 final : public IImplementation
	{
	public:
		virtual void Method1(void) noexcept override final;
		virtual void Method2(void) noexcept override final;
		virtual void Method3(void) noexcept override final;
	};
#pragma endregion
	class Abstraction
	{
	public:
		Abstraction(void) = default;
		~Abstraction(void) = default;

		void ChangeImplementation(IImplementation* implementation);
		void Feature1(void) noexcept;
		void Feature2(void) noexcept;
		void Feature3(void) noexcept;
	private:
		IImplementation* current_implementation;
	};

	class Client
	{
	private:
		Abstraction abtraction;
	public:
		void ChangeImplementation(IImplementation* implementation);
		void UseFeature1() noexcept;
		void UseFeature2() noexcept;
		void UseFeature3() noexcept;
	};

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__BRIDGE_HPP__