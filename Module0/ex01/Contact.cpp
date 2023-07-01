#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getTruncFirstName() const
{
	std::string str = this->_firstName;
	if(str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}
std::string Contact::getTruncLastName() const
{
	std::string str = this->_lastName;
	if(str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}
std::string Contact::getTruncNickName() const
{
	std::string str = this->_nickname;
	if(str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}
std::string Contact::getFirstName() const {return this->_firstName;}
std::string Contact::getLastName() const {return this->_lastName;}
std::string Contact::getNickName() const {return this->_nickname;}
std::string Contact::getPhoneNumber() const {return this->_phoneNumber;}
std::string Contact::getDarkestSecret() const {return this->_darkestSecret;}

Contact::Contact() {}

Contact::~Contact() {}
