#pragma once
#ifndef __BUILDER_HPP__
#define __BUILDER_HPP__

// for work demonstration
#include <iostream>
#include <string>

namespace Builder
{
#pragma region IBuilder
	class IBuilder
	{
	public:
		virtual ~IBuilder(void) = 0 {};

		virtual void Reset(void) noexcept = 0;
		virtual void BuilderStepFirst(void) = 0;
		virtual void BuilderStepSecond(void) = 0;
		virtual void BuilderStepThird(void) = 0;
	};
#pragma endregion

#pragma region Concrete Builders

#pragma region ConcreteBuilder1
	class ConcreteBuilder1 : public IBuilder
	{
	public:
		ConcreteBuilder1(void) = default;
		~ConcreteBuilder1(void) = default;

		virtual void Reset(void) noexcept override final;
		virtual void BuilderStepFirst(void) override final;
		virtual void BuilderStepSecond(void) override final;
		virtual void BuilderStepThird(void) override final;

		std::string& GetResult(void) noexcept;
	private:
		std::string concrete_builder1_result;
	};
#pragma endregion

#pragma region ConcreteBuilder2
	class ConcreteBuilder2 : public IBuilder
	{
	public:
		ConcreteBuilder2(void) = default;
		~ConcreteBuilder2(void) = default;

		virtual void Reset(void) noexcept override final;
		virtual void BuilderStepFirst(void) override final;
		virtual void BuilderStepSecond(void) override final;
		virtual void BuilderStepThird(void) override final;

		ptrdiff_t& GetResult(void) noexcept;
	private:
		ptrdiff_t concrete_builder2_result;
	};
#pragma endregion

#pragma endregion

#pragma region Director
	class Director
	{
	public:
		Director(void) = default;
		Director(IBuilder* builder);
		~Director(void) = default;

		void ChangeBuilder(IBuilder& builder);
		void Make(void) const;
	private:
		IBuilder* current_builder;
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

#endif // !__BUILDER_HPP__