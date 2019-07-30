// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Command.hpp"

Command::ConcreteCommand1::ConcreteCommand1(Receiver1* receiver)
{
	this->receiver = receiver;
}
void Command::ConcreteCommand1::Execute(void)
{
	this->receiver->SomeOperation(/* params // if need */);
}

Command::ConcreteCommand2::ConcreteCommand2(Receiver2* receiver)
{
	this->receiver = receiver;
}
void Command::ConcreteCommand2::Execute(void)
{
	this->receiver->SomeOperation(/* params // if need */);
}

void Command::Receiver1::SomeOperation(void)
{
	std::cout << "Some operation from Receiver1\n";
}
void Command::Receiver2::SomeOperation(void)
{
	std::cout << "Some operation from Receiver2\n";
}

Command::Invoker::Invoker(ICommand* command)
{
	this->command = command;
}
void Command::Invoker::ChangeCommand(ICommand* command)
{
	this->command = command;
}
void Command::Invoker::ExecuteCommand(/* Params params // if need */)
{
	this->command->Execute(/* params // if need */);
}

#pragma region TEST
void Command::TEST::DO_TEST(void)
{
	Receiver1 r1; Receiver2 r2;
	ConcreteCommand1 cc1(&r1); ConcreteCommand2 cc2(&r2);

	Invoker invoker(&cc1);
	invoker.ExecuteCommand(/* params // if need */);
	invoker.ChangeCommand(&cc2);
	invoker.ExecuteCommand(/* params // if need */);
}
#pragma endregion