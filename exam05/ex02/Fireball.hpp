#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include "ASpell.hpp"

class	Fireball : public ASpell
{
	public:
		Fireball();
		Fireball(Fireball const &src);
		virtual ~Fireball();

		Fireball	&operator=(Fireball const &src);

		virtual ASpell	*clone() const;

	private:
};

#endif
