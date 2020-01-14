// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <vector>
#include <random>

namespace BubbleCoctailEvenOddCombo
{
	void BubbleSort(std::vector<int>& array) //-V2009
	{
		for (size_t t = 0; t < array.size(); ++t)
			for (size_t _t = 0; _t < array.size() - t - 1; ++_t)
				if (array.at(_t + 1) < array.at(_t))
					std::swap(array.at(_t + 1), array.at(_t));
	};
	void CocktailSort(std::vector<int>& array) //-V2009
	{
		for (size_t l = 0, r = array.size() - 1; l < r;)
		{
			for (size_t t = l; t < r; ++t)
				if (array.at(t + 1) < array.at(t))
					std::swap(array.at(t + 1), array.at(t));
			--r;
			for (size_t t = r; t > l; --t)
				if (array.at(t - 1) > array.at(t))
					std::swap(array.at(t - 1), array.at(t));
			++l;
		}
	}
	void EvenOddSort(std::vector<int>& array) //-V2009
	{
		for (size_t t = 0; t < array.size(); ++t)
			for (size_t _t = (t % 2 == 0) ? 0 : 1; _t < array.size() - 1; _t += 2)
				if (array.at(_t) > array.at(_t + 1))
					std::swap(array.at(_t), array.at(_t + 1));
	}
	void CombSort(std::vector<int>& array) //-V2009
	{
		size_t count = 0;
		double coeff = 1.2473309;
		double step = static_cast<double>(array.size() - 1);
		while (step >= 1)
		{
			for (size_t t = 0; t + static_cast<size_t>(step) < array.size(); ++t) //-V2004
				if (array.at(t) > array.at(t + static_cast<size_t>(step))) //-V2004
				{
					std::swap(array.at(t), array.at(t + static_cast<size_t>(step))); //-V2004
					++count;
				}
			step /= coeff;
			for (size_t t = 0; t < array.size() - 1; ++t)
			{
				bool isSwap = false;
				for (size_t _t = 0; _t < array.size() - t - 1; ++_t)
					if (array.at(_t) > array.at(_t + 1))
					{
						std::swap(array.at(_t), array.at(_t + 1));
						isSwap = true;
						++count;
					}
				if (!isSwap)
					break;
			}
		}
	}
	void print(std::vector<int>& array) //-V2009
	{
		for (size_t t = 0; t < array.size(); ++t)
			std::cout << array.at(t) << " ";
		std::cout << "\n";
	}
	void randomize(std::vector<int>& array) //-V2009
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
	}

	int TEST()
	{
		std::vector<int> arr;
		std::cout << "\nBubbleSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t"; BubbleSort(arr);
		print(arr);
		std::cout << "\nCocktailSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t";	CocktailSort(arr);
		print(arr);
		std::cout << "\nEvenOddSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t";	EvenOddSort(arr);
		print(arr);
		std::cout << "\nCombSort:\n";
		randomize(arr);
		std::cout << "Input:\t"; print(arr);
		std::cout << "Sorted:\t";	CombSort(arr);
		print(arr);
		std::cin.get();
		return 0;
	}
};