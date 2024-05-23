#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

# include "ASpell.hpp"

class	ASpell;

class	ATarget
{
	public:
		ATarget(void);
		ATarget(std::string const &type);
		ATarget(ATarget const &src);
		virtual ~ATarget(void);

		ATarget	&operator=(ATarget const &src);

		std::string const	&getType(void) const;

		virtual ATarget	*clone(void) const = 0;
		void	getHitBySpell(ASpell const &spell) const;

	protected:
		std::string	_type;

	private:
};

#endif
