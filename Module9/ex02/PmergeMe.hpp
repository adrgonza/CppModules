#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>

class PmergeMe
{
	private:
		std::list<unsigned int>_list;
		std::vector<unsigned int> _vect;
		int NbArguments;
	public:
		PmergeMe();
		PmergeMe(int argc);
		PmergeMe(const PmergeMe & other);

		PmergeMe& operator=(const PmergeMe & other);

		~PmergeMe();

		bool parseArgument(char **argv);
		void exec();
		void mergeInsertVect();
		void mergeInsertList();
};

#endif
