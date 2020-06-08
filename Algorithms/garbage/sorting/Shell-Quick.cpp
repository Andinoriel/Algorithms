// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <vector>
#include <functional>
#include <random>

namespace ShellQuick
{
	void ShellSort(std::vector<ptrdiff_t>& array) //-V2009
	{
		size_t step = array.size() / 2;
		while (step > 0)
		{
			for (size_t t = 0; t < array.size() - step; ++t)
			{
				ptrdiff_t _t = t;
				while (_t >= 0 && array.at(_t) > array.at(_t + step))
				{
					std::swap(array.at(_t), array.at(_t + step));
					--_t;
				}
			}
			step /= 2;
		}
	}
	void QuickSort(std::vector<ptrdiff_t>& array)
	{
		std::function<void(std::vector<ptrdiff_t>&, size_t, size_t)> qSort = [&qSort](std::vector<ptrdiff_t>& array, ptrdiff_t left, ptrdiff_t right) -> void
		{
			ptrdiff_t pivot;
			ptrdiff_t lo = left, hi = right;
			pivot = array.at(left);
			while (left < right)
			{
				while (array.at(right) >= pivot && left < right)
					--right;
				if (left != right)
				{
					array.at(left) = array.at(right);
					++left;
				}
				while ((array.at(left) <= pivot) && (left < right))
					++left;
				if (left != right)
				{
					array.at(right) = array.at(left);
					--right;
				}
			}
			array.at(left) = pivot;
			pivot = left;
			left = lo; right = hi;
			if (left < pivot) qSort(array, left, pivot - 1);
			if (right > pivot) qSort(array, pivot + 1, right);
		};
		qSort(array, 0, array.size() - 1);
	}
	void print(std::vector<ptrdiff_t>& array) //-V2009
	{
		for (size_t t = 0; t < array.size(); ++t)
			std::cout << array.at(t) << " ";
		std::cout << "\n";
	};
	void randomize(std::vector<ptrdiff_t>& array) //-V2009
	{
		array.clear();
#ifndef _WIN64
		std::mt19937 random;
#else
		std::mt19937_64 random;
#endif
		std::random_device device;
		random.seed(device());
		std::uniform_int_distribution<ptrdiff_t> distr(-10, 10);
		for (size_t t = 0; t < 10; ++t)
			array.push_back(distr(random));
	};

	int TEST()
	{
		std::vector<ptrdiff_t> arr;
		std::cout << "\nShellSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t";
		ShellSort(arr);
		print(arr);
		std::cout << "\nQuickSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t";
		QuickSort(arr);
		print(arr);

		std::cin.get();
		return 0;
	};
};