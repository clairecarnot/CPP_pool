#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class	Fireball : public ASpell
{
	public:
		Fireball(void);
		Fireball(Fireball const &src);
		virtual ~Fireball(void);

		Fireball	&operator=(Fireball const &src);

		virtual ASpell	*clone(void) const;

	private:
};

#endif
