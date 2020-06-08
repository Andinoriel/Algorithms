#pragma once
#ifndef __PCH_HPP__
#define __PCH_HPP__

#include <exception>
#include <iostream>
#include <vector>
#include <any>
#include <utility>
#include <memory>
#include <string>

#include <cstddef>
#include <cstdlib>

#pragma region
// auto some_pointer = ...;
// if (some_pointer)
// some_pointer->call_some_method();
//
// auto some_pointer = ...;
// prefix_safe_call_void(some_pointer, call_some_method());
//
// auto somePointer = ...;
// auto x = prefix_safe_call(0, some_pointer, call_some_method());

#define prefix_safe_call_base_expression(default_value, object_pointer, method_with_arguments)\
	((pointer) ? ((pointer)->method_with_arguments) : (default_value))

#define prefix_safe_call(default_value, object_pointer, method_with_arguments)							\
	[&](decltype((object_pointer))&& pointer)															\
		-> decltype(prefix_safe_call_base_expression(default_value, pointer, method_with_arguments))	\
	{																									\
		return prefix_safe_call_base_expression(default_value, pointer, method_with_arguments);			\
	}																									\
	(object_pointer)

#define prefix_safe_call_void(object_pointer, method_with_arguments)	\
	[&](decltype((object_pointer))&& pointer)							\
	{																	\
		if (pointer)													\
			(pointer->methodWithArguments);								\
	}																	\
	(object_pointer)

#pragma endregion

#define var_dump(variable) std::cout << #variable << " = [" << (variable) << "]" << std::endl;
#define prefix_unused(variable) [[maybe_unused]] variable

[[noreturn]] inline static volatile void __panic(std::string const& message) noexcept
{
	std::cerr << message << std::endl;
	std::exit(EXIT_FAILURE);
};

#pragma region garbage
#ifdef __GARBAGE_EXTERN__
	#define EXTERN_TEST__ extern int TEST(void);
	namespace BubbleCoctailEvenOddCombo { EXTERN_TEST__ };
	namespace DFSBFS					{ EXTERN_TEST__ };
	namespace DijkstraFloydWarshall		{ EXTERN_TEST__ };
	namespace InsertSelectionMerge		{ EXTERN_TEST__ };
	namespace KraskalPrim				{ EXTERN_TEST__ };
	namespace Converter					{ EXTERN_TEST__ };
	namespace ShellQuick				{ EXTERN_TEST__ };

	#pragma region garbage_run_tests
	#define __GARBAGE_RUN(name) name::TEST()
		namespace garbage_test
		{
			inline static void run(void)
			{
				__GARBAGE_RUN(BubbleCoctailEvenOddCombo);
				__GARBAGE_RUN(DFSBFS);
				__GARBAGE_RUN(DijkstraFloydWarshall);
				__GARBAGE_RUN(InsertSelectionMerge);
				__GARBAGE_RUN(KraskalPrim);
				__GARBAGE_RUN(Converter);
				__GARBAGE_RUN(ShellQuick);
			};
		};
	#pragma endregion
#endif // __GARBAGE_EXTERN__
#pragma endregion

#pragma region patterns
#ifdef __PATTERNS_INCLUDES__

#include "..//Algorithms/patterns/creational/AbstractFactory.hpp"
#include "..//Algorithms/patterns/creational/Builder.hpp"
#include "..//Algorithms/patterns/creational/FactoryMethod.hpp"
#include "..//Algorithms/patterns/creational/Prototype.hpp"
#include "..//Algorithms/patterns/creational/Singleton.hpp"

#include "..//Algorithms/patterns/structural/Adapter.hpp"
#include "..//Algorithms/patterns/structural/Bridge.hpp"
#include "..//Algorithms/patterns/structural/Composite.hpp"
#include "..//Algorithms/patterns/structural/Decorator.hpp"
#include "..//Algorithms/patterns/structural/Facade.hpp"
#include "..//Algorithms/patterns/structural/Flyweight.hpp"
#include "..//Algorithms/patterns/structural/Proxy.hpp"

#include "..//Algorithms/patterns/behavioral/Command.hpp"
#include "..//Algorithms/patterns/behavioral/CoR.hpp"
#include "..//Algorithms/patterns/behavioral/Iterator.hpp"
#include "..//Algorithms/patterns/behavioral/Mediator.hpp"
#include "..//Algorithms/patterns/behavioral/Memento.hpp"
#include "..//Algorithms/patterns/behavioral/Observer.hpp"
#include "..//Algorithms/patterns/behavioral/State.hpp"
#include "..//Algorithms/patterns/behavioral/Strategy.hpp"
#include "..//Algorithms/patterns/behavioral/TemplateMethod.hpp"
#include "..//Algorithms/patterns/behavioral/Visitor.hpp"

#pragma region patterns_run_tests
#define __PATTERNS_RUN(pattern) pattern::TEST::DO_TEST()
	namespace patterns_test
	{
		inline static void run(void) noexcept
		{
			__PATTERNS_RUN(AbstractFactory);
			__PATTERNS_RUN(Builder);
			__PATTERNS_RUN(FactoryMethod);
			__PATTERNS_RUN(Prototype);
			__PATTERNS_RUN(Singleton);

			__PATTERNS_RUN(Adapter);
			__PATTERNS_RUN(Bridge);
			__PATTERNS_RUN(Composite);
			__PATTERNS_RUN(Decorator);
			__PATTERNS_RUN(Facade);
			__PATTERNS_RUN(Flyweight);
			__PATTERNS_RUN(Proxy);

			__PATTERNS_RUN(Command);
			__PATTERNS_RUN(CoR);
			__PATTERNS_RUN(Iterator);
			__PATTERNS_RUN(Mediator);
			__PATTERNS_RUN(Memento);
			__PATTERNS_RUN(Observer);
			__PATTERNS_RUN(State);
			__PATTERNS_RUN(Strategy);
			__PATTERNS_RUN(TemplateMethod);
			__PATTERNS_RUN(Visitor);
		};
	};
#pragma endregion

#endif // __PATTERNS_TEST__
#pragma endregion

#endif // !__PCH_HPP__