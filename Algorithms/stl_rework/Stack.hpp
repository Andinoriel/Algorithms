#pragma once
#ifndef __STACK__
#define __STACK__

#include <iostream>
#include <algorithm>

namespace Andi
{
#pragma region Stack

#pragma region StackDef
	template<typename Type>
	class Stack
	{
	private:
		LinkedList<Type>* __stack;
	public:
		Stack();
		~Stack();

		void push(Type const& value);
		Type& const pop();
		Type& const peek() const;

		size_t count() const;
	};
#pragma endregion

#pragma region StackImpl
	template<typename Type>
	Stack<Type>::Stack()
	{
		this->__stack = new LinkedList<Type>();
	}
	template<typename Type>
	Stack<Type>::~Stack()
	{
		delete this->__stack;
	}

	template<typename Type>
	void Stack<Type>::push(Type const& value)
	{
		this->__stack->add(value);
	}
	template<typename Type>
	Type& const Stack<Type>::pop()
	{
		Type* result = new Type();
		*result = this->__stack->operator[](this->__stack->count() - 1);
		this->__stack->removeTail();
		return *result;
	}
	template<typename Type>
	Type& const Stack<Type>::peek() const
	{
		return this->__stack->operator[](this->__stack->count() - 1);
	}
	template<typename Type>
	size_t Stack<Type>::count() const
	{
		return this->__stack->count();
	}
#pragma endregion

#pragma endregion
};

#endif //__STACK__