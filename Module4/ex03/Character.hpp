#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
	public:
		Character();
		Character(std::string name);
		Character(const Character & other);

		~Character();

		Character& operator=( const Character &other );

		virtual std::string const &getName() const override;
};

#endif
