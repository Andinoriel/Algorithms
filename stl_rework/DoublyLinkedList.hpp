#pragma once
#ifndef __DOUBLYLINKEDLIST__
#define __DOUBLYLINKEDLIST__

#include <iostream>
#include <algorithm>

namespace Andi
{
#pragma region DoublyLinkedList

#pragma region DoublyLinkedListDef
	template<typename Type>
	class DoublyLinkedList
	{
	private:
		struct Node
		{
			Type* __value;
			Node* __next;
			Node* __prev;

			Node();
			Node(Type const& value);
			~Node();
		};
		Node* __head;
		Node* __tail;

		size_t __count;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		void addFirst(Type const& value);
		void addLast(Type const& value);
		void removeFirst();
		void removeLast();
		bool remove(Type const& value);
		bool contains(Type const& value) const noexcept;
		void clear();
		void copyTo(Type* array, size_t start_pos) const;
		void copyTo(Type* array) const;
		size_t count() const noexcept;

		Type& const operator[](size_t pos) const;
	};
#pragma endregion

#pragma region NodeImpl
	template<typename Type>
	DoublyLinkedList<Type>::Node::Node()
	{
		this->__value = nullptr;
		this->__next = nullptr;
		this->__prev = nullptr;
	}
	template<typename Type>
	DoublyLinkedList<Type>::Node::Node(Type const& value)
	{
		this->__value = new Type(value);
		this->__next = nullptr;
		this->__prev = nullptr;
	}
	template<typename Type>
	DoublyLinkedList<Type>::Node::~Node()
	{
		delete this->__value;
		delete this->__next;
		//delete this->__prev;
	}
#pragma endregion

#pragma region DoublyLinkedListImpl
	template<typename Type>
	DoublyLinkedList<Type>::DoublyLinkedList()
	{
		this->__head = nullptr;
		this->__tail = nullptr;
		this->__count = 0;
	}
	template<typename Type>
	DoublyLinkedList<Type>::~DoublyLinkedList()
	{
		this->clear();
	}

	template<typename Type>
	void DoublyLinkedList<Type>::addFirst(Type const& value)
	{
		Node* node = new Node(value);
		Node* tmp = this->__head;
		this->__head = node;
		this->__head->__next = tmp;
		if (this->__count == 0)
			this->__tail = this->__head;
		else
			tmp->__prev = this->__head;
		++this->__count;
	}
	template<typename Type>
	void DoublyLinkedList<Type>::addLast(Type const& value)
	{
		Node* node = new Node(value);
		if (this->__count == 0)
			this->__head = node;
		else
		{
			this->__tail->__next = node;
			node->__prev = this->__tail;
		}
		this->__tail = node;
		++this->__count;
	}
	template<typename Type>
	void DoublyLinkedList<Type>::removeFirst()
	{
		if (this->__head != nullptr)
		{
			Node* current = this->__head->__next;
			if (this->__count > 1)
				current->__prev = nullptr;
			else
				this->__tail = nullptr;
			this->__head->__next = nullptr;
			delete this->__head;
			this->__head = current;
			--this->__count;
		}
	}
	template<typename Type>
	void DoublyLinkedList<Type>::removeLast()
	{
		if (this->__head != nullptr)
		{
			if (this->__count == 1)
			{
				delete this->__head;
				this->__head = nullptr;
				this->__tail = nullptr;
			}
			else
			{
				Node* current = this->__tail->__prev;
				current->__next = nullptr;
				this->__tail->__prev = nullptr;
				delete this->__tail;
				this->__tail = current;
			}
			--this->__count;
		}
	}
	template<typename Type>
	bool DoublyLinkedList<Type>::remove(Type const& value)
	{
		Node* previous = nullptr;
		Node* current = this->__head;
		while (current != nullptr)
		{
			if (*current->__value == value)
			{
				if (previous != nullptr)
				{
					previous->__next = current->__next;
					if (current->__next == nullptr)
						this->__tail = previous;
					else
						current->__next->__prev = previous;
					delete current;
					--this->__count;
				}
				else
					this->removeFirst();
				return true;
			}
			previous = current;
			current = current->__next;
		}
		return false;
	}
	template<typename Type>
	bool DoublyLinkedList<Type>::contains(Type const& value) const noexcept
	{
		Node* current = this->__head;
		while (current != nullptr)
		{
			if (*current->__value == value)
				return true;
			current = current->__next;
		}
		return false;
	}
	template<typename Type>
	void DoublyLinkedList<Type>::clear()
	{
		delete this->__head;
		this->__head = nullptr;
		this->__tail = nullptr;
		this->__count = 0;
	}
	template<typename Type>
	void DoublyLinkedList<Type>::copyTo(Type* array, size_t start_pos) const
	{
		Node* current = this->__head;
		for (size_t t = 0; t < start_pos; ++t)
			current = current->__next;
		size_t it = 0;
		while (current != nullptr)
		{
			array[it++] = *current->__value;
			current = current->__next;
		}
	}
	template<typename Type>
	void DoublyLinkedList<Type>::copyTo(Type* array) const
	{
		Node* current = this->__head;
		size_t it = 0;
		while (current != nullptr)
		{
			array[it++] = *current->__value;
			current = current->__next;
		}
	}
	template<typename Type>
	size_t DoublyLinkedList<Type>::count() const noexcept
	{
		return this->__count;
	}

	template<typename Type>
	Type& const DoublyLinkedList<Type>::operator[](size_t pos) const
	{
		Node* current = this->__head;
		for (size_t t = 0; t < pos; ++t)
			current = current->__next;
		return *current->__value;
	}
#pragma endregion

#pragma endregion
};

#endif //__DOUBLYLINKEDLIST__