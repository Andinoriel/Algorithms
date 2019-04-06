#pragma once
#ifndef __MAP__
#define __MAP__

#include <iostream>
#include <algorithm>

namespace Andi
{
	template<typename Key, typename Type, typename Comparator = std::less<>>
	class Map
	{
	private:
		class MapElement
		{
		private:
			Key* key; Type* data;
		public:
			MapElement();
		};
		MapElement* data;
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
		Map();
		template<typename Right_Comparator = std::less<>>
		Map(Map<Key, Type, Right_Comparator> const& map);
		//Construct only for lambda pred;
		//Use std::function<bool(Type, Type)> for comparator definition
		explicit Map(Comparator const& comparator);
		~Map();

		void insert(Type const& value);
		bool empty() const;
		void erase(size_t pos);
		size_t size_() const;
		void clear();
		void swap(Map& map);
		Type* const find(Type const& key) const;

		Type operator[](size_t pos) const;
		template <typename Right_Comparator = std::less<>>
		Map<Key, Type, Comparator>& operator=(Map<Key, Type, Right_Comparator>& right);
		template <typename Right_Comparator>
		inline Map<Key, Type, _NO_CHANGE>& operator+(Map<Key, Type, Right_Comparator> const& right)
		{
			Map<Key, Type, _NO_CHANGE>* result = new Map<Key, Type, _NO_CHANGE>;
			for (size_t t = 0; t < this->size; ++t)
				result->insert(this->data[t]);
			for (size_t t = 0; t < right(); ++t)
				result->insert(right[t]);
			return *result;
		}
		//declaration inside for _NO_CHANGE visibility

		template <typename __Key, typename __Type, typename __Comparator = std::less<>>
		friend std::ostream& operator<<(std::ostream& os, Map<__Key, __Type, __Comparator> const& map);
	};

	template<typename Key, typename Type, typename Comparator>
	Map<Key, Type, Comparator>::Map()
	{
		this->data = nullptr;
		this->size = 0;
	}
	template<typename Key, typename Type, typename Comparator>
	template<typename Right_Comparator>
	Map<Key, Type, Comparator>::Map(Map<Key, Type, Right_Comparator> const& map)
	{
		//copying construct
	}
	template<typename Key, typename Type, typename Comparator>
	Map<Key, Type, Comparator>::Map(Comparator const& comparator)
	{
		this->comparator = comparator;
	}
	template<typename Key, typename Type, typename Comparator>
	Map<Key, Type, Comparator>::~Map()
	{
		delete[] this->data;
	}
}

#endif //__MAP__