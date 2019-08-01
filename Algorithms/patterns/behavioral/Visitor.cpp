// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Visitor.hpp"

void Visitor::ConcreteElementA::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
}
void Visitor::ConcreteElementA::FeatureA(void)
{
	std::cout << "ConcreteElementA: FeatureA\n";
}

void Visitor::ConcreteElementB::Accept(IVisitor* visitor)
{
	visitor->Visit(this);
}
void Visitor::ConcreteElementB::FeatureB(void)
{
	std::cout << "ConcreteElementB: FeatureB\n";
}

void Visitor::ConcreteVisitor::Visit(ConcreteElementA* elementA)
{
	elementA->FeatureA();
}
void Visitor::ConcreteVisitor::Visit(ConcreteElementB* elementB)
{
	elementB->FeatureB();
}

#pragma region TEST
void Visitor::TEST::DO_TEST(void)
{
	ConcreteElementA ceA;
	ConcreteElementB ceB;
	ConcreteVisitor cv;

	ceA.Accept(&cv);
	ceB.Accept(&cv);
};
#pragma endregion