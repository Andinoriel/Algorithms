// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "CoR.hpp"

void CoR::BaseHandler::SetNext(IHandler* handler)
{
	this->next = handler;
}

void CoR::BaseHandler::Handle(std::string const& request)
{
	if (this->next != nullptr)
		this->next->Handle(request);
	else
		std::cout << "End of chain...\n";
}

void CoR::ConcreteHandler1::Handle(std::string const& request)
{
	if (request != "handle1")
		BaseHandler::Handle(request);
	else
		std::cout << "Handler 1 request: " << request << "; chain termination...\n";
}
void CoR::ConcreteHandler2::Handle(std::string const& request)
{
	if (request != "handle2")
		BaseHandler::Handle(request);
	else
		std::cout << "Handler 2 request: " << request << "; chain termination...\n";
}
void CoR::ConcreteHandler3::Handle(std::string const& request)
{
	if (request != "handle3")
		BaseHandler::Handle(request);
	else
		std::cout << "Handler 3 request: " << request << "; chain termination...\n";
}

#pragma region TEST
void CoR::TEST::DO_TEST(void)
{
	IHandler* h1 = new ConcreteHandler1();
	IHandler* h2 = new ConcreteHandler2();
	IHandler* h3 = new ConcreteHandler3();

	h1->SetNext(h2);
	h2->SetNext(h3);

	h1->Handle("handle1"); // as a result ConcreteHandler1::Handle() will be called
	h1->Handle("handle2"); // as a result ConcreteHandler2::Handle() will be called
	h1->Handle("handle3"); // as a result ConcreteHandler3::Handle() will be called
	h1->Handle("end"); // end of chain

	delete h1;
	delete h2;
	delete h3;
};
#pragma endregion