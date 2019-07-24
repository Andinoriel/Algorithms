#pragma once
#ifndef __FACADE_HPP__
#define __FACADE_HPP__

// for work demonstration
#include <iostream>

namespace Facade
{
#pragma region SubSystems
	class SubSystem1
	{
	public:
		void DoMagicSpell(void);
		void DoMagicThing(void);
	};

	class SubSystem2
	{
	public:
		void DoMagicStuff(void);
		void DoMagicEnchantment(void);
	};

	class SubSystem3
	{
	public:
		void DoMagicExplosion(void);
		void DoMagicMess(void);
	};
#pragma endregion

	class Facade
	{
	public:
		void DoMagic(void);
	};

	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
};

#endif // !__FACADE_HPP__