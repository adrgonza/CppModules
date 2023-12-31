#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <stdexcept>
#include <cstdarg>
#include <vector>

template<typename T>
class MutantStack : public std::stack<T, std::list<T> >
{
	private:
		T*	data;
		int	lenght;
	public:
		MutantStack()
		{
		}

		MutantStack(const MutantStack & other)
		{
			*this = other;
		}

		MutantStack& operator= ( const MutantStack &other )
		{
			if (this != &other)
			{
				*this = other;
			}
			return (*this);
		}

		~MutantStack()
		{
		}

		typedef typename std::list<T>::iterator iterator;
		typedef  typename std::list<T>::const_iterator const_iterator;
		typedef  typename std::list<T>::reverse_iterator reverse_iterator;
		typedef typename std::list<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}
		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}

		reverse_iterator rbegin()
		{
			return this->c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const
		{
			return this->c.rbegin();
		}

		const_reverse_iterator rend() const
		{
			return this->c.rend();
		}
};

#endif
