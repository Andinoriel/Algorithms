#include "Builder.hpp"

#pragma region ConcreteBuilder1
void ConcreteBuilder1::Reset(void) noexcept
{
	this->concrete_builder1_result = std::string();
}
void ConcreteBuilder1::BuilderStepFirst(void)
{
	this->concrete_builder1_result.append("Step1\t"); // do unique first step
}
void ConcreteBuilder1::BuilderStepSecond(void)
{
	this->concrete_builder1_result.append("Step2\t"); // do unique second step
}
void ConcreteBuilder1::BuilderStepThird(void)
{
	this->concrete_builder1_result.append("Step3\t\n"); // do unique third step
}
std::string& ConcreteBuilder1::GetResult(void) noexcept
{
	return this->concrete_builder1_result;
}
#pragma endregion

#pragma region ConcreteBuilder2
void ConcreteBuilder2::Reset(void) noexcept
{
	this->concrete_builder2_result = NULL;
}
void ConcreteBuilder2::BuilderStepFirst(void)
{
	this->concrete_builder2_result += 100; // do unique first step
}
void ConcreteBuilder2::BuilderStepSecond(void)
{
	this->concrete_builder2_result += 1000; // do unique second step
}
void ConcreteBuilder2::BuilderStepThird(void)
{
	this->concrete_builder2_result += 10000; // do unique first step
}
ptrdiff_t& ConcreteBuilder2::GetResult(void) noexcept
{
	return this->concrete_builder2_result;
}
#pragma endregion

#pragma region Director
Director::Director(IBuilder* builder)
{
	this->current_builder = builder;
}
void Director::ChangeBuilder(IBuilder& builder)
{
	this->current_builder = &builder;
}
void Director::Make(void) const
{
	this->current_builder->Reset();
	this->current_builder->BuilderStepFirst();
	this->current_builder->BuilderStepSecond();
	this->current_builder->BuilderStepThird();
}
#pragma endregion

#pragma region TEST
void TEST::DO_TEST(void)
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