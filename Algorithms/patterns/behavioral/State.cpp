// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "State.hpp"

State::Context::Context(IState* state)
{
	this->state = state;
	this->state->ChangeContext(this);
}
void State::Context::ChangeState(IState* state)
{
	this->state = state;
	this->state->ChangeContext(this);
}
void State::Context::SomeOperation(void)
{
	std::cout << "Some operation from context\n";
	this->state->SomeOperation();
}

#pragma region States
void State::ConcreteState1::SomeOperation(void)
{
	std::cout << "Concrete state 1: some operation\n";
	this->context->ChangeState(new ConcreteState2);
}
void State::ConcreteState1::ChangeContext(Context* context)
{
	this->context = context;
}

void State::ConcreteState2::SomeOperation(void)
{
	std::cout << "Concrete state 2: some operation\n";
	this->context->ChangeState(new ConcreteState1);
}
void State::ConcreteState2::ChangeContext(Context* context)
{
	this->context = context;
}
#pragma endregion

#pragma region TEST
void State::TEST::DO_TEST(void)
{
	IState* init_state = new ConcreteState1;
	Context context(init_state);
	context.SomeOperation();
	context.SomeOperation();
}
#pragma endregion