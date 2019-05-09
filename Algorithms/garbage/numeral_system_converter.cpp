#include <iostream>
#include <string>
#include <string_view>

class Converter
{
private:
	static short constexpr
		base2 = 2,
		base8 = 8,
		base16 = 16;
	static std::string_view constexpr digits[] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
public:
	Converter();
	~Converter();

	std::string convert2(size_t value_dec) const noexcept;
	std::string convert8(size_t value_dec) const noexcept;
	std::string convert13(size_t value_dec) const noexcept;
	std::string convert16(size_t value_dec) const noexcept;

	void calculate() const noexcept;
};

Converter::Converter()
{
}
Converter::~Converter()
{
	;
}
std::string Converter::convert2(size_t value_dec) const noexcept
{
	if (value_dec == 0)
		return std::string();
	std::string result;
	result.insert(0, this->digits[value_dec % this->base2]);
	result.insert(0, this->convert2(value_dec /= this->base2));
	return result;
}
std::string Converter::convert8(size_t value_dec) const noexcept
{
	if (value_dec == 0)
		return std::string();
	std::string result;
	result.insert(0, this->digits[value_dec % this->base8]);
	result.insert(0, this->convert8(value_dec /= this->base8));
	return result;
}
std::string Converter::convert13(size_t value_dec) const noexcept
{
	if (value_dec == 0)
		return std::string();
	std::string result;
	result.insert(0, this->digits[value_dec % 13]);
	result.insert(0, this->convert13(value_dec /= 13));
	return result;
}
std::string Converter::convert16(size_t value_dec) const noexcept
{
	if (value_dec == 0)
		return std::string();
	std::string result;
	result.insert(0, this->digits[value_dec % this->base16]);
	result.insert(0, this->convert16(value_dec /= this->base16));
	return result;
}
void Converter::calculate() const noexcept
{
	size_t temp;
	std::cout << "\nEnter the dec value: ";
	(std::cin >> temp).get();
	std::cout << "\nDec to Bin: " << this->convert2(temp);
	std::cout << "\nDec to Oct: " << this->convert8(temp);
	std::cout << "\nDec to Hex: " << this->convert16(temp);
}

int main()
{
	Converter converter;
	converter.calculate();

	std::cout << "\n\n";
	std::cout << "\nWHAT DO YOU GET IF YOU MULTIPLY SIX BY NINE? or\nThe Ultimate Question of Life, the Universe, and Everything\n\tAnswer: ";
	std::cout << atoi(converter.convert13(6 * 9).c_str());

	std::cin.get();
	return 0;
}