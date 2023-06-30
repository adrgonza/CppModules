#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	std::string str = this->_firstName;
	if(str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}
std::string Contact::getLastName() const
{
	std::string str = this->_lastName;
	if(str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}
std::string Contact::getNickName() const
{
	std::string str = this->_nickname;
	if(str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}

Contact::Contact() {}

Contact::~Contact() {}
