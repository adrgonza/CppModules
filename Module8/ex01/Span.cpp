#include "Span.hpp"

Span::Span()
{
	this->MaxNumbers = 20;
}

Span::Span(unsigned int nb)
{
	this->MaxNumbers = nb;
}

Span::Span(const Span & other)
{
	this->MaxNumbers = other.MaxNumbers;
	this->vect = other.vect;
}

Span& Span::operator= ( const Span &other )
{
	if (this != &other)
	{
		this->MaxNumbers = other.MaxNumbers;
		this->vect = other.vect;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{
	if (this->vect.size() >= this->MaxNumbers)
		throw	std::length_error("Vect is alredy full...");

	this->vect.push_back(nb);
}

void Span::addLotNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (vect.size() + std::distance(begin, end) > MaxNumbers)
		throw std::overflow_error("Adding these numbers would exceed the capacity of Span.");

	vect.insert(vect.end(), begin, end);
}

int Span::shortestSpan()
{
	if (vect.size() < 2)
	{
		throw std::runtime_error("Insufficient numbers to calculate span.");
	}

	std::vector<int> tmpVect = this->vect;

	std::sort(tmpVect.begin(), tmpVect.end());

	int shortest = 2147483647;

	for (std::vector<int>::iterator i = tmpVect.begin(); i != tmpVect.end() - 1; i++)
	{
		int span = *(i + 1) - *i;

		if (span < shortest)
			shortest = span;
	}

	return (shortest);
}

int Span::longestSpan()
{
	if (vect.size() < 2)
	{
		throw std::runtime_error("Insufficient numbers to calculate span.");
	}

	std::vector<int> tmpVect = this->vect;

	std::sort(tmpVect.begin(), tmpVect.end());

	return tmpVect[tmpVect.size() - 1] - tmpVect[0];
}
