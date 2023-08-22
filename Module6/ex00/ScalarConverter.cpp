#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal)
{
	try
	{
		std::cout << "char: " << convertToChar(literal) << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: " << convertToInt(literal) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: ";

		float num = static_cast<float>(convertToFloat(literal));

		std::cout << num;

		if (num - static_cast<int>(num) == 0)
			std::cout << ".0";

		std::cout << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: ";

		double num = static_cast<double>(convertToDouble(literal));

		std::cout << num;

		if (num - static_cast<int>(num) == 0)
			std::cout << ".0";

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

char ScalarConverter::convertToChar(std::string literal)
{
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (std::cout << "'", literal[0]);

	if (literal == "nan" || literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf")
		throw ScalarConverter::Imposible();

	int chr = static_cast<int>(std::atoi(literal.c_str()));

	if (chr > 31 && chr < 127)
	{
		std::cout << "'";
		return (static_cast<char>(chr));
	}

	if (chr == 0 && literal[0] != 48)
		throw ScalarConverter::NonDisplayable();
	else
		throw ScalarConverter::Imposible();
}

int ScalarConverter::convertToInt(std::string literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf")
		throw ScalarConverter::Imposible();

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (static_cast<int>(literal[0]));

	int num = static_cast<int>(std::atoi(literal.c_str()));

	if (literal == "0" || literal == "-1")
		return (num);

	if ((num == 0 && literal[0] != 48)|| num == -1)
		throw ScalarConverter::NonDisplayable();
	return (num);
}

float ScalarConverter::convertToFloat(std::string literal)
{
	if (literal == "0")
		return (0);

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (static_cast<float>(literal[0]));

	float num = static_cast<float>(std::atof(literal.c_str()));

	if (num == 0)
		throw ScalarConverter::NonDisplayable();

	return (num);
}

double ScalarConverter::convertToDouble(std::string literal)
{
	if (literal == "0")
		return (0);

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (static_cast<double>(literal[0]));

	double num = static_cast<double>(std::atof(literal.c_str()));

	if (num == 0)
		throw ScalarConverter::NonDisplayable();

	return (num);
}

const char * ScalarConverter::NonDisplayable::what() const throw()
{
	return ("Non displayable");
}

const char * ScalarConverter::Imposible::what() const throw()
{
	return ("impossible");
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter &other )
{
	(void)other;
	return (*this);
}
