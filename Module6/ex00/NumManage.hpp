#ifndef NUMMANAGE_HPP
#define NUMMANAGE_HPP

#include <string>
#include <iostream>

class NumManage
{
	private:
		std::string literal;
	public:
		NumManage(std::string literal);
		NumManage(const NumManage & other);

		~NumManage();

		class  NonDisplayable: public std::exception
		{
			public:
				const char * what() const throw();
		};

		class Imposible : public std::exception
		{
			public:
				const char * what() const throw();
		};

		NumManage& operator=( const NumManage &other );
		char convertToChar();
		int convertToInt();
		float convertToFloat();
		double convertToDouble();
};

#endif
