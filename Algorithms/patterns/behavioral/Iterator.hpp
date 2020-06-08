#pragma once
#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

// for work demonstration
#include <iostream>
#include <cstddef>
#include <vector>

namespace Iterator
{
	template <typename Type>
	class IIterator
	{
	public:
		virtual ~IIterator(void) {};

		virtual Type& GetNext(void) = 0;
		virtual bool HasMore(void) const = 0;
	};

	template <typename Type>
	class IIterableCollection
	{
	public:
		virtual ~IIterableCollection(void) {};

		virtual IIterator<Type>* CreateIterator(void) = 0;
	};

	template <typename Type> class ConcreteCollection;
	template <typename Type>
	class ConcreteIterator final : public IIterator<Type>
	{
	public:
		ConcreteIterator(ConcreteCollection<Type>* collection);

		virtual Type& GetNext(void) override final;
		virtual bool HasMore(void) const override final;
	private:
		ConcreteCollection<Type>* collection;
		std::size_t iteration_state;
	};

	template <typename Type>
	class ConcreteCollection final : public IIterableCollection<Type>
	{
	public:
		ConcreteCollection();

		void AddElement(Type const& element);
		void operator+=(Type const& element);

		virtual IIterator<Type>* CreateIterator(void) override final;

		friend class ConcreteIterator<Type>;
	private:
		Type* collection;
		std::size_t collection_size;
	};

#pragma region Templates Implementation

#pragma region ConcreteCollection implementation
	template<typename Type>
	inline ConcreteCollection<Type>::ConcreteCollection() : collection(nullptr), collection_size(0) {}
	template<typename Type>
	inline void ConcreteCollection<Type>::AddElement(Type const& element)
	{
		if (this->collection_size == 0)
		{
			this->collection = new Type[++this->collection_size];
			this->collection[this->collection_size - 1] = element;
		}
		else
		{
			Type* new_collection = new Type[++this->collection_size];
			for (std::size_t t = 0; t < this->collection_size - 1; ++t)
				new_collection[t] = this->collection[t];
			delete[] this->collection;
			this->collection = new_collection;
			this->collection[this->collection_size - 1] = element;
		}
	}
	template<typename Type>
	inline void ConcreteCollection<Type>::operator+=(Type const& element)
	{
		this->AddElement(element);
	}
	template<typename Type>
	inline IIterator<Type>* ConcreteCollection<Type>::CreateIterator(void)
	{
		return new ConcreteIterator(this);
	}
#pragma endregion

#pragma region ConcreteIterator implementation
	template<typename Type>
	inline Iterator::ConcreteIterator<Type>::ConcreteIterator(ConcreteCollection<Type>* collection) : collection(collection), iteration_state(0) {}
	template<typename Type>
	inline Type& ConcreteIterator<Type>::GetNext(void)
	{
		return this->collection->collection[this->iteration_state++];
	}
	template<typename Type>
	inline bool ConcreteIterator<Type>::HasMore(void) const
	{
		return this->iteration_state >= this->collection->collection_size || this->collection->collection == nullptr? false : true;
	}
#pragma endregion

#pragma endregion

#pragma region TEST
	class TEST
	{
	public:
		// use TEST::DO_TEST() for test
		inline static void DO_TEST(void)
		{
			ConcreteCollection<std::size_t> collection;
			auto iterator = collection.CreateIterator();

			for (std::size_t t = 0; t < 10; ++t)
				collection += t;

			while (iterator->HasMore())
			{
				std::cout << iterator->GetNext();
			}
		};
	};
#pragma endregion
};

#endif // !__ITERATOR_HPP__