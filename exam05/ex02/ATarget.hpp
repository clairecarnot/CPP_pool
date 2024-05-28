#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell ;

class	ATarget
{
	public:
		ATarget();
		ATarget(std::string const &type);
		ATarget(ATarget const &src);
		virtual ~ATarget();

		ATarget &operator=(ATarget const &src);

		std::string const	&getType() const;

		virtual ATarget			*clone() const = 0;

		void			getHitBySpell(ASpell const &spell) const;

	protected:
		std::string	_type;
};

# endif
