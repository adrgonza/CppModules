#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

typedef struct TData
{
	char *dataPointer;
} Data;


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer & other);

		Serializer& operator=(Serializer& other);

		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
