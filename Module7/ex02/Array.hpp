#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* data;
		unsigned int lenght;
	public:
		Array()
		{
			this->data = NULL;
			this->lenght = 0;
		}

		Array(unsigned int n)
		{
			this->lenght = n;
			this->data = new T[lenght];
			for (unsigned int i = 0; i < lenght; i++)
				data[i] = T();
		}

		Array(const Array &other)
		{
			this->lenght = other.lenght;
			this->data = new T[lenght];

			for (unsigned i = 0; i < lenght; i++)
				data[i] = other.data[i];
		}

		~Array()
		{
			delete[] data;
		}

		Array& operator= ( const Array &other )
		{
			if (this != &other)
			delete[] this->data;

			this->lenght = other.lenght;

			data = new T[lenght];
			for (int i = 0; i < lenght; i++)
				data[i] = other.data[i];

			return *this;
		}

		T& operator[](int index)
		{
			if (index < 0 || index >= static_cast<int>(lenght))
				throw std::out_of_range("Index out of range");

			return data[index];
		}

		int size() const
		{
			return (lenght);
		}
};

#endif
