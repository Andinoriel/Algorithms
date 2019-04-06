#pragma once
#ifndef __DEQUE__
#define __DEQUE__

#include <iostream>
#include <algorithm>

namespace Andi
{
#pragma region Deque

#pragma region DequeDef
	template<typename Type>
	class Deque
	{
	private:
		DoublyLinkedList<Type>* __deque;
	public:
		Deque();
		~Deque();

		void enqueueFirst(Type const& value);
		void enqueueLast(Type const& value);
		Type& const dequeueFirst();
		Type& const dequeueLast();
		Type& const peekFirst();
		Type& const peekLast();

		size_t count() const noexcept;
	};
#pragma endregion

#pragma region DequeImpl
	template<typename Type>
	Deque<Type>::Deque()
	{
		this->__deque = new DoublyLinkedList<Type>();
	}
	template<typename Type>
	Deque<Type>::~Deque()
	{
		delete this->__deque;
	}
	
	template<typename Type>
	void Deque<Type>::enqueueFirst(Type const& value)
	{
		this->__deque->addFirst(value);
	}
	template<typename Type>
	void Deque<Type>::enqueueLast(Type const& value)
	{
		this->__deque->addLast(value);
	}
	template<typename Type>
	Type& const Deque<Type>::dequeueFirst()
	{
		Type* result = new Type();
		*result = this->__deque->operator[](0);
		this->__deque->removeFirst();
		return *result;
	}
	template<typename Type>
	Type& const Deque<Type>::dequeueLast()
	{
		Type* result = new Type();
		*result = this->__deque->operator[](this->__deque->count() - 1);
		this->__deque->removeLast();
		return *result;
	}
	template<typename Type>
	Type& const Deque<Type>::peekFirst()
	{
		return this->__deque->operator[](0);
	}
	template<typename Type>
	Type& const Deque<Type>::peekLast()
	{
		return this->__deque->operator[](this->__deque->count() - 1);
	}
	template<typename Type>
	size_t Deque<Type>::count() const noexcept
	{
		return this->__deque->count();
	}
#pragma endregion

#pragma endregion
};

#endif //__DEQUE__