#include "Facade.hpp"

void Facade::SubSystem1::DoMagicSpell(void)
{
	std::cout << "\nMagic spell!";
}
void Facade::SubSystem1::DoMagicThing(void)
{
	std::cout << "\nMagic thing!";
}

void Facade::SubSystem2::DoMagicStuff(void)
{
	std::cout << "\nMagic stuff!";
}
void Facade::SubSystem2::DoMagicEnchantment(void)
{
	std::cout << "\nMagic enchantment!";
}

void Facade::SubSystem3::DoMagicExplosion(void)
{
	std::cout << "\nMagic explosion!";
}
void Facade::SubSystem3::DoMagicMess(void)
{
	std::cout << "\nMagic mess!";
}

void Facade::Facade::DoMagic(void)
{
	SubSystem1 ss1;
	SubSystem2 ss2;
	SubSystem3 ss3;

	// doing necessary things in correct order

	ss1.DoMagicSpell();
	ss1.DoMagicThing();

	ss2.DoMagicEnchantment();
	ss2.DoMagicStuff();

	ss3.DoMagicExplosion();
	ss3.DoMagicMess();
}

#pragma region TEST
void Facade::TEST::DO_TEST(void)
{
	// you can do so
	SubSystem1 ss1;	SubSystem2 ss2;	SubSystem3 ss3;

	ss2.DoMagicEnchantment();
	ss3.DoMagicMess();
	ss1.DoMagicSpell();
	ss2.DoMagicStuff();
	ss1.DoMagicThing();
	ss3.DoMagicExplosion();
	
	// and getting incorrect result

	// so it is easier to do so
	Facade facade;
	std::cout << "\n\n";
	facade.DoMagic();
};
#pragma endregion