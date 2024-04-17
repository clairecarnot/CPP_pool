#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Colors.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		virtual ~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &src);

		virtual void		learnMateria(AMateria *src);
		virtual AMateria*	createMateria(std::string const & type);
		void			printTemplates(void) const;

	private:
		AMateria	*_inventory[4];
};

#endif
