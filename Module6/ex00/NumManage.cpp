#include "NumManage.hpp"

NumManage::NumManage(std::string literal)
{
	this->literal = literal;
	try
	{
		std::cout << "char: " << convertToChar() << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "int: " << convertToInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "float: ";

		float num = convertToFloat();

		std::cout << num;

		if (num - (int)num == 0)
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

		double num = convertToDouble();

		std::cout << num;

		if (num - (int)num == 0)
			std::cout << ".0";

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

NumManage::NumManage(const NumManage & other)
{
	this->literal = other.literal;
}

NumManage::~NumManage()
{

}

char NumManage::convertToChar()
{
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (std::cout << "'", literal[0]);

	if (literal == "nan" || literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf")
		throw NumManage::Imposible();

	int chr = std::atoi(literal.c_str());

	if (chr > 31 && chr < 127)
	{
		std::cout << "'";
		return ((char)chr);
	}

	if (chr == 0)
		throw NumManage::NonDisplayable();
	else
		throw NumManage::Imposible();
}

int NumManage::convertToInt()
{
	if (literal == "nan" || literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf")
		throw NumManage::Imposible();

	int num = std::atoi(literal.c_str());

	if (literal == "0" || literal == "-1")
		return (num);

	if (num == 0 || num == -1)
		throw NumManage::NonDisplayable();
	return (num);
}

float NumManage::convertToFloat()
{
	if (literal == "0")
		return (0);

	float num = std::atof(literal.c_str());

	if (num == 0)
		throw NumManage::NonDisplayable();

	return (num);
}

double NumManage::convertToDouble()
{
	if (literal == "0")
		return (0);

	float num = std::atof(literal.c_str());

	if (num == 0)
		throw NumManage::NonDisplayable();

	return (num);
}

const char * NumManage::NonDisplayable::what() const throw()
{
	return ("Non displayable");
}

const char * NumManage::Imposible::what() const throw()
{
	return ("impossible");
}
