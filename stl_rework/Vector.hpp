#pragma once
#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>

namespace Andi
{
	template <typename Type>
	class Vector
	{
	private:
		Type* data;
		size_t _size;
	public:
		Vector();
		Vector(Vector<Type> const& vec);
		~Vector();

		bool empty() const;
		Type at(size_t pos) const;
		size_t size() const;
		void push_back(Type const& value);
		void pop_back();
		void erase(size_t pos);
		void insert(size_t pos, Type const& value);
		void reverse();
		Type front() const;
		Type back() const;

		Type operator[](size_t);
		Vector<Type>& operator=(Vector<Type> const& vec);
		template<typename __Type>
		friend std::ostream& operator<<(std::ostream&, Vector<__Type> const&);
		template<typename __Type>
		friend bool operator==(Vector<Type> const&, Vector<__Type> const&);
		template<typename __Type>
		friend bool operator!=(Vector<Type> const&, Vector<__Type> const&);
	};
	template<typename Type>
	Vector<Type>::Vector()
	{
		this->_size = 0;
	}
	template<typename Type>
	Vector<Type>::Vector(Vector<Type> const& vec)
	{
		this->_size = vec.size();
		this->data = new Type[this->_size];
		for (size_t t = 0; t < this->_size; ++t)
			this->data[t] = vec.at(t);
	}
	template<typename Type>
	Vector<Type>::~Vector()
	{
		delete[] this->data;
	}

	template<typename Type>
	bool Vector<Type>::empty() const
	{
		return this->_size == 0 ? true : false;
	}
	template<typename Type>
	Type Vector<Type>::at(size_t pos) const
	{
		return this->data[pos];
	}
	template<typename Type>
	size_t Vector<Type>::size() const
	{
		return this->_size;
	}
	template<typename Type>
	void Vector<Type>::push_back(Type const& value)
	{
		if (this->_size == 0)
		{
			this->data = new Type[++_size];
			this->data[this->_size - 1] = value;
		}
		else
		{
			Type* temp = new Type[++_size];
			for (size_t t = 0; t < this->_size - 1; ++t)
				temp[t] = this->data[t];
			delete[] this->data;
			this->data = temp;
			this->data[this->_size - 1] = value;
		}
	}
	template<typename Type>
	void Vector<Type>::pop_back()
	{
		Type* temp = new Type[--_size];
		for (size_t t = 0; t < this->_size; ++t)
			temp[t] = this->data[t];
		delete[] this->data;
		this->data = temp;
	}
	template<typename Type>
	void Vector<Type>::erase(size_t pos)
	{
		if (pos < 1 || pos > this->_size)
			return;
		Type* temp = new Type[--_size];
		for (size_t t = 0; t < pos - 1; ++t)
			temp[t] = this->data[t];
		for (size_t t = pos - 1; t < this->_size; ++t)
			temp[t] = this->data[t + 1];
		delete[] this->data;
		this->data = temp;
	}
	template<typename Type>
	void Vector<Type>::insert(size_t pos, Type const& value)
	{
		if (pos < 1 || pos > this->_size)
			return;
		Type* temp = new Type[++_size];
		for (size_t t = 0; t < pos - 1; ++t)
			temp[t] = this->data[t];
		temp[pos - 1] = value;
		for (size_t t = pos; t < this->_size; ++t)
			temp[t] = this->data[t - 1];
		delete[] this->data;
		this->data = temp;
	}
	template<typename Type>
	void Vector<Type>::reverse()
	{
		Type* temp = new Type[this->_size];
		for (size_t t = 0; t < this->_size; ++t)
			temp[t] = this->data[this->_size - 1 - t];
		delete[] this->data;
		this->data = temp;
	}
	template<typename Type>
	Type Vector<Type>::front() const
	{
		return this->data[0];
	}
	template<typename Type>
	Type Vector<Type>::back() const
	{
		return this->data[_size - 1];
	}

	template<typename Type>
	Type Vector<Type>::operator[](size_t pos)
	{
		return this->data[pos];
	}
	template<typename Type>
	Vector<Type>& Vector<Type>::operator=(Vector<Type> const& vec)
	{
		if (this == &vec)
			return *this;
		this->_size = vec.size();
		this->data = new Type[this->_size];
		for (size_t t = 0; t < this->_size; ++t)
			this->data[t] = vec.at(t);
	}
	template<typename __Type>
	std::ostream& operator<<(std::ostream& ofs, Vector<__Type> const& vec)
	{
		for (size_t t = 0; t < vec.size(); ++t)
			ofs << vec.at(t) << " ";
		std::cout << "\n";
		return ofs;
	}
	template<typename __Type>
	bool operator==(Vector< __Type> const& vec1, Vector<__Type> const& vec2)
	{
		if (vec1.size() != vec2.size())
			return false;
		for (size_t t = 0; t < vec1.size(); ++t)
			if (vec1.at(t) != vec2.at(t))
				return false;
		return true;
	}
	template<typename __Type>
	bool operator!=(Vector<__Type> const& vec1, Vector<__Type> const& vec2)
	{
		if (vec1.size() != vec2.size())
			return true;
		for (size_t t = 0; t < vec1.size(); ++t)
			if (vec1.at(t) != vec2.at(t))
				return true;
		return false;
	}
}
#endif //__VECTOR__