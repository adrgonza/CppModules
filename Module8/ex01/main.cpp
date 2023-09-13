#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span hola = Span(200);

	Span sec(100);

	sec.addNumber(0);
	sec.addNumber(0);
	sec.addNumber(0);
	sec.addNumber(0);

	std::cout << "Longest : " << sec.longestSpan() << std::endl;
	std::cout << "Shortest : " << sec.shortestSpan() << std::endl;

	sec.addNumber(-1);

	std::cout << "Longest : " << sec.longestSpan() << std::endl;
	std::cout << "Shortest : " << sec.shortestSpan() << std::endl;

	Span s = Span(30000);

	std::vector<int> vec;
	for (int i = 0; i < 10 * 3000; i += 5)
		vec.push_back(i);
	s.addLotNumbers(vec.begin(), vec.end());
	std::cout << "Longest : " << s.longestSpan() << std::endl;
	std::cout << "Shortest : " << s.shortestSpan() << std::endl;

	Span one = Span(1);

	one.addNumber(3);

	try
	{
		one.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		one.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		one.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try {
		std::vector<int> vect(1, 500);
		one.addLotNumbers(vect.begin(), vect.end());
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

