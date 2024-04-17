#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog	&operator=(Dog const &src);

		virtual void	makeSound(void) const;
		Brain		*getBrain(void) const;

	private:
		Brain	*_brain;
};

#endif
