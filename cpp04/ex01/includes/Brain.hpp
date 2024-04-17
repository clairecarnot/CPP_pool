#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);

		Brain	&operator=(Brain const &src);

		std::string const	getIdeas(int const i) const;
		void		setIdeas(int const i, std::string const &idea);

	private:
		std::string	_ideas[100];
};

#endif
