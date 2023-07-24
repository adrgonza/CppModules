#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>


class ClapTrap
{
	protected:
		std::string name;
		int HitPoints;
		int EnergyPoints;
		int AttackDamage;

	public:
		ClapTrap();
		ClapTrap( const std::string name );
		ClapTrap(std::string name, int hp, int ep, int ad);
		ClapTrap( const ClapTrap &other );

		~ClapTrap();

		ClapTrap& operator= ( const ClapTrap &other );

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
