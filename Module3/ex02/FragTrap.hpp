#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap( const FragTrap &other );

		FragTrap& operator= ( const FragTrap &other );

		~FragTrap();

		void guardGate();
		void highFivesGuys(void);
};

#endif
