#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T* data;
		unsigned int lenght;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);

		~Array();

		Array& operator= ( const Array &other );
		T& operator[](int index);

		int size() const;
};


#endif