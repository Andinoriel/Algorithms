#pragma once
#ifndef __GARBAGE_TESTS_HPP__
#define __GARBAGE_TESTS_HPP__

#include <cstddef>
#include <utility>

#include "rttr/registration.h"

namespace AlmostReflectionTypeTraits
{
	// pod field count
	// cl /EHsc /std:c++[17|14]
	inline namespace
	{
		static constexpr std::size_t max_search_count = 100;
		class pod_reflection final
		{
		private:
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
			inline static void constexpr refl_detect_fields_count(std::size_t& out, std::index_sequence<AnotherParams...>) noexcept
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
};

namespace RTTR_Test
{
	class RTTR_Test final
	{
	public:
		inline RTTR_Test(void) : foo(0) {};
		inline explicit RTTR_Test(double foo) : foo(foo) {};

		double get_foo(void) const
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

};

#endif // !__GARBAGE_TESTS_HPP__