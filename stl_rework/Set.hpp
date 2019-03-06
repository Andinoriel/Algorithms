#pragma once
#ifndef __SET__
#define __SET__

#include <iostream>
#include <algorithm>
#include <functional>

namespace Andi
{
	template <typename Type, typename Comparator = std::less<Type>>
	class Set
	{
	private:
		Type *data;
		size_t size;
		Comparator comparator;

		typedef struct
		{
			bool operator()(Type left, Type right)
			{
				return left == right;
			}
		} _NO_CHANGE;

	public:
		Set();
		template <typename Right_Comparator = std::less<Type>>
		Set(Set<Type, Right_Comparator> const &set);
		//Construct only for lambda pred;
		//Use std::function<bool(Type, Type)>
		explicit Set(Comparator const &comparator);
		~Set();

		void insert(Type const &value);
		bool empty() const;
		void erase(size_t pos);
		void clear();
		void swap(Set &set);
		Type *const find(Type const &key) const;

		Type operator[](size_t pos) const;
		size_t operator()() const;
		template <typename Right_Comparator = std::less<Type>>
		Set<Type, Comparator> &operator=(Set<Type, Right_Comparator> &right);
		template <typename Right_Comparator>
		inline Set<Type, _NO_CHANGE> &operator+(Set<Type, Right_Comparator> const &right)
		{
			Set<Type, _NO_CHANGE> *result = new Set<Type, _NO_CHANGE>;
			for (size_t t = 0; t < this->size; ++t)
				result->insert(this->data[t]);
			for (size_t t = 0; t < right(); ++t)
				result->insert(right[t]);
			return *result;
		}
		//declaration inside for _NO_CHANGE visibility

		template <typename __Type, typename __Comparator = std::less<__Type>>
		friend std::ostream &operator<<(std::ostream &os, Set<__Type, __Comparator> const &set);
	};

	template <typename Type, typename Comparator>
	Set<Type, Comparator>::Set()
	{
		this->data = nullptr;
		this->size = 0;
	}
	template <typename Type, typename Comparator>
	template <typename Right_Comparator>
	Set<Type, Comparator>::Set(Set<Type, Right_Comparator> const &set)
	{
		this->size = set();
		this->data = new Type[this->size];
		for (size_t t = 0; t < this->size; ++t)
			this->data[t] = set[t];
	}
	template <typename Type, typename Comparator>
	Set<Type, Comparator>::Set(Comparator const &comparator)
	{
		this->comparator = comparator;
	}
	template <typename Type, typename Comparator>
	Set<Type, Comparator>::~Set()
	{
		delete[] this->data;
	}
	template <typename Type, typename Comparator>
	void Set<Type, Comparator>::insert(Type const &value)
	{
		if (this->size == 0)
		{
			this->data = new Type[++this->size];
			this->data[this->size - 1] = value;
		}
		else
		{
			for (size_t t = 0; t < this->size; ++t)
				if (this->data[t] == value)
					return;
			Type *temp = new Type[++this->size];
			for (size_t t = 0; t < this->size - 1; ++t)
				temp[t] = this->data[t];
			delete[] this->data;
			this->data = temp;
			this->data[this->size - 1] = value;
			std::sort(&this->data[0], &this->data[this->size], this->comparator);
		}
	}
	template <typename Type, typename Comparator>
	bool Set<Type, Comparator>::empty() const
	{
		return this->size == 0 ? true : false;
	}
	template <typename Type, typename Comparator>
	void Set<Type, Comparator>::erase(size_t pos)
	{
		if (pos < 0 || pos > this->size - 1)
			return;
		Type *temp = new Type[--this->size];
		for (size_t t = 0; t < pos; ++t)
			temp[t] = this->data[t];
		for (size_t t = pos; t < this->size; ++t)
			temp[t] = this->data[t + 1];
		delete[] this->data;
		this->data = temp;
	}
	template <typename Type, typename Comparator>
	void Set<Type, Comparator>::clear()
	{
		for (size_t t = 0; t < this->size; ++t)
		{
			this->erase(t);
			--t;
		}
	}
	template <typename Type, typename Comparator>
	void Set<Type, Comparator>::swap(Set &set)
	{
		Type *left = this->data;
		size_t s_left = this->size;
		Type *right = set.data;
		size_t s_right = set.size;
		this->data = right;
		this->size = s_right;
		set.data = left;
		set.size = s_left;
	}
	template <typename Type, typename Comparator>
	Type *const Set<Type, Comparator>::find(Type const &key) const
	{

		for (size_t t = 0; t < this->size; ++t)
			if (this->data[t] == key)
				return &this->data[t];
		return nullptr;
	}

	template <typename Type, typename Comparator>
	Type Set<Type, Comparator>::operator[](size_t pos) const
	{
		return this->data[pos];
	}
	template <typename Type, typename Comparator>
	size_t Set<Type, Comparator>::operator()() const
	{
		return this->size;
	}
	template <typename Type, typename Comparator>
	template <typename Right_Comparator>
	Set<Type, Comparator> &Set<Type, Comparator>::operator=(Set<Type, Right_Comparator> &right)
	{
		this->size = 0;
		delete[] this->data;
		for (size_t t = 0; t < right(); ++t)
			this->insert(right[t]);
		return *this;
	}

	template <typename __Type, typename __Comparator>
	std::ostream &operator<<(std::ostream &os, Set<__Type, __Comparator> const &set)
	{
		for (size_t t = 0; t < set.size; ++t)
			os << set.data[t] << " ";
		os << "\n";
		return os;
	}
}

#endif //__SET__