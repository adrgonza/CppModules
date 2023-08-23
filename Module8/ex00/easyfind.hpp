#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator i = std::find(container.begin(), container.end(), value);

	if (i == container.end())
		throw	std::out_of_range("There is not coincidences..");

	return (i);
}
#endif
