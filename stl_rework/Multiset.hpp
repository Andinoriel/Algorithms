#pragma once
#ifndef __MULTISET__
#define __MULTISET__

#include <iostream>
#include <algorithm>
#include <functional>


namespace Andi
{
	template <typename Type, typename Comparator = std::less<Type>>
	class Multiset
	{
	private:
		Type* data;
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
		Multiset();
		template <typename Right_Comparator = std::less<Type>>
		Multiset(Multiset<Type, Right_Comparator> const& set);
		//Construct only for lambda pred;
		//Use std::function<bool(Type, Type)>
		explicit Multiset(Comparator const& comparator);
		~Multiset();

		void insert(Type const& value);
		bool empty() const;
		void erase(size_t pos);
		void size_() const;
		void clear();
		void swap(Multiset& multiset);
		Type* const find(Type const& key) const; //return first finding value

		Type operator[](size_t pos) const;
		template <typename Right_Comparator = std::less<Type>>
		Multiset<Type, Comparator>& operator=(Multiset<Type, Right_Comparator>& right);
		template <typename Right_Comparator>
		inline Multiset<Type, _NO_CHANGE>& operator+(Multiset<Type, Right_Comparator> const& right)
		{
			Multiset<Type, _NO_CHANGE> *result = new Multiset<Type, _NO_CHANGE>;
			for (size_t t = 0; t < this->size; ++t)
				result->insert(this->data[t]);
			for (size_t t = 0; t < right(); ++t)
				result->insert(right[t]);
			return *result;
		}
		//declaration inside for _NO_CHANGE visibility

		template <typename __Type, typename __Comparator = std::less<__Type>>
		friend std::ostream& operator<<(std::ostream& os, Multiset<__Type, __Comparator> const& multiset);
	};

	template <typename Type, typename Comparator>
	Multiset<Type, Comparator>::Multiset()
	{
		this->data = nullptr;
		this->size = 0;
	}
	template <typename Type, typename Comparator>
	template <typename Right_Comparator>
	Multiset<Type, Comparator>::Multiset(Multiset<Type, Right_Comparator> const& multiset)
	{
		this->size = multiset();
		this->data = new Type[this->size];
		for (size_t t = 0; t < this->size; ++t)
			this->data[t] = set[t];
	}
	template <typename Type, typename Comparator>
	Multiset<Type, Comparator>::Multiset(Comparator const& comparator)
	{
		this->comparator = comparator;
	}
	template <typename Type, typename Comparator>
	Multiset<Type, Comparator>::~Multiset()
	{
		delete[] this->data;
	}

	template <typename Type, typename Comparator>
	void Multiset<Type, Comparator>::insert(Type const &value)
	{
		if (this->size == 0)
		{
			this->data = new Type[++this->size];
			this->data[this->size - 1] = value;
		}
		else
		{
			Type* temp = new Type[++this->size];
			for (size_t t = 0; t < this->size - 1; ++t)
				temp[t] = this->data[t];
			delete[] this->data;
			this->data = temp;
			this->data[this->size - 1] = value;
			std::sort(&this->data[0], &this->data[this->size], this->comparator);
		}
	}
	template <typename Type, typename Comparator>
	bool Multiset<Type, Comparator>::empty() const
	{
		return this->size == 0 ? true : false;
	}
	template <typename Type, typename Comparator>
	void Multiset<Type, Comparator>::erase(size_t pos)
	{
		if (pos < 0 || pos > this->size - 1)
			return;
		Type* temp = new Type[--this->size];
		for (size_t t = 0; t < pos; ++t)
			temp[t] = this->data[t];
		for (size_t t = pos; t < this->size; ++t)
			temp[t] = this->data[t + 1];
		delete[] this->data;
		this->data = temp;
	}
	template <typename Type, typename Comparator>
	void Multiset<Type, Comparator>::clear()
	{
		for (size_t t = 0; t < this->size; ++t)
		{
			this->erase(t);
			--t;
		}
	}
	template <typename Type, typename Comparator>
	void Multiset<Type, Comparator>::swap(Multiset& multiset)
	{
		Type* left = this->data;
		size_t s_left = this->size;
		Type* right = multiset.data;
		size_t s_right = multiset.size;
		this->data = right;
		this->size = s_right;
		multiset.data = left;
		multiset.size = s_left;
	}
	template <typename Type, typename Comparator>
	Type* const Multiset<Type, Comparator>::find(Type const& key) const
	{

		for (size_t t = 0; t < this->size; ++t)
			if (this->data[t] == key)
				return &this->data[t];
		return nullptr;
	}

	template <typename Type, typename Comparator>
	Type Multiset<Type, Comparator>::operator[](size_t pos) const
	{
		return this->data[pos];
	}
	template <typename Type, typename Comparator>
	template <typename Right_Comparator>
	Multiset<Type, Comparator>& Multiset<Type, Comparator>::operator=(Multiset<Type, Right_Comparator> &right)
	{
		this->size = 0;
		delete[] this->data;
		for (size_t t = 0; t < right(); ++t)
			this->insert(right[t]);
		return *this;
	}

	template <typename __Type, typename __Comparator>
	std::ostream& operator<<(std::ostream& os, Multiset<__Type, __Comparator> const& multiset)
	{
		for (size_t t = 0; t < set.size; ++t)
			os << set.data[t] << " ";
		os << "\n";
		return os;
	}
}



#endif //__MULTISET__