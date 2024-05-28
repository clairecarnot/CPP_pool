#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include "ATarget.hpp"

class	Dummy : public ATarget
{
	public:
		Dummy();
		Dummy(Dummy const &src);
		virtual ~Dummy();

		Dummy	&operator=(Dummy const &src);

		virtual ATarget	*clone() const;

	private:
};

#endif
