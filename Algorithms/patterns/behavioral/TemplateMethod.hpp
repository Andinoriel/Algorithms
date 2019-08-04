#pragma once
#ifndef __TEMPLATE_METHOD_HPP__
#define __TEMPLATE_METHOD_HPP__

// for work demonstration
#include <iostream>

namespace TemplateMethod
{
	class AbstractTemplate
	{
	public:
		virtual ~AbstractTemplate(void) = 0 {};

		virtual void TemplateMethod(void) final;
	private:
		virtual void Step1(void);
		virtual void Step2(void);
		virtual void Step3(void) = 0;
		virtual void Step4(void) = 0;
	};

	class ConcreteTemplate1 : public AbstractTemplate
	{
	private:
		virtual void Step3(void) override final;
		virtual void Step4(void) override final;
	};

	class ConcreteTemplate2 : public AbstractTemplate
	{
	private:
		virtual void Step2(void) override final;
		virtual void Step3(void) override final;
		virtual void Step4(void) override final;
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

#endif // !__TEMPLATE_METHOD_HPP__