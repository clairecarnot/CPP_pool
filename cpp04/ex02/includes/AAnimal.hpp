#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);

		AAnimal	&operator=(AAnimal const &src);

		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	_type;
	
	private:
};

#endif
