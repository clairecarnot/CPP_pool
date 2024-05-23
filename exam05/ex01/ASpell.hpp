#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

# include "ATarget.hpp"

class	ATarget;

class	ASpell
{
	public:
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &src);
		virtual ~ASpell(void);

		ASpell	&operator=(ASpell const &src);

		std::string const	&getName(void) const;
		std::string const	&getEffects(void) const;

		virtual ASpell	*clone(void) const = 0;
		void		launch(ATarget const &target) const;

	protected:
		std::string	_name;
		std::string	_effects;

	private:
};

#endif
