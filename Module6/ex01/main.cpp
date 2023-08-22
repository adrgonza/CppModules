#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data datax;
	std::cout << "Original Data object address " << &datax << std::endl;

	uintptr_t ptr = Serializer::serialize(&datax);
	std::cout << "Serialized address: " << ptr << std::endl;

	Data* res = Serializer::deserialize(ptr);
	std::cout << "Deserialized address: " << res << std::endl;
}
