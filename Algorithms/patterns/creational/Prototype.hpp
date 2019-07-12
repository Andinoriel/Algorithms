#pragma once
#ifndef __PROTOTYPE_HPP__
#define __PROTOTYPE_HPP__

// for work demonstration
#include <iostream>
#include <string>

namespace Prototype
{
#pragma region IPrototype
	class IPrototype
	{
	public:
		virtual IPrototype* Clone(void) = 0;
	};
#pragma endregion

#pragma region ConcretePrototype
	class ConcretePrototype : public IPrototype
	{
	public:
		ConcretePrototype(void);
		~ConcretePrototype(void) = default;

		virtual IPrototype* Clone(void) override final;
		void PrintData(void) const noexcept;
	private:
		std::string some_field_1;
		ptrdiff_t some_field_2;
		float some_field_3;
	};
#pragma endregion

#pragma region TEST
	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
#pragma endregion
};

#endif // !__PROTOTYPE_HPP__