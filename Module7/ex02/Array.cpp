#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array()
{
    this->data = nullptr;
    this->lenght = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->lenght = n;
    this->data = new T[lenght];
    for (int i = 0; i < lenght; i++)
        data[i] = T();
}

template <typename T>
Array<T>::Array(const Array &other)
{
    this->lenght = other.lenght;
    this->data = new T[lenght];

    for (int i = 0; i < lenght; i++)
        data[i] = other.data[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
Array<T>& Array<T>::operator= ( const Array &other )
{
    if (this != &other)
        delete[] this->data;
    
    this->lenght = other.lenght;

    data = new T[lenght];
    for (int i = 0; i < lenght; i++)
        data[i] = other.data[i];

    return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || index >= lenght)
        throw std::out_of_range("Index out of range");

    return data[index];
}

template <typename T>
int Array<T>::size() const
{
    return (lenght);
}