// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Mediator.hpp"

Mediator::ConcreteComponentA::ConcreteComponentA(IMediator* mediator) : mediator(mediator) {}
void Mediator::ConcreteComponentA::React(void)
{
	std::cout << "CCA: reacting...\n";
}
void Mediator::ConcreteComponentA::OperationA(void)
{
	std::cout << "Operation A\n";
	this->mediator->Notify(this);
}
Mediator::ConcreteComponentB::ConcreteComponentB(IMediator* mediator) : mediator(mediator) {}
void Mediator::ConcreteComponentB::React(void)
{
	std::cout << "CCB: reacting...\n";
}
void Mediator::ConcreteComponentB::OperationB(void)
{
	std::cout << "Operation B\n";
	this->mediator->Notify(this);
}
Mediator::ConcreteComponentC::ConcreteComponentC(IMediator* mediator) : mediator(mediator) {}
void Mediator::ConcreteComponentC::React(void)
{
	std::cout << "CCC: reacting...\n";
}
void Mediator::ConcreteComponentC::OperationC(void)
{
	std::cout << "Operation C\n";
	this->mediator->Notify(this);
}

void Mediator::ConcreteMediator::SetComponents(ConcreteComponentA* cca, ConcreteComponentB* ccb, ConcreteComponentC* ccc) 
{
	this->cca = cca;
	this->ccb = ccb;
	this->ccc = ccc;
}
void Mediator::ConcreteMediator::Notify(IComponent* component)
{
	if (typeid(*component) == typeid(ConcreteComponentA))
	{
		std::cout << "React on CCA...\n";
		this->ccb->React();
	}
	else if (typeid(*component) == typeid(ConcreteComponentB))
	{
		std::cout << "React on CCB...\n";
		this->ccc->React();
	}
	else if (typeid(*component) == typeid(ConcreteComponentC))
	{
		std::cout << "React on CCC...\n";
		this->cca->React();
	}
}

#pragma region TEST
void Mediator::TEST::DO_TEST(void)
{
	ConcreteMediator mediator;
	ConcreteComponentA cca(&mediator);
	ConcreteComponentB ccb(&mediator); 
	ConcreteComponentC ccc(&mediator);

	cca.OperationA();
	ccb.OperationB();
	ccc.OperationC();
};
#pragma endregion