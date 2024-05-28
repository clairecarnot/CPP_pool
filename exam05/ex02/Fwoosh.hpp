#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include "ASpell.hpp"

class	Fwoosh : public ASpell
{
	public:
		Fwoosh();
		Fwoosh(Fwoosh const &src);
		virtual ~Fwoosh();

		Fwoosh	&operator=(Fwoosh const &src);

		virtual ASpell	*clone() const;

	private:
};

#endif
