// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Decorator.hpp"

#pragma region Components
void Decorator::ConcreteComponent::Execute(void)
{
	std::cout << "\nConcrete component 1: executing...";
}
#pragma endregion

#pragma region Decorators
Decorator::BaseDecorator::BaseDecorator(IComponent* wrappee)
{
	this->wrappee = wrappee;
}
void Decorator::BaseDecorator::Execute(void)
{
	this->wrappee->Execute();
}

Decorator::ConcreteDecorator1::ConcreteDecorator1(IComponent* wrappee) : BaseDecorator(wrappee) {}
void Decorator::ConcreteDecorator1::Execute(void)
{
	BaseDecorator::Execute();
	this->DoExtraThing();
}
void Decorator::ConcreteDecorator1::DoExtraThing(void)
{
	std::cout << "\nConcrete decorator 1: doing extra thing...";
}

Decorator::ConcreteDecorator2::ConcreteDecorator2(IComponent* wrappee) : BaseDecorator(wrappee) {}
void Decorator::ConcreteDecorator2::Execute(void)
{
	BaseDecorator::Execute();
	this->DoExtraThing();
}
void Decorator::ConcreteDecorator2::DoExtraThing(void)
{
	std::cout << "\nConcrete decorator 2: doing extra thing...";
}
#pragma endregion

#pragma region TEST
void Decorator::TEST::DO_TEST(void)
{
	IComponent* cc = new ConcreteComponent;
	cc->Execute();

	IComponent* decorated = new ConcreteDecorator1(cc);
	decorated->Execute();

	delete decorated;
	decorated = new ConcreteDecorator2(cc);
	decorated->Execute();

	delete decorated;
	delete cc;
};
#pragma endregion