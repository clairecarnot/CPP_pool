#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Fwoosh.hpp"
# include "Dummy.hpp"
# include "SpellBook.hpp"
# include "BrickWall.hpp"
# include "Polymorph.hpp"
# include "Fireball.hpp"
# include "TargetGenerator.hpp"

# include <iostream>
# include <vector>

class SpellBook;

class	Warlock
{
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);

		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void			setTitle(std::string const &title);

		void			introduce() const;
		void			learnSpell(ASpell *spell);
		void			forgetSpell(std::string const &spell);
		void			launchSpell(std::string const &spell, ATarget const &target);

	private:
		Warlock(void);
		Warlock(Warlock const &src);

		Warlock	&operator=(Warlock const &src);

		std::string		_name;
		std::string		_title;
		SpellBook		*_book;
};

#endif
