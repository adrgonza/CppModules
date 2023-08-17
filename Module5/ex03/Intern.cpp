#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	const std::string FormNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (FormNames[i] == name)
		{
			std::cout << "Intern creates " << name << " Form" << std::endl;
			switch (i)
			{
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}

	std::cout << "Intern could not create " << name << " Form" << std::endl;
	return (NULL);
}
