#pragma once
#ifndef __MEMENTO_HPP__
#define __MEMENTO_HPP__

// for work demonstration
#include <iostream>
#include <string>
#include <vector>

namespace Memento
{
	class Originator
	{
	public:
		class Memento
		{
		public:
			Memento(std::string state);

			std::string GetState(void) const;
		private:
			std::string state;
		};

		Memento* Save(void) const;
		void Restore(Memento* snapshot);

		void UpdateCurrentState(std::string state);
		std::string GetCurrentState(void) const;

	private:
		std::string state;
	};

	class Caretaker
	{
	public:
		Caretaker(Originator* originator);

		void DoSomething(void);
		void Undo(void);
	private:
		Originator* originator;
		std::vector<Originator::Memento*> history;
	};

#pragma region TEST
	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		static void DO_TEST(void);
	};
#pragma endregion
};

#endif // !__MEMENTO_HPP__