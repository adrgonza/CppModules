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
			this->data = new T[0];
			if (!data)
			{
				std::cerr << "New failed.." << std::endl;
				return ;
			}
			this->lenght = 0;
		}

		Array(unsigned int n)
		{
			this->data = new T[n];
			if (!data)
			{
				std::cerr << "New failed.." << std::endl;
				return ;
			}
			this->lenght = n;
		}

		Array(const Array &other)
		{
			this->data = new T[other.lenght];
			if (!data)
			{
				std::cerr << "New failed.." << std::endl;
				return ;
			}
			for (unsigned int i = 0; i < other.lenght; i++)
				this->data[i] = other.data[i];
			this->lenght = other.lenght;
		}

		~Array()
		{
			delete[] data;
		}

		Array& operator= ( const Array &other )
		{
			if (this != &other)
			{
				delete[] this->data;

				data = new T[other.lenght];
				if (!this->data)
				{
					std::cerr << "New failed.." << std::endl;
					return *this;
				}

				for (unsigned int i = 0; i < other.lenght; i++)
					this->data[i] = other.data[i];
				this->lenght = other.lenght;
			}
			return *this;
		}

		T& operator[](int index)
		{
			if (index < 0 || static_cast<unsigned int>(index) >= this->lenght)
				throw std::out_of_range("Index out of range");

			return this->data[index];
		}

		unsigned int size() const
		{
			return (this->lenght);
		}
};

#endif
