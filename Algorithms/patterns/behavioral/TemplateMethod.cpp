// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "TemplateMethod.hpp"

void TemplateMethod::AbstractTemplate::Step1(void)
{
	std::cout << "Abstract template: step 1...\n";
}
void TemplateMethod::AbstractTemplate::Step2(void)
{
	std::cout << "Abstract template: step 2...\n";
}
void TemplateMethod::AbstractTemplate::TemplateMethod(void)
{
	this->Step1();
	this->Step2();
	this->Step3();
	this->Step4();
}

void TemplateMethod::ConcreteTemplate1::Step3(void)
{
	std::cout << "Concrete template 1: step 3...\n";
}
void TemplateMethod::ConcreteTemplate1::Step4(void)
{
	std::cout << "Concrete template 1: step 4...\n";
}

void TemplateMethod::ConcreteTemplate2::Step2(void)
{
	std::cout << "Concrete template 2: step 2...\n";
}
void TemplateMethod::ConcreteTemplate2::Step3(void)
{
	std::cout << "Concrete template 2: step 3...\n";
}
void TemplateMethod::ConcreteTemplate2::Step4(void)
{
	std::cout << "Concrete template 2: step 4...\n";
}

void TemplateMethod::TEST::DO_TEST(void)
{
	AbstractTemplate* tm1 = new ConcreteTemplate1();
	AbstractTemplate* tm2 = new ConcreteTemplate2();

	tm1->TemplateMethod();
	std::cout << "\n\n";
	tm2->TemplateMethod();

	delete tm1;
	delete tm2;
};