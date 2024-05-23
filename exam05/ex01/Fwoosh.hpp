#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class	Fwoosh : public ASpell
{
	public:
		Fwoosh(void);
		Fwoosh(Fwoosh const &src);
		virtual ~Fwoosh(void);

		Fwoosh	&operator=(Fwoosh const &src);

		virtual ASpell	*clone(void) const;

	private:
};

#endif
