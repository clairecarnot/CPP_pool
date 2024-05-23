#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <vector>

# include "Warlock.hpp"

class SpellBook
{
	public:
		SpellBook(void);
		~SpellBook();

		void	learnSpell(ASpell*);
		void	forgetSpell(std::string const &);
		ASpell*	createSpell(std::string const &);

	private:
		SpellBook(SpellBook const &src);

		SpellBook	&operator=(SpellBook const &src);

		std::vector<ASpell*>	_sp;
};

#endif
