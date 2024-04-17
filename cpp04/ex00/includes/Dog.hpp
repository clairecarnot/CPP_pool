#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog	&operator=(Dog const &src);

		virtual void	makeSound(void) const;

};

#endif
