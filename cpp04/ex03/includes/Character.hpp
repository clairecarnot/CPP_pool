#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iomanip>
# include "ICharacter.hpp"
# include "Colors.hpp"

class	Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		~Character(void);

		Character	&operator=(Character const &src);

		std::string const	&getName(void) const;

		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);
		AMateria const	*droppedMateria(int idx) const;
		void		printInventory(void) const;

	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif
