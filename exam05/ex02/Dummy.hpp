#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy(void);
		Dummy(Dummy const &src);
		virtual ~Dummy(void);

		Dummy	&operator=(Dummy const &src);

		virtual ATarget	*clone(void) const;

	private:
};

#endif
