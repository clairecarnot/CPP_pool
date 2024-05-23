#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Fwoosh.hpp"
# include "Dummy.hpp"

# include <iostream>
# include <vector>

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
		std::vector<ASpell *>	_sp;
};

#endif
