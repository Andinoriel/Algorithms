#pragma once
#ifndef __FLYWEIGHT_HPP__
#define __FLYWEIGHT_HPP__

// for work demonstration
#include <iostream>
#include <vector>
#include <algorithm>

namespace Flyweight
{
	class Flyweight
	{
	public:
		Flyweight(void) = default;
		Flyweight(std::ptrdiff_t repeating);
		~Flyweight(void) = default;

		std::ptrdiff_t Get(void) const;
	private:
		std::ptrdiff_t repeating;
	};

	class Context
	{
	public:
		Context(void) = delete;
		Context(Flyweight* repeating, std::ptrdiff_t unique);
	private:
		Flyweight* flyweight;
		std::ptrdiff_t unique;
	};

	class FlyweightFactory
	{
	public:
		Flyweight& GetFlyweight(Flyweight* repeating);
	private:
		std::vector<Flyweight*> cache;
	};

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__FLYWEIGHT_HPP__