// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <vector>
#include <random>

namespace InsertSelectionMerge
{
	void InsertSort(std::vector<int>& array)
	{
		for (size_t t = 1; t < array.size(); ++t)
			for (size_t _t = t; _t > 0 && array.at(_t - 1) > array.at(_t); --_t)
				std::swap(array.at(_t - 1), array.at(_t));
	};
	void SelectionSort(std::vector<int>& array)
	{
		for (size_t t = 0; t < array.size() - 1; ++t)
		{
			size_t min = t;
			for (size_t _t = t + 1; _t < array.size(); ++_t)
				if (array.at(_t) < array.at(min))
					min = _t;
			if (min != t)
			{
				std::swap(array.at(t), array.at(min));
				min = t;
			}
		}
	}
	void MergeSort(std::vector<int>& array)
	{
		if (array.size() <= 1)
			return;
		size_t middle = array.size() / 2;
		std::vector<int> left, right;
		for (size_t t = 0; t < middle; ++t)
			left.push_back(array.at(t));
		for (size_t t = middle; t < array.size(); ++t)
			right.push_back(array.at(t));
		MergeSort(left);
		MergeSort(right);
		array.clear();
		auto Merge = [](std::vector<int>& left, std::vector<int>& right) -> std::vector<int> &
		{
			std::vector<int>* result = new std::vector<int>(left.size() + right.size());
			size_t t1 = 0, t2 = 0;
			for (size_t t = 0; t < result->size(); ++t)
				if (t1 == left.size())
					result->at(t) = right.at(t2++);
				else
					if (t2 == right.size())
						result->at(t) = left.at(t1++);
					else
					{
						if (left.at(t1) < right.at(t2))
							result->at(t) = left.at(t1++);
						else
							result->at(t) = right.at(t2++);
					}
			return *result;
		};
		array = Merge(left, right);
	}
	void print(std::vector<int>& array)
	{
		for (size_t t = 0; t < array.size(); ++t)
			std::cout << array.at(t) << " ";
		std::cout << "\n";
	};
	void randomize(std::vector<int>& array)
	{
		array.clear();
#ifndef _WIN64
		std::mt19937 random;
#else
		std::mt19937_64 random;
#endif
		std::random_device device;
		random.seed(device());
		std::uniform_int_distribution<int> distr(-10, 10);
		for (size_t t = 0; t < 10; ++t)
			array.push_back(distr(random));
	};

	int TEST()
	{
		std::vector<int> arr;
		std::cout << "\nInsertSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t"; InsertSort(arr);
		print(arr);
		std::cout << "\nSelectionSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t"; SelectionSort(arr);
		print(arr);
		std::cout << "\nMergeSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t"; MergeSort(arr);
		print(arr);

		std::cin.get();
		return 0;
	}
};