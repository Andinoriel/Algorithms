// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <string>
#include <string_view>

namespace Converter
{
	class Converter
	{
	private:
		static short constexpr
			base2 = 2,
			base8 = 8,
			base16 = 16;
		static std::string_view constexpr digits[] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
	public:
		static std::string convert2(size_t value_dec) noexcept;
		static std::string convert8(size_t value_dec) noexcept;
		static std::string convert13(size_t value_dec) noexcept;
		static std::string convert16(size_t value_dec) noexcept;

		static void calculate() noexcept;
	};
	std::string Converter::convert2(size_t value_dec) noexcept
	{
		if (value_dec == 0)
			return std::string();
		std::string result;
		result.insert(0, Converter::digits[value_dec % Converter::base2]);
		result.insert(0, Converter::convert2(value_dec /= Converter::base2));
		return result;
	}
	std::string Converter::convert8(size_t value_dec) noexcept
	{
		if (value_dec == 0)
			return std::string();
		std::string result;
		result.insert(0, Converter::digits[value_dec % Converter::base8]);
		result.insert(0, Converter::convert8(value_dec /= Converter::base8));
		return result;
	}
	std::string Converter::convert13(size_t value_dec) noexcept
	{
		if (value_dec == 0)
			return std::string();
		std::string result;
		result.insert(0, Converter::digits[value_dec % 13]);
		result.insert(0, Converter::convert13(value_dec /= 13));
		return result;
	}
	std::string Converter::convert16(size_t value_dec) noexcept
	{
		if (value_dec == 0)
			return std::string();
		std::string result;
		result.insert(0, Converter::digits[value_dec % Converter::base16]);
		result.insert(0, Converter::convert16(value_dec /= Converter::base16));
		return result;
	}
	void Converter::calculate() noexcept
	{
		size_t temp;
		std::cout << "\nEnter the dec value: ";
		(std::cin >> temp).get();
		std::cout << "\nDec to Bin: " << Converter::convert2(temp);
		std::cout << "\nDec to Oct: " << Converter::convert8(temp);
		std::cout << "\nDec to Hex: " << Converter::convert16(temp);
	}

	int TEST()
	{
		Converter::calculate();

		std::cout << "\n\n";
		std::cout << "\nWHAT DO YOU GET IF YOU MULTIPLY SIX BY NINE? or\nThe Ultimate Question of Life, the Universe, and Everything\n\tAnswer: ";
		std::cout << atoi(Converter::convert13(6 * 9).c_str());

		std::cin.get();
		return 0;
	}
};