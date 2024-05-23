#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

class	Polymorph : public ASpell
{
	public:
		Polymorph(void);
		Polymorph(Polymorph const &src);
		virtual ~Polymorph(void);

		Polymorph	&operator=(Polymorph const &src);

		virtual ASpell	*clone(void) const;

	private:
};

#endif
