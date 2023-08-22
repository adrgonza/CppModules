#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	std::srand(std::time(0));
	int random = (std::rand() % 3) + 1;

	switch (random)
	{
		case 1:
			return (new A);
		case 2:
			return (new B);
		case 3:
			return (new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "In this case p = A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "In this case p = B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "In this case p = C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& ptr = dynamic_cast<A&>(p); (void)ptr;
		std::cout << "In this p = A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed checking type.." << std::endl;
	}
	try
	{
		B& ptr = dynamic_cast<B&>(p);(void)ptr;
		std::cout << "In this p = B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed checking type.." << std::endl;
	}
	try
	{
		C& ptr = dynamic_cast<C&>(p); (void)ptr;
		std::cout << "In this p = C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed checking type.." << std::endl;
	}
}

int main()
{
	Base* Ab = new A();

	identify(Ab);
	identify(*Ab);
	delete Ab;

	Base* Bb = new B();

	identify(Bb);
	identify(*Bb);
	delete Bb;

	Base* Cb = new C();

	identify(Cb);
	identify(*Cb);
	delete Cb;

	Base* Db = generate();

	identify(Db);
	identify(*Db);
	delete Db;
}
