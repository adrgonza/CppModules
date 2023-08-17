#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	for (int i = 0; container[i], i++)
	{
		if (container[i] == value)
			return (i);
	}
}
