#pragma once
#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>

namespace Andi
{
	template <typename T>
	class Vector
	{
	private:
		T* data;
		size_t _size;
	public:
		Vector();
		Vector(Vector<T> const& vec);
		~Vector();

		bool empty() const;
		T at(size_t pos) const;
		size_t size() const;
		void push_back(T const& value);
		void pop_back();
		void erase(size_t pos);
		void insert(size_t pos, T const& value);
		void reverse();
		T front() const;
		T back() const;

		T operator[](size_t);
		Vector<T>& operator=(Vector<T> const& vec);
		template<typename Type>
		friend std::ostream& operator<<(std::ostream&, Vector<Type> const&);
		template<typename Type>
		friend bool operator==(Vector<Type> const&, Vector<Type> const&);
		template<typename Type>
		friend bool operator!=(Vector<Type> const&, Vector<Type> const&);
	};
	template<typename T>
	Vector<T>::Vector()
	{
		this->_size = 0;
	}
	template<typename T>
	Vector<T>::Vector(Vector<T> const& vec)
	{
		this->_size = vec.size();
		this->data = new T[this->_size];
		for (size_t t = 0; t < this->_size; ++t)
			this->data[t] = vec.at(t);
	}
	template<typename T>
	Vector<T>::~Vector()
	{
		delete[] this->data;
	}

	template<typename T>
	bool Vector<T>::empty() const
	{
		return this->_size == 0 ? true : false;
	}
	template<typename T>
	T Vector<T>::at(size_t pos) const
	{
		return this->data[pos];
	}
	template<typename T>
	size_t Vector<T>::size() const
	{
		return this->_size;
	}
	template<typename T>
	void Vector<T>::push_back(T const& value)
	{
		if (this->_size == 0)
		{
			this->data = new T[++_size];
			this->data[this->_size - 1] = value;
		}
		else
		{
			T* temp = new T[++_size];
			for (size_t t = 0; t < this->_size - 1; ++t)
				temp[t] = this->data[t];
			delete[] this->data;
			this->data = temp;
			this->data[this->_size - 1] = value;
		}
	}
	template<typename T>
	void Vector<T>::pop_back()
	{
		T* temp = new T[--_size];
		for (size_t t = 0; t < this->_size; ++t)
			temp[t] = this->data[t];
		delete[] this->data;
		this->data = temp;
	}
	template<typename T>
	void Vector<T>::erase(size_t pos)
	{
		if (pos < 1 || pos > this->_size)
			return;
		T* temp = new T[--_size];
		for (size_t t = 0; t < pos - 1; ++t)
			temp[t] = this->data[t];
		for (size_t t = pos - 1; t < this->_size; ++t)
			temp[t] = this->data[t + 1];
		delete[] this->data;
		this->data = temp;
	}
	template<typename T>
	void Vector<T>::insert(size_t pos, T const& value)
	{
		if (pos < 1 || pos > this->_size)
			return;
		T* temp = new T[++_size];
		for (size_t t = 0; t < pos - 1; ++t)
			temp[t] = this->data[t];
		temp[pos - 1] = value;
		for (size_t t = pos; t < this->_size; ++t)
			temp[t] = this->data[t - 1];
		delete[] this->data;
		this->data = temp;
	}
	template<typename T>
	void Vector<T>::reverse()
	{
		T* temp = new T[this->_size];
		for (size_t t = 0; t < this->_size; ++t)
			temp[t] = this->data[this->_size - 1 - t];
		delete[] this->data;
		this->data = temp;
	}
	template<typename T>
	T Vector<T>::front() const
	{
		return this->data[0];
	}
	template<typename T>
	T Vector<T>::back() const
	{
		return this->data[_size - 1];
	}

	template<typename T>
	T Vector<T>::operator[](size_t pos)
	{
		return this->data[pos];
	}
	template<typename T>
	Vector<T>& Vector<T>::operator=(Vector<T> const& vec)
	{
		if (this == &vec)
			return *this;
		this->_size = vec.size();
		this->data = new T[this->_size];
		for (size_t t = 0; t < this->_size; ++t)
			this->data[t] = vec.at(t);
	}
	template<typename T>
	std::ostream& operator<<(std::ostream& ofs, Vector<T> const& vec)
	{
		for (size_t t = 0; t < vec.size(); ++t)
			ofs << vec.at(t) << " ";
		std::cout << "\n";
		return ofs;
	}
	template<typename T>
	bool operator==(Vector<T> const& vec1, Vector<T> const& vec2)
	{
		if (vec1.size() != vec2.size())
			return false;
		for (size_t t = 0; t < vec1.size(); ++t)
			if (vec1.at(t) != vec2.at(t))
				return false;
		return true;
	}
	template<typename T>
	bool operator!=(Vector<T> const& vec1, Vector<T> const& vec2)
	{
		if (vec1.size() != vec2.size())
			return true;
		for (size_t t = 0; t < vec1.size(); ++t)
			if (vec1.at(t) != vec2.at(t))
				return true;
		return false;
	}
	//---------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------
}
#endif //_VECTOR_