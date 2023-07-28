#ifndef Data_HPP
#define Data_HPP

#include <cstdint>
#include <iostream>

class Data
{
	private:
	public:
		Data();
		~Data();
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
