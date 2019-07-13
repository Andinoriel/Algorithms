// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Adapter.hpp"

void Adapter::Service::DoSomeThingsDifferently(void)
{
	std::cout << "\nService method working...";
}
void Adapter::Adapter::DoSomeThings(void) noexcept
{
	std::cout << "\nClient method working...";
	this->DoSomeThingsDifferently();
}
void Adapter::TEST::DO_TEST(void)
{
	Adapter adapter;
	adapter.DoSomeThings();
};