// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Builder.hpp"

#pragma region ConcreteBuilder1
void Builder::ConcreteBuilder1::Reset(void) noexcept
{
	this->concrete_builder1_result.clear(); // V815
}
void Builder::ConcreteBuilder1::BuilderStepFirst(void)
{
	this->concrete_builder1_result.append("Step1\t"); // do unique first step
}
void Builder::ConcreteBuilder1::BuilderStepSecond(void)
{
	this->concrete_builder1_result.append("Step2\t"); // do unique second step
}
void Builder::ConcreteBuilder1::BuilderStepThird(void)
{
	this->concrete_builder1_result.append("Step3\t\n"); // do unique third step
}
std::string& Builder::ConcreteBuilder1::GetResult(void) noexcept
{
	return this->concrete_builder1_result;
}
#pragma endregion

#pragma region ConcreteBuilder2
void Builder::ConcreteBuilder2::Reset(void) noexcept
{
	this->concrete_builder2_result = ptrdiff_t(0);
}
void Builder::ConcreteBuilder2::BuilderStepFirst(void)
{
	this->concrete_builder2_result += 100; // do unique first step
}
void Builder::ConcreteBuilder2::BuilderStepSecond(void)
{
	this->concrete_builder2_result += 1000; // do unique second step
}
void Builder::ConcreteBuilder2::BuilderStepThird(void)
{
	this->concrete_builder2_result += 10000; // do unique first step
}
ptrdiff_t& Builder::ConcreteBuilder2::GetResult(void) noexcept
{
	return this->concrete_builder2_result;
}
#pragma endregion

#pragma region Director
Builder::Director::Director(IBuilder* builder)
{
	this->current_builder = builder;
}
void Builder::Director::ChangeBuilder(IBuilder& builder)
{
	this->current_builder = &builder;
}
void Builder::Director::Make(void) const
{
	this->current_builder->Reset();
	this->current_builder->BuilderStepFirst();
	this->current_builder->BuilderStepSecond();
	this->current_builder->BuilderStepThird();
}
#pragma endregion

#pragma region TEST
void Builder::TEST::DO_TEST(void)
{
	Director director;	
	ConcreteBuilder1 builder1; ConcreteBuilder2 builder2;

	director.ChangeBuilder(builder1);
	director.Make();
	std::cout << "\nConcrete Builder 1 - result: " << builder1.GetResult();

	director.ChangeBuilder(builder2);
	director.Make();
	std::cout << "\nConcrete Builder 2 - result: " << builder2.GetResult();
}
#pragma endregion