#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN & other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN()
{

}

bool RPN::isSign(char input)
{
	switch (input)
	{
		case '+':
			return (true);
		case '-':
			return (true);
		case '*':
			return (true);
		case '/':
			return (true);
	}
	return (false);
}

bool RPN::parseInput(const std::string &input)
{
	std::stringstream split(input);
	std::string iter;

	split >> iter;

	if (input.empty() || !std::isdigit(iter[0]) || iter.length() > 1)
	{
		std::cerr << "Error: no valid input: " << input << std::endl;
		return (false);
	}

	while (split >> iter)
	{
		if (iter.length() > 1)
		{
			std::cerr << "Error: parsing expresion : " << iter << std::endl;
			return (false);
		}
		if (!std::isdigit(iter[0]) && !isSign(iter[0]))
		{
			std::cerr << "Error: Invalid expression : " << iter << std::endl;
			return (false);
		}
	}
	return  (true);
}

bool RPN::exec(const std::string &input)
{
	std::stringstream split(input);
	std::string iter;
	int aux = 0;

	while (split >> iter)
	{
		if (std::isdigit(iter[0]))
			this->_stack.push(atoi(iter.c_str()));
		else if (this->_stack.size() > 1)
		{
			aux = this->_stack.top();
			this->_stack.pop();

			switch (iter[0])
			{
				case '+':
					this->_stack.top() += aux;
					break;
				case '-':
					this->_stack.top() -= aux;
					break;
				case '*':
					this->_stack.top() *= aux;
					break;
				case '/':
					if (aux == 0)
					{
						std::cerr << "Error: Division by zero" << std::endl;
						return (false);
					}
					this->_stack.top() /= aux;
			}
		}
		else
		{
			std::cerr << "Error: bad expression on : " << input << std::endl;
			return (false);
		}
	}

	if (this->_stack.size() > 1)
	{
		std::cerr << "Error : not enought operands to finish de expression" << std::endl;
		return (false);
	}

	std::cout << this->_stack.top() << std::endl;

	return (true);
}
