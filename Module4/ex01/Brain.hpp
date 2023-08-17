#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &other );

	~Brain();

	Brain& operator=( const Brain &other );
	std::string getIdeas(const int ideaNb);
	void setIdea(std::string, const int& idx);
};

#endif
