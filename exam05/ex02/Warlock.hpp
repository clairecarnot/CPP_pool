#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Dummy.hpp"
# include "Fwoosh.hpp"
# include "SpellBook.hpp"
# include "BrickWall.hpp"
# include "Fireball.hpp"
# include "Polymorph.hpp"
# include "TargetGenerator.hpp"

class Warlock
{
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();


		std::string const	&getName() const;
		std::string const	&getTitle() const;
		void			setTitle(std::string const &title);

		void			introduce() const;
		void			learnSpell(ASpell *spell);
		void			forgetSpell(std::string spell);
		void			launchSpell(std::string spell, ATarget const &target);

	private:
		Warlock();
		Warlock(Warlock const &src);

		Warlock	&operator=(Warlock const &src);

		std::string	_name;
		std::string	_title;
		SpellBook	_sB;
};

# endif
