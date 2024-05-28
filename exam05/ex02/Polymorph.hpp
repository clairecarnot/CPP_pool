#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include "ASpell.hpp"

class	Polymorph : public ASpell
{
	public:
		Polymorph();
		Polymorph(Polymorph const &src);
		virtual ~Polymorph();

		Polymorph	&operator=(Polymorph const &src);

		virtual ASpell	*clone() const;

	private:
};

#endif
