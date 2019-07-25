// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <string>
#include <string_view>

namespace Converter
{
	class ConverterFrom10
	{
	private:
		short current_base;
		static std::string_view constexpr digits[] = { "0", "1", "2", "3", "4", "5", "6","7", "8", "9", "A", "B", "C", "D", "E", "F",
			"G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
	public:
		ConverterFrom10(void);
		ConverterFrom10(short base);
		~ConverterFrom10(void) = default;

		void ChangeBase(short base);
		std::string Convert(size_t value_dec) const;
	};
	ConverterFrom10::ConverterFrom10(void) : current_base(10) {}
	ConverterFrom10::ConverterFrom10(short base) : current_base(base) {}

	void ConverterFrom10::ChangeBase(short base)
	{
		this->current_base = base;
	}
	std::string ConverterFrom10::Convert(size_t value_dec) const
	{
		if (value_dec == 0)
			return std::string();
		std::string result;
		result.insert(0, ConverterFrom10::digits[value_dec % this->current_base]);
		result.insert(0, ConverterFrom10::Convert(value_dec /= this->current_base));
		return result;
	}

	int TEST()
	{
		ConverterFrom10 cv(20);
		std::cout << cv.Convert(256); // CG

		std::cin.get();
		return 0;
	};
};