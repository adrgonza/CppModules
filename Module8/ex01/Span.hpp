#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <cstdarg>
#include <vector>

class Span
{
	private:
		std::vector<int> vect;
		unsigned int MaxNumbers;
	public:
		Span();
		Span(unsigned int nb);
		Span(const Span & other);

		~Span();

		void addNumber(int nb);
		void addLotNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		Span& operator= ( const Span &other );
};

#endif
