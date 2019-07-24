// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Flyweight.hpp"

Flyweight::Flyweight::Flyweight(std::ptrdiff_t repeating)
{
	this->repeating = repeating;
}
std::ptrdiff_t Flyweight::Flyweight::Get(void) const
{
	return this->repeating;
}

Flyweight::Context::Context(Flyweight* repeating, std::ptrdiff_t unique)
{
	this->flyweight = repeating;
	this->unique = unique;
}

Flyweight::Flyweight& Flyweight::FlyweightFactory::GetFlyweight(Flyweight* repeating)
{
	std::vector<Flyweight*>::iterator pos = std::find_if(this->cache.begin(), this->cache.end(), [&repeating](Flyweight* flyweight) {
		return flyweight->Get() == repeating->Get(); // implement your copy constructor for the required classes
	});
	if (pos == this->cache.end())
	{
		this->cache.emplace_back(repeating);
		return *this->cache.back();
	}
	else
		return **pos;
}

#pragma region TEST
void Flyweight::TEST::DO_TEST(void)
{
	FlyweightFactory fw_factory;
	Flyweight fw_5(5);

	std::vector<Context> contexts;

	//for (std::ptrdiff_t t = 0; t < 10000000; ++t)
	//	contexts.emplace_back(*new Context(new Flyweight(5), std::ptrdiff_t()));

	for (std::ptrdiff_t t = 0; t < 10000000; ++t)
		contexts.emplace_back(*new Context(&fw_factory.GetFlyweight(&fw_5), std::ptrdiff_t()));
}
#pragma endregion