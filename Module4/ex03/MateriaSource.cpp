#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		_materias[i] = other._materias[i];
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			_materias[i] = other._materias[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{

	for (int i = 0; i < 4; i++)
		if (!_materias[i])
		{
			_materias[i] = m;
			return;
		}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for ( int i = 0; i < 4; i++ )
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	return (NULL);
}
