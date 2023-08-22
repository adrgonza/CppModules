#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(std::string literal);
		ScalarConverter(const ScalarConverter & other);

		ScalarConverter& operator=( const ScalarConverter &other );

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

		static char convertToChar(std::string literal);
		static int convertToInt(std::string literal);
		static float convertToFloat(std::string literal);
		static double convertToDouble(std::string literal);

	public:
		~ScalarConverter();

		static void convert(std::string literal);
};

#endif
