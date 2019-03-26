#pragma once
#ifndef __QUEUE__
#define __QUEUE__

#include <iostream>
#include <algorithm>

namespace Andi
{
#pragma region Queue

#pragma region QueueDef
	template<typename Type>
	class Queue
	{
	private:
		LinkedList<Type>* __queue;
	public:
		Queue();
		~Queue();

		void enqueue(Type const& value);
		Type& const dequeue();
		Type& const peek() const;
		size_t count() const noexcept;
	};
#pragma endregion

#pragma region QueueImpl
	template<typename Type>
	Queue<Type>::Queue()
	{
		this->__queue = new LinkedList<Type>();
	}
	template<typename Type>
	Queue<Type>::~Queue()
	{
		delete this->__queue;
	}

	template<typename Type>
	void Queue<Type>::enqueue(Type const& value)
	{
		this->__queue->add(value);
	}
	template<typename Type>
	Type& const Queue<Type>::dequeue()
	{
		Type* result = new Type();
		*result = this->__queue->operator[](0);
		this->__queue->removeHead();
		return *result;
	}
	template<typename Type>
	Type& const Queue<Type>::peek() const 
	{
		return this->__queue->operator[](0);
	}
	template<typename Type>
	size_t Queue<Type>::count() const noexcept
	{
		return this->__queue->count();
	}
#pragma endregion 

#pragma endregion
};

#endif //__QUEUE__