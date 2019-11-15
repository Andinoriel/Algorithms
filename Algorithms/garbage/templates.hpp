#pragma once
#ifndef __GARBAGE_TESTS_HPP__
#define __GARBAGE_TESTS_HPP__

#include <cstddef>
#include <iostream>
#include <string_view>
#include <utility>

#pragma region __RTTR_TEST_OFF__
#ifndef __RTTR_TEST_OFF__

#ifndef __BUILD_NOT_WITH_VS__
	#if defined(_WIN64)
		#ifdef _DEBUG  
			#pragma comment(lib, "../3rd_party/rttrorg/rttr/lib/rttr_core_d.lib")
		#else
			#pragma comment(lib, "../3rd_party/rttrorg/rttr/lib/rttr_core.lib")
		#endif 
	// defined(_WIN64)
	#elif defined(__linux__)
		// ...
		
	#endif // defined(__linux__)
#endif // !__MSVC_VS_LIB__

#include "rttr/registration.h"

namespace RTTR_Test
{
	class RTTR_Test final
	{
	public:
		inline RTTR_Test(void) : foo(0) {};
		inline explicit RTTR_Test(double foo) : foo(foo) {};

		inline double get_foo(void) const
		{
			return this->foo;
		};
	private:
		double foo;
	};
	RTTR_REGISTRATION
	{
		rttr::registration::class_<RTTR_Test>("RTTR_Test")
			.constructor<>()
			.constructor<double>()
			.method("get_foo", &RTTR_Test::get_foo);
	};

	inline static void DO_TEST(void)
	{
		rttr::type type = rttr::type::get<RTTR_Test>();
		for (auto& elem : type.get_methods())
			std::cout << elem.get_signature() << " \n";
	};
};
#endif // __RTTR_TEST_OFF__
#pragma endregion // __RTTR_TEST_OFF__

namespace AlmostReflectionTypeTraits
{
	// pod field count
	// cl /EHsc /std:c++[17|14]
	inline namespace
	{
		inline namespace pod_count
		{
			class pod_reflection final
			{
			private:
				static constexpr std::size_t max_search_count = 100;
				struct pod_any_cast_constructible
				{
					template <typename AnyType>
					constexpr operator AnyType(void) const noexcept { return AnyType(); };
					explicit pod_any_cast_constructible(void) = default;
				};
				template <std::size_t AnotherParam>
				struct pod_any_cast
				{
					template <typename AnyType>
					constexpr operator AnyType& (void) const noexcept; // not implemented
				};
				// more specialized template
				template <typename pod_struct, std::size_t Param, std::size_t... AnotherParams>
				inline static auto constexpr refl_detect_fields_count(std::size_t& out, std::index_sequence<Param, AnotherParams...> const) noexcept
					-> decltype(pod_struct{ pod_any_cast<Param>(), pod_any_cast<AnotherParams>{}... })
				{
					out = sizeof...(AnotherParams) + static_cast<std::size_t>(1);
					return pod_any_cast_constructible();
				};
				// less specialized template
				template <typename pod_struct, std::size_t... AnotherParams>
				inline static auto constexpr refl_detect_fields_count(std::size_t& out, std::index_sequence<AnotherParams...>) noexcept -> void
				{
					refl_detect_fields_count<pod_struct>(out, std::make_index_sequence<sizeof...(AnotherParams) - 1>());
				};
			public:
				template <typename Type>
				inline static constexpr auto detect_fields_count(std::size_t& out) noexcept -> void
				{
					static_assert(std::is_pod<Type>::value, "Not a pod-value");
					pod_reflection::refl_detect_fields_count<Type>(out, std::make_index_sequence<std::size_t(max_search_count)>());
				};
			};
			struct POD final
			{
				int i;		// 1 field
				double d;	// 2 field
				char c;		// 3 field
			};
		};

		inline namespace
		{
			template <typename Type>
			auto call_foo_or_bar(Type const& obj) -> decltype(obj.foo())
			{
				return obj.foo();
			};
			template <typename Type>
			auto call_foo_or_bar(Type const& obj) -> decltype(obj.bar())
			{
				return obj.bar();
			};
		};
	};
};

namespace TemplateMagic
{
#pragma region factorial
	template <std::size_t n>
	struct factorial
	{
		static constexpr std::size_t result = n * factorial<n - 1>::result;
	};
	template<>
	struct factorial<std::size_t(0)>
	{
		static constexpr std::size_t result = std::size_t(1);
	};
#pragma endregion

#pragma region deeper

	// cl /EHsc /std:c++17
	class deep_switch
	{
	private:
		// more specialized template
		template <std::size_t n, typename... packet, typename function>
		static constexpr inline typename std::enable_if<(sizeof...(packet) == n), void>::type call(function const& func) noexcept
		{
			func();
		};
		// less specialized template
		template <std::size_t n, typename...>
		static constexpr void call(...) noexcept {};
	public:
		template <typename... packet>
		static constexpr inline typename std::enable_if<sizeof...(packet) < 3, void>::type calc(packet... p) noexcept
		{
			deep_switch::call<0, packet...>([&p...]() {std::cout << "0\n"; });
			deep_switch::call<1, packet...>([&p...]() {std::cout << "1\n"; });
			deep_switch::call<2, packet...>([&p...]() {std::cout << "2\n"; });
		};
		template <typename...>
		static constexpr inline void calc(...) noexcept {};
	};


#pragma endregion
};

#endif // !__GARBAGE_TESTS_HPP__