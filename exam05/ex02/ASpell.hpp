#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget ;

class	ASpell
{
	public:
		ASpell();
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &src);
		virtual ~ASpell();

		ASpell	&operator=(ASpell const &src);

		std::string const	&getName() const;
		std::string const	&getEffects() const;

		virtual ASpell		*clone() const = 0;
		
		void			launch(ATarget const &target) const;

	protected:
		std::string	_name;
		std::string	_effects;
};

# endif
