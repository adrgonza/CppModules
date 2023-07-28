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
		std::cout << "Non displayable" << std::endl;
	}
	try
	{
		std::cout << "int: " << convertToInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Non displayable" << std::endl;
	}
	try
	{
		std::cout << "float: " << convertToFloat() << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Non displayable" << std::endl;
	}
	try
	{
		std::cout << "double: " << convertToDouble() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Non displayable" << std::endl;
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
		return (literal[0]);
	int chr = convertToInt();

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
	return (std::stoi(literal));
}

float NumManage::convertToFloat()
{
	return (std::stof(literal));
}

double NumManage::convertToDouble()
{
	return (std::stod(literal));
}


const char * NumManage::NonDisplayable::what() const throw()
{
	return ("Non displayable");
}

const char * NumManage::Imposible::what() const throw()
{
	return ("impossible");
}
