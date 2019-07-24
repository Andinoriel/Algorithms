// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Proxy.hpp"

void Proxy::Service::SomeOperation(void)
{
	std::cout << "\nService, doing some operation...";
}

Proxy::Proxy::Proxy(void)
{
	this->service = new Service();
	this->is_alloc = true;
}
Proxy::Proxy::Proxy(Service* service)
{
	this->service = service;
	this->is_alloc = false;
}
Proxy::Proxy::~Proxy(void)
{
	if (this->is_alloc)
		delete this->service;
}

void Proxy::Proxy::SomeOperation(void)
{
	this->SomeAnotherOperation();
	this->service->SomeOperation();
}
void Proxy::Proxy::SomeAnotherOperation(void)
{
	std::cout << "\nDoing some another operation...";
}

#pragma region TEST
void Proxy::TEST::DO_TEST(void)
{
	IServiceInterface* service;
	
	service = new Service();
	service->SomeOperation();

	delete service;
	service = new Proxy();
	service->SomeOperation();
	delete service;
};
#pragma endregion