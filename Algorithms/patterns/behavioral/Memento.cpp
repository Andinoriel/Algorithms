// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Memento.hpp"

Memento::Originator::Memento* Memento::Originator::Save(void) const
{
	return new Memento(this->state);
}
void Memento::Originator::Restore(Memento* snapshot)
{
	this->state = snapshot->GetState();
}
void Memento::Originator::UpdateCurrentState(std::string state)
{
	this->state = state;
}
std::string Memento::Originator::GetCurrentState(void) const
{
	return this->state;
}

Memento::Originator::Memento::Memento(std::string state)
{
	this->state = state;
}
std::string Memento::Originator::Memento::GetState(void) const
{
	return this->state;
}

Memento::Caretaker::Caretaker(Originator* originator)
{
	this->originator = originator;
}
void Memento::Caretaker::DoSomething(void)
{
	this->history.emplace_back(this->originator->Save());

	std::cout << "Doing some things...\n";

	// changing originator state...
	static int times = 1;
	this->originator->UpdateCurrentState("state " + std::to_string(times++));
}
void Memento::Caretaker::Undo(void)
{
	std::cout << "Undo last operation...\n";
	this->originator->Restore(this->history.back());
	this->history.pop_back();
}

void Memento::TEST::DO_TEST(void)
{
	Originator originator;
	Caretaker ctk(&originator);

	ctk.DoSomething(); // state 1
	ctk.DoSomething(); // state 2
	ctk.DoSomething(); // state 3

	std::cout << "Current state: " << originator.GetCurrentState() << "\n"; // state 3

	ctk.Undo(); // undo state 3; 
	std::cout << "Current state: " << originator.GetCurrentState() << "\n"; // state 2
};