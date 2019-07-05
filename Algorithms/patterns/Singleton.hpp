#pragma once
#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#pragma region PureSingleton
template <typename SingleInstance>
class PureSingleton
{
public:
	PureSingleton() = delete;
	PureSingleton(PureSingleton<SingleInstance> const&) = delete;
	PureSingleton(PureSingleton<SingleInstance> const&&) = delete;
	PureSingleton<SingleInstance> const& operator=(PureSingleton<SingleInstance> const&) = delete;
	PureSingleton<SingleInstance> const&& operator=(PureSingleton<SingleInstance> const&&) = delete;

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
	MeyersSingleton(MeyersSingleton<SingleInstance> const&&) = delete;
	MeyersSingleton<SingleInstance> const& operator=(MeyersSingleton<SingleInstance> const&) = delete;
	MeyersSingleton<SingleInstance> const&& operator=(MeyersSingleton<SingleInstance> const&&) = delete;

	[[nodiscard]] static SingleInstance& GetInstance(void)
	{
		static SingleInstance currentInstance;
		return currentInstance;
	};
};
#pragma endregion

#pragma region MeyersSingletonWithoutLazyInit
template <typename SingleInstance>
class MeyersSingletonWithoutLazyInit : public IDisposable
{
public:
	MeyersSingletonWithoutLazyInit() = delete;
	MeyersSingletonWithoutLazyInit(MeyersSingletonWithoutLazyInit<SingleInstance> const&) = delete;
	MeyersSingletonWithoutLazyInit(MeyersSingletonWithoutLazyInit<SingleInstance> const&&) = delete;
	MeyersSingletonWithoutLazyInit<SingleInstance> const& operator=(MeyersSingletonWithoutLazyInit<SingleInstance> const&) = delete;
	MeyersSingletonWithoutLazyInit<SingleInstance> const&& operator=(MeyersSingletonWithoutLazyInit<SingleInstance> const&&) = delete;

	[[nodiscard]] static SingleInstance& GetInstance(void)
	{
		return MeyersSingletonWithoutLazyInit<SingleInstance>::currentInstance;
	};
private:
	inline static SingleInstance currentInstance;
};
#pragma endregion

#endif // !__SINGLETON_HPP__