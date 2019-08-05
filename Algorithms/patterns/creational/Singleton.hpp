#pragma once
#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

// for work demonstration
#include <iostream>

namespace Singleton
{
#pragma region PureSingleton
	template <typename SingleInstance>
	class PureSingleton
	{
	public:
		PureSingleton() = delete;
		PureSingleton(PureSingleton<SingleInstance> const&) = delete;
		PureSingleton(PureSingleton<SingleInstance>&&) = delete;
		PureSingleton<SingleInstance> const& operator=(PureSingleton<SingleInstance> const&) = delete;
		PureSingleton<SingleInstance> const&& operator=(PureSingleton<SingleInstance>&&) = delete;

		[[nodiscard]] static SingleInstance* const GetInstance(void)
		{
			if (PureSingleton<SingleInstance>::currentInstance == nullptr)
				// sync threads if multi-threaded 
				PureSingleton<SingleInstance>::currentInstance = new SingleInstance();
			return PureSingleton<SingleInstance>::currentInstance;
		};
		static void Dispose(void) noexcept
		{
			delete PureSingleton<SingleInstance>::currentInstance;
		};
	private:
		static SingleInstance* currentInstance;
	};
	template <typename SingleInstance>
	SingleInstance* PureSingleton<SingleInstance>::currentInstance = nullptr;
#pragma endregion

#pragma region MeyersSingleton
	template <typename SingleInstance>
	class MeyersSingleton
	{
	public:
		MeyersSingleton() = delete;
		MeyersSingleton(MeyersSingleton<SingleInstance> const&) = delete;
		MeyersSingleton(MeyersSingleton<SingleInstance>&&) = delete;
		MeyersSingleton<SingleInstance> const& operator=(MeyersSingleton<SingleInstance> const&) = delete;
		MeyersSingleton<SingleInstance> const&& operator=(MeyersSingleton<SingleInstance>&&) = delete;

		[[nodiscard]] static SingleInstance& GetInstance(void)
		{
			static SingleInstance currentInstance;
			return currentInstance;
		};
	};
#pragma endregion

#pragma region MeyersSingletonWithoutLazyInit
	template <typename SingleInstance>
	class MeyersSingletonWithoutLazyInit
	{
	public:
		MeyersSingletonWithoutLazyInit() = delete;
		MeyersSingletonWithoutLazyInit(MeyersSingletonWithoutLazyInit<SingleInstance> const&) = delete;
		MeyersSingletonWithoutLazyInit(MeyersSingletonWithoutLazyInit<SingleInstance>&&) = delete;
		MeyersSingletonWithoutLazyInit<SingleInstance> const& operator=(MeyersSingletonWithoutLazyInit<SingleInstance> const&) = delete;
		MeyersSingletonWithoutLazyInit<SingleInstance> const&& operator=(MeyersSingletonWithoutLazyInit<SingleInstance>&&) = delete;

		[[nodiscard]] static SingleInstance& GetInstance(void)
		{
			return MeyersSingletonWithoutLazyInit<SingleInstance>::currentInstance;
		};
	private:
		inline static SingleInstance currentInstance;
	};
#pragma endregion

#pragma region TEST
	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		inline static void DO_TEST(void)
		{
#pragma region PureSingleton Test
			auto f1 = PureSingleton<size_t>::GetInstance();
			std::cout << "\nf addr: " << &f1;
			auto s1 = PureSingleton<size_t>::GetInstance();
			std::cout << "\ns addr: " << &s1;

			std::cout << std::boolalpha << "\n" << (&f1 == &s1 ? false : true);
#pragma endregion

#pragma region MeyersSingleton Test
			auto f2 = MeyersSingleton<float>::GetInstance();
			std::cout << "\nf addr: " << &f2;
			auto s2 = MeyersSingleton<float>::GetInstance();
			std::cout << "\ns addr: " << &s2;

			std::cout << std::boolalpha << "\n" << (&f2 == &s2 ? false : true);
#pragma endregion

#pragma region MeyersSingletonWithoutLazyInit Test
			auto f3 = MeyersSingleton<float>::GetInstance();
			std::cout << "\nf addr: " << &f3;
			auto s3 = MeyersSingleton<float>::GetInstance();
			std::cout << "\ns addr: " << &s3;

			std::cout << std::boolalpha << "\n" << (&f3 == &s3 ? false : true);
#pragma endregion
		};
	};
#pragma endregion
};

#endif // !__SINGLETON_HPP__