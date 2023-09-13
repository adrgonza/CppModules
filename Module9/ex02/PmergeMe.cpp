#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc)
{
	this->NbArguments = argc - 1;
}

PmergeMe::PmergeMe(const PmergeMe & other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe & other)
{
	if (this != &other)
	{
		this->NbArguments = other.NbArguments;
		this->_list = other._list;
		this->_vect = other._vect;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::parseArgument(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::string str = argv[i];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isdigit(str[i]))
			{
				std::cout << "Error: not valid token : " << str << std::endl;
				return (false);
			}
		}

		unsigned int aux = std::atol(str.c_str());
		if (aux > 2147483647 || str.length() > 11)
		{
			std::cout << "Error: not valid token : " << str << std::endl;
			return (false);
		}

		if (std::find(this->_vect.begin(), this->_vect.end(), aux) != this->_vect.end())
		{
			std::cout << "Error: repeated number : " << aux << std::endl;
			return (false);
		}

		this->_vect.push_back(aux);
		this->_list.push_back(aux);
	}

	return (true);
}

void PmergeMe::mergeInsertVect()
{
	for (size_t i = 1; i < _vect.size(); ++i)
	{
		unsigned int key = _vect[i];
		int j = static_cast<int>(i) - 1;

		while (j >= 0 && _vect[j] > key)
		{
			_vect[j + 1] = _vect[j];
			--j;
		}

		_vect[j + 1] = key;
	}
}

void PmergeMe::mergeInsertList()
{
	std::list<unsigned int> sortedList;
	std::list<unsigned int>::iterator it = _list.begin();

	sortedList.push_back(*it++);

	while (it != _list.end())
	{
		std::list<unsigned int>::iterator resultIt = sortedList.begin();

		while (resultIt != sortedList.end() && *resultIt < *it)
			++resultIt;

		sortedList.insert(resultIt, *it++);
	}

	_list = sortedList;
}

void PmergeMe::exec()
{
	std::cout << "Before:";
	for (size_t i = 0; i < this->_vect.size(); i++)
		std::cout << " " << this->_vect[i];
	std::cout << std::endl;

	clock_t startVector = clock();
	mergeInsertVect();
	clock_t endVector = clock();

	std::cout << "After:";
	for (size_t i = 0; i < this->_vect.size(); i++)
		std::cout << " " << this->_vect[i];
	std::cout << std::endl;

	clock_t startList = clock();
	mergeInsertList();
	clock_t endList = clock();

	double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;
	double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000;

	std::cout << "Time to process a range of " << this->NbArguments << " elements with std::vector: " << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << this->NbArguments << " elements with std::list: " << timeList << " us" << std::endl;
}
